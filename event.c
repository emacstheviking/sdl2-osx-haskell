#include <stdio.h>
#include <math.h>

#include <SDL.h>
#include <SDL_error.h>

#include "gui_app.h"




extern SDL_bool g_quit;
extern SDL_bool	g_sw_enabled;



void handle_event(SDL_Event *e)
{
  if (e)
    {
      switch(e->type)
	{
	case SDL_QUIT:
	  g_quit = SDL_TRUE;
	  break;

	case SDL_MOUSEMOTION:
	  printf("SDL_MOUSEMOTION\n");
	  break;

	case SDL_KEYUP:
	  printf("SDL_KEYUP\n");
	  switch(e->key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      g_quit = SDL_TRUE;
	      break;
	      
	    case SDLK_SPACE:
	      if (SDL_TRUE == g_sw_enabled)
		{
		  g_sw_enabled = SDL_FALSE;
		}
	      else
		{
		  g_sw_enabled = SDL_TRUE;
		}
	    }
	  break;
	}
    }
}
