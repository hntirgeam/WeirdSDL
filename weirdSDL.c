#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils.h"

static const int WIDTH = 1280;
static const int HEIGHT = 1020;


void drawWeirdPoints(int amount, bool rndClr, SDL_Renderer *renderer)
{
   for(int i = 0; i < amount; ++i)
   {
      if(rndClr)
      {
         SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
      }

      SDL_RenderDrawPoint(renderer, randomNum(0, WIDTH), randomNum(0, HEIGHT));
   }
}

void drawWeirdLines(int amount, bool rndClr, SDL_Renderer *renderer)
{
   for(int i = 0; i < amount; ++i)
   {
      if(rndClr)
      {
         SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
      }

      SDL_RenderDrawLine(renderer, randomNum(0, WIDTH), randomNum(0, HEIGHT), randomNum(0, WIDTH), randomNum(0, HEIGHT));

      
   }
}

void drawLinesMousePos(int amount, SDL_Renderer *renderer, int x, int y)
{
   for(int i = 0; i < amount; ++i)
   {
      SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(), randomColor(), 255);
      SDL_RenderDrawLine(renderer, x, y, randomNum(0, WIDTH), randomNum(0, HEIGHT));
   }
}

int main(int argc, char *argv[])
{
   SDL_Init(SDL_INIT_VIDEO);

   SDL_Window *win = NULL;
   SDL_Renderer *renderer = NULL;

   win = SDL_CreateWindow("wow", 100, 100, WIDTH, HEIGHT, 0);
   renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

   bool go = true;

   SDL_Event event;

   while (go)
   {
      while (SDL_PollEvent(&event))
      {
         if(event.type == SDL_QUIT)
         {
            go = false;
         }
      }

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderClear(renderer);

      int x;
      int y;
      SDL_GetMouseState(&x, &y);
      printf("x: %d, y: %d \n", x, y);

      drawLinesMousePos(50, renderer, x, y);
      // drawWeirdLines(50, true, renderer);
      // drawWeirdPoints(5000, true, renderer);

      SDL_RenderPresent(renderer);
   }
   
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(win);
   SDL_Quit();

   return 0;
}
