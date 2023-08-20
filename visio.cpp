#include <iostream>
#include <cmath>
#include <X11/Xlib.h>
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   Display *d;
   Window w;
   XEvent e;
   //const char *msg = "X";
   int s;

   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }

   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 30, 30, 1000, 1000, 5,
                           WhitePixel(d, s), BlackPixel(d, s));
XSetBackground(d, DefaultGC(d, s), WhitePixel(d, s));
XSetForeground(d, DefaultGC(d, s), WhitePixel(d, s));

   //XSelectInput(d, w, ExposureMask | KeyPressMask);
XSelectInput(d, w, ExposureMask | ButtonPressMask | KeyPressMask);
   
XMapWindow(d, w);

double x1;// = 1;
bool f;
   while (1) {
  //         XClearWindow(d, w);

// 	if(f)f=false;else f = true;     
//XNextEvent(d, &e);
      //if(e.type==Expose) {
          if(f)f=false;else f = true;     
	 //XFillRectangle(d, w, DefaultGC(d, s), 20, 20, 10, 10);
         //XDrawString(d, w, DefaultGC(d, s), 10, 50, msg, strlen(msg));
         XDrawLine(d, w, DefaultGC(d, s), 500, 1000, 500, 0);
         XDrawLine(d, w, DefaultGC(d, s), 0, 500, 1000, 500);
         XDrawString(d, w, DefaultGC(d, s), 950, 490, "X", strlen("X"));
         XDrawString(d, w, DefaultGC(d, s), 450, 50, "Y", strlen("Y"));
	for(int i=10;i<120;i+=10)
	XDrawLine(d, w, DefaultGC(d, s), 440+i, 510, 440+i, 490);
        XDrawString(d, w, DefaultGC(d, s), 440, 480, "-5", strlen("-5"));
        XDrawString(d, w, DefaultGC(d, s), 550, 480, "5", strlen("5"));
	XDrawString(d, w, DefaultGC(d, s), 450, 200, "y=x^3", strlen("y=x^3"));

	 if(f){
	 std::cout<<"input x: "<<std::endl;
        std::cin>>x1;
	XClearWindow(d, w);
	 }
	 for(double x =-5.65;x<5.65;x+=0.01){
 double m=0;
//if(x1<0)m=(pow(x1,2))-2;else if(x1>0)m=pow(x1,2)+2; else m=pow(x1,2);
m=pow(x1,2)+2;
if(x1==0)m=pow(x1,2);
double y1 = (pow(x1,3));//pow(x1,3)-25*x1));
//double j = ((m*x1-y1));
XDrawPoint(d, w, DefaultGC(d, s), (x*10)+500, 500-((pow(x,3)))*10);
//if((m*(x-x1)+y1)>0)XDrawPoint(d, w, DefaultGC(d, s), (x*10)+500, 500-(m*(x-x1)+y1)*10);
//if((m*(x-x1)+y1)<0)XDrawPoint(d, w, DefaultGC(d, s), 500-abs(x*10), 500+(m*(abs(x)-x1)+y1)*10);
XDrawPoint(d, w, DefaultGC(d, s), (x*10)+500, 500-(m*(x-x1)+y1)*10);

//         XDrawLine(d, w, DefaultGC(d, s), x1*10+497, 497-y1*10, x1*10+503, 503-y1*10);
//         XDrawLine(d, w, DefaultGC(d, s), x1*10+503, 497-y1*10, x1*10+497, 503-y1*10);
         //XFillRectangle(d, w, DefaultGC(d, s), x1*10+497, 497-y1*10, 6, 6);
XDrawArc(d, w, DefaultGC(d, s), x1*10+497, 497-y1*10, 5, 5, 0, 360 * 64);

//XDrawPoint(dis, win ,gc, (x*10)+500, 500-((sqrt(pow(x,3)-25*x)*10)));
//XDrawPoint(dis, win ,gc, (x*10)+500, ((sqrt(pow(x,3)-25*x)*10)+500));




	 }

//      }
//      if (e.type == KeyPress)
	//if(f){
	 //XNextEvent(d, &e);
	   //   if(e.type==ButtonPress)
                //XSetForeground(dis, gc, white);
             // XDrawPoint(d, w, DefaultGC(d, s), e.xbutton.x, e.xbutton.y);
                
//     }



	      //break;
  //std::cout<<"input x: "<<std::endl;
  //std::cin>>x1;
   
   }

   XCloseDisplay(d);
   return 0;
}
