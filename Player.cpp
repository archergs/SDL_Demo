#include "player.h"

#include <SDL.h>

#include "colour.h"

Player::Player(int x, int y, Colour colour) : colour(colour) {
  rect.x = x;
  rect.y = y;
  rect.h = 20;
  rect.w = 16;
}

void Player::movePlayer(int newX, int newY) {
  rect.x += newX;
  rect.y += newY;
}

void Player::setPlayerColour(Colour colour_) { colour = colour_; }
Colour Player::getPlayerColour() { return colour; }

SDL_Rect Player::getRect() { return rect; }

void Player::moveX(int x_) { rect.x += x_; }
void Player::moveY(int y_) { rect.y += y_; }
void Player::setRotateX(int rotatex_) { rotatex = rotatex_; }
void Player::setRotateY(int rotatey_) { rotatey = rotatey_; }