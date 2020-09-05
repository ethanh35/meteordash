void stars(N) {
  
  if(N<1) {
    return;
  }
  else {
    int x = rand()%500;
    int y = rand()%500;
    graphics_pixel(x, y, 255, 255, 255);
    //stars(N-1);
  }
}


void tree(int x, int y) {
  
  graphics_rectangle_fill(x, y, x+15, y-50, 153, 76, 0);
  graphics_triangle_fill(x-20, y-20, x+35, y-20, x+7, y-70, 0, 200, 0);
  
}


void draw_forest() {
  
  graphics_fill(0, 0, 102);
  
  
  tree(100, 350);
  tree(300, 350);
  tree(400, 350);
  
  graphics_rectangle_fill(0, 350, 500, 500, 102, 51, 0);
  graphics_rectangle_fill(0, 350, 500, 365, 0, 102, 0);
  
}