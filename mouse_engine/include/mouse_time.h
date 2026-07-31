/* time code for mouse engine */
/* NOTE: this is linux specific code */

#ifndef MOUSE_TIME
#define MOUSE_TIME

#include <SDL.h>
#include <stdint.h>
#include <time.h>

// TODO: figure out if it's bad form to #define multiple things to one number
#define NSEC_PER_USEC 1000
#define NSEC_PER_MSEC 1000000
#define NSEC_PER_SEC 1000000000
#define USEC_PER_SEC 1000000
#define USEC_PER_MSEC 1000
#define MSEC_PER_SEC 1000
#define SEC_PER_MIN 60
#define TARGET_FPS 60
#define MS_PER_UPDATE 10 /* 100 ticks per second */

typedef enum
  {
    MOUSE_NANOSECONDS,
    MOUSE_MICROSECONDS,
    MOUSE_MILLISECONDS,
    MOUSE_SECONDS,
    MOUSE_MINUTES
  } mouse_time_sel_t;

// TODO: make sure we know how many bits go into this double
typedef double mouse_time_t;

mouse_time_t mouse_get_time(mouse_time_sel_t unit_select);
uint32_t mouse_get_fps(void);

#endif
