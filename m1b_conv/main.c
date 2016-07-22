#include <string.h>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/xmlschemas.h>

#include "geometry.h"
#include "util.h"

int m_main(int argc, char **argv)
{
	xmlDoc *doc;
	xmlNode *root, *cur, *aux;

	geometry_t *geometries = NULL;
	geometry_t **geom_next = &geometries;

	LIBXML_TEST_VERSION;
	xmlKeepBlanksDefault(0);

	doc = xmlParseFile("model.dae");
	if(doc == NULL){
		printf("Failed to load model.dae");
		return -1;
	}

	root = xmlDocGetRootElement(doc);
	if(xmlStrcmp(root->name, (const xmlChar*)"COLLADA") == 0){
		for(cur = root->children; cur != NULL; cur = cur->next){
			// <library_geometries>
			if(xmlStrcmp(cur->name, (const xmlChar*)"library_geometries") == 0){
				for(aux = cur->children; aux != NULL; aux = aux->next){

					// <geometry>
					if(xmlStrcmp(aux->name, (const xmlChar*)"geometry") == 0){
						*geom_next = parse_geometry(aux);
						if(*geom_next != NULL)
							geom_next = &(*geom_next)->next;
					}
					// </geometry>

					else{
						printf("[ERROR] Unexpected <library_geometries> child: %s\n", aux->name);
					}
				}
			}
			// </library_geometries>

			else{
				printf("[ERROR] Unexpected <COLLADA> child: %s\n", cur->name);
			}
		}
	}
	else{
		printf("Invalid root element!\n");
	}

	for(geometry_t *geom = geometries; geom != NULL; geom = geom->next){
	}

	xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();
	return 0;
}