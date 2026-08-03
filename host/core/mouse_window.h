//  Mouse Windowing System Header.
//  This file provides the public windowing API used by the engine.
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
} mouse_window_params_t;

/*
pal_window_init:        Initializes the platform dependent windowing system
pal_window_shutdown:    Shuts down the platform dependent windowing system
pal_window_create:      Creates a platform dependent window
pal_window_destroy:     Destroys a platform dependent window
pal_window_poll_events: Polls events on the platform dependent window
pal_swap_buffers:       Swaps the platform dependent windows
*/
typedef struct
{
  mouse_error_t (*init)(void);
  mouse_error_t (*shutdown)(void);
  mouse_error_t (*create)(void);
  mouse_error_t (*destroy)(void);
  mouse_error_t (*display)(void);
  mouse_error_t (*poll_events)(void);
  mouse_error_t (*swap_buffers)(void);
} mouse_window_api_t;

/* Mouse Windowing System functions */
mouse_error_t mouse_window_init(void);
mouse_error_t mouse_window_shutdown(void);
mouse_error_t mouse_window_create(void);
mouse_error_t mouse_window_destroy(void);
mouse_error_t mouse_window_display(void);
mouse_error_t mouse_window_poll_events(void);
mouse_error_t mouse_window_swap_buffers(void);

#endif
