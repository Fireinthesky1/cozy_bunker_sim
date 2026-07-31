//  Linux Windowing.
//    This header is responsible for all X Windowing System Specific code.
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

#include "linux_platform.h"

void linux_create_window(mouse_window_t * m_window)
{
  Display * d;
  Window * w;

  //NOTE: NULL defaults display name to the DISPLAY environment variable.
  d = XOpenDisplay(NULL);
  w = XCreateWindow(d, DefaultRootWindow(display),
                    0, 0,
                    m_window.window_width,
                    m_window.window_height,
                    m_window.border_width,
                    CopyFromParent,
                    InputOutput,
                    CopyFromParent,
                    0,
                    NULL);
  // Clear the window.



  // Map the window
  XMapWindow(d, &w);
}

void linux_destroy_window(void)
{

}

void linux_display_window(void)
{

}

void linux_poll_events(void)
{

}

void linux_swap_buffers(void)
{

}
