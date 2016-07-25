Mutante1
========

This is a very early version of the engine and is still a work in progress.

File Layout
-----------

```
code/		mutante1 source code
m1b_mdl/	model converter - converts models into the .m1b binary format
m1b_map/	map compiler - compiles the .xml from the editor into the .m1b binary format
m1birl/		map editor
```

File Formats
------------

```
.m1b		mutante1 binary format
.xml		XML file
.lua		Lua file
.c		C source file
.h		C header file
```

Programming
-----------

The project will make extensive use of C, XML, and Lua languages.

License
-------

Refer to LICENSE.txt for information about the GNU General Public License.

Graphics
--------

* OpenGL (try to support version 2.0)
* Vulkan

See uses:
* shadow map / shadow volumes (distinct)
* deferred rendering / deferred lighting (distinct)
* paralax mapping
* particle system
* ambient occlusion
* phong shading
* skeletal animation

Sound
-----

* OpenAL

Network
-------

* use a simple client model on client
* use e-poll(linux), kqueue(FreeBSD), or iocp(Windows) on dedicated server

Utility
-------

Physics:
* collisions
* energy dissipation
* doppler effect (if i remember correctly, OpenAL already has something)
* ?

Math:
* vectors
* quaternions (rotations)
* matrices (transforms)

OS:
* windowing system -> consider QT or SDL


I/O:
* logging
* file loading
* file compacting (e.g. .pak)

Misc:
* UTF-8 strings library
* big numbers library - RSA

Editor
------

Make an editor with brush.
