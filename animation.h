const int WIDTH = 500;
const int HEIGHT = 500;


typedef struct pos_struct {
  
  int x;
  int y;
  
} position;


typedef struct meteor_struct {
  
  int radius;
  position met_pos;
  double velocity;
  double angle;
    
} meteor;

typedef struct robot_struct {
  
  double velocity;
  position robo_pos;
    
} robot;





int x_rot(int x, int y, int x0, int y0, double theta)      //rotations functions from canvas
{ return x0 + (x-x0) * cos(theta) + (y-y0) * sin(theta);}

int y_rot(int x, int y, int x0, int y0, double theta)
{ return y0 - (x-x0) * sin(theta) + (y-y0) * cos(theta);}


double angle() {
  
  double angle = 4200 + rand()% 1046;
    return 3.14 / 2 + angle/1000;}


double random_x() {
  
  return rand()%WIDTH;}


void draw_meteor(meteor m1) {
  
  
  int x1 = x_rot(m1.met_pos.x - m1.radius, m1.met_pos.y, m1.met_pos.x, m1.met_pos.y, m1.angle);
  int y1 = y_rot(m1.met_pos.x - m1.radius, m1.met_pos.y, m1.met_pos.x, m1.met_pos.y, m1.angle);
    
  int x2 = x_rot(m1.met_pos.x + m1.radius, m1.met_pos.y, m1.met_pos.x, m1.met_pos.y, m1.angle);
  int y2 = y_rot(m1.met_pos.x + m1.radius, m1.met_pos.y, m1.met_pos.x, m1.met_pos.y, m1.angle);
  
  int x3 = x_rot(m1.met_pos.x, m1.met_pos.y - 45, m1.met_pos.x, m1.met_pos.y, m1.angle);
  int y3 = y_rot(m1.met_pos.x, m1.met_pos.y - 45, m1.met_pos.x, m1.met_pos.y, m1.angle);
  
  int x4 = x_rot(m1.met_pos.x, m1.met_pos.y, m1.met_pos.x, m1.met_pos.y, m1.angle);
  int y4 = y_rot(m1.met_pos.x, m1.met_pos.y, m1.met_pos.x, m1.met_pos.y, m1.angle);
  
  
  graphics_triangle_fill(x1, y1,
                         x2, y2, 
                         x3, y3, 
                         153, 255, 255);
  graphics_circle_fill(x4, y4, m1.radius,
                         128, 128, 128);
}


void draw_robot(int xRef, int yRef) {
  
  graphics_rectangle_fill(xRef - 3, yRef,
                          xRef + 3, yRef - 20, 
                          64, 64, 64);
  graphics_rectangle_fill(xRef - 12, yRef - 20, 
                          xRef + 12, yRef - 27, 
                          220, 220, 0);
  graphics_rectangle_fill(xRef - 15, yRef - 15,
                          xRef + 15, yRef + 15,
                          220, 220, 0);
  graphics_triangle_fill(xRef, yRef,
                          xRef - 20, yRef + 15,
                          xRef + 20, yRef + 15,
                          0, 0, 0);
  graphics_circle(xRef - 7, yRef - 24, 2,
                          0, 0, 0);
  graphics_circle(xRef + 7, yRef - 24, 2,
                          0, 0, 0);
}

/*
int met_position(meteor m, int uLimit, int lLimit) {
  
  if(m.met_pos.y >= uLimit) {
    draw_meteor(m.met_pos.x, 0, m, angle() );}
  
  else {
    return m.met_pos.y;}
}
*/

int robo_position(robot r, int uLimit, int lLimit) {
  
  if(r.robo_pos.x >= uLimit) {
    return r.robo_pos.x = lLimit;}
  
  else if(r.robo_pos.x < lLimit) {
    return r.robo_pos.x = uLimit;}
  
  else {
    return r.robo_pos.x;}
}

