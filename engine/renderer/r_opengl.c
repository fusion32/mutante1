#include "gl/gl_loader.h"

typedef enum RCommandID{
	COMMAND_UNKNOWN = 0,
	COMMAND_COPY_BUFFER,
	COMMAND_BIND_VERTEX_BUFFER,
	COMMAND_BIND_INDEX_BUFFER,
	COMMAND_BIND_PIPELINE,
	COMMAND_DRAW_INDEXED,

	// we might not even need these
	// because opengl doesn't have
	// render passes BUT still we'll
	// have to include the functions
	// for vulkan

	// vulkan = call vulkan api
	// opengl = do nothing
	COMMAND_PIPELINE_BARRIER,
	COMMAND_BEGIN_RENDER_PASS,
	COMMAND_END_RENDER_PASS,
	COMMAND_NEXT_SUBPASS,
} RCommandID;

typedef struct RCommand{
	RCommandID id;
	// command params
} RCommand;

// it might be better to use a linked list
// and alocate command buffers on the fly (?)

#define MAX_COMMANDS 256
typedef struct RCommandBuffer{
	RCommand buffer[MAX_COMMANDS];
} RCommandBuffer;


// these are system specific (defined in r_win32.c, r_unix.c)
void GL_CreateContext();
void GL_DestroyContext();