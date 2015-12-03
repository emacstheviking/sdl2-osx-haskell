#include <SDL.h>
#include <SDL_error.h>

#include "gui_app.h"




SDL_Window*    g_app_window   = NULL;
SDL_Renderer*  g_app_renderer = NULL;
SDL_bool       g_quit         = SDL_FALSE;




void
create_app_window_or_die()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
      exit(1);
    }

  g_app_window =
    SDL_CreateWindow("Another go at it...",
		     INITIAL_X,
		     INITIAL_Y,
		     SCREEN_WIDTH,
		     SCREEN_HEIGHT,
		     SDL_WINDOW_SHOWN);

  if (NULL == g_app_window)
    {
      printf("Window could not be created! SDL Error: %s\n",
	     SDL_GetError() );
      exit(1);
    }
}




void
create_app_renderer_or_die()
{
  g_app_renderer =
    SDL_CreateRenderer(g_app_window,
		       -1,
		       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (NULL == g_app_renderer)
    {
      printf("Renderer for g_app_window could not be created! SDL Error: %s\n",
	     SDL_GetError() );
      exit(1);
    }
}
