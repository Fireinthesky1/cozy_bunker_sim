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

#include <stdio.h> // TODO: Implement Mouse Logger and remoce

#include "linux_window.h"

mouse_error_t pal_window_init(void)
{
  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_shutdown(void)
{
  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_create(void)
{
  Display * d;
  Window w;

  // NOTE: NULL defaults display name to the DISPLAY environment variable.
  // TODO(HICKS): Make it so this function call doesn't have hardcoded values
  // Open a connection to the X Window Server
  d = XOpenDisplay(NULL);
  if(d == NULL)
  {
    printf("FAILED TO OPEN DISPLAY\n");
  }

  // Create a window
  w = XCreateSimpleWindow(d, DefaultRootWindow(d),
                    0, 0,
                    800,
                    600,
                    10,
                    100,
                    255);

  // Clear the window.

  // Map the window
  XMapWindow(d, w);

  // flush
  XFlush(d);

  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_destroy(void)
{
  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_display(void)
{
  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_poll_events(void)
{
  return MOUSE_ERROR_NONE;
}

mouse_error_t pal_window_swap_buffers(void)
{
  return MOUSE_ERROR_NONE;
}
