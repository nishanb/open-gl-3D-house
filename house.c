#include<stdio.h>
#include<GL/glut.h>
float speed=0.5;
int x=-1,y=-1,z=-1;
float rotate[3]={0,0,0};
int axis=-1;
GLubyte roofPat[]={
	0xff, 0x01, 0x00, 0x01,    
	0x00, 0x01, 0x00, 0x01,                               
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,    
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                               
	0x00, 0x01, 0x00, 0x01,  
	0xff, 0x01, 0xff, 0x01,   
	0xff, 0x01, 0x00, 0x01,    
	0x00, 0x01, 0x00, 0x01,                               
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,    
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                                 
	0x00, 0x01, 0x00, 0x01,                               
	0x00, 0x01, 0x00, 0x01,  
	0xff, 0x01, 0xff, 0x01
};

int houseBase[][3]={
		{-90,-90,90},
		{90,-90,90},
		{90,-70,90},
		{-90,-70,90},

		{90,-70,-90},
		{90,-90,-90},
		{-90,-70,-90},
		{-90,-90,-90}
		};

int houseBaseSecondary[][3]={
		{-40,-90,-90},
		{40,-90,-90},
		{40,-70,-90},
		{-40,-70,-90},
		
		{40,-70,-150},
		{40,-90,-150},
		{-40,-70,-150},
		{-40,-90,-150}
};

int houseWall[][3]={
		{-80,-70,80},
		{80,-75,80},
		{80,50,80},
		{-80,50,80},

		{80,50,-80},
		{80,-75,-80},
		{-80,50,-80},
		{-80,-75,-80}
};

int houseWallSecondary[][3]={
		{-40,-70,-80},
		{40,-70,-80},
		{40,30,-80},
		{-40,30,-80},

		{40,30,-140},
		{40,-70,-140},
		{-40,30,-140},
		{-40,-70,-140}
	};

int houseRoof[][3]={
		{-120,50,80},
		{120,50,80},
		{0,120,80},
		{0,120,80},

		{0,120,-80},
		{120,50,-80},
		{0,120,-80},
		{-120,50,-80}
	};

int houseRoofSecondary[][3]={
		{-55,30,-80},
		{55,30,-80},
		{0,50,-80},
		{0,50,-80},

		{0,50,-140},
		{55,30,-140},
		{0,50,-140},
		{-55,30,-140}
	};


int houseDoor[][3]={
		{-30,-70,-140},
		{30,-70,-140},
		{30,20,-140},
		{-30,20,-140},

		{30,20,-141},
		{30,-70,-141},
		{-30,20,-141},
		{-30,-70,-141}
};
		
			
void init()
{
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.57,0.57,0.57,1.0);
	glColor3f(0.4,0.2,0.6);
	glOrtho(-200.0,200.0,-200.0,200.0,-200.0,200.0);
	glMatrixMode(GL_MODELVIEW);
}

void drawface(int *A,int *B,int *C,int *D)
{
	glBegin(GL_POLYGON);
	glVertex3iv(A);
	glVertex3iv(B);
	glVertex3iv(C);
	glVertex3iv(D);
	glEnd();
}

void drawfacepat(int *A,int *B,int *C,int *D)
{
	glBegin(GL_POLYGON);
	
	glVertex3iv(A);
	glVertex3iv(B);
	glVertex3iv(C);
	glVertex3iv(D);
	glEnd();
}

void drawHouseRoofpat(int cube[][3])
{	
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(roofPat);	
	//glColor3f(0.23,0.25,0.2);
	drawfacepat(cube[0],cube[1],cube[2],cube[3]);	
	//glColor3f(0.23,0.26,0.2);
	drawfacepat(cube[1],cube[2],cube[4],cube[5]);
	//glColor3f(0.23,0.27,0.2);
	drawfacepat(cube[0],cube[3],cube[6],cube[7]);
	//glColor3f(0.23,0.25,0.2);
	drawfacepat(cube[0],cube[1],cube[5],cube[7]);
	//glColor3f(0.23,0.24,0.2);
	drawfacepat(cube[2],cube[3],cube[6],cube[4]);
	//glColor3f(0.23,0.25,0.2);
	drawface(cube[4],cube[5],cube[7],cube[6]);
	glDisable(GL_POLYGON_STIPPLE);
}

void drawBase(int cube[][3])
{

	
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(roofPat);	
	//glColor3f(1.0,0.63,0.24);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	//glColor3f(1.0,0.53,0.24);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	//glColor3f(1.0,0.73,0.24);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	//glColor3f(1.0,0.53,0.24);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	//glColor3f(1.0,0.63,0.24);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	//glColor3f(1.0,0.73,0.24);
	drawface(cube[4],cube[5],cube[7],cube[6]);
	glDisable(GL_POLYGON_STIPPLE);

	glColor3f(1.0,0.63,0.24);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	glColor3f(1.0,0.53,0.24);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	glColor3f(1.0,0.73,0.24);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	glColor3f(1.0,0.53,0.24);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	glColor3f(1.0,0.63,0.24);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	glColor3f(1.0,0.73,0.24);
	drawface(cube[4],cube[5],cube[7],cube[6]);	


	
	
	
}

void drawBaseSecondary(int cube[][3])
{
	glColor3f(1.0,0.63,0.24);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	glColor3f(1.0,0.53,0.24);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	glColor3f(1.0,0.73,0.24);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	glColor3f(1.0,0.53,0.24);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	glColor3f(1.0,0.63,0.24);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	glColor3f(1.0,0.73,0.24);
	drawface(cube[4],cube[5],cube[7],cube[6]);
}


void drawHouseWall(int cube[][3])
{
	glColor3f(0.86,0.86,0.86);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	glColor3f(0.86,0.76,0.86);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	glColor3f(0.86,0.76,0.86);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	glColor3f(0.86,0.86,0.86);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	glColor3f(0.86,0.76,0.86);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	glColor3f(0.86,0.66,0.86);
	drawface(cube[4],cube[5],cube[7],cube[6]);
}


void drawHouseWallSecondary(int cube[][3])
{
	glColor3f(0.0,0.4,0.9);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	glColor3f(0.0,0.5,0.8);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	glColor3f(0.0,0.6,0.9);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	glColor3f(0.0,0.5,0.9);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	glColor3f(0.0,0.5,0.8);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	glColor3f(0.0,0.5,0.7);
	drawface(cube[4],cube[5],cube[7],cube[6]);
}

void drawHouseRoof(int cube[][3])
{
	glColor3f(0.23,0.25,0.2);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	glColor3f(0.23,0.26,0.2);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	glColor3f(0.23,0.27,0.2);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	glColor3f(0.23,0.25,0.2);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	glColor3f(0.23,0.24,0.2);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	glColor3f(0.23,0.25,0.2);
	drawface(cube[4],cube[5],cube[7],cube[6]);
}



void drawHouseRoofSecondary(int cube[][3])
{
	glColor3f(0.2,0.4568,0.51569);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	glColor3f(0.2,0.4568,0.41569);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	glColor3f(0.2,0.5068,0.41569);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	glColor3f(0.2,0.4568,0.51569);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	glColor3f(0.2,0.4568,0.51569);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	glColor3f(0.2,0.4568,0.51569);
	drawface(cube[4],cube[5],cube[7],cube[6]);
}

void drawHouseDoor(int cube[][3])
{
	glColor3f(1,1,1);
	drawface(cube[0],cube[1],cube[2],cube[3]);	
	//glColor3f(0.2,0.4568,0.41569);
	drawface(cube[1],cube[2],cube[4],cube[5]);
	//glColor3f(0.2,0.5068,0.41569);
	drawface(cube[0],cube[3],cube[6],cube[7]);
	//glColor3f(0.2,0.4568,0.51569);
	drawface(cube[0],cube[1],cube[5],cube[7]);
	//glColor3f(0.2,0.4568,0.51569);
	drawface(cube[2],cube[3],cube[6],cube[4]);
	//glColor3f(0.2,0.4568,0.51569);
	drawface(cube[4],cube[5],cube[7],cube[6]);
}



void display()
{	
	
      
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	switch(axis)
	{
		case 0: rotate[0]+=(speed*x);
		        break;
		case 1: rotate[1]+=(speed*y);
		        break;
		case 2: rotate[2]+=(speed*z);
		        break;
	 }
	 
	glRotatef( rotate[0], 1.0, 0.0, 0.0 );
	glRotatef( rotate[1], 0.0, 1.0, 0.0 );
	glRotatef( rotate[2], 0.0, 0.0, 1.0 );




	drawBase(houseBase);
	drawBaseSecondary(houseBaseSecondary);
	drawHouseWall(houseWall);
	drawHouseWallSecondary(houseWallSecondary);
	//drawHouseRoofpat(houseRoof);
	drawHouseRoof(houseRoof);
	drawHouseRoofSecondary(houseRoofSecondary);
	drawHouseDoor(houseDoor);
	glFlush();	
	glutSwapBuffers();
	glutPostRedisplay();

}

void mouse(int button,int state,int a,int b)
{
          
  if (button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
    axis=0;
    x*=-1;
    }
  else if (button==GLUT_RIGHT_BUTTON&&state==GLUT_UP){
   axis=1;
   y*=-1;
   }
 
  else if (button==GLUT_MIDDLE_BUTTON&&state==GLUT_UP){
    axis=2;
    z*=-1;
    }
  
 
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("House Rotation");
	
	glEnable(GL_DEPTH_TEST);
	
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}

