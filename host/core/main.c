//  This file contains the main function and the engine loop.
//  This file is responsible initializing the host, loading modules, and
//  shutting Mouse Engine shown.
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

#include <stdio.h> // TODO: Implement Mouse Logger and remove.
#include <stdint.h>
#include <stdbool.h>

#include "mouse_window.h"
#include "mouse_error.h"
#include "mouse_time.h"

bool game_running = false;

// fully global
uint32_t num_entities = 0;

// initializes everything
mouse_error_t init(void)
{

  mouse_error_t return_code;

  return_code = MOUSE_ERROR_NONE;

  // initialize mouse_host
  return_code = mouse_window_init();
  if(return_code != MOUSE_ERROR_NONE)
  {
    // TODO(HICKS): Log fatal error. Replace function call with logging macro.
  }

  // create window
  return_code = mouse_window_create();
  if(return_code != MOUSE_ERROR_NONE)
  {
    // TODO(HICKS): Log fatal error. Replace function call with logging macro.
  }

  // create renderer

  // load the sprite sheet into memory

  return return_code;

}

int main(void)
{

  mouse_time_t  prev_mouse_time;
  mouse_time_t  cur_mouse_time;
  mouse_time_t  elapsed_mouse_time;
  mouse_time_t  lag;
  mouse_error_t return_code;

  return_code = init();
  if(return_code == MOUSE_ERROR_NONE)
    {
      printf("INTIALIZATION COMPLETE");
      game_running = true;
    }

  // Start a new frame with a black screen

  // display the window
  return_code = mouse_window_display();
  if(return_code != MOUSE_ERROR_NONE)
  {
    // TODO(HICKS): Log fatal error. Replace function call with logging macro.
  }

  // game loop
  // 0 check the dela time
  // 1 process input
  // 2 update game state
  // 3 render the game
  prev_mouse_time = mouse_get_time(MOUSE_MILLISECONDS);
  while(game_running)
    {

      cur_mouse_time = mouse_get_time(MOUSE_MILLISECONDS);
      elapsed_mouse_time = cur_mouse_time - prev_mouse_time;
      prev_mouse_time = cur_mouse_time;
      lag += elapsed_mouse_time;

      /* update the game logic until we catch up */
      while(lag >= MS_PER_UPDATE)
	{
	  /* update game logic */
	  lag -= MS_PER_UPDATE;
	}

      /* render */
    }

  // cleanup
  return_code = mouse_window_shutdown(); // Shut down Mouse Window System

  // return 0 for on success
  return return_code;
}
