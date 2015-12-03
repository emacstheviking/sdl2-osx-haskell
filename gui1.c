#include <stdio.h>
#include <math.h>

#include <SDL.h>
#include <SDL_error.h>

#include "gui_app.h"


extern void create_app_window_or_die();
extern void create_app_renderer_or_die();
extern void handle_event(SDL_Event*);




extern SDL_Window* g_app_window;
extern SDL_Renderer* g_app_renderer;
extern SDL_bool g_quit;


// sine wave parameters
const double g_pi     = 3.14159265;
const double g_rad    = g_pi / 180;

double		g_sw_theta1	= 0;
double		g_sw_theta2	= 0;
double		g_sw_amplitude	= SCREEN_HEIGHT >> 1;
SDL_bool	g_sw_enabled	= SDL_TRUE;


// SDL abbreviations, potential portability helpers!
#define GFX_COLOR(r,g,b) SDL_SetRenderDrawColor(g_app_renderer, r, g, b, 255)
#define GFX_COLORA(r,g,b,a) SDL_SetRenderDrawColor(g_app_renderer, r, g, b, a)
#define GFX_LINES(X,Y)  SDL_RenderDrawLines(g_app_renderer,&X[0],Y)



/*
 * gcc -I/opt/local/include/SDL2 -L/opt/local/include -framework SDL2 -o gui gui1.c event.c gui_app.c
 */

#define SINE1_COLOR (128,128,192)
#define SINE2_COLOR (128,128,192)


void draw_sine()
{
  SDL_Point curve1[SCREEN_WIDTH];
  SDL_Point curve2[SCREEN_WIDTH];

  int offset = SCREEN_HEIGHT >> 1;

  for(int i=0; i<SCREEN_WIDTH; i++)
    {
      curve1[i].x = i;
      curve1[i].y = offset +
	(sin( (i + g_sw_theta1) * g_rad)
	 *
	 g_sw_amplitude);

      curve2[i].x = i;;
      curve2[i].y = offset +
	(sin( (i + g_sw_theta2 + 270) * g_rad)
	 *
	 (g_sw_amplitude/2) );
    }

  GFX_COLOR(128, 128, 192);
  GFX_LINES(curve1, SCREEN_WIDTH);
  GFX_COLOR(128, 192, 128);
  GFX_LINES(curve2, SCREEN_WIDTH);
}




void update_sine()
{
  if (SDL_TRUE == g_sw_enabled)
    {
      g_sw_theta1 -= 0.1;
      g_sw_theta2 += 0.2;
    }
}




int main(int argc, char* argv[])
{
  create_app_window_or_die();
  create_app_renderer_or_die();

  while (!g_quit)
    {
      SDL_Event e;

      while( SDL_PollEvent(&e))
	{
	  handle_event(&e);
	}

      // --] clear the screen
      SDL_SetRenderDrawColor(g_app_renderer,
			     255, 255, 255,
			     SDL_ALPHA_OPAQUE);

      SDL_RenderClear(g_app_renderer);

      // --] draw fresh content
      draw_sine();

      // --] update application state
      update_sine();

      // --] present the frame
      SDL_RenderPresent(g_app_renderer);
    }

  SDL_Quit();
  return 0;
}
