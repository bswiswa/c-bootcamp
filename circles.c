/* C can draw graphics? */
// NOT NOW AT LEAST. Macs do not have the graphics.h header which is part of BGWIN
// so this program will not compile

#include <graphics.h>

int main(){
  int gd = DETECT, gm;
  int x = 320, y = 240, radius;
  
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  
  for(radius=25; radius <= 125; radius = radius + 20)
    circle(x,y,radius);
    
  getch();
  closegraph();
  return 0;
}
