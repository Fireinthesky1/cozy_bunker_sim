//  Mouse Windowing System Header.
//  This file declares types and prototypes for the Mouse Windowing System.
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

#ifndef MOUSE_WINDOW
#define MOUSE_WINDOW

#include <stdint.h>
#include "mouse_error.h"

typedef struct
{
  uint16_t window_height;
  uint16_t window_width;
  uint16_t border_width;
} mouse_window_stats_t;

/*
The below struct is the Mouse Engine Window interface.
platform_window_init:        Initializes the platform dependent windowing system
platform_window_shutdown:    Shuts down the platform dependent windowing system
platform_window_create:      Creates a platform dependent window
platform_window_destroy:     Destroys a platform dependent window
platform_window_poll_events: Polls events on the platform dependent window
platform_swap_buffers:       Swapts the platform dependent windows
*/
typedef struct
{
  mouse_error_t (*platform_window_init)(void);
  mouse_error_t (*platform_window_shutdown)(void);
  mouse_error_t (*platform_window_create)(void);
  mouse_error_t (*platform_window_destroy)(void);
  mouse_error_t (*platform_window_poll_events)(void);
  mouse_error_t (*platform_window_swap_buffers)(void);
} mouse_window_t;

/* Mouse Windowing System variables */
extern mouse_window_t * window;

/* Mouse Windowing System functions */
extern mouse_error_t mouse_window_init(void);
extern mouse_error_t mouse_window_shutdown(void);
extern mouse_error_t mouse_window_create(void);
extern mouse_error_t mouse_window_destroy(void);
extern mouse_error_t mouse_window_display(void);
extern mouse_error_t mouse_window_poll_events(void);
extern mouse_error_t mouse_window_swap_buffers(void);

#endif
