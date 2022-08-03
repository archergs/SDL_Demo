#include <SDL.h>

#include "colour.h"
#include "game.h"
#include "player.h"

int main(int argc, char *argv[]) {
  int height = 200;
  int width = 400;

  Game game(height, width);

  SDL_Event event;

  int frameDelay = 100;

  Colour playerColour = Colour(0, 103, 231, 0);
  Player player = Player(width / 2, height / 2, playerColour);

  while (!(event.type == SDL_QUIT)) {
    // int frameStart = SDL_GetTicks();

    game.clear(Colour(0, 0, 0, 0));

    game.draw_circle(150, 150, 30, Colour(255, 150, 43, 0));
    game.draw_circle(100, 100, 30, Colour(5, 250, 104, 0));

    game.draw_filled_circle(120, 100, 40, Colour(5, 250, 104, 0));
    game.draw_filled_circle(300, 170, 20, Colour(5, 250, 104, 0));

    game.draw_player(player);

    game.render();

    SDL_PollEvent(&event);

    switch (event.type) {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_LEFT:
            player.moveX(-2);
            break;
          case SDLK_RIGHT:
            player.moveX(2);
            break;
          case SDLK_UP:
            player.moveY(-2);
            break;
          case SDLK_DOWN:
            player.moveY(2);
            break;
        }

        break;
    }

    /*int frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }*/
  }
}