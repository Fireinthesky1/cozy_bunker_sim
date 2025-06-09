#include "mouse_time.h"

// TODO: Test this function
mouse_time_t mouse_get_time(mouse_time_sel_t unit_select)
{

  struct timespec tp;
  mouse_time_t result;

  // get the time from the system
  if(clock_gettime(CLOCK_MONOTONIC_RAW, &tp))
    {
      SDL_Log("mouse_get_time()::Failed to get time\n");
    }

  switch(unit_select)
    {
    case MOUSE_NANOSECONDS:
      result = tp.tv_sec * NSEC_PER_SEC + tp.tv_nsec;
      break;
    case MOUSE_MICROSECONDS:
      result = tp.tv_sec * USEC_PER_SEC + (tp.tv_nsec / NSEC_PER_USEC);
      break;
    case MOUSE_MILLISECONDS:
      result = tp.tv_sec * MSEC_PER_SEC + (tp.tv_nsec / NSEC_PER_MSEC);
      break;
    case MOUSE_SECONDS:
      result = tp.tv_sec;
      break;
    case MOUSE_MINUTES:
      result = tp.tv_sec / SEC_PER_MIN;
      break;
    default: // should never be here
      break;
    }

  return result;

}
