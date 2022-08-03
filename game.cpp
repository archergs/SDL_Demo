#include "game.h"

#include <cmath>

#include "colour.h"
#include "player.h"

Game::Game(int height_, int width_) : height(height_), width(width_) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void Game::draw_circle(int center_x, int center_y, int radius_, Colour colour) {
  SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);

  const int32_t diameter = (radius_ * 2);

  int32_t x = (radius_ - 1);
  int32_t y = 0;
  int32_t tx = 1;
  int32_t ty = 1;
  int32_t error = (tx - diameter);

  while (x >= y) {
    //  Each of the following renders an octant of the circle
    SDL_RenderDrawPoint(renderer, center_x + x, center_y - y);
    SDL_RenderDrawPoint(renderer, center_x + x, center_y + y);
    SDL_RenderDrawPoint(renderer, center_x - x, center_y - y);
    SDL_RenderDrawPoint(renderer, center_x - x, center_y + y);
    SDL_RenderDrawPoint(renderer, center_x + y, center_y - x);
    SDL_RenderDrawPoint(renderer, center_x + y, center_y + x);
    SDL_RenderDrawPoint(renderer, center_x - y, center_y - x);
    SDL_RenderDrawPoint(renderer, center_x - y, center_y + x);

    if (error <= 0) {
      ++y;
      error += ty;
      ty += 2;
    }

    if (error > 0) {
      --x;
      tx += 2;
      error += (tx - diameter);
    }
  }
}

void Game::draw_filled_circle(int center_x, int center_y, int radius_,
                              Colour colour) {
  SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);

  // Drawing circle
  for (int x = center_x - radius_; x <= center_x + radius_; x++) {
    for (int y = center_y - radius_; y <= center_y + radius_; y++) {
      if ((std::pow(center_y - y, 2) + std::pow(center_x - x, 2)) <=
          std::pow(radius_, 2)) {
        SDL_RenderDrawPoint(renderer, x, y);
      }
    }
  }
}

void Game::draw_player(Player player) {
  Colour c = player.getPlayerColour();
  SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

  SDL_Rect rect = player.getRect();

  SDL_RenderFillRect(renderer, &rect);
}

void Game::render() { SDL_RenderPresent(renderer); }

void Game::clear(Colour clearColour) {
  SDL_SetRenderDrawColor(renderer, clearColour.r, clearColour.g, clearColour.b,
                         clearColour.a);
  SDL_RenderClear(renderer);
}