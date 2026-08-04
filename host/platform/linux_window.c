//  Linux Windowing.
//  This header is responsible for all X Windowing System Specific code.
//  Copyright (C) <2026>  <James Hicks>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h> // TODO: Implement Mouse Logger and remove

#include "linux_window.h"

// TODO: We obviously shouldn't do it this way.
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

static Display *d;
static Window   w;
static GC       gc;
static Pixmap   back_buffer;

mouse_error_t pal_window_init(void)
{
  mouse_error_t return_code;

  return_code = MOUSE_ERROR_NONE;

  // NOTE: NULL defaults display name to the DISPLAY environment variable.
  // TODO(HICKS): Make it so this function call doesn't have hardcoded values
  // Open a connection to the X Window Server
  d = XOpenDisplay(NULL);
  if(d == NULL)
  {
    return_code = MOUSE_ERROR_PLATFORM_WINDOW_INITIALIZATION;
    printf("FAILED TO OPEN DISPLAY\n"); // TODO: Implement logger and remove
  }

  // Create a window
  w = XCreateSimpleWindow(d, DefaultRootWindow(d),
                          0, 0,
                          WINDOW_WIDTH,
                          WINDOW_HEIGHT,
                          10,
                          100,
                          255);

  // Create a graphics context (valuemask set to zero. No values selected)
  gc = XCreateGC(d, w, 0, NULL);

  // Create the back buffer
  back_buffer = XCreatePixmap(d, w,
                              WINDOW_WIDTH, WINDOW_HEIGHT,
                              DefaultDepth(d, 0));

  return return_code;
}

mouse_error_t pal_window_shutdown(void)
{
  mouse_error_t return_code;

  return_code = MOUSE_ERROR_NONE;

  // Free the back buffer
  XFreePixmap(d, back_buffer);

  // Free the graphics context
  XFreeGC(d, gc);

  // Destroy the window
  XDestroyWindow(d, w);

  // Close the connection to the X Window Server
  XCloseDisplay(d);

  return return_code;
}

mouse_error_t pal_window_create(void)
{
  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_destroy(void)
{
  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_display(void)
{
  mouse_error_t return_code;

  return_code = MOUSE_ERROR_NONE;

  // Map the window
  XMapWindow(d, w);

  // flush
  XFlush(d);

  return return_code;
}

mouse_error_t pal_window_swap_buffers(void)
{
  return MOUSE_ERROR_NONE;
}
