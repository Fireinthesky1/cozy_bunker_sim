#include "component.h"

extern uint32_t num_entities;

/*
  INPUT:  comp_list - pointer to the global components list
          comp_sel  - bitfield indicating which components belong to the entity
  OUTPUT: entity_id_t - the entity id of the newly created entity

  This function assigns an entity id to the entity and initializes any component
  structures belonging to the entity based on the input comp_sel bitfield
*/
entity_id_t create_entity(component_lists_t * comp_list,
			  const component_mask_t * comp_sel)
{

  entity_id_t id;

  id = num_entities; // set the id to the new increment
  num_entities++; // increment the number of entities

  if(num_entities > ENTITY_MAX)
    {
      SDL_Log("Over entity limit\n");
    }

  // initialize selected components based on comp_sel
  if(*comp_sel & LOCATION_COMP_MSK)
    {
      comp_list->location_components[id].id = id;
      comp_list->total_location_components++;
    }
  else if(*comp_sel & VELOCITY_COMP_MSK)
    {
      comp_list->velocity_components[id].id = id;
      comp_list->total_velocity_components++;
    }
  else if(*comp_sel & RENDERABLE_COMP_MSK)
    {
      comp_list->renderable_components[id].id = id;
      comp_list->total_renderable_components++;
    }

  return id;

}

void destroy_entity(component_lists_t * components, entity_id_t id)
{
}

void init_location_component(component_lists_t * components,
			     entity_id_t id,
			     int32_t x, int32_t y)
{

  components->location_components[id].x = x;
  components->location_components[id].y = y;

}

void init_velocity_component(component_lists_t * components,
			     entity_id_t id,
			     int32_t x, int32_t y)
{

    components->velocity_components[id].x = x;
    components->velocity_components[id].y = y;

}

mouse_error_code init_renderable_component(component_lists_t * components,
					   entity_id_t id,
					   int32_t src_x, int32_t src_y,
					   int32_t src_w, int32_t src_h,
					   int32_t dst_x, int32_t dst_y,
					   int32_t dst_w, int32_t dst_h,
					   uint32_t layer)
{

  mouse_error_code result;
  rect_t src_rect;
  rect_t dst_rect;

  result = MOUSE_ERROR_NONE;

  // initialize the renderable component at this id
  components->renderable_components[id].layer = layer;

  // initialize the source rect (i.e. the portion of the sprite map we want)
  src_rect.x = src_x;
  src_rect.y = src_y;
  src_rect.w = src_w;
  src_rect.h = src_h;

  // initialize the destination rect
  dst_rect.x = dst_x;
  dst_rect.y = dst_y;
  dst_rect.w = dst_w;
  dst_rect.h = dst_h;

  // fill out the rest of the structure
  components->renderable_components[id].src_rect = src_rect;
  components->renderable_components[id].dst_rect = dst_rect;

  return result;

}

/* Each system is updated using the below functions */
void update_location_system(location_t * l, component_lists_t * components)
{

}

void update_velocity_system(velocity_t * v, component_lists_t * components)
{

}

void update_renderable_system(renderable_t * r, component_lists_t * components)
{

}
