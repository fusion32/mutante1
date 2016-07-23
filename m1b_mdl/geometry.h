#include <libxml/parser.h>
#include <libxml/xmlschemas.h>

#define MAX_INPUT 16

#define TYPE_UNKNOWN 0
#define TYPE_FLOAT 1
#define TYPE_INTEGER 2
#define TYPE_STRING 3

typedef struct _array{
	int			type;
	xmlChar		*id;
	xmlChar		*count;
	xmlChar		*content;
} array_t;

typedef struct _accessor{
	xmlChar		*source;
	xmlChar		*count;
	xmlChar		*stride;
	int			mask;
} accessor_t;

typedef struct _source{
	xmlChar		*id;
	array_t		*array;
	accessor_t	*accessor;

	struct _source *next;
} source_t;

typedef struct _vertices{
	xmlChar		*id;
	xmlChar		*source;
} vertices_t;

typedef struct _input{
	xmlChar *semantic;
	xmlChar *source;
	xmlChar *offset;
	xmlChar *set;

	struct _input *next;
} input_t;

typedef struct _triangles{
	xmlChar *material;
	xmlChar *count;
	input_t *inputs;
	xmlChar *content;

	struct _triangles *next;
} triangles_t;

typedef struct _geometry{
	source_t *sources;
	vertices_t *vertices;
	triangles_t *triangles;

	struct _geometry *next;
} geometry_t;


void free_sources(source_t *sources);
void free_inputs(input_t *inputs);
void free_triangles(triangles_t *triangles);

source_t *parse_source(xmlNode *node);
vertices_t *parse_vertices(xmlNode *node);
triangles_t *parse_triangles(xmlNode *node);
geometry_t *parse_geometry(xmlNode *node);