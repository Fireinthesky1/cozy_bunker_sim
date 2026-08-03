//  Mouse Windowing System implementation.
//  This file provides the platform-independed implementation of the Mouse
//  Windowing System.
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

#include "mouse_window.h"
#include "../platform/platform.h"

static mouse_window_api_t mouse_window_api;

mouse_error_t mouse_window_init(void)
{
  mouse_error_t      return_code;

  return_code = MOUSE_ERROR_NONE;

  // Populate the mouse_window_platform_callbacks_t struct.
  mouse_window_api.init         = pal_window_init;
  mouse_window_api.shutdown     = pal_window_shutdown;
  mouse_window_api.create       = pal_window_create;
  mouse_window_api.destroy      = pal_window_destroy;
  mouse_window_api.display      = pal_window_display;
  mouse_window_api.poll_events  = pal_window_poll_events;
  mouse_window_api.swap_buffers = pal_window_swap_buffers;

  // Call the platform init function.
  return_code = mouse_window_api.init();

  return return_code;
}

mouse_error_t mouse_window_shutdown(void)
{
  mouse_error_t return_code;
  return_code = MOUSE_ERROR_NONE;
  return_code = mouse_window_api.shutdown();
  return return_code;
}

mouse_error_t mouse_window_create(void)
{
  mouse_error_t return_code;
  return_code = MOUSE_ERROR_NONE;
  return_code = mouse_window_api.create();
  return return_code;
}

mouse_error_t mouse_window_destroy(void)
{
  mouse_error_t return_code;
  return_code = MOUSE_ERROR_NONE;
  return_code = mouse_window_api.destroy();
  return return_code;
}

mouse_error_t mouse_window_display(void)
{
  mouse_error_t return_code;
  return_code = MOUSE_ERROR_NONE;
  return_code = mouse_window_api.display();
  return return_code;
}

mouse_error_t mouse_window_poll_events(void)
{
  mouse_error_t return_code;
  return_code = MOUSE_ERROR_NONE;
  return_code = mouse_window_api.poll_events();
  return return_code;
}

mouse_error_t mouse_window_swap_buffers(void)
{
  mouse_error_t return_code;
  return_code = MOUSE_ERROR_NONE;
  return_code = mouse_window_api.swap_buffers();
  return return_code;
}
