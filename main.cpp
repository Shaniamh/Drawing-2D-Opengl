//
//  main.cpp
//  pens
//
//  Created by dosen1 on 10/7/17.
//  Copyright (c) 2017 dosen1. All rights reserved.
//


#include <GL/GLUT.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    float x,y;
} point2D_t;

typedef struct{
    float r,g,b;
}color_t;




void drawPolygon(point2D_t p[], color_t col,int n){
    glBegin(GL_POLYGON);
    glColor3f(col.r,col.g,col.b);
    for(int i=0;i<n;i++){
        glVertex2f(p[i].x,p[i].y);
    }
    glEnd();
}

void drawPolygon(point2D_t p[], color_t col[],
                 int n){
    glBegin(GL_POLYGON);
    for(int i=0;i<n;i++){
        glColor3f(col[i].r,col[i].g,col[i].b);
        glVertex2f(p[i].x,p[i].y);
    }
    glEnd();
}


void drawLine(float x1, float y1, float x2, float y2){
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void userdraw(void){
	//langit
	point2D_t p1[4]={{0,20},{320,20},
        {320,240},{0,240}};
    color_t c1[4]={{0,0,0.7},{0,0,0.7},
        {0,0,0.7},{0,0,0.7}};
    drawPolygon(p1,c1,4);
    
   //bintang
    static point2D_t b[200];
    static int d[200];
    static int sw=0;
    // Membuat titik2 acak
    if(sw==0){
      for(int i=0;i<200;i++){
        b[i].x=320*(float)rand()/RAND_MAX;
        b[i].y=240*(float)rand()/RAND_MAX;
        d[i]=1+rand()%3;
      }
    }
    sw=1;
    // Menggambar titik2 bintang
    for(int i=0;i<200;i++){
        glPointSize(d[i]);
        float r=(float)rand()/RAND_MAX;
        if(r<0.1) glColor3f(0,0,0);
        else glColor3f(1,1,1);
        glBegin(GL_POINTS);
        glVertex2f(b[i].x,b[i].y);
        glEnd();
    }
    
    //LAUT
	point2D_t laut[5]={{0,0},{400,0},{400,55},{300,45},{0,50}};
    color_t wLaut[5]={{0.1,0.5,0.7},{0.5,0.2,0},{0.5,0.2,0},{0,0,1},{0.1,0.5,0.7}};
	drawPolygon(laut,wLaut,5);
    

	 //Membuat perahu
             point2D_t perahu[4]={{43,45},{110,45},{123,80},{28,80}};
             color_t wPerahu[4]={{0,0,0},{0,0,0},{1,0.2,0.4},{1,0.2,0.4}};
             drawPolygon(perahu,wPerahu,4);
   
 	 //membuat tiang
             point2D_t tiang[4]={{65,80},{67,80},{67,120},{65,120}};
             color_t wTiang[4]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
             drawPolygon(tiang,wTiang,4);
	//membuat bendera merah
           point2D_t merah[4]={{67,115},{80,115},{80,120},{67,120}};
           color_t wMerah [4]={{1,0,0},{1,0,0},{1,0,0},{1,0,0}};
           drawPolygon(merah,wMerah,4);
    //membuat bendera putih
            point2D_t putih[4]={{67,110},{80,110},{80,115},{67,115}};
           color_t wPutih [4]={{1,1,1},{1,1,1},{1,1,1},{1,1,1}};
           drawPolygon(putih,wPutih,4);
           
    //Bulan
	point2D_t p[60];
    color_t pth={1,1,1};
    color_t abu2={0.5,0.5,0.5};
    float s;
    for(int i=0;i<60;i++){
        s=(float)i*6/57.3;
        p[i].x=250+14*cos(s);
        p[i].y=180+15*sin(s);
    }
    drawPolygon(p,abu2,60);

    for(int i=0;i<60;i++){
        s=(float)i*6/57.3;
        p[i].x=250+12*cos(s);
        p[i].y=180+13*sin(s);
    }
    drawPolygon(p,pth,60);

   
   //air
     float xp,yp,dx;
           glColor3f(1,1,1);
           for(int i=1;i<20;i++){
           xp=200*(float)rand()/RAND_MAX-10;
        yp=55*(float)rand()/RAND_MAX-10;
        dx=10+20*(float)rand()/RAND_MAX;
        drawLine(xp,yp,xp+dx,yp); 
        
        //pohon
        
  
  
 }
    
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(300., 300.);
    glutInitWindowSize(800., 500.);
    glutCreateWindow("Tugas punya shania :)) ");
    glClearColor(0.,0.,0.,0.);
    gluOrtho2D(0., 320., 0., 240);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


