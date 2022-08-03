#ifndef _GAME
#define _GAME

#include <SDL.h>

#include "colour.h"
#include "player.h"

class Game {
 public:
  // Constructor that inits parameters
  Game(int height_, int width_);

  ~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  void draw_circle(int center_x, int center_y, int radius_, Colour colour);
  void draw_filled_circle(int center_x, int center_y, int radius_,
                          Colour colour);

  void draw_player(Player player);
  void render();
  void clear(Colour clearColour);

 private:
  int height;  // height of window
  int width;   // width of window
  SDL_Renderer *renderer = NULL;
  SDL_Window *window = NULL;
};

#endif