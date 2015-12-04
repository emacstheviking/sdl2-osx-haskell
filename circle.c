#include <stdio.h>
#include <math.h>

#include <SDL.h>
#include <SDL_error.h>

//--------------------------------------------------------------------
//
//
//
//                    Circle functions
//
// (stolen from my GNU-Prolog integration!)
//
//--------------------------------------------------------------------


void
SDL_RenderDrawCircle(SDL_Renderer* rndr, int x0, int y0, int radius)
{
  int x = radius;
  int y = 0;
  int decisionOver2 = 1 - x;

  while(x >= y)
    {
      SDL_RenderDrawPoint(rndr,  x + x0,  y + y0);
      SDL_RenderDrawPoint(rndr,  y + x0,  x + y0);
      SDL_RenderDrawPoint(rndr, -x + x0,  y + y0);
      SDL_RenderDrawPoint(rndr, -y + x0,  x + y0);
      SDL_RenderDrawPoint(rndr, -x + x0, -y + y0);
      SDL_RenderDrawPoint(rndr, -y + x0, -x + y0);
      SDL_RenderDrawPoint(rndr,  x + x0, -y + y0);
      SDL_RenderDrawPoint(rndr,  y + x0, -x + y0);

      y++;

      if (decisionOver2>0)
	{
	  decisionOver2 += ((y - (--x))<<1)+1;
	}
      else
	{
	  decisionOver2 += (y<<1)+1;
	}
    }
}


void
SDL_RenderFillCircle(SDL_Renderer* rndr, int x0, int y0, int radius)
{
  int x = radius;
  int y = 0;
  int decisionOver2 = 1 - x;

  while(x >= y)
    {
      SDL_RenderDrawLine(rndr,  x + x0,  y + y0,  x + x0, -y + y0);
      SDL_RenderDrawLine(rndr,  y + x0,  x + y0,  y + x0, -x + y0);
      SDL_RenderDrawLine(rndr, -x + x0,  y + y0, -x + x0, -y + y0);
      SDL_RenderDrawLine(rndr, -y + x0,  x + y0, -y + x0, -x + y0);

      y++;

      if (decisionOver2>0)
	{
	  decisionOver2 += ((y - (--x))<<1)+1;
	}
      else
	{
	  decisionOver2 += (y<<1)+1;
	}
    }
}
