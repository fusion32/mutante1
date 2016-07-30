#ifndef __R_PUBLIC_H__
#define __R_PUBLIC_H__

#include "../types.h"

//
typedef struct RModel RModel;

// Vulkan = Buffer
// OpenGL = Buffer
typedef struct RVertexBuffer RVertexBuffer;
typedef struct RIndexBuffer RIndexBuffer;

typedef struct RBuffer RBuffer;

// Vulkan = Image
// OpenGL = Texture (add support for bindless textures?)
typedef struct RTexture RTexture;

// Vulkan = ShaderModules / GraphicsPipeline
// OpenGL = Shader Objects
typedef struct RPipeline RPipeline;

// model has all static data
typedef struct RModel{
	// mesh
	void *vertices;
	void *indices;
	uint32_t vertexCount;
	uint32_t indexCount;

	// texture
	void *texture;
	void *texcoords;

	void *animations;
} RModel;

// entity has the model and
// the current model pose
typedef struct REntity{
	// model
	RModel *model;

	// model pose (state)
	void *bones;
} REntity;

// To init the renderer we need the window itself and it's extents
void R_Init();
void R_Cleanup();

// NOTE:
// so we don't need to create a descriptor set object here because the model/particle/surface/whateverthefuck will have the data to
// be used inside the shader and it's each specific renderer task to assign the right data to the shader input

// NOTE:
// The mesh is a part (or the whole) of the model's vertex data.
// The model has the vertex data, texture data, skeleton data, animation data, so on...

uint32_t R_RenderEntity(REntity *entity);

// render functions must be pointers to functions of OpenGL renderer or Vulkan renderer!
extern void (*R_Function1)(int a, int b);
extern void (*R_Function2)(void *a, void *b);


#endif //__R_PUBLIC_H__