# include<stdio.h>
# include<kipr/graphics.h>
# include<stdlib.h>
# include"forest.h"
# include<time.h>
# include<math.h>
# include"animation.h"
# include"desert.h"
# include"moon.h"


typedef struct {
  
  char initials[4];
  int score;
  
} player;

void get_name(char name[5], player p[]) {
  printf("Please enter your name: ");
  scanf("%c", p[0].initials);
}



void background(char c) {
  if(c == 'D') {desert();}
    if(c == 'M') {draw_moon();}
    if(c == 'F') {draw_forest();}
}

void fill_array(meteor m[]) {
  int i;
  
  for(i=0;i<1000;i++) {                  //loads every meteor with values
       m[i].angle = angle();
       m[i].met_pos.x = random_x();
       m[i].met_pos.y = 0;
       m[i].radius = 10;
       m[i].velocity = 15;
  }
}

void sort(player p[], int numEntries) {

  int i, j;
  int max, dummy;
  int minIndex;

  for(j=0;j<numEntries;j++) {

    max = p[j].score;
    minIndex = p[j].score;

    for(i=j;i<numEntries;i++){
      if(p[i].score < max) {
        max = p[i].score;
        minIndex = i;}}

    dummy = p[j].score;
    p[j].score  = max;
    p[minIndex].score = dummy;}}


void orderedInsert (player arr[], int first, int last, int target)   //source: https://secweb.cs.odu.edu/~zeil/cs361/web/website/Lectures/sortingAndSearching/pages/orderedInsert.html

{
  int i = first;  
  while ((i < last) && (target < arr[i-1].score))
    {   
      arr[i].score = arr[i+1].score;
      i = i + 1;
    }
  arr[i+1].score = target; 
}




int main() {
  
  
  player p[6];
  
  int i;
  
  for(i=0;i<6;i++) {
    p[i].score = 0;
  }
  

    
  
  srand((int) time (0) );
  
  meteor m[1000];
  fill_array(m);
  
  meteor m2[1000];
  fill_array(m2);
  
  meteor m3[1000];
  fill_array(m3);
  
  meteor m4[1000];
  fill_array(m4);
  
  meteor m5[1000];
  fill_array(m5);
  
  meteor m6[1000];
  fill_array(m6);
  
  meteor m7[1000];
  fill_array(m7);
  
  meteor m8[1000];
  fill_array(m8);
  
  meteor m9[1000];
  fill_array(m9);
  
  meteor m10[1000];
  fill_array(m10);
  
  
  robot r1;
  r1.robo_pos.x = 250;
  r1.robo_pos.y = 350;
  r1.velocity = 40;
  
  int N = 0;
  int numLines = 0;
  
  char find;
  char biome;
  char name[5];
  
  get_name(name, p);
  
  
  double oldtime = seconds();
  double DT;
  
  printf("    Welcome to Meteor Dash!\n   Please choose your biome(D/M/F): ");
  scanf("%c", &biome);
  
  graphics_open(WIDTH, HEIGHT);
  graphics_fill(230, 230, 230);
  
  
  
  while(get_key_state(KeySpace) == 0) {
  g_printString("METEOR DASH", 50, 50, 0,0,0, 5.0);
  g_printString("press the keyboard button", 50, 120, 0,0,0, 1.0);
  g_printString("Press Space Bar to Begin", 50, 220, 0, 0, 0, 2.5);
  g_printString("Arrow keys to move", 50, 250, 0, 0, 0, 1.5);
  graphics_update();
  }
  
  
  
  
  
  

  

  
  while(get_key_state(KeyQ) == 0) {       //animation loop
    
    DT = seconds() - oldtime;
    oldtime = seconds();
    
    char c[6] = " ";
    sprintf(c, "%s %d", c, N);
    
    
    
    if(get_key_state(KeyRight) != 0) {
          DT = DT + 1;}
    
    else if(get_key_state(KeyLeft) != 0) {    
          DT = DT * -1 -1;}
    
    else {DT = DT - DT;}
    
    graphics_fill(240, 240, 240);
    
    m[N].met_pos.y = m[N].met_pos.y + m[N].velocity;// * ACC;
    
    m[N].met_pos.x = m[N].met_pos.x + 20 * sin(m[N].angle);
    
    r1.robo_pos.x = robo_position(r1, WIDTH, 0) + r1.velocity * DT;
    
    
    
    
    if(biome == 'D') {desert();}
    else if(biome == 'M') {draw_moon();}
    else {draw_forest();}
    
    
    draw_robot(r1.robo_pos.x, r1.robo_pos.y);
    draw_meteor(m[N]);
    
    
    if(N>5) {
      
   
      draw_meteor(m2[N]);
      m2[N].met_pos.y = m2[N].met_pos.y + m2[N].velocity;
      m2[N].met_pos.x = m2[N].met_pos.x + 20 * sin(m2[N].angle);
      if( abs(m2[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m2[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    
    
    if(N>10) {
      m3[N].met_pos.y = m3[N].met_pos.y + m3[N].velocity;
      m3[N].met_pos.x = m3[N].met_pos.x + 20 * sin(m3[N].angle);
      draw_meteor(m3[N]);
      if( abs(m3[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m3[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    if(N>15) {
      m4[N].met_pos.y = m4[N].met_pos.y + m4[N].velocity;
      m4[N].met_pos.x = m4[N].met_pos.x + 20 * sin(m4[N].angle);
      draw_meteor(m4[N]);
      if( abs(m4[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m4[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    if(N>20) {
      m5[N].met_pos.y = m5[N].met_pos.y + m5[N].velocity;
      m5[N].met_pos.x = m5[N].met_pos.x + 20 * sin(m5[N].angle);
      draw_meteor(m5[N]);
      if( abs(m5[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m5[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    if(N>25) {
      m6[N].met_pos.y = m6[N].met_pos.y + m6[N].velocity;
      m6[N].met_pos.x = m6[N].met_pos.x + 20 * sin(m6[N].angle);
      draw_meteor(m6[N]);
      if( abs(m6[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m6[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    if(N>30) {
      m7[N].met_pos.y = m7[N].met_pos.y + m7[N].velocity;
      m7[N].met_pos.x = m7[N].met_pos.x + 20 * sin(m7[N].angle);
      draw_meteor(m7[N]);
      if( abs(m7[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m7[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    if(N>40) {
      m8[N].met_pos.y = m8[N].met_pos.y + m8[N].velocity;
      m8[N].met_pos.x = m8[N].met_pos.x + 20 * sin(m8[N].angle);
      draw_meteor(m8[N]);
      if( abs(m8[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m8[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    if(N>50) {
      m9[N].met_pos.y = m9[N].met_pos.y + m9[N].velocity;
      m9[N].met_pos.x = m9[N].met_pos.x + 20 * sin(m9[N].angle);
      draw_meteor(m9[N]);
      if( abs(m9[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m9[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
    }
    if(N>20) {
      m10[N].met_pos.y = m10[N].met_pos.y + m10[N].velocity;
      m10[N].met_pos.x = m10[N].met_pos.x + 20 * sin(m10[N].angle);
      draw_meteor(m10[N]);
      if( abs(m10[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m10[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}
      }
 
    
    g_printString(c, 200, 50, 255, 0, 0, 2.0);
    
    graphics_update();  
    
    if( abs(m[N].met_pos.y - r1.robo_pos.y) < 25 && abs(m[N].met_pos.x - r1.robo_pos.x) < 25) 
      {break;}

    
    if( m[N].met_pos.y >= HEIGHT - 150 ) {N++;}
 
    }
  
  printf("*****GAME OVER***** \n\n*******************\n\n   YOUR SCORE: %d\n\n\n", N);
  
  
    
  int j;
  
  for(i=1;i<6;i++) {
    for(j=0;j<3;j++) {
      p[i].initials[j] = 'A' + rand()% 26;
    }
  }
      
  
  char s1[5];
  char s2[5];
  char s3[5];
  char s4[5];
  char s5[5];
  
  FILE* scoreF;
  scoreF = fopen("ScoreSort.txt", "r");
  if(scoreF == NULL) {scoreF = fopen("ScoreSort.txt", "w");
                     fprintf(scoreF, "%s %d\n",p[0].initials, p[0].score);
                     return 0;}
  
  while( (find = fgetc(scoreF) ) != EOF){   //tell how many lines there are, source is michael schilling from stack overflow
    if(find == '\n') {numLines++;}
  }
  fclose(scoreF);
  

  if(numLines<5) {
  scoreF = fopen("ScoreSort.txt", "a");
   
  fprintf(scoreF, "%d\n", N);
    fclose(scoreF);
  } 
  
  

  scoreF = fopen("ScoreSort.txt", "r");
  
  fgets(s1, 5, scoreF);
  fgets(s2, 5, scoreF);
  fgets(s3, 5, scoreF);
  fgets(s4, 5, scoreF);
  fgets(s5, 5, scoreF);
  
  
  fclose(scoreF);
 
  
  
  
  
  sscanf(s1, "%d", &p[1].score);
  sscanf(s2, "%d", &p[2].score);
  sscanf(s3, "%d", &p[3].score);      //fills array with file values
  sscanf(s4, "%d", &p[4].score);
  sscanf(s5, "%d", &p[5].score);
  

  
  
  

  
 
  
  //orderedInsert(p, 0, 4, N);
    
  
  

  
  
  
  
  
  
  graphics_fill(0, 0, 0);
  g_printString("Leaderboard: ", 50, 50, 0, 204, 0, 5.0);
  
  g_printString("1. ", 35, 150, 0, 255, 0, 1.0);
  g_printString("2. ", 35, 200, 0, 255, 0, 1.0);
  g_printString("3. ", 35, 250, 0, 255, 0, 1.0);
  g_printString("4. ", 35, 300, 0, 255, 0, 1.0);
  g_printString("5. ", 35, 350, 0, 255, 0, 1.0);
  
  for(i=0;i<5;i++) {
    g_printString(p[i].initials, 50, 150 + 50 * i, 0, 255, 0, 1.0);
    g_printInt(p[i].score,0 , 100, 150 + 50 * i, 0, 255, 0, 1.0); 
  }
  
  
  
  graphics_update();
  graphics_close();
  
  
  return 0;
}