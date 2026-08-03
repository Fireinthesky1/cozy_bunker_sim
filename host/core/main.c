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

  mouse_error_t result;

  result = MOUSE_ERROR_NONE;

  // initialize mouse_host
  result = mouse_window_init();
  if(result != MOUSE_ERROR_NONE)
  {
    // TODO(HICKS): Log fatal error. Replace function call with logging macro.
  }

  // create window
  result = mouse_window_create();
  if(result != MOUSE_ERROR_NONE)
  {
    // TODO(HICKS): Log fatal error. Replace function call with logging macro.
  }

  // create renderer

  // load the sprite sheet into memory

  return result;

}

int main(void)
{

  mouse_time_t  prev_mouse_time;
  mouse_time_t  cur_mouse_time;
  mouse_time_t  elapsed_mouse_time;
  mouse_time_t  lag;
  mouse_error_t result;

  result = init();
  if(result == MOUSE_ERROR_NONE)
    {
      printf("INTIALIZATION COMPLETE");
      game_running = true;
    }

  // Start a new frame with a black screen

  // display the window
  result = mouse_window_display();
  if(result != MOUSE_ERROR_NONE)
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

  // return 0 for on success
  return 0;

}
