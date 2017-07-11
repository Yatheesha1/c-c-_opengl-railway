//g++ 'railway.cpp' -lGL -lGLU -lglut
#include<GL/glut.h>
#include<math.h>

int seq=0;
float a,b,s=0;
int flag,k=0;

void rgb(int r,int g,int b)
{
  glColor3f(r/255.0,g/255.0,b/255.0);	
}

void displaytext(float r,float g,float b,const char *string,int x,int y)
{
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);   
}

void start()
{
     displaytext(0.9,0.5,0.8,"CG MINI PROJECT",460,320);
     displaytext(0.9,0.5,0.8,"________________",460,310);
     displaytext(0.9,0.5,0.8,"RAILWAY GATE",480,280);
     displaytext(0.9,0.5,0.8,"4SF13CS016 & 4SF13CS065",430,240);
     if(k)
      displaytext(0.6,0.2,0.7,"Press any key!",470,70);
     k=~k;
     glutPostRedisplay();
     glutSwapBuffers();
}

void end()
{
	 glClearColor(0,0,0,1.0);
     displaytext(0.6,0.2,0.7,"OBEY TRAFIC RULES",450,320);
     glutPostRedisplay();
     glutSwapBuffers();
}

void DrawSegment(float cx, float cy, float r, int degree1,int degree2) 
{ 
	int num_segments=360;
	  glBegin(GL_POLYGON);
	for(int i = degree1; i < degree2; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void track()
{
  rgb(146, 153, 142);
  glBegin(GL_POLYGON);
  glVertex2f(1100,100);
  glVertex2f(0,100);
  glVertex2f(0,180);
  glVertex2f(1100,180);
  glEnd();   
  
  rgb(53, 53, 53);//track down
  glBegin(GL_LINES);
  glVertex2f(0,140);
  glVertex2f(1100,140);
  glEnd(); 
  
  glBegin(GL_LINES);//track upp
  glVertex2f(0,160);
  glVertex2f(1100,160);
  glEnd(); 
}

void gate(int x,int y)
{
  glColor3f(1,1,1);
  glLineWidth(2);
  glBegin(GL_LINES);//horizontal
  glVertex2f(-15+x,110+y);
  glVertex2f(510+x,110+y);
  glEnd(); 
  glBegin(GL_LINES);
  glVertex2f(-15+x,120+y);
  glVertex2f(510+x,120+y);
  glEnd();
   
  for(int i=-10;i<510;i+=5)//vertical
  { 
  glBegin(GL_LINES);
  glVertex2f(i+x,100+y);
  glVertex2f(i+x,130+y);
  glEnd(); 
  }
}

void road_gate(int x,int y)
{
  glColor3f(1,0,0);
  glLineWidth(2);
  glBegin(GL_LINES);//horizontal
  glVertex2f(510+x,110+y);
  glVertex2f(590+x,110+y);
  glEnd(); 
  glBegin(GL_LINES);
  glVertex2f(510+x,120+y);
  glVertex2f(590+x,120+y);
  glEnd();
   
  for(int i=510;i<=590;i+=5)
  { 
  glBegin(GL_LINES);//vertical
  glVertex2f(i+x,100+y);
  glVertex2f(i+x,130+y);
  glEnd(); 
  }
}

void sky()
{
  //sky
  glColor3f(0.0,0.9,0.9);
  glBegin(GL_POLYGON);
  glVertex2f(0,450);
  glVertex2f(0,700);
  glVertex2f(1100,700);
  glVertex2f(1100,450);
  glEnd();
}

void sun()
{
  //sun
  glColor3f(1.0,0.9,0.0);
  DrawSegment(645,620,40,0,360);
}

void road()
{
   rgb(73, 76, 71);//vertical
   glBegin(GL_POLYGON);
   glVertex2f(500,0);
   glVertex2f(600,0);
   glVertex2f(560,450);
   glVertex2f(540,450);
   glEnd(); 
   
   glBegin(GL_POLYGON);//horizontal
   glVertex2f(0,415);
   glVertex2f(1100,415);
   glVertex2f(1100,400);
   glVertex2f(0,400);
   glEnd(); 
}
void mountain()
{
  rgb(160, 118, 1);
  glBegin(GL_POLYGON);
  glVertex2f(20,450);
  glVertex2f(250,600);
  glVertex2f(400,460);
  glVertex2f(550,650);
  glVertex2f(750,440);
  glVertex2f(950,625);
  glVertex2f(1070,450);
  glEnd();
}

void tree()
{
  glColor3f(0.5019,0.0,0.0);
  glBegin(GL_POLYGON);//stem
  glVertex2f(350,325);
  glVertex2f(350,395);
  glVertex2f(365,395);
  glVertex2f(365,325);
  glEnd();

  glColor3f(0.0,0.5,0.0);
  DrawSegment(340,400,30,0,360);//leaf
  DrawSegment(380,400,30,0,360);
  DrawSegment(350,440,25,0,360);
  DrawSegment(370,440,25,0,360);
  DrawSegment(360,465,20,0,360);
}

void draw_tree()
{
  glPushMatrix();
  glTranslated(50,50,0);
  tree();
  
  glTranslated(200,-280,0);
  glScaled(1.5,1.5,0);
  tree();
  
  glTranslated(-400,50,0);
  glScaled(0.9,0.9,0);
  tree();
  
  glPopMatrix();
}

void train()
{
  rgb(2, 138, 206);//side
  glBegin(GL_POLYGON);
  glVertex2f(10,145);
  glVertex2f(10,180);
  glVertex2f(110,180);
  glVertex2f(110,145);
  glEnd();
  
  rgb(70, 71, 71);//front
  glBegin(GL_POLYGON);
  glVertex2f(110,145);
  glVertex2f(110,180);
  glVertex2f(120,210);
  glVertex2f(120,175);
  glEnd();
  
  rgb(194, 197, 198);//top
  glBegin(GL_POLYGON);
  glVertex2f(10,180);
  glVertex2f(110,180);
  glVertex2f(120,210);
  glVertex2f(20,210);
  glEnd();
  
  glPointSize(15);//window
  glColor3f(1,1,1);
  glBegin(GL_POINTS);
  glVertex2f(25,165);
  glVertex2f(55,165);
  glVertex2f(85,165);
  glEnd();
  
  rgb(0,0,0);
  glLineWidth(4);
  glBegin(GL_LINES);//connecter
  glVertex2f(110,160);
  glVertex2f(116,160);
  glEnd(); 
  
  glBegin(GL_LINES);//connecter
  glVertex2f(116,175);
  glVertex2f(122,175);
  glEnd();
  
  rgb(58, 58, 58);//tires
  DrawSegment(25,145,5,0,360);
  DrawSegment(35,145,5,0,360);
  DrawSegment(45,145,5,0,360);
  DrawSegment(95,145,5,0,360);
  DrawSegment(85,145,5,0,360);
  DrawSegment(75,145,5,0,360); 
}

void draw_train()
{
	int p=7;
	int x=-105*p;
	for(int i=0;i<p;i++)
	{
	  x=x+105;
	  glPushMatrix();
	  glTranslated(x,0,0);
	  train();
	  glPopMatrix();
    }
    glPopMatrix();
}

void bus()
{
  glPointSize(4);//tire
  glColor3f(0,0,0);
  glBegin(GL_POINTS);
  glVertex2f(530,19);
  glVertex2f(569,19);
  glEnd();
  
  rgb(252, 84, 37);//front
  glBegin(GL_POLYGON);
  glVertex2f(520,20);
  glVertex2f(580,20);
  glVertex2f(580,70);
  glVertex2f(520,70);
  glEnd();
  
  rgb(255,255,255);//glass
  glBegin(GL_POLYGON);
  glVertex2f(578,68);
  glVertex2f(578,48);
  glVertex2f(552,48);
  glVertex2f(552,68);
  glEnd();
  glBegin(GL_POLYGON);
  glVertex2f(522,68);
  glVertex2f(522,48);
  glVertex2f(550,48);
  glVertex2f(550,68);
  glEnd();
  
  glBegin(GL_POLYGON);//headlight
  glVertex2f(524,24);
  glVertex2f(524,32);
  glVertex2f(532,32);
  glVertex2f(532,24);
  glEnd();
  glBegin(GL_POLYGON);//headlight
  glVertex2f(576,24);
  glVertex2f(576,32);
  glVertex2f(568,32);
  glVertex2f(568,24);
  glEnd();
  
  rgb(194, 197, 198);//top
  glBegin(GL_POLYGON);
  glVertex2f(520,70);
  glVertex2f(580,70);
  glVertex2f(575,110);
  glVertex2f(525,110);
  glEnd();
  
}

void process()
{
	a+=5;
    if((a>-200 && a<1300))
      flag=0;
    else
      flag=1;  
    
    if(flag==1 || (b>200||b<150))
    {
      b-=2+s;
      s+=0.02;
    }
	if(a>3000)
	 a=-600;
	if(b<-450)
	{
	 s=-2;
	 b=440;
	} 
	 
	gate(6,80);
	
	glPushMatrix();
    glTranslated(605,0,0);
    gate(-6,80);
    glPopMatrix();
    
    if(flag==0)
     road_gate(0,80);
    else
     road_gate(-75,80);
	 
	glPushMatrix();
    glTranslated(b*1.1,b,0);
    glScaled(1-2*b/1000.0,1-2*b/1000.0,0); 
    bus();
    glPopMatrix();
    
	glPushMatrix();
	glTranslated(a,0,0);
    draw_train();  
    glPopMatrix();
    
    gate(0,0);
	
	glPushMatrix();
    glTranslated(605,0,0);
    gate(0,0);
    glPopMatrix();
    
    if(flag==0)
      road_gate(0,0);
    else
     road_gate(-82,0);  
	  
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  if(seq==0)
  {
    start();
  }
  if(seq==1)
  {
	glClearColor(0.1,0.7,0.0,1.0);
	sky();
    sun();
    mountain();
	track();
    road();
    draw_tree();
    process();
  }
  if(seq==2)
  {
	 end(); 
  }
  
  glutPostRedisplay();
  glutSwapBuffers();
}

void myinit()
{
  glClearColor(0.0,0.0,0.0,1.0);
  glPointSize(1.0);
  gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void keys(unsigned char key,int x,int y)
{
	seq+=1;	
	if(seq>2)
	  seq=2;		
}

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize(1100.0,700.0);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Railway");
  glutKeyboardFunc(keys);
  myinit();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
