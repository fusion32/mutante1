#ifndef __KEYCODE_H__
#define __KEYCODE_H__

typedef enum MouseState{
	M_BUTTON1 = 1,
	M_BUTTON2 = 2,
	M_BUTTON3 = 4,
	M_BUTTON4 = 8,
	M_BUTTON5 = 16
} MouseState;

typedef enum KeyCode{
	KEY_UNKNOWN = 0,

	// A-Z keys
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,

	// 0-9 keys
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,

	//
	KEY_MINUS,
	KEY_EQUAL,
	KEY_COMMA,
	KEY_PERIOD,

	//
	KEY_ESCAPE,
	KEY_BACKSPACE,
	KEY_RETURN,
	KEY_SPACE,
	KEY_TAB,
	KEY_CAPSLOCK,
	KEY_MENU,

	//
	KEY_CTRL,
	KEY_SHIFT,
	KEY_ALT,
	KEY_COMMAND,

	//
	KEY_PRTSCRN,
	KEY_SCRLCK,
	KEY_PAUSE,

	//
	KEY_INS,
	KEY_DEL,
	KEY_HOME,
	KEY_END,
	KEY_PGUP,
	KEY_PGDN,

	KEY_LEFTARROW,
	KEY_UPARROW,
	KEY_RIGHTARROW,
	KEY_DOWNARROW,

	KEY_KP_NUMLOCK,
	KEY_KP_SLASH,
	KEY_KP_MULT,
	KEY_KP_MINUS,
	KEY_KP_PLUS,
	KEY_KP_PERIOD,

	KEY_KP_NUM0,
	KEY_KP_NUM1,
	KEY_KP_NUM2,
	KEY_KP_NUM3,
	KEY_KP_NUM4,
	KEY_KP_NUM5,
	KEY_KP_NUM6,
	KEY_KP_NUM7,
	KEY_KP_NUM8,
	KEY_KP_NUM9,

	//
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,

	//
	KEY_MOUSE1,
	KEY_MOUSE2,
	KEY_MOUSE3,
	KEY_MOUSE4,
	KEY_MOUSE5,

	KEY_MWHEELUP,
	KEY_MWHEELDOWN,

	// auxiliary keys for different keyboard layouts
	KEY_AUX0,
	KEY_AUX1,
	KEY_AUX2,
	KEY_AUX3,
	KEY_AUX4,
	KEY_AUX5,
	KEY_AUX6,
	KEY_AUX7,
	KEY_AUX8,
	KEY_AUX9,
	KEY_AUX10,
	KEY_AUX11,
	KEY_AUX12,
	KEY_AUX13,
	KEY_AUX14,
	KEY_AUX15,
	KEY_AUX16

} KeyCode;

#endif //__KEYCODE_H__