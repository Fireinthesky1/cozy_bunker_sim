//  Linux Windowing System header.
//  This file defines the windowing system interface that linux provides.
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

#include <X11/Xlib.h>
#include "../core/mouse_error.h"

/* Linux Specific PAL Windowing System functions */
mouse_error_t pal_window_init(void);
mouse_error_t pal_window_shutdown(void);
mouse_error_t pal_window_create(void);
mouse_error_t pal_window_destroy(void);
mouse_error_t pal_window_display(void);
mouse_error_t pal_window_poll_events(void);
mouse_error_t pal_window_swap_buffers(void);
