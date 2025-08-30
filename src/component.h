/* Here lies all of the components that entities can be composed of */

#ifndef COMPONENT
#define COMPONENT

#include <SDL.h>
#include <stdint.h>
#include "mouse_error.h"

/* For now, at most 100 entities */
#define ENTITY_MAX 100

/*
The following are bit masks use to indicate which components an entity
has active
 */
typedef enum
{
  LOCATION_COMP_MSK   = (1 << 0),
  VELOCITY_COMP_MSK   = (1 << 1),
  RENDERABLE_COMP_MSK = (1 << 2)
} component_bit_t;

typedef uint32_t component_mask_t;
typedef uint32_t entity_id_t;

typedef struct
{
  entity_id_t id;
  component_mask_t comp_sel;
} entity_t;

/* For now these are game logic coordinates? */
typedef struct
{
  entity_id_t id;
  uint32_t x;
  uint32_t y;
} location_t, velocity_t;

/* mouse engine rectangle structure */
typedef struct
{
  int32_t x;
  int32_t y;
  int32_t w;
  int32_t h;
} rect_t;

/* TODO: need a way to sort the renderable components list by layer
         this will allow us to render all layers in order */
typedef struct
{
  entity_id_t id; /* the id of the entity */
  rect_t src_rect; /* the section of the spritesheet to render */
  rect_t dst_rect; /* the section of the window to render */
  uint8_t layer; /* The layer on which to render the sprite */
} renderable_t;

/* -This struct holds a list for every available component
   -These lists are ENTITY_MAX long
*/
typedef struct
{
  location_t   location_components[ENTITY_MAX];
  velocity_t velocity_components[ENTITY_MAX];
  renderable_t renderable_components[ENTITY_MAX];
  uint32_t total_location_components;
  uint32_t total_velocity_components;
  uint32_t total_renderable_components;
} component_lists_t;

entity_id_t create_entity(component_lists_t * comp_list,
			  const component_mask_t * comp_sel);
void destroy_entity(component_lists_t * components, entity_id_t id);

/* Each component has an initialization function */
void init_location_component(component_lists_t * components,
			     entity_id_t id,
			     int32_t x, int32_t y);
void init_velocity_component(component_lists_t * components,
			     entity_id_t id,
			     int32_t x, int32_t y);
mouse_error_code init_renderable_component(component_lists_t * components,
					   entity_id_t id,
					   int32_t src_x, int32_t src_y,
					   int32_t src_w, int32_t src_h,
					   int32_t dst_x, int32_t dst_y,
					   int32_t dst_w, int32_t dst_h,
					   uint32_t layer);

/* Each system is updated using the below functions */
void update_systems(component_lists_t * components);
void update_location_system(location_t * l, component_lists_t * components);
void update_velocity_system(location_t * v, component_lists_t * components);
void update_renderable_system(renderable_t * r, component_lists_t * components);

#endif
