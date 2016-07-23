Mutante 1
=========

System Requirements
-------------------
	Still don't know but a OpenGL 3.3 compatible card seems reasonable
	because video cards with support for it have been around since ~2007.
	Now there are few Vulkan compatible cards (i guess for the lack of
	drivers more than for the compatibility itself) but still, Vulkan's
	performance should be above OpenGL's on these cards.

Guidelines
==========

Item (1)
--------
	Init/Cleanup functions should always assume it will have exclusive
	access to its interface resources for initialization or cleanup and
	calling multiple Init functions from the same interface will cause
	undefined behaviour.

Item (2)
--------
	Initialization of resources should be single threaded on start of
	execution and work threads should only be spawned after every
	initialization has succeded.

Item (3)
--------
	Interfaces should have its functions prefixed with the interface
	prefix (e.g. THR_Create).

Item (4)
--------
	For style, variables should use camelCase and functions, PascalCase.
	If it is a public interface function, it must contain its interface
	prefix (e.g. PFX_Function).

Item (5)
--------
	Interface prefixes may have any number of letters but should use the
	common sense (not too short, not too long).

Item (6)
--------
	Local variables must be declared static in the *.c file with a 'l'
	prefix (e.g. l_var). Global variables must be declared non-static in
	the *.c file with the interface prefix (e.g. vec3_up).