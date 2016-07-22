// thoughts:
// make some kind of state machine that will have
// all client state and config files are only files
// that change the state machine by executing commands

// at the start of execution reset the state and load a
// file that will change the non-default states

// r_ <- renderer commands
// snd_ <- sound commands
// net_ <- net commands
// cl_ <- client commands
// sv_ <- server commands

// adding the prefix will help speeding up the execution
// of commands because we can organize them in some kind
// of tree

// r_extent <width> <height>
// bind <key> <cmd>

// CON_RegisterVar("r_drawdistance", &l_drawDistance);

// interfaces must use these as locals or must have a mechanism
// of propagating changes (r_flush, snd_flush, net_flush, ...)

// connecting/creating a game will always flush all changes
