/*
TODO:
[X] Render a clear color
[X] Render a texture
[X] Render a character on the screen
[X] fix build issue with the project
[X] resolve linking error
[X] downgrade to SDL2
[X] resolve all errors
[X] render the player on the screen using the entity component system
[X] implement an entity component system
[X] figure out naming conventions
[X] decouple the game engine from SDL
[X] fix storing the adress of a local variable rect in init renderable
[ ] Move the character using joystick
[ ] make it so you can exit the window
[ ] figure out what to do with the functions that utelize SDL
[ ] implement a logger

BUGS:
[ ] resizable window glitching

NOTES:
 - I want the game engine as decoupled as possible from SDL. This way I
   can reuse the engine for later projects and not have to rewrite the engine

*/

#include <SDL.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "component.h"
#include "mouse_error.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

bool game_running = false;

// local global
static SDL_Window * window; // the window for the entire game
static SDL_Renderer * renderer; // the renderer for the entire game
static SDL_Texture * texture; // the sprite map for the entire game
static component_lists_t cl = {0}; // components list for the scope of the game

// fully global
uint32_t num_entities = 0;

/* loads the spritesheet so SDL can use it */
mouse_error_code load_global_spritesheet(const char * bmp_name)
{
  mouse_error_code result;
  SDL_Surface * surface;
  char * spritesheet_path;

  result = MOUSE_ERROR_NONE;

  // create the path to spritesheet string
  SDL_asprintf(&spritesheet_path, "/home/fire/mouse_game/art/%s", bmp_name);

  surface = SDL_LoadBMP(spritesheet_path); // load the bit map

  if(!surface)
    {
      SDL_Log("Couldn't Load bitmap: %s", SDL_GetError());
      result = MOUSE_ERROR_TEXTURE;
    }

  SDL_free(spritesheet_path); /* deallocate the bit map path string */

  texture = SDL_CreateTextureFromSurface(renderer, surface);

  if(!texture)
    {
      SDL_Log("Couldn't create static texture: %s", SDL_GetError());
      result = MOUSE_ERROR_TEXTURE;
    }

  return result;

}

// initializes everything
mouse_error_code init(void)
{

  mouse_error_code result;

  result = MOUSE_ERROR_NONE;

  // initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) == -1)
    {
      SDL_Log("Failed to initialize game: %s\n", SDL_GetError());
      result = MOUSE_ERROR_INITIALIZATION;
    }

  // create window and renderer
  // NOTE: careful here will a return of -1 enter the function?
  if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH,
				  WINDOW_HEIGHT,
				  SDL_WINDOW_RESIZABLE,
				  &window,
				  &renderer) == -1)
    {
      SDL_Log("Failed to initialize Window and Renderer: %s", SDL_GetError());
      result = MOUSE_ERROR_RENDERER;
    }


  // load the sprite sheet into memory
  result = load_global_spritesheet("Robot.bmp");

  return result;

}

// this function renders things passed to it
// TODO: figure out what this takes as an argument
mouse_error_code render(renderable_t *r)
{
  mouse_error_code result;

  result = MOUSE_ERROR_NONE;

  // just want to draw a mouse here
  SDL_RenderCopy(renderer, texture,
		 (SDL_Rect *)&(r->src_rect),
		 (SDL_Rect *)&(r->dst_rect));

  SDL_RenderPresent(renderer);

  return result;

}

// this function updates the audio being played
// TODO: figure out what this takes as an argument
mouse_error_code update_audio(void)
{
  mouse_error_code result;

  result = MOUSE_ERROR_NONE;

  return result;
}

// this function updates the game logic
// TODO: figure out what this takes as an argument
mouse_error_code update_game_logic(void)
{
  return MOUSE_ERROR_NONE;
}

int main(void)
{


  if(init() == MOUSE_ERROR_NONE)
    {
      SDL_Log("game Initialized...\n");
      game_running = true;
    }

  // starts a new frame with a black screen
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  // create a player entity
  component_mask_t components = LOCATION_COMP_MSK | RENDERABLE_COMP_MSK;
  entity_id_t Player = create_entity(&cl, &components);
  init_renderable_component(&cl, Player, 0, 0, 64, 64, 100, 100, 64, 64, 0);

  // show the window
  SDL_ShowWindow(window);

  // game loop
  while(game_running)
    {
      // update game logic

      // update sound

      // pump error messages

      // render
      render(&cl.renderable_components[Player]);
    }

  // cleanup
  SDL_DestroyTexture(texture);
  SDL_Quit();

  // return 0 for on success
  return 0;

}
