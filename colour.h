#ifndef _COLOUR
#define _COLOUR

struct Colour {
 public:
  int r;  // red (0-255)
  int g;  // green (0-255)
  int b;  // blue (0-255)
  int a;  // alpha (0-1)

  Colour(int r_, int g_, int b_, int a_) {
    r = r_;
    g = g_;
    b = b_;
    a = a_;
  };
};

#endif