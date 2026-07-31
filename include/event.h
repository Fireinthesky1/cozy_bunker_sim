#ifndef EVENT
#define EVENT

#define MOUSE_EVENT_BUFFER_SIZE 128 /* TODO: consider the size of this */
#define MOUSE_MAX_PENDING_EVENTS 64 /* TODO: consider this */

/* the following are bitmasks to indicate the event type*/
typedef enum
{
  MOUSE_EVENT_INPUT_UP = 0,
  MOUSE_EVENT_INPUT_DOWN,
  MOUSE_EVENT_INPUT_LEFT,
  MOUSE_EVENT_INPUT_RIGHT,
  MOUSE_EVENT_INPUT_OPEN_MAP,
  MOUSE_EVENT_INPUT_OPEN_INVENTORY
} mouse_event_type_t;

typedef struct
{
  uint32_t head;
  uint32_t tail;
  mouse_event_t [MOUSE_EVENT_BUFFER_SIZE];
} mouse_event_buffer_t;


#endif
