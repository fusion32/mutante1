
typedef struct _material{
	int startIndex;
	int endIndex;
	int materialIndex;

	struct _material *next;
} material_t;

typedef struct _mesh {
	int vertexCount;
	int indexCount;
	float *vertices;
	int *indices;

	// a material will be set for a range of indices [a, b] so
	// the vertex data must be assembled with that in mind.

	// \/\/\/
	// or make multiple meshes with a single material

	material_t *materials;
} mesh_t;

typedef struct _model {
	mesh_t *mesh;
	void *animation_data;
} model_t;