#ifndef _PLAYER
#define _PLAYER

#include <SDL.h>

#include "colour.h"

class Player {
 public:
  Player(int initX, int initY, Colour colour_);
  void moveX(int x);
  void moveY(int y);
  void setRotateX(int rotatex);
  void setRotateY(int rotatey);

  void movePlayer(int newX, int newY);

  void setPlayerColour(Colour colour);
  Colour getPlayerColour();

  SDL_Rect getRect();

 private:
  int rotatex;
  int rotatey;
  Colour colour;
  SDL_Rect rect;
};

#endif