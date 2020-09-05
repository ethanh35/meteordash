void cactus(int x) {
  int R = 0;
  int G = 153;
  int B = 0;
  graphics_rectangle_fill(x, 350, x + 20, 300, R, G, B);
  graphics_rectangle_fill(x + 20, 314, x + 40, 330, R, G, B);
  graphics_rectangle_fill(x + 32, 322, x + 48, 300, R, G, B);
  
  graphics_circle_fill(x + 10, 300, 10, R, G, B);
  graphics_circle_fill(x + 40, 322, 8, R, G, B);
  graphics_circle_fill(x + 40, 300, 8, R, G, B);
}


void cactus2(int x) {
  int R = 0;
  int G = 153;
  int B = 0;
  graphics_rectangle_fill(x, 350, x - 20, 270, R, G, B);
  graphics_rectangle_fill(x - 20, 314, x - 40, 330, R, G, B);
  graphics_rectangle_fill(x - 32, 322, x - 48, 300, R, G, B);
  
  graphics_circle_fill(x - 10, 270, 10, R, G, B);
  graphics_circle_fill(x - 40, 322, 8, R, G, B);
  graphics_circle_fill(x - 40, 300, 8, R, G, B);
}



void desert() {
graphics_fill(255, 153, 51);

graphics_circle_fill(250, 350, 40, 255, 255, 153);
graphics_rectangle_fill(0, 350, 500, 500, 194, 178, 128);
  

  cactus(150);
  cactus(400);
  cactus2(50);
}