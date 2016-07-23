#include "geometry.h"

void free_sources(source_t *sources)
{
	source_t *src, *tmp;

	src = sources;
	while(src != NULL){
		tmp = src->next;

		if(src->id != NULL)
			xmlFree(src->id);

		if(src->array != NULL){
			if(src->array->id != NULL)
				xmlFree(src->array->id);
			if(src->array->count != NULL)
				xmlFree(src->array->count);
			if(src->array->content != NULL)
				xmlFree(src->array->content);
		}

		if(src->accessor != NULL){
			if(src->accessor->source != NULL)
				xmlFree(src->accessor->source);
			if(src->accessor->count != NULL)
				xmlFree(src->accessor->count);
			if(src->accessor->stride)
				xmlFree(src->accessor->stride);
		}

		free(src);
		src = tmp;
	}
}

void free_inputs(input_t *inputs)
{
	input_t *in, *tmp;

	in = inputs;
	while(in != NULL){
		tmp = in->next;

		if(in->semantic != NULL)
			xmlFree(in->semantic);
		if(in->source != NULL)
			xmlFree(in->source);
		if(in->offset != NULL)
			xmlFree(in->offset);
		if(in->set != NULL)
			xmlFree(in->set);

		free(in);
		in = tmp;
	}
}

void free_triangles(triangles_t *triangles)
{
	triangles_t *tri, *tmp;

	tri = triangles;
	while(tri != NULL){
		tmp = tri->next;

		if(tri->material != NULL)
			xmlFree(tri->material);
		if(tri->count != NULL)
			xmlFree(tri->count);
		if(tri->content != NULL)
			xmlFree(tri->content);

		if(tri->inputs != NULL)
			free_inputs(tri->inputs);

		free(tri);
		tri = tmp;
	}
}

static int check_vcount(const xmlChar *vcount)
{
	int vc;
	const xmlChar *ptr;
	xmlChar *endptr;

	ptr = vcount;
	while(*ptr != 0x00){
		if(ptr[0] == 0x20 || ptr == vcount){
			vc = strtol(ptr, &endptr, 0);
			if(ptr != endptr)
				printf("\nstrtol failed!\n");
			if(ptr != endptr && vc != 3)
				return -1;
		}
		ptr++;
	}

	return 0;
}

source_t *parse_source(xmlNode *node)
{
	xmlNode *cur, *aux, *a2;

	source_t *source = NULL;
	array_t *array = NULL;
	accessor_t *accessor = NULL;
	xmlChar *source_id = NULL;
	xmlChar *param_name = NULL;
	xmlChar *param_type = NULL;
	int check, i;

	if(xmlStrcmp(node->name, (const xmlChar*)"source") != 0){
		printf("[ERROR] parse_source: trying to parse an incompatible node!\n");
		return NULL;
	}

	source_id = xmlGetProp(node, (const xmlChar*)"id");
	if(source_id == NULL){
		printf("[WARNING] <source> doesn't have an id! Skipping...\n");
		return NULL;
	}

	// <source>
	//	cur = <source> children
	for(cur = node->children; cur != NULL; cur = cur->next){

		// <float_array>
		if(xmlStrcmp(cur->name, (const xmlChar*)"float_array") == 0){
			if(array == NULL){
				array = malloc(sizeof(array_t));
				array->id = xmlGetProp(cur, (const xmlChar*)"id");
				array->count = xmlGetProp(cur, (const xmlChar*)"count");
				array->content = xmlNodeGetContent(cur);

				if(array->id == NULL || array->count == NULL || array->content == NULL){
					if(array->id != NULL)
						xmlFree(array->id);
					if(array->count != NULL)
						xmlFree(array->count);
					if(array->content != NULL)
						xmlFree(array->content);
					free(array);
					array = NULL;
					printf("[ERROR] <float_array> is missing properties!\n");
				}
			}
			else{
				printf("[WARNING] This implementation supports only one float_array per <source>! Only the first occurrence will be parsed.\n");
			}
		}
		// </float_array>

		// <technique_common>
		//	aux = <technique_common> children
		//	a2 = <accessor> children
		else if(xmlStrcmp(cur->name, (const xmlChar*)"technique_common") == 0){
			for(aux = cur->children; aux != NULL && accessor == NULL; aux = aux->next){
				if(xmlStrcmp(aux->name, (const xmlChar*)"accessor") == 0){
					accessor = malloc(sizeof(accessor_t));
					accessor->source = xmlGetProp(aux, (const xmlChar*)"source");
					accessor->count = xmlGetProp(aux, (const xmlChar*)"count");
					accessor->stride = xmlGetProp(aux, (const xmlChar*)"stride");

					check = 0;
					if(accessor->source == NULL || accessor->count == NULL || accessor->stride == NULL){
						printf("[ERROR] <accessor> is missing properties! Skipping...\n");
					}
					else{
						accessor->mask = 0;
						for(a2 = aux->children, i = 0; a2 != NULL; a2 = a2->next, ++i){
							if(xmlStrcmp(a2->name, (const xmlChar*)"param") == 0){
								param_name = xmlGetProp(a2, (const xmlChar*)"name");
								param_type = xmlGetProp(a2, (const xmlChar*)"type");

								if(param_type == NULL){
									printf("[ERROR] <param> must have a type!\n");
								}
								else if(xmlStrcmp(param_type, (const xmlChar*)"float") != 0){
									printf("[ERROR] <param> must have a float type!\n");
								}
								else if(param_name != NULL){
									accessor->mask |= (1 << i);
								}

								if(param_name != NULL)
									xmlFree(param_name);
								if(param_type != NULL)
									xmlFree(param_type);
							}
							else{
								printf("[WARNING] Unexpected <accessor> child: %s\n", a2->name);
							}
						}

						if(accessor->mask == 0){
							printf("[ERROR] <accessor> retrieves no data from it's source!\n");
						}
						else{
							check = 1;
						}
					}

					if(check == 0){
						if(accessor->source != NULL)
							xmlFree(accessor->source);
						if(accessor->count != NULL)
							xmlFree(accessor->count);
						if(accessor->stride != NULL)
							xmlFree(accessor->stride);
						free(accessor);
						accessor = NULL;
					}
				}
				else{
					printf("[ERROR] Unexpected <technique_common> child: %s\n", aux->name);
				}
			}

			if(accessor != NULL && aux != NULL){
				printf("[WARNING] This implementation supports only one <accessor> per <technique_common>. Only the first valid occurrence will be parsed.\n");
			}
		}
		// </technique_common>

		else{
			printf("[ERROR] Unexpected <source> child: %s\n", cur->name);
		}
	}
	// </source>

	if(array != NULL && accessor != NULL){
		source = malloc(sizeof(source_t));
		source->id = source_id;
		source->array = array;
		source->accessor = accessor;
		source->next = NULL;
	}
	else{
		if(array != NULL){
			if(array->id != NULL)
				xmlFree(array->id);
			if(array->count != NULL)
				xmlFree(array->count);
			if(array->content != NULL)
				xmlFree(array->content);
			free(array);
			array = NULL;
		}

		if(accessor != NULL){
			if(accessor->source != NULL)
				xmlFree(accessor->source);
			if(accessor->count != NULL)
				xmlFree(accessor->count);
			if(accessor->stride != NULL)
				xmlFree(accessor->stride);
			free(accessor);
			accessor = NULL;
		}

		xmlFree(source_id);
	}

	return source;
}

vertices_t *parse_vertices(xmlNode *node)
{
	xmlNode *cur;

	vertices_t *vertices = NULL;
	xmlChar *vertices_id = NULL;
	xmlChar *input_semantic = NULL;
	xmlChar *input_source = NULL;
	int check;

	if(xmlStrcmp(node->name, (const xmlChar*)"vertices") != 0){
		printf("[ERROR] parse_vertices: trying to parse an incompatible node!!\n");
		return NULL;
	}

	vertices_id = xmlGetProp(node, (const xmlChar*)"id");
	if(vertices_id == NULL){
		printf("[WARNING] <vertices> doesn't have an id! Skipping...\n");
		return NULL;
	}

	for(cur = node->children; cur != NULL && input_source == NULL; cur = cur->next){
		input_semantic = xmlGetProp(cur, (const xmlChar*)"semantic");
		input_source = xmlGetProp(cur, (const xmlChar*)"source");

		check = 0;
		if(input_source == NULL){
			printf("[ERROR] <input> must have a source!\n");
		}
		else if(input_semantic == NULL){
			printf("[ERROR] <input> must have a semantic!\n");
		}
		else if(xmlStrcmp(input_semantic, (const xmlChar*)"POSITION") != 0){
			printf("[ERROR] <input> must have the `POSITION` semantic!\n");
		}
		else{
			check = 1;
		}

		if(input_source != NULL && check == 0)
			xmlFree(input_source);
		if(input_semantic != NULL)
			xmlFree(input_semantic);
	}

	if(input_source != NULL){
		if(cur != NULL){
			printf("[WARNING] This implementation supports only one <input> per <vertices> with the `POSITION` semantic. Only the first valid occurrence will be parsed.\n");
		}

		vertices = malloc(sizeof(vertices_t));
		vertices->id = vertices_id;
		vertices->source = input_source;
	}
	else{
		xmlFree(vertices_id);
	}


	return vertices;
}

triangles_t *parse_triangles(xmlNode *node)
{
	xmlNode *cur;

	triangles_t *triangles = NULL;
	xmlChar *material = NULL;
	xmlChar *count = NULL;
	input_t *inputs = NULL;
	input_t **in_next = &inputs;
	xmlChar *content = NULL;
	int inputCount = 0;
	int vcheck = 0;
	int check = 0;

	if(xmlStrcmp(node->name, (const xmlChar*)"triangles") != 0
			&& xmlStrcmp(node->name, (const xmlChar*)"polylist") != 0){
		printf("[ERROR] parse_triangles: trying to parse an incompatible node!\n");
		return NULL;
	}


	material = xmlGetProp(node, (const xmlChar*)"material");
	count = xmlGetProp(node, (const xmlChar*)"count");
	if(material == NULL || count == NULL){
		printf("[ERROR] <triangles> is missing properties!\n");
	}
	else{
		for(cur = node->children; cur != NULL; cur = cur->next){
			if(xmlStrcmp(cur->name, (const xmlChar*)"input") == 0){
				input_t *newinput;

				newinput = malloc(sizeof(input_t));
				newinput->semantic = xmlGetProp(cur, (const xmlChar*)"semantic");
				newinput->source = xmlGetProp(cur, (const xmlChar*)"source");
				newinput->offset = xmlGetProp(cur, (const xmlChar*)"offset");
				newinput->set = xmlGetProp(cur, (const xmlChar*)"set");
				newinput->next = NULL;

				if(newinput->semantic == NULL || newinput->source == NULL || newinput->offset == NULL){
					if(newinput->semantic != NULL)
						xmlFree(newinput->semantic);
					if(newinput->source != NULL)
						xmlFree(newinput->source);
					if(newinput->offset != NULL)
						xmlFree(newinput->offset);
					if(newinput->set != NULL)
						xmlFree(newinput->set);

					free(newinput);

					printf("[ERROR] Missing <input> properties!\n");
				}
				else{
					// manually allocate and set default value 0
					if(newinput->set == NULL){
						newinput->set = xmlMalloc(2);
						newinput->set[0] = 0x30;
						newinput->set[1] = 0x00;
					}

					*in_next = newinput;
					in_next = &(*in_next)->next;
					++inputCount;
				}
			}
			else if(xmlStrcmp(cur->name, (const xmlChar*)"vcount") == 0){
				xmlChar *vcount;

				vcount = xmlNodeGetContent(cur);
				if(vcount != NULL){
					if(check_vcount(vcount) == 0)
						vcheck = 1;

					xmlFree(vcount);
				}
				else{
					printf("[WARNING] <vcount> has invalid content! Skipping...\n");
				}
			}
			else if(xmlStrcmp(cur->name, (const xmlChar*)"p") == 0){
				if(content != NULL){
					printf("[WARNING] This implementation supports only one <p> per <triangles>/<polylist>. Only the first valid occurrence will be parsed.\n");
				}
				else{
					content = xmlNodeGetContent(cur);
					if(content == NULL){
						printf("[WARNING] <p> has invalid content! Skipping...\n");
					}
				}
			}
		}

		if(inputCount == 0 || content == NULL || vcheck == 0){
			printf("[ERROR] <triangles>/<polylist> is not valid!\n");
		}
		else{
			check = 1;
		}
	}


	if(check == 0){
		if(material != NULL)
			xmlFree(material);
		if(count != NULL)
			xmlFree(count);

		input_t *tmp;
		while(inputs != NULL){
			tmp = inputs;
			inputs = inputs->next;
			free(tmp);
		}

		if(content != NULL)
			xmlFree(content);
	}
	else{
		triangles = malloc(sizeof(triangles_t));
		triangles->material = material;
		triangles->count = count;
		triangles->inputs = inputs;
		triangles->content = content;
		triangles->next = NULL;
	}

	return triangles;
}


//<geometry id="mesh_id" name="mesh_name">
//	<mesh>

//		<source id="source_id">
//			<float_array id="array_id" count="array_size"> ... </float_array>
//			<technique_common>
//				<accessor source="#array_id" count="n" stride="s">
//					<param name="X" type="float"/>
//					<param name="Y" type="float"/>
//					<param name="Z" type="float"/>
//				</accessor>
//			</technique_common>
//		</source>

//		<vertices id="vertices_id">
//			<input semantic="POSITION" source="#source_id"/>
//		</vertices>

//		<triangles material="material_id" count="face_count">
//			<input semantic="POSITION" source="#source_id" offset="0"/>
//			<input semantic="NORMAL" source="#source_id" offset="1"/>
//			<input semantic="TEXCOORD" source="#source_id" offset="2" set="0"/>
//			<p> ... </p>
//		</triangles>

//		<polylist material="material_id" count="face_count">
//			<input semantic="POSITION" source="#source_id" offset="0"/>
//			<input semantic="NORMAL" source="#source_id" offset="1"/>
//			<input semantic="TEXCOORD" source="#source_id" offset="2" set="0"/>
//			<vcount> ... </vcount>
//			<p> ... </p>
//		</polylist>

//	</mesh>
//</geometry>

geometry_t *parse_geometry(xmlNode *node)
{
	xmlNode *cur;
	geometry_t *geometry;
	source_t *sources;
	source_t **src_next;
	vertices_t *vertices;
	triangles_t *triangles;
	triangles_t **tri_next;
	int sourceCount, trianglesCount;

	cur = node->children;
	if(cur == NULL || xmlStrcmp(cur->name, (const xmlChar*)"mesh") != 0){
		printf("[ERROR] Unexpected <geometry> child!\n");
		return NULL;
	}

	geometry = NULL;
	sources = NULL;
	src_next = &sources;
	vertices = NULL;
	triangles = NULL;
	tri_next = &triangles;
	sourceCount = 0;
	trianglesCount = 0;

	for(cur = cur->children; cur != NULL; cur = cur->next){
		if(xmlStrcmp(cur->name, (const xmlChar*)"source") == 0){
			source_t *newsource;

			if(sourceCount >= MAX_INPUT){
				printf("[ERROR] Max source inputs for a single <geometry> node reached! (%d inputs)\n", MAX_INPUT);
				continue;
			}

			newsource = parse_source(cur);
			if(newsource != NULL){
				*src_next = newsource;
				src_next = &(*src_next)->next;
				++sourceCount;
			}
		}

		else if(xmlStrcmp(cur->name, (const xmlChar*)"vertices") == 0){
			vertices = parse_vertices(cur);
		}

		else if(xmlStrcmp(cur->name, (const xmlChar*)"triangles") == 0
				|| xmlStrcmp(cur->name, (const xmlChar*)"polylist") == 0){
			triangles_t *newtriangles;

			if(trianglesCount >= MAX_INPUT){
				printf("[ERROR] Max inputs for a single <triangles> node reached! (%d inputs)\n", MAX_INPUT);
				continue;
			}

			newtriangles = parse_triangles(cur);
			if(newtriangles != NULL){
				*tri_next = newtriangles;
				tri_next = &(*tri_next)->next;
				++trianglesCount;
			}
		}
		else{
			printf("[ERROR] Unexpected <mesh> child: %s\n", cur->name);
		}
	}

	if(sources != NULL && triangles != NULL && vertices != NULL){
		geometry = malloc(sizeof(geometry_t));
		geometry->sources = sources;
		geometry->vertices = vertices;
		geometry->triangles = triangles;
		geometry->next = NULL;
	}
	else{
		free_sources(sources);
		free_triangles(triangles);

		if(vertices != NULL){
			if(vertices->id != NULL)
				xmlFree(vertices->id);
			if(vertices->source != NULL)
				xmlFree(vertices->source);
		}
	}

	return geometry;
}