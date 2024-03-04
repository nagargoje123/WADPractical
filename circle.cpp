#include<GL/glut.h>
#include<math.h>
#include<iostream>

using namespace std;
int xc=333,yc=240;

void plot_point(int x,int y){
	glBegin(GL_POINTS);
	glVertex2i(xc+x,yc+y);
	glVertex2i(xc+x,yc-y);
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc+y,yc-x);
	glVertex2i(xc-x,yc-y);
	glVertex2i(xc-y,yc-x);
	glVertex2i(xc-x,yc+y);
	glVertex2i(xc-y,yc+x);
	glEnd();
}

 void Bresenham_Circle(int r){
 	int x=0,y=r;
 	float d=3-2*r;
 	plot_point(x,y);
 	int k;
 	while (x<y){
 		x=x+1;
 		if(d<0){
 			d=d+4*x+6;
 		}
 		else{
 			y=y-1;
 			d=d+4*(x-y)+10;
 		}
 		plot_point(x,y);
 	}
 	glFlush();
 }
 
 void display(){
 	int radius1=75;
 	glClear(GL_COLOR_BUFFER_BIT);
 	Bresenham_Circle(radius1);
 }
 
 void Init(){
 	glClearColor(1.0,1.0,1.0,0);
 	glColor3f(0.0,0.0,0.0);
 	gluOrtho2D(0,640,0,480);
 	glPointSize(5);
 }
 
 int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(0,0);
	glutInitWindowPosition(640,480);
	glutCreateWindow( "Bresenham_Circle");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();					
	
}
 		
	
