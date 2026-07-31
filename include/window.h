/*
Mouse Windowing System header.
*/

#ifndef MOUSE_WINDOW
#define MOUSE_WINDOW

#include <X11/Xlib.h>

/*
mouse_window_t struct:
-
*/
typedef struct
{
  // TODO
} mouse_window_t;

/* Mouse Windowing System variables */
extern Display * x_server_connection;

/* Mouse Windowing System functions */
extern void open_connection_to_x_server(void);

#endif
