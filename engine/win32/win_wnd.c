#include "win32.h"

#include "../types.h"

#include "../log.h"
#include "../system.h"
#include "../keycodes.h"
#include "../util.h"
#include "../event.h"

#include "../work.h"

// locals
static const char l_className[] = "Game";
static HINSTANCE l_hinstance = NULL;

// window
static HWND l_window = NULL;
static int l_posX;
static int l_posY;
static int l_width;
static int l_height;

// fullscreen/active
static int l_fullscreen;
static int l_active;

// mouse mode
static int l_mouseRelative;
static MouseState l_mouseState;

#define WINDOWED_STYLE			(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU)
#define WINDOWED_STYLE_EX		0

#define FULLSCREEN_STYLE		WS_OVERLAPPED
#define FULLSCREEN_STYLE_EX		WS_EX_APPWINDOW

/*

the approach with virtual keys isn't very good because multiple keys can yield the same
virtual key code which is not desired

US

KEY_AUX0 = [{
KEY_AUX1 = ]}
KEY_AUX2 = ;:
KEY_AUX3 = '"
KEY_AUX4 = `~
KEY_AUX5 = \|
KEY_AUX6 = /?
KEY_AUX7 = undefined
KEY_AUX8 = undefined


ABTN2

KEY_AUX0 = ´` (ACUTE/GRAVE ACCENT)
KEY_AUX1 = [{
KEY_AUX2 = ç
KEY_AUX3 = ~^
KEY_AUX4 = '"
KEY_AUX5 = ]}
KEY_AUX6 = ;:
KEY_AUX7 = \|
KEY_AUX8 = /?

*/

static const KeyCode l_keyMap[128] = {
	0,				KEY_ESCAPE,		KEY_1,			KEY_2,			KEY_3,			KEY_4,			KEY_5,			KEY_6,			KEY_7,			KEY_8,			// 0
	KEY_9,			KEY_0,			KEY_MINUS,		KEY_EQUAL,		KEY_BACKSPACE,	KEY_TAB,		KEY_Q,			KEY_W,			KEY_E,			KEY_R,			// 1
	KEY_T,			KEY_Y,			KEY_U,			KEY_I,			KEY_O,			KEY_P,			KEY_AUX0,		KEY_AUX1,		KEY_RETURN,		KEY_CTRL,		// 2
	KEY_A,			KEY_S,			KEY_D,			KEY_F,			KEY_G,			KEY_H,			KEY_J,			KEY_K,			KEY_L,			KEY_AUX2,		// 3
	KEY_AUX3,		KEY_AUX4,		KEY_SHIFT,		KEY_AUX5,		KEY_Z,			KEY_X,			KEY_C,			KEY_V,			KEY_B,			KEY_N,			// 4
	KEY_M,			KEY_COMMA,		KEY_PERIOD,		KEY_AUX6,		KEY_SHIFT,		KEY_KP_MULT,	KEY_ALT,		KEY_SPACE,		KEY_CAPSLOCK,	KEY_F1,			// 5
	KEY_F2,			KEY_F3,			KEY_F4,			KEY_F5,			KEY_F6,			KEY_F7,			KEY_F8,			KEY_F9,			KEY_F10,		KEY_PAUSE,		// 6
	KEY_SCRLCK,		KEY_KP_NUM7,	KEY_KP_NUM8,	KEY_KP_NUM9,	KEY_KP_MINUS,	KEY_KP_NUM4,	KEY_KP_NUM5,	KEY_KP_NUM6,	KEY_KP_PLUS,	KEY_KP_NUM1,	// 7
	KEY_KP_NUM2,	KEY_KP_NUM3,	KEY_KP_NUM0,	KEY_KP_PERIOD,	0,				0,				KEY_AUX7,		KEY_F11,		KEY_F12,		0,				// 8
	0,				KEY_COMMAND,	KEY_COMMAND,	KEY_MENU,		0,				0,				0,				0,				0,				0,				// 9
	0,				0,				0,				0,				0,				0,				0,				0,				0,				0,				// 10
	0,				0,				0,				0,				0,				KEY_AUX8,		0,				0,				0,				0,				// 11
	0,				0,				0,				0,				0,				0,				0,				0												// 12
};

KeyCode MapKey(uint16_t scan, uint16_t vkey, uint16_t flags)
{
	KeyCode key;

	switch(vkey){
		case VK_PAUSE:
			return KEY_PAUSE;
		case VK_NUMLOCK:
			return KEY_KP_NUMLOCK;

		// when the OS sends a virtual key 0xFF it means it sent a
		// fake key (shift, ctrl, w/e) attached to another key

		// in the case of KEY_PAUSE the fake key has the correct
		// virtual key god knows why and in the other cases
		// the actual key has the correct virtual key
		case 0xFF:
			return 0;
	}

	if(scan > 127)
		return 0;

	key = l_keyMap[scan];
	if(flags & RI_KEY_E0){
		switch(key){
			case KEY_AUX6:
				return KEY_KP_SLASH;

			case KEY_KP_MULT:
				return KEY_PRTSCRN;

			case KEY_KP_PERIOD:
				return KEY_DEL;
			case KEY_KP_NUM0:
				return KEY_INS;
			case KEY_KP_NUM1:
				return KEY_END;
			case KEY_KP_NUM2:
				return KEY_DOWNARROW;
			case KEY_KP_NUM3:
				return KEY_PGDN;
			case KEY_KP_NUM4:
				return KEY_LEFTARROW;
			case KEY_KP_NUM6:
				return KEY_RIGHTARROW;
			case KEY_KP_NUM7:
				return KEY_HOME;
			case KEY_KP_NUM8:
				return KEY_UPARROW;
			case KEY_KP_NUM9:
				return KEY_PGUP;
		}
	}

	return key;
}

/*

event received by windows sent to window proc

event received by window proc translated and dispatched

(this is for a no-fps game. if a key is bound to a modifier, it lose its status of modifier)
check if any modifier key is down (shift, ctrl, alt, cmd)

(in a classic fps game shift an ctrl will often already be bound so no combination with those will be possible)
execute command bound to combination (modifier, key)

make possible to make any key a modifier and binding something to it will make it lose its modifier status

kbd_unmodall
Kbd_mod <KEY>
kbd_unmod <KEY>

kbd_unbindall
kbd_bind <KEY> <COMMAND>
kbd_unbind <KEY>

//example:
kbd_mod SHIFT
kbd_bind SHIFT+Q <COMMAND>

//example (error)
kbd_bind SHIFT+Q <COMMAND>

Error: SHIFT is not flagged as a modifier! Check kbd_mod for more information.



/////////

investigate AltGr seems to trigger both KEY_CTRL and KEY_ALT at the same time

*/

void WIN32_WarpCursor(int x, int y)
{
	POINT pos = {x, y};
	ClientToScreen(l_window, &pos);
	SetCursorPos(pos.x, pos.y);
}

void WIN32_UpdateClipRect()
{
	RECT rect;
	if(l_mouseRelative){
		// need to clip the mouse to the client area or is possible
		// the user closes or moves the window accidentally while in
		// windowed mode
		if(!GetClientRect(l_window, &rect) || IsRectEmpty(&rect))
			return;
		ClientToScreen(l_window, (POINT *)&rect);
		ClientToScreen(l_window, (POINT *)&rect + 1);
		ClipCursor(&rect);
		//ShowCursor(FALSE);
	}
	else{
		ClipCursor(NULL);
		//ShowCursor(TRUE);
	}
}

void WIN32_MouseRelative(int relative)
{
	l_mouseRelative = (relative != 0);
	WIN32_UpdateClipRect();
}

void WIN32_UpdateDisplay()
{
	int ret;
	DEVMODE devMode;

	if(l_fullscreen){
		if(l_active){
			// restore window
			SendMessage(l_window, WM_SYSCOMMAND, SC_RESTORE, 0);

			// change display settings if needed
			EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode);
			LOG_DEBUG("CURRENT DISPLAY: %d, %d, %d, %d", devMode.dmBitsPerPel, devMode.dmPelsWidth, devMode.dmPelsHeight, devMode.dmDisplayFrequency);
			if(devMode.dmBitsPerPel != 32 ||
					devMode.dmPelsWidth != l_width ||
					devMode.dmPelsHeight != l_height ||
					devMode.dmDisplayFrequency != 60){
				devMode.dmBitsPerPel = 32;
				devMode.dmPelsWidth = l_width;
				devMode.dmPelsHeight = l_height;
				devMode.dmDisplayFrequency = 60;
				devMode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;
				if((ret = ChangeDisplaySettings(&devMode, CDS_FULLSCREEN)) != DISP_CHANGE_SUCCESSFUL)
					SYS_Error("Failed to change display settings! (%d)", ret);
			}
		}
		else{
			// minimize window
			SendMessage(l_window, WM_SYSCOMMAND, SC_MINIMIZE, 0);

			// restore display
			if((ret = ChangeDisplaySettings(NULL, 0)) != DISP_CHANGE_SUCCESSFUL)
				SYS_Error("Failed to restore desktop display settings! (%d)", ret);
		}
	}
	else{
		// if not in fullscreen this should restore the display settings
		if((ret = ChangeDisplaySettings(NULL, 0)) != DISP_CHANGE_SUCCESSFUL)
			SYS_Error("Failed to restore desktop display settings! (%d)", ret);

		// if active restore the window if somehow it is minimized
		if(l_active)
			SendMessage(l_window, WM_SYSCOMMAND, SC_RESTORE, 0);
	}
}

void WIN32_SetFullscreen(int fullscreen)
{
	if(fullscreen){
		LOG_DEBUG("SET FULLSCREEN");

		// remove window decoration
		SetWindowLong(l_window, GWL_STYLE, FULLSCREEN_STYLE);
		SetWindowLong(l_window, GWL_EXSTYLE, FULLSCREEN_STYLE_EX);

		l_fullscreen = 1;
		SetWindowPos(l_window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_FRAMECHANGED | SWP_NOSENDCHANGING);
	}
	else{
		LOG_DEBUG("RESET FULLSCREEN");

		// reset window decoration
		SetWindowLong(l_window, GWL_STYLE, WINDOWED_STYLE);
		SetWindowLong(l_window, GWL_EXSTYLE, WINDOWED_STYLE_EX);

		l_fullscreen = 0;
		SetWindowPos(l_window, HWND_NOTOPMOST, l_posX, l_posY, 0, 0, SWP_NOSIZE | SWP_FRAMECHANGED | SWP_NOSENDCHANGING);
	}
	WIN32_UpdateDisplay();
}

void WIN32_Activate(int active, int min)
{
	l_active = active;
	WIN32_UpdateDisplay();

	if(active){
		// activate sound and shit
	}
}

static LRESULT __stdcall WIN32_WindowProc(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg){
		// text
		case WM_UNICHAR:
			// idkwtf tbh
			//wParam; // UTF32 key code
			//lParam; // like WM_KEYDOWN
			// TODO: use only WM_CHAR and ignore this? or w/e
			break;

		case WM_CHAR:
			// parse this when the player is typing on chat
			// this event is generated when translate message translates a keydown event that can be writen as a character
			// and generates a UTF16 character according to the current keyboard layout

			// TODO: convert UTF16 to UTF8

			//wParam; // UTF16 key code
			//lParam; // like WM_KEYDOWN
			break;
			
		// mouse
		case WM_MOUSEWHEEL:
		{
			int dw, i;

			//LOG_DEBUG("mouse wheel event-> dist: %d, buttons: %d, x: %d, y: %d", (int16_t)HIWORD(wParam), LOWORD(wParam), LOWORD(lParam), HIWORD(lParam));

			dw = (int16_t)(HIWORD(wParam)) / WHEEL_DELTA;
			if(dw > 0){
				for(i = 0; i < dw; ++i)
					EV_Add(EVENT_KEY, 1, KEY_MWHEELUP, 0);
			}
			else if(dw < 0){
				for(i = 0; i > dw; --i)
					EV_Add(EVENT_KEY, 1, KEY_MWHEELDOWN, 0);
			}

			break;
		}

		case WM_MOUSEMOVE:
		{
			if(l_mouseRelative)
				break;

			EV_Add(EVENT_MOUSE, 0, LOWORD(lParam), HIWORD(lParam));
			// let it fall through the button check
		}

		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_XBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
		case WM_XBUTTONUP:
		case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDBLCLK:
		case WM_MBUTTONDBLCLK:
		case WM_XBUTTONDBLCLK:
		{
			if(l_mouseRelative)
				break;

			if((wParam & MK_LBUTTON) != (l_mouseState & M_BUTTON1)){
				l_mouseState ^= M_BUTTON1;
				EV_Add(EVENT_KEY, (l_mouseState & M_BUTTON1) != 0, KEY_MOUSE1, 0);
			}

			if((wParam & MK_RBUTTON) != (l_mouseState & M_BUTTON2)){
				l_mouseState ^= M_BUTTON2;
				EV_Add(EVENT_KEY, (l_mouseState & M_BUTTON2) != 0, KEY_MOUSE2, 0);
			}

			if((wParam & MK_MBUTTON) != (l_mouseState & M_BUTTON3)){
				l_mouseState ^= M_BUTTON3;
				EV_Add(EVENT_KEY, (l_mouseState & M_BUTTON3) != 0, KEY_MOUSE3, 0);
			}

			if((wParam & MK_XBUTTON1) != (l_mouseState & M_BUTTON4)){
				l_mouseState ^= M_BUTTON4;
				EV_Add(EVENT_KEY, (l_mouseState & M_BUTTON4) != 0, KEY_MOUSE4, 0);
			}

			if((wParam & MK_XBUTTON2) != (l_mouseState & M_BUTTON5)){
				l_mouseState ^= M_BUTTON5;
				EV_Add(EVENT_KEY, (l_mouseState & M_BUTTON5) != 0, KEY_MOUSE5, 0);
			}

			break;
		}

		case WM_INPUT:
		{
			RAWINPUT input;
			RAWMOUSE *mouse;
			RAWKEYBOARD *keyboard;
			KeyCode key;
			UINT size;

			size = sizeof(RAWINPUT);
			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, &input, &size, sizeof(RAWINPUTHEADER));

			if(input.header.dwType == RIM_TYPEMOUSE){
				mouse = &input.data.mouse;

				//NOTE: we should use only the raw input for mouse input while in play mode.
				//in menu we should use the WM_MOUSEMOVE as it will give an absolute position
				//of the mouse and will give the usual sensitivity of the system.

				if(!l_mouseRelative)
					break;

				LOG_DEBUG("M -> flags: %d, dx: %d, dy: %d, btn: %d, btnf: %d, btnd: %d, btnr: %d, extra: %d", mouse->usFlags,
					mouse->lLastX, mouse->lLastY, mouse->ulButtons, mouse->usButtonFlags, mouse->usButtonData,
					mouse->ulRawButtons, mouse->ulExtraInformation);
			}
			else if(input.header.dwType == RIM_TYPEKEYBOARD){
				keyboard = &input.data.keyboard;
				key = MapKey(keyboard->MakeCode, keyboard->VKey, keyboard->Flags);
				switch(keyboard->Message){
					case WM_SYSKEYDOWN:
					case WM_KEYDOWN:
					{
						EV_Add(EVENT_KEY, 1, key, 0);
						break;


						//
						LOG_DEBUG("KB -> code: %d, flags: %d, res: %d, vkey: %d, msg: %d, extra: %d",
							keyboard->MakeCode, keyboard->Flags, keyboard->Reserved, keyboard->VKey,
							keyboard->Message, keyboard->ExtraInformation);
						LOG_DEBUG("KeyCode: %d", key);

						switch(key){
							case KEY_H:
								//WIN32_SetFullscreen(!l_fullscreen);
								break;
							case KEY_R:
								//WIN32_MouseRelative(!l_mouseRelative);
								break;
							case KEY_KP_NUM5:
								EV_Dump();
								break;
						}
						break;
					}

					case WM_SYSKEYUP:
					case WM_KEYUP:
						EV_Add(EVENT_KEY, 0, key, 0);
						break;

					default:
						LOG_DEBUG("Caught invalid keyboard message! (%X)", keyboard->Message);
				}
			}

			break;
		}

		case WM_ACTIVATE:
			// this is an activate notification
			WIN32_Activate(LOWORD(wParam) != WA_INACTIVE, HIWORD(wParam));
			break;

		case WM_DESTROY:
			// dispatch quit event
			break;

		case WM_CLOSE:
			// dispatch quit event
			break;

		case WM_WINDOWPOSCHANGED:
		{
			WINDOWPOS *pos = (WINDOWPOS *)lParam;
			LOG_DEBUG("POSCHANGED: %d, %d, %d", l_fullscreen, pos->x, pos->y);

			// record the window position
			// only while not in fullscreen
			if(!l_fullscreen){
				l_posX = pos->x;
				l_posY = pos->y;
			}

			WIN32_UpdateClipRect();
			return 0;
		}

		case WM_SYSCOMMAND:
			switch(wParam){
				case SC_MONITORPOWER:
					// if the display is off somehow, let
					// it wake up
					if(lParam == -1)
						break;

				case SC_SCREENSAVE:
				case SC_KEYMENU:
					return 0;
			}
			break;
	}

	return DefWindowProc(window, msg, wParam, lParam);
}

void WIN32_RegisterRawInput()
{
	RAWINPUTDEVICE deviceList[] = {
		// {usUsagePage, usUsage, dwFlags, hwndTarget}

		// mouse
		{1, 2, 0, NULL},
		// joystick
		//{1, 4, 0, NULL},
		// gamepad
		//{1, 5, 0, NULL},
		// keyboard
		{1, 6, 0, NULL},
	};

	if(!RegisterRawInputDevices(deviceList, ARRAYSIZE(deviceList), sizeof(RAWINPUTDEVICE)))
		SYS_Error("Failed to register raw input! (%X)", GetLastError());
}

void WIN32_Init()
{
	l_hinstance = GetModuleHandle(NULL);
	WNDCLASSEX wndClass = {
		.cbSize = sizeof(WNDCLASSEX),
		.style = 0,
		.lpfnWndProc = WIN32_WindowProc,
		.cbClsExtra = 0,
		.cbWndExtra = 0,
		.hInstance = l_hinstance,
		.hIcon = NULL,
		.hCursor = NULL,
		.hbrBackground = NULL,
		.lpszMenuName = NULL,
		.lpszClassName = l_className,
		.hIconSm = NULL
	};

	if(RegisterClassEx(&wndClass) == 0)
		SYS_Error("Failed to register WIN32 class! (%X)", GetLastError());

	// when in fullscreen posX and posY should be 0
	l_posX = 800;	// CFG_GetInt(CFG_WND_POSX); --> clip to monitor range
	l_posY = 100;	// CFG_GetInt(CFG_WND_POSY); --> clip to monitor range
	l_width = 800; // CFG_GetInt(CFG_WND_WIDTH);
	l_height = 600; // CFG_GetInt(CFG_WND_HEIGHT);

	l_fullscreen = 0; // CFG_GetInt(CFG_WND_FULLSCREEN);
	l_active = 0;

	RECT rc = {0, 0, l_width, l_height};
	AdjustWindowRect(&rc, WINDOWED_STYLE, FALSE);
	l_window = CreateWindowEx(WINDOWED_STYLE_EX, l_className, l_className, WINDOWED_STYLE, l_posX,
		l_posY, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, l_hinstance, NULL);

	if(l_window == NULL)
		SYS_Error("Failed to create WIN32 window! (%X)", GetLastError());

	ShowWindow(l_window, SW_SHOW);

	//WIN32_SetFullscreen(0);
	WIN32_UpdateDisplay();

	// register raw input
	WIN32_RegisterRawInput();
}

void WIN32_Cleanup()
{
	DestroyWindow(l_window);
	UnregisterClass(l_className, l_hinstance);
}

HINSTANCE WIN32_GetInstanceHandle()
{
	if(!l_hinstance)
		SYS_Error("WIN32_GetInstanceHandle: Trying to retrieve instance handle without having previously initialized the windows interface!");
	return l_hinstance;
}

HWND WIN32_GetWindowHandle()
{
	if(!l_window)
		SYS_Error("WIN32_GetWindowHandle: Trying to retrieve window handle without having previously initialized the windows interface!");
	return l_window;
}

void WIN32_GetWindowExtent(uint32_t *width, uint32_t *height)
{
	if(!l_window)
		SYS_Error("WIN32_GetWindowExtent: Trying to retrieve window extent without having previously initialized the windows interface!");

	if(!width || !height){
		LOG_WARNING("WIN32_GetWindowExtent: Params `width` and `height` must be non-null!");
		return;
	}

	*width = l_width;
	*height = l_height;
}

void WIN32_DispatchEvents()
{
	MSG msg;
	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}