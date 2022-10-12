#include <windows.h>
#include <GL/glut.h>
#include<math.h>>
#include<stdio.h>
#include <mmsystem.h>
#define PI 3.14159265358979323846
#include <GL/gl.h>
#include <GL/glut.h>

static GLfloat angle=90.0;
static GLint f1=1,f2=1;

GLfloat position1 = 0.0f;//sun
GLfloat speed1 = 0.001f;//sun 0.001

GLfloat position2 = 0.0f;//car1 up
GLfloat speed2 = 0.02f;

GLfloat position3 = 0.0f;//car2 down
GLfloat speed3 = 0.02f;

GLfloat position4 = 0.0f;//bus1 up
GLfloat speed4 = 0.02f;

GLfloat position5 = 0.0f;//bus2 down
GLfloat speed5 = 0.02f;

GLfloat position6 = 0.0f;//plane
GLfloat speed6 = 0.01f;

GLfloat position7 = 0.0f;//boat1
GLfloat speed7 = 0.015f;

GLfloat position8 = 0.0f;//boat2
GLfloat speed8 = 0.015f;

GLfloat position9 = 0.0f;//cloud 1
GLfloat speed9 = 0.004f;

GLfloat position10 = 0.0f;//cloud 2
GLfloat speed10 = 0.004f;

GLfloat position11 = 0.0f;//cloud 3
GLfloat speed11 = 0.004f;

GLfloat position12 = 0.0f;//river motion
GLfloat speed12 = 0.010f;

/*GLfloat positionRain= 0.0f;
GLfloat speedRain= 0.01f;



void updateRain(int value)
{
    if(positionRain < -0.02f)
    {
        positionRain = 0.02f;
    }
    positionRain -= speedRain;
    glutPostRedisplay();
    glutTimerFunc(100, updateRain, 0);
}*/

void update1(int value){//sun

        if(position1 <-1.0)
            position1 = 1.0f;
        position1 -= speed1;

        glutPostRedisplay();
        glutTimerFunc(100, update1, 0);

    }

void update2(int value) {//car 1,

        if(position2 >1.0)
            position2 =-1.0f;

        position2 += speed2;

    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);

    }

void update3(int value){//car 2,

        if(position3 <-1.0)
            position3 = 1.0f;
        position3 -= speed3;

        glutPostRedisplay();
        glutTimerFunc(100, update3, 0);

    }

void update4(int value) {//bus1

        if(position4 >1.0)
            position4 =-1.0f;

        position4 += speed4;

    glutPostRedisplay();
    glutTimerFunc(100, update4, 0);

    }

void update5(int value){//bus2

        if(position5 <-1.0)
            position5 = 1.0f;
        position5 -= speed5;

        glutPostRedisplay();
        glutTimerFunc(100, update5, 0);

    }

void update6(int value){//plane

        if(position6 <-1.0)
            position6 = 1.0f;
        position6 -= speed6;

        glutPostRedisplay();
        glutTimerFunc(100, update6, 0);

    }

void update7(int value) {//boat 1,

        if(position7 >1.0)
            position7 =-1.0f;

        position7 += speed7;

    glutPostRedisplay();
    glutTimerFunc(100, update7, 0);

    }

void update8(int value){//boat 2,

        if(position8 <-1.0)
            position8 = 1.0f;
        position8 -= speed8;

        glutPostRedisplay();
        glutTimerFunc(100, update8, 0);

    }

void update9(int value){//cloud 1

        if(position9 <-1.0)
            position9 = 1.0f;
        position9 -= speed9;

        glutPostRedisplay();
        glutTimerFunc(100, update9, 0);

    }

void update10(int value){//cloud 2

        if(position10 <-1.0)
            position10 = 1.0f;
        position10 -= speed10;

        glutPostRedisplay();
        glutTimerFunc(100, update10, 0);

    }

void update11(int value){//cloud 3

        if(position11 <-1.0)
            position11 = 1.0f;
        position11 -= speed11;

        glutPostRedisplay();
        glutTimerFunc(100, update11, 0);

    }

void update12(int value){//river motion

        if(position12 <-1.0)
            position12 = 1.0f;
        position12 -= speed12;

        glutPostRedisplay();
        glutTimerFunc(100, update12, 0);

    }










void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void shape(void)
{
    glBegin(GL_TRIANGLES);//windmill fan
    glColor3ub(255,255, 0);
    glVertex3f( 0.0, 0.0,0.0);
    glVertex3f( 0.1, 0.1,0.0);
    glVertex3f( 0.0, 0.4,0.0);

    glEnd();
}

void fan(void)
{
    shape();
    glRotatef(90.0, 0.0, 0.0, 1.0);
    shape();
    glRotatef(180.0, 0.0, 0.0, 1.0);
    shape();
    glRotatef(270.0, 0.0, 0.0, 1.0);
    shape();
}

void reshape(int w, int h)
    {
        glViewport(0.0, 0.0, (GLsizei)w, (GLsizei)h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(22.7, 1.0, 1.0, 100.0);///default 22.7
        glMatrixMode(GL_MODELVIEW);
    }

void spinDisplayReverse(void)
    {
        angle-=0.05;
        glutPostRedisplay();
    }

/*void spinDisplay(void)
    {
        angle+=0.1;
        glutPostRedisplay();
    }*/











/*void rain() //horizontal row rain
{
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2f(1.0,1.0);
    glVertex2f(0.995,0.975);

    glVertex2f(0.960,1.0);
    glVertex2f(0.955,0.975);

    glVertex2f(0.920,1.0);
    glVertex2f(0.915,0.98);

     glVertex2f(0.880,1.0);
    glVertex2f(0.875,0.98);

     glVertex2f(0.840,1.0);
    glVertex2f(0.835,0.98);

      glVertex2f(0.800,1.0);
    glVertex2f(0.795,0.98);

     glVertex2f(0.760,1.0);
    glVertex2f(0.755,0.98);

     glVertex2f(0.720,1.0);
    glVertex2f(0.715,0.98);

     glVertex2f(0.680,1.0);
    glVertex2f(0.675,0.98);

     glVertex2f(0.640,1.0);
    glVertex2f(0.635,0.98);

     glVertex2f(0.600,1.0);
    glVertex2f(0.595,0.98);

     glVertex2f(0.560,1.0);
    glVertex2f(0.555,0.98);

     glVertex2f(0.520,1.0);
    glVertex2f(0.515,0.98);

     glVertex2f(0.480,1.0);
    glVertex2f(0.475,0.98);

     glVertex2f(0.440,1.0);
    glVertex2f(0.435,0.98);

     glVertex2f(0.400,1.0);
    glVertex2f(0.395,0.98);

     glVertex2f(0.360,1.0);
    glVertex2f(0.355,0.98);

     glVertex2f(0.320,1.0);
    glVertex2f(0.315,0.98);

     glVertex2f(0.280,1.0);
    glVertex2f(0.275,0.98);

     glVertex2f(0.240,1.0);
    glVertex2f(0.235,0.98);

     glVertex2f(0.200,1.0);
    glVertex2f(0.195,0.98);

     glVertex2f(0.160,1.0);
    glVertex2f(0.155,0.98);

     glVertex2f(0.120,1.0);
    glVertex2f(0.115,0.98);

     glVertex2f(0.080,1.0);
    glVertex2f(0.075,0.98);

     glVertex2f(0.040,1.0);
    glVertex2f(0.035,0.98);

    glVertex2f(0.000,1.0);
    glVertex2f(-0.005,0.98);

    glVertex2f(-0.040,1.0);
    glVertex2f(-0.045,0.98);

    glVertex2f(-0.080,1.0);
    glVertex2f(-0.085,0.98);

    glVertex2f(-0.120,1.0);
    glVertex2f(-0.125,0.98);

    glVertex2f(-0.160,1.0);
    glVertex2f(-0.165,0.98);

    glVertex2f(-0.200,1.0);
    glVertex2f(-0.205,0.98);

    glVertex2f(-0.240,1.0);
    glVertex2f(-0.245,0.98);

    glVertex2f(-0.280,1.0);
    glVertex2f(-0.285,0.98);

    glVertex2f(-0.320,1.0);
    glVertex2f(-0.325,0.98);

    glVertex2f(-0.360,1.0);
    glVertex2f(-0.365,0.98);

    glVertex2f(-0.400,1.0);
    glVertex2f(-0.405,0.98);

    glVertex2f(-0.440,1.0);
    glVertex2f(-0.445,0.98);

    glVertex2f(-0.480,1.0);
    glVertex2f(-0.485,0.98);

    glVertex2f(-0.520,1.0);
    glVertex2f(-0.525,0.98);

    glVertex2f(-0.560,1.0);
    glVertex2f(-0.565,0.98);

    glVertex2f(-0.600,1.0);
    glVertex2f(-0.605,0.98);

    glVertex2f(-0.640,1.0);
    glVertex2f(-0.645,0.98);

    glVertex2f(-0.680,1.0);
    glVertex2f(-0.685,0.98);

    glVertex2f(-0.720,1.0);
    glVertex2f(-0.725,0.98);

    glVertex2f(-0.760,1.0);
    glVertex2f(-0.765,0.98);

    glVertex2f(-0.800,1.0);
    glVertex2f(-0.805,0.98);

    glVertex2f(-0.840,1.0);
    glVertex2f(-0.845,0.98);

    glVertex2f(-0.880,1.0);
    glVertex2f(-0.885,0.98);

    glVertex2f(-0.920,1.0);
    glVertex2f(-0.925,0.98);

    glVertex2f(-0.960,1.0);
    glVertex2f(-0.965,0.98);

    glEnd();

}

void fullrain()
{
    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glTranslatef(0.0,-0.15,0.0);
    rain();

    glFlush();
}


void rainAnimation()
{
    glPushMatrix();
    glTranslatef(positionRain, positionRain, 0.0f);
    fullrain();
    glPopMatrix();
}*/





void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    angle=angle;


    ///========================================================================================sky
    if(position1 <= 0.0)
        {
            glBegin(GL_QUADS);
            glColor3ub(195, 236, 248);
            glVertex2f(-1.0f,-0.05f);
            glVertex2f(1.0f, -0.05f);

            glColor3ub(129, 209, 244);
            glVertex2f(1.0f,1.00f);

            glColor3ub(60, 183, 248);
            glVertex2f(-1.0f,1.00f);

            glEnd();
        }
    else if(position1>= 0.0)
        {
            glBegin(GL_QUADS);
            glColor3ub(35, 35, 35);

            glVertex2f(-1.0f,-0.05f);
            glVertex2f(1.0f, -0.05f);
            glVertex2f(1.0f,1.00f);
            glVertex2f(-1.0f,1.00f);

            glEnd();
        }







    ///=======================================================================================star and moon
    glPushMatrix();

    if(position1>= 0.0)
        {
            glPointSize(5.0);
            glBegin(GL_POINTS);
            glColor3ub(255,204,51);

            glVertex2f(-1.0f, 0.80f);//
            glVertex2f(-0.95f, 0.90f);//
            glVertex2f(-0.90f, 0.85f);//
            glVertex2f(-0.85f, 0.95f);//
            glVertex2f(-0.80f, 0.90f);//
            glVertex2f(-0.75f, 0.80f);//
            glVertex2f(-0.70f, 0.85f);//
            glVertex2f(-0.65f, 0.95f);//
            glVertex2f(-0.60f, 0.90f);//
            glVertex2f(-0.55f, 0.85f);//
            glVertex2f(-0.50f, 0.95f);//
            glVertex2f(-0.45f, 0.85f);//
            glVertex2f(-0.40f, 0.80f);//
            glVertex2f(-0.35f, 0.90f);//
            glVertex2f(-0.30f, 0.95f);//
            glVertex2f(-0.25f, 0.85f);//
            glVertex2f(-0.20f, 0.90f);//
            glVertex2f(-0.15f, 0.80f);//
            glVertex2f(-0.10f, 0.85f);//
            glVertex2f(-0.05f, 0.95f);//
            glVertex2f(0.0f, 0.85f);
            glVertex2f(1.0f, 0.90f);//
            glVertex2f(0.95f, 0.90f);//
            glVertex2f(0.90f, 0.85f);//
            glVertex2f(0.85f, 0.95f);//
            glVertex2f(0.80f, 0.90f);//
            glVertex2f(0.75f, 0.80f);//
            glVertex2f(0.70f, 0.85f);//
            glVertex2f(0.65f, 0.95f);//
            glVertex2f(0.60f, 0.90f);//
            glVertex2f(0.55f, 0.85f);//
            glVertex2f(0.50f, 0.95f);//
            glVertex2f(0.45f, 0.85f);//
            glVertex2f(0.40f, 0.80f);//
            glVertex2f(0.35f, 0.90f);//
            glVertex2f(0.30f, 0.95f);//
            glVertex2f(0.25f, 0.85f);//
            glVertex2f(0.20f, 0.90f);//
            glVertex2f(0.15f, 0.80f);//
            glVertex2f(0.10f, 0.85f);//
            glVertex2f(0.05f, 0.90f);//

            glEnd();


            GLfloat p24 =0.90; GLfloat q24= 0.90; GLfloat r24=0.10;
            int triangle24 = 20;
            GLfloat tp24 = 2.0f * PI;
                glBegin(GL_TRIANGLE_FAN);//chaka1
                    glColor3ub(210,210,210);
                    glVertex2f(p24 , q24); // center of circle
                    for(int i = 0; i <= triangle24;i++) {
                    glVertex2f(
                    p24 + (r24 * cos(i * tp24 / triangle24)),
                    q24 + (r24 * sin(i * tp24 / triangle24))
                    );
            }
            glEnd();
        }

    glPopMatrix();







    ///===================================================================================================sun

    glPushMatrix();
    glTranslatef(0.0f,position1, 0.0f);

    GLfloat p3 =0.90; GLfloat q3 = 0.90; GLfloat r3 =0.10;/// sun
    int triangle3 = 20; //# of triangles used to draw circle
    GLfloat tp3 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);//chaka1
        glColor3ub(255,204,51);
        glVertex2f(p3 , q3); // center of circle
        for(int i = 0; i <= triangle3;i++) {
        glVertex2f(
        p3 + (r3 * cos(i * tp3 / triangle3)),
        q3 + (r3 * sin(i * tp3 / triangle3))
        );
    }
    glEnd();
    glPopMatrix();




    glBegin(GL_TRIANGLES); ///==========================================================================forest
	glColor3ub(0,255,0);
	glVertex2f(-1.0f,0.2f);
	glVertex2f(-0.8f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(-0.9f,0.4f);

	glColor3ub(0,255,0);
	glVertex2f(-0.85f,0.2f);
	glVertex2f(-0.6f, 0.2f);
	glColor3ub(200,0,0);
	glVertex2f(-0.725f,0.5f);

	glColor3ub(0,255,0);
	glVertex2f(-0.65f,0.2f);
	glVertex2f(-0.45f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(-0.55f,0.4f);

    glColor3ub(0,255,0);
	glVertex2f(-0.5f,0.2f);
	glVertex2f(-0.25f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(-0.375f,0.4f);

	glColor3ub(0,255,0);
	glVertex2f(-0.3f,0.2f);
	glVertex2f(-0.05f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(-0.175f,0.5f);

	glColor3ub(0,255,0);
	glVertex2f(-0.1f,0.2f);
	glVertex2f(0.1f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(-0.0f,0.4f);

	glColor3ub(0,255,0);
	glVertex2f(1.05f,0.2f);
	glVertex2f(0.85f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(0.95f,0.4f);

	/*glColor3ub(0,255,0);// 2nd fountain forest
	glVertex2f(0.85f,0.2f);
	glVertex2f(0.6f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(0.725f,0.5f);*/

	/*glColor3ub(0,255,0);
	glVertex2f(0.65f,0.2f);
	glVertex2f(0.45f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(0.55f,0.4f);*/

	glColor3ub(0,255,0);
	glVertex2f(0.3f,0.2f);
	glVertex2f(0.05f, 0.2f);
	glColor3ub(50,255,100);
	glVertex2f(0.175f,0.5f);
	glEnd();




	///===============================================================================fountain forest and fountain
	glPushMatrix();
        glTranslatef(-0.2, -0.12, 0.0);
        glScalef(1.6,1.6,0.0);

        glBegin(GL_TRIANGLES);
        glColor3ub(0,255,0);///fountain forest 1
        glVertex2f(0.5f,0.2f);
        glVertex2f(0.25f, 0.2f);
        glColor3ub(50,255,100);
        glVertex2f(0.375f,0.45f);

        glEnd();
                glLineWidth(4);///fountain
                glBegin(GL_LINES);

                glColor3f(0.2f, 0.6f, 1.0f);
                glVertex2f(0.375f,0.45f);
                glVertex2f(0.385f,0.4f);
                glEnd();

                glLineWidth(5);
                glBegin(GL_LINES);

                glColor3f(0.2f, 0.6f, 1.0f);
                glVertex2f(0.385f,0.4f);
                glVertex2f(0.375f,0.35f);
                glEnd();

                glLineWidth(6);
                glBegin(GL_LINES);

                glColor3f(0.2f, 0.6f, 1.0f);
                glVertex2f(0.395f,0.25f);
                glVertex2f(0.375f,0.35f);
                glEnd();

                glLineWidth(7);
                glBegin(GL_LINES);

                glColor3f(0.2f, 0.6f, 1.0f);
                glVertex2f(0.395f,0.25f);
                glVertex2f(0.37f,0.2f);
                glEnd();
        glLoadIdentity();
        glPopMatrix();





    ///===============================================================================fountain forest and fountain 2
	glPushMatrix();
        glTranslatef(-0.6, -0.14, 0.0);
        glScalef(1.8,1.7,0.0);

        glBegin(GL_TRIANGLES);
        glColor3ub(0,255,0);// 2nd fountain forest
        glVertex2f(0.85f,0.2f);
        glVertex2f(0.6f, 0.2f);
        glColor3ub(50,255,100);
        glVertex2f(0.725f,0.5f);

        glEnd();

                glBegin(GL_POLYGON);
                glColor3ub(55, 190, 220);

                glVertex2f(0.725f,0.5f);
                glVertex2f(0.710f, 0.2f);
                glVertex2f(0.740f, 0.2f);
                glVertex2f(0.725f, 0.5f);
                glEnd();

        glLoadIdentity();
        glPopMatrix();






    glBegin(GL_QUADS); ///=================================================================================river
	glColor3ub(55, 190, 255);
	//glColor3ub(0, 255, 255);
	glVertex2f(-1.0f,-0.05f);
	glVertex2f(1.0f, -0.05f);
	glVertex2f(1.0f,0.2f);
	glVertex2f(-1.0f,0.2f);
    glEnd();





    glPushMatrix();///================================================================================river water flow
    glTranslatef(position12,0.0f, 0.0f);
    glLineWidth(0.3);

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.5f, 0.15f);
    glVertex2f(-0.2f, 0.15f);

    glVertex2f(0.0f, 0.15f);
    glVertex2f(0.3f, 0.15f);

    glVertex2f(0.5f, 0.15f);
    glVertex2f(0.7f, 0.15f);

    glVertex2f(-0.8f, 0.15f);
    glVertex2f(-0.65f, 0.15f);

    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-0.1f, 0.0f);

    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.35f, 0.0f);

    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.8f, 0.0f);

    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.8f, 0.0f);

    glVertex2f(-0.2f, 0.075f);
    glVertex2f(0.1f, 0.075f);

    glVertex2f(0.3f, 0.075f);
    glVertex2f(0.6f, 0.075f);

    glVertex2f(-0.4f, 0.075f);
    glVertex2f(-0.7f, 0.075f);

    glVertex2f(0.9f, 0.075f);
    glVertex2f(0.7f, 0.075f);

    glVertex2f(-0.8f, 0.075f);
    glVertex2f(-.95f, 0.075f);

    glEnd();
    glPopMatrix();





    glBegin(GL_QUADS); ///===========================================================================ground
	glColor3ub(0, 200, 0);
	glVertex2f(-1.0f,-0.05f);
	glVertex2f(-1.0f, -0.35f);
	glVertex2f(1.0f, -0.35f);
	glVertex2f(1.0f, -0.05f);

    glEnd();





    ///===========================================================================boat2*/
	glPushMatrix();
	glTranslatef(position8,0.0f, 0.0f);

	glTranslatef(1.0, 0.37, 0.0);
    glScalef(0.4,0.4,0.0);

	glBegin(GL_POLYGON);//boat2
	glColor3f(0.4, 0.0, 0.0);
	glVertex2f(-0.833f, -0.66f);
	glVertex2f(-0.33f, -0.66f);
	glVertex2f(-0.25f, -0.583f);
	glVertex2f(-0.916f, -0.583f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(242, 244, 244);
	glVertex2f(-0.833f, -0.583f);
	glVertex2f(-0.33f, -0.583f);
	glVertex2f(-0.416f, -0.5f);
	glVertex2f(-0.75f, -0.5f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(212, 172, 13);
	glVertex2f(-0.66f, -0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.583f, -0.33f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-0.583f, -0.33f);
	glVertex2f(-0.583f, -0.166f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.583f, -0.283);
	glVertex2f(-0.55f, -0.25f);
	glVertex2f(-0.583f, -0.2166f);
	glEnd();

	glBegin(GL_POLYGON);////Boatwindows//
	glColor3ub(164,64,64);
	glVertex2f(-0.75f, -0.566f);
	glVertex2f(-0.7f, -0.566f);
	glVertex2f(-0.7, -0.516f);
	glVertex2f(-0.75f, -0.516f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(164,64,64);
	glVertex2f(-0.633f, -0.566f);
	glVertex2f(-0.583f, -0.566f);
	glVertex2f(-0.583, -0.516f);
	glVertex2f(-0.633f, -0.516f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(164,64,64);
	glVertex2f(-0.516f, -0.566f);
	glVertex2f(-0.46f, -0.566f);
	glVertex2f(-0.46f, -0.516f);
	glVertex2f(-0.516f, -0.516f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.56, 0.698);
	glVertex2f(-0.833f, -0.6833f);
	glVertex2f(-0.33f, -0.6833f);
	glVertex2f(-0.33f, -0.66f);
	glVertex2f(-0.833f, -0.66f);
	glEnd();
	glLoadIdentity();
	glPopMatrix();






	///****=====================================================================boat1*/
	glPushMatrix();
	glTranslatef(position7,0.0f, 0.0f);

    glTranslatef(-0.25, 0.3, 0.0);
    glScalef(0.4,0.4,0.0);

    glBegin(GL_QUADS);

    glColor3ub(181,61,45);
    glVertex2f(-0.95f, -0.7f);
    glVertex2f( -0.85f, -0.8f);
    glVertex2f( -0.5f,  -0.8f);
    glVertex2f(-0.4f,  -0.7f);

    glColor3ub(245,193,7);
    glVertex2f(-0.7f, -0.7f);
    glVertex2f( -0.5f, -0.7f);
    glVertex2f( -0.5f,  -0.65f);
    glVertex2f(-0.7f,  -0.65f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.8f, -0.65f);
    glVertex2f( -0.7f, -0.625f);
    glVertex2f( -0.7f,  -0.4f);

    glVertex2f(-0.75f, -0.65f);
    glVertex2f( -0.65f, -0.625f);
    glVertex2f( -0.65f,  -0.35f);

    glVertex2f(-0.625f, -0.625f);
    glVertex2f( -0.54f, -0.66f);
    glVertex2f( -0.625f,  -0.35f);

    glEnd();

    glLoadIdentity();
    glPopMatrix();




	/**==========================================================================plane*/
	glPushMatrix();
	glTranslatef(position6,0.0f, 0.0f);

	glBegin(GL_TRIANGLES);//plane front
	glColor3ub(96, 96, 96);
	glVertex2f(.38, .65);
	glVertex2f(.40, .62);
	glVertex2f(.40, .68);
	glEnd();

	glBegin(GL_POLYGON);//plane body
	glColor3ub(179, 177, 234);
	glVertex2f(.40, .62);
	glVertex2f(.49, .62);
	glVertex2f(.52, .71);
	glVertex2f(.50, .71);
	glVertex2f(.49, .68);
	glVertex2f(.40, .68);
	glEnd();


	glBegin(GL_QUADS);//plane wing upper
	glColor3ub(179, 177, 234);
	glVertex2f(.44, .68);
	glVertex2f(.46, .68);
	glVertex2f(.47, .71);
	glVertex2f(.45, .71);
	glEnd();

	glBegin(GL_QUADS);//plane wing lower
	glColor3ub(179, 177, 234);
	glVertex2f(.44, .62);
	glVertex2f(.46, .62);
	glVertex2f(.47, .58);
	glVertex2f(.45, .58);
	glEnd();

	glLoadIdentity();
	glPopMatrix();




    ///==================================================================================windmill 1
    glPushMatrix();

    glTranslatef(-0.3, 0.2, 0.0);
    glScalef(0.45,0.45,0.0);

    glBegin(GL_QUADS);//windmill stand
    glColor3ub(255, 255, 255);
    glVertex2f(-0.32f, 0.0f);
    glVertex2f( -0.32f, 0.6f);
    glVertex2f( -0.338f,  0.6f);
    glVertex2f(-0.338f,  0.0f);

    glEnd();

    GLfloat p1=-0.33f;  GLfloat q1= 0.59f;  GLfloat r1 = 0.03f;
    int triangle1=40;
    GLfloat tp1 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 224, 23, 16);
    glVertex2f (p1,q1);
    for(int i= 0;i<=triangle1; i++)
    {
        glVertex2f (
                    p1+(r1*cos(i*tp1/triangle1)),
                    q1+(r1*sin(i*tp1/triangle1))
                    );
    }
    glEnd ();

    glPopMatrix();





    ///==================================================================================windmill 2
    glPushMatrix();

    glTranslatef(-0.1, 0.2, 0.0);
    glScalef(0.45,0.45,0.0);

    glBegin(GL_QUADS);//windmill stand
    glColor3ub(255, 255, 255);
    glVertex2f(-0.32f, 0.0f);
    glVertex2f( -0.32f, 0.6f);
    glVertex2f( -0.338f,  0.6f);
    glVertex2f(-0.338f,  0.0f);

    glEnd();

    GLfloat p2=-0.33f;  GLfloat q2= 0.59f;  GLfloat r2 = 0.03f;
    int triangle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 224, 23, 16);
    glVertex2f (p2,q2);
    for(int i= 0;i<=triangle2; i++)
    {
        glVertex2f (
                    p2+(r2*cos(i*tp2/triangle2)),
                    q2+(r2*sin(i*tp2/triangle2))
                    );
    }
    glEnd ();

    glPopMatrix();






    ///=====================================================================================windmill fan
    if (f1==1)
    {
        //glutPostRedisplay();
        glPushMatrix();
        glColor3f(1.0f, 1.0f, 0.0f);
        glScalef(0.2, 0.2, 0.2);
        glTranslatef(-1.05, 1.95, 4.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        fan();
        glPopMatrix();
    }

    //(-x,-y)
    if (f2==1)
    {
        //glutPostRedisplay();
        glPushMatrix();
        glScalef(0.3, 0.3, 0.3);
        glTranslatef(-1.855, 1.92, -4.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        fan();
        glPopMatrix();
    }






    ///======================================================================================  road
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f( 1.0f, -0.8f);
    glVertex2f( 1.0f, -0.35f);
    glVertex2f(-1.0f, -0.35f);

    glEnd();

        glLineWidth(2.5);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f,-0.575f);
        glVertex2f(1.0f,-0.575f);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(0.95f,-0.8f);
        glVertex2f(0.8f,-0.8f);

        glVertex2f(0.95f,-0.75f);
        glVertex2f(0.8f,-0.75f);

        glVertex2f(0.95f,-0.70f);
        glVertex2f(0.8f,-0.70f);

        glVertex2f(0.95f,-0.65f);
        glVertex2f(0.8f,-0.65f);

        glVertex2f(0.95f,-0.6f);
        glVertex2f(0.8f,-0.6f);

        glVertex2f(0.95f,-0.55f);
        glVertex2f(0.8f,-0.55f);

        glVertex2f(0.95f,-0.50f);
        glVertex2f(0.8f,-0.50f);

        glVertex2f(0.95f,-0.45f);
        glVertex2f(0.8f,-0.45f);

        glVertex2f(0.95f,-0.40f);
        glVertex2f(0.8f,-0.40f);

        glVertex2f(0.95f,-0.35f);
        glVertex2f(0.8f,-0.35f);


        glEnd();

    glPopMatrix();






    ///======================================================================================stop sign and bus stop
    glPushMatrix();

    glTranslatef(0.75, 0.0, 0.0);
    glScalef(0.04 ,0.06,0.0);

	GLfloat p25 =0.0; GLfloat q25= 0.0; GLfloat r25=1.0;
    int triangle25 = 20;
    GLfloat tp25 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,0,0);
            glVertex2f(p25 , q25); // center of circle
            for(int i = 0; i <= triangle25;i++) {
            glVertex2f(
            p25 + (r25 * cos(i * tp25 / triangle25)),
            q25 + (r25 * sin(i * tp25 / triangle25))
            );
    }
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub ( 255, 255, 255);

    glVertex2f(-0.5f,0.4f);
    glVertex2f(-0.8f,0.4f);

    glVertex2f(-0.8f,0.4f);
    glVertex2f(-0.8f,0.0f);

    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.8f,0.0f);

    glVertex2f(-0.5f,-0.4f);
    glVertex2f(-0.5f,0.0f);

    glVertex2f(-0.5f,-0.4f);
    glVertex2f(-0.8f,-0.4f);


    glVertex2f(-0.1f,0.4f);
    glVertex2f(-0.4f,0.4f);

    glVertex2f(-0.25f,0.4f);
    glVertex2f(-0.25f,-0.4f);


    glVertex2f(0.0f,0.4f);
    glVertex2f(0.3f,0.4f);

    glVertex2f(0.0f,-0.4f);
    glVertex2f(0.3f,-0.4f);

    glVertex2f(0.0f,0.4f);
    glVertex2f(0.0f,-0.4f);

    glVertex2f(0.3f,-0.4f);
    glVertex2f(0.3f,0.4f);


    glVertex2f(0.4f,0.4f);
    glVertex2f(0.7f,0.4f);

    glVertex2f(0.4f,0.4f);
    glVertex2f(0.4f,-0.4f);

    glVertex2f(0.7f,0.4f);
    glVertex2f(0.7f,0.0f);

    glVertex2f(0.4f,0.0f);
    glVertex2f(0.7f,0.0f);

    glEnd();

    glPopMatrix();

	glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub ( 255, 255, 255);

    glVertex2f(0.75f,-0.3f);
    glVertex2f(0.75f,-0.05f);

    glEnd();







    ///====================================================================================bench
    glPushMatrix();

    glTranslatef(0.55, 0.05, 0.0);
    glScalef(0.85 ,0.85,0.0);

    //Piller 1
       glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.286f,-0.365f);
          glVertex2f(0.276f,-0.365f);
          glVertex2f(0.276f,-0.18f);
          glVertex2f(0.286f,-0.18f);
       glEnd();

     //Piller 2

      glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.486f,-0.365f);
          glVertex2f(0.476f,-0.365f);
          glVertex2f(0.476f,-0.18f);
          glVertex2f(0.486f,-0.18f);
       glEnd();

    //Piller 3

      glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.27f,-0.4f);
          glVertex2f(0.259f,-0.4f);
          glVertex2f(0.259f,-0.315f);
          glVertex2f(0.27f,-0.315f);
       glEnd();

    //Piller 4

      glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.499f,-0.4f);
          glVertex2f(0.489f,-0.4f);
          glVertex2f(0.489f,-0.315f);
          glVertex2f(0.499f,-0.315f);
       glEnd();

    //Bench Sit 1

    glBegin(GL_QUADS);
          glColor3ub(135, 0, 0);
          glVertex2f(0.506f,-0.32f);
          glVertex2f(0.25f,-0.32f);
          glVertex2f(0.275f,-0.26f);
          glVertex2f(0.49f,-0.26f);
       glEnd();

    // Bench Wood Upper 3

    glBegin(GL_QUADS);
          glColor3ub(135, 0, 0);
          glVertex2f(0.49f,-0.19f);
          glVertex2f(0.27f,-0.19f);
          glVertex2f(0.27f,-0.16f);
          glVertex2f(0.49f,-0.16f);
       glEnd();

    // Bench Wood Upper 2

    glBegin(GL_QUADS);
          glColor3ub(135, 0, 0);
          glVertex2f(0.49f,-0.23f);
          glVertex2f(0.27f,-0.23f);
          glVertex2f(0.27f,-0.20f);
          glVertex2f(0.49f,-0.20f);
       glEnd();

       // Bench Wood Upper 1

    glBegin(GL_QUADS);
          glColor3ub(135,0,0);
          glVertex2f(0.49f,-0.255f);
          glVertex2f(0.27f,-0.255f);
          glVertex2f(0.27f,-0.24f);
          glVertex2f(0.49f,-0.24f);
       glEnd();

    /*
    //Right Bench

    //Piller 21
       glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.548f,-0.365f);
          glVertex2f(0.539f,-0.365f);
          glVertex2f(0.539f,-0.18f);
          glVertex2f(0.548f,-0.18f);
       glEnd();

     //Piller 22

      glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.752f,-0.365f);
          glVertex2f(0.744f,-0.365f);
          glVertex2f(0.744f,-0.18f);
          glVertex2f(0.752f,-0.18f);
       glEnd();

    //Piller 23

    glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.53f,-0.4f);
          glVertex2f(0.519f,-0.4f);
          glVertex2f(0.519f,-0.315f);
          glVertex2f(0.53f,-0.315f);
       glEnd();

    //Piller 2 4

      glBegin(GL_QUADS);
          glColor3ub(44, 62, 80);
          glVertex2f(0.768f,-0.4f);
          glVertex2f(0.758f,-0.4f);
          glVertex2f(0.758f,-0.315f);
          glVertex2f(0.768f,-0.315f);
       glEnd();

    //Bench Sit 2

    glBegin(GL_QUADS);
          glColor3ub(135, 54, 0);
          glVertex2f(0.776f,-0.32f);
          glVertex2f(0.51f,-0.32f);
          glVertex2f(0.538f,-0.26f);
          glVertex2f(0.75f,-0.26f);
       glEnd();

    // Bench Wood Upper 2 3

    glBegin(GL_QUADS);
          glColor3ub(135, 54, 0);
          glVertex2f(0.757f,-0.19f);
          glVertex2f(0.534f,-0.19f);
          glVertex2f(0.534f,-0.16f);
          glVertex2f(0.757f,-0.16f);
       glEnd();

    // Bench Wood Upper 2 2

    glBegin(GL_QUADS);
          glColor3ub(135, 54, 0);
          glVertex2f(0.757f,-0.23f);
          glVertex2f(0.534f,-0.23f);
          glVertex2f(0.534f,-0.20f);
          glVertex2f(0.757f,-0.20f);
       glEnd();


       // Bench Wood Upper 2 1

    glBegin(GL_QUADS);
          glColor3ub(135, 54, 0);
          glVertex2f(0.757f,-0.255f);
          glVertex2f(0.534f,-0.255f);
          glVertex2f(0.534f,-0.24f);
          glVertex2f(0.757f,-0.24f);
       glEnd();
    */

    glPopMatrix();







    ///======================================================================================  side road
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3ub(255, 100, 0);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f( 1.0f, -1.0f);
    glVertex2f( 1.0f, -0.8f);

    glEnd();


    for (float i = 1.0f; i>= -1.0f; i-= 0.050f)
    {
       for (float j = -1.0f; j<= -0.8f; j+= 0.05f)
       {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // Red
        glVertex2f(i, -0.8);
        glVertex2f(i, -1);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // Red
        glVertex2f(1, j);
        glVertex2f(-1, j);
        glEnd();

       }
    }

    glPopMatrix();









    ///======================================================================================  car1
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);

    glTranslatef(-0.7, -0.5, 0.0);
    glScalef(0.33,0.43,0.0);

    glBegin(GL_POLYGON);///car body
    glColor3ub(255, 0, 0);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.35f, 0.0f);
    glVertex2f( 0.4f, 0.05f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.38f, 0.165f);
    glVertex2f(0.35f, 0.2f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.5f, 0.4f);
    glVertex2f(-0.57f, 0.365f);
    glVertex2f(-0.6f, 0.3f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.57f, 0.05f);
    glEnd();


    glBegin(GL_POLYGON);///back window
    glColor3ub(255,255,255);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.35f, 0.3f);
    glVertex2f(-0.45f, 0.3f);
    glVertex2f(-0.48f, 0.28f);
    glVertex2f(-0.5f, 0.25f);
    glVertex2f(-0.5f, 0.2f);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);///window front
    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.125f, 0.3f);
    glVertex2f(-0.125f, 0.2f);

    glVertex2f(-0.15f, 0.2f);///window middle
    glVertex2f(-0.15f, 0.3f);
    glVertex2f(-0.325f, 0.3f);
    glVertex2f(-0.325f, 0.2f);

    glVertex2f(0.4f, 0.06f);///front light
    glVertex2f(0.4f, 0.13f);
    glVertex2f(0.38f, 0.13f);
    glVertex2f(0.38f, 0.06f);

    glVertex2f(-0.6f, 0.1f);///back light
    glVertex2f(-0.6f, 0.17f);
    glVertex2f(-0.58f, 0.17f);
    glVertex2f(-0.58f, 0.1f);

    glEnd();


    GLfloat p12= 0.2f;  GLfloat q12= 0.0f;  GLfloat r12 = 0.1f;
    int triangle12=40;
    GLfloat tp12 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p12,q12);
    for(int i= 0;i<=triangle12; i++)
    {
        glVertex2f (
                    p12+(r12*cos(i*tp12/triangle12)),
                    q12+(r12*sin(i*tp12/triangle12))
                    );
    }
    glEnd ();

    GLfloat p13= -0.4f;  GLfloat q13= 0.0f;  GLfloat r13 = 0.1f;
    int triangle13=40;
    GLfloat tp13 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p13,q13);
    for(int i= 0;i<=triangle13; i++)
    {
        glVertex2f (
                    p13+(r13*cos(i*tp13/triangle13)),
                    q13+(r13*sin(i*tp13/triangle13))
                    );
    }
    glEnd ();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.12f,0.0f);
    glVertex2f(0.28f,0.0f);

    glVertex2f(0.2f,0.08f);
    glVertex2f(0.2f,-0.08f);

    glVertex2f(-0.32f,0.0f);
    glVertex2f(-0.48f,0.0f);

    glVertex2f(-0.4f,0.08f);
    glVertex2f(-0.4f,-0.08f);

    glEnd();


    if(position1>= 0.0)
        {
            glBegin(GL_TRIANGLES);
            glColor3ub ( 255, 255, 0);

            glVertex2f(0.4f,0.1f);
            glVertex2f(0.8f,0.03f);
            glVertex2f(0.8f,0.17f);

            glEnd();
        }



    glPopMatrix();






    ///======================================================================================  car2
    glPushMatrix();
    glTranslatef(position3,0.0f, 0.0f);

    glTranslatef(-0.3, -0.75, 0.0);
    glScalef(0.33,0.43,0.0);

    glBegin(GL_POLYGON);///car body
    glColor3ub(255 ,165 ,0);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(-0.35f, 0.0f);
    glVertex2f( -0.4f, 0.05f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.38f, 0.165f);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.0f, 0.4f);
    glVertex2f(0.5f, 0.4f);
    glVertex2f(0.57f, 0.365f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.57f, 0.05f);
    glEnd();


    glBegin(GL_POLYGON);///back window
    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.2f);
    glVertex2f(0.35f, 0.3f);
    glVertex2f(0.45f, 0.3f);
    glVertex2f(0.48f, 0.28f);
    glVertex2f(0.5f, 0.25f);
    glVertex2f(0.5f, 0.2f);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);///window front
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.0f, 0.3f);
    glVertex2f(0.125f, 0.3f);
    glVertex2f(0.125f, 0.2f);

    glVertex2f(0.15f, 0.2f);///window middle
    glVertex2f(0.15f, 0.3f);
    glVertex2f(0.325f, 0.3f);
    glVertex2f(0.325f, 0.2f);

    glVertex2f(-0.4f, 0.06f);///front light
    glVertex2f(-0.4f, 0.13f);
    glVertex2f(-0.38f, 0.13f);
    glVertex2f(-0.38f, 0.06f);

    glVertex2f(0.6f, 0.1f);///back light
    glVertex2f(0.6f, 0.17f);
    glVertex2f(0.58f, 0.17f);
    glVertex2f(0.58f, 0.1f);

    glEnd();


    GLfloat p14= -0.2f;  GLfloat q14= 0.0f;  GLfloat r14 = 0.1f;
    int triangle14=40;
    GLfloat tp14 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p14,q14);
    for(int i= 0;i<=triangle14; i++)
    {
        glVertex2f (
                    p14+(r14*cos(i*tp14/triangle14)),
                    q14+(r14*sin(i*tp14/triangle14))
                    );
    }
    glEnd ();

    GLfloat p15= 0.4f;  GLfloat q15= 0.0f;  GLfloat r15= 0.1f;
    int triangle15=40;
    GLfloat tp15 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p15,q15);
    for(int i= 0;i<=triangle15; i++)
    {
        glVertex2f (
                    p15+(r15*cos(i*tp15/triangle15)),
                    q15+(r15*sin(i*tp15/triangle15))
                    );
    }
    glEnd ();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.12f,0.0f);
    glVertex2f(-0.28f,0.0f);

    glVertex2f(-0.2f,0.08f);
    glVertex2f(-0.2f,-0.08f);

    glVertex2f(0.32f,0.0f);
    glVertex2f(0.48f,0.0f);

    glVertex2f(0.4f,0.08f);
    glVertex2f(0.4f,-0.08f);

    glEnd();


    if(position1>= 0.0)
        {
            glBegin(GL_TRIANGLES);
            glColor3ub ( 255, 255, 0);

            glVertex2f(-0.4f,0.1f);
            glVertex2f(-0.8f,0.03f);
            glVertex2f(-0.8f,0.17f);

            glEnd();
        }


    glPopMatrix();







    ///===========================================================================gackground home
    /*glPushMatrix();
    glBegin(GL_QUADS); ///back ground home
	glColor3ub(108, 178, 203);
	glVertex2f(-1.0f,-0.05f);
	glVertex2f(1.0f, -0.05f);
	glVertex2f(1.0f,0.20f);
	glVertex2f(-1.0f,0.20f);
    glEnd();


    glBegin(GL_QUADS); ///back ground home1
	glColor3ub(108, 178, 203);
	glVertex2f(-1.0f,0.20f);
	glVertex2f(-0.90f, 0.20f);
	glVertex2f(-0.90f,0.27f);
	glVertex2f(-1.0f,0.27f);
    glEnd();


     glBegin(GL_QUADS); ///back ground home 2
	glColor3ub(108, 178, 203);
	glVertex2f(-0.80f,0.20f);
	glVertex2f(-0.50f,0.20f);
	glVertex2f(-0.50f,0.35f);
	glVertex2f(-0.80f,0.35f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 3
	glColor3ub(108, 178, 203);
	glVertex2f(-0.48f,0.20f);
	glVertex2f(-0.40f,0.20f);
	glVertex2f(-0.40f,0.40f);
	glVertex2f(-0.48f,0.40f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 4
	glColor3ub(108, 178, 203);
	glVertex2f(-0.40f,0.20f);
	glVertex2f(-0.35f,0.20f);
	glVertex2f(-0.35f,0.30f);
	glVertex2f(-0.40f,0.30f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 7
	glColor3ub(108, 178, 203);
	glVertex2f(-0.30f,0.20f);
	glVertex2f(-0.07f,0.20f);
	glVertex2f(-0.07f,0.30f);
	glVertex2f(-0.30f,0.30f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 5
	glColor3ub(108, 178, 203);
	glVertex2f(-0.33f,0.20f);
	glVertex2f(-0.20f,0.20f);
	glVertex2f(-0.20f,0.35f);
	glVertex2f(-0.33f,0.35f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 6
	glColor3ub(108, 178, 203);
	glVertex2f(-0.19f,0.20f);
	glVertex2f(-0.08f,0.20f);
	glVertex2f(-0.08f,0.40f);
	glVertex2f(-0.19f,0.40f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 2
	glColor3ub(108, 178, 203);
	glVertex2f(0.80f,0.20f);
	glVertex2f(0.50f,0.20f);
	glVertex2f(0.50f,0.35f);
	glVertex2f(0.80f,0.35f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 3
	glColor3ub(108, 178, 203);
	glVertex2f(0.48f,0.20f);
	glVertex2f(0.40f,0.20f);
	glVertex2f(0.40f,0.40f);
	glVertex2f(0.48f,0.40f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 4
	glColor3ub(108, 178, 203);
	glVertex2f(0.40f,0.20f);
	glVertex2f(0.35f,0.20f);
	glVertex2f(0.35f,0.30f);
	glVertex2f(0.40f,0.30f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 7
	glColor3ub(108, 178, 203);
	glVertex2f(0.30f,0.20f);
	glVertex2f(0.07f,0.20f);
	glVertex2f(0.07f,0.30f);
	glVertex2f(0.30f,0.30f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 5
	glColor3ub(108, 178, 203);
	glVertex2f(0.33f,0.20f);
	glVertex2f(0.20f,0.20f);
	glVertex2f(0.20f,0.35f);
	glVertex2f(0.33f,0.35f);
    glEnd();

    glBegin(GL_QUADS); ///back ground home 6
	glColor3ub(108, 178, 203);
	glVertex2f(0.19f,0.20f);
	glVertex2f(0.08f,0.20f);
	glVertex2f(0.08f,0.40f);
	glVertex2f(0.19f,0.40f);
    glEnd();
    glPopMatrix();*/



    ///===========================================================================================the house in front
    //========================================================================================================

    glPushMatrix();
    glTranslatef(-0.16, -0.12, 0.0);
    glScaled(0.85,0.85,0.0);


    glBegin(GL_QUADS); ///front home1
	glColor3ub(207, 202, 162);
	glVertex2f(-0.70f,-0.18f);
	glVertex2f(-0.95f,- 0.18f);
	glVertex2f(-0.95f,-0.10f);
	glVertex2f(-0.70f,-0.10f);
    glEnd();


      glBegin(GL_QUADS); ///front home
	glColor3ub(236, 238, 225);
	glVertex2f(-0.70f,-0.10f);
	glVertex2f(-0.95f,- 0.10f);
	glVertex2f(-0.95f,0.15f);
	glVertex2f(-0.70f,0.15f);
    glEnd();



    glBegin(GL_QUADS); ///front home chal
	glColor3ub(242, 152, 45);
	glVertex2f(-0.65f,0.15f);
	glVertex2f(-0.96f, 0.15f);
	glVertex2f(-0.88f,0.29f);
	glVertex2f(-0.65f,0.29f);
    glEnd();

    glBegin(GL_QUADS); ///front home hind
	glColor3ub(219, 226, 215);
	glVertex2f(-0.72f,-0.20f);
	glVertex2f(-0.55f, -0.20f);
	glVertex2f(-0.55f,0.15f);
	glVertex2f(-0.72f,0.15f);
    glEnd();

    glBegin(GL_QUADS); ///front home
	glColor3ub(244, 249, 238);
	glVertex2f(-0.71f,-0.20f);
	glVertex2f(-0.50f, -0.20f);
	glVertex2f(-0.50f,0.15f);
	glVertex2f(-0.71f,0.15f);
    glEnd();


    glBegin(GL_TRIANGLES); ///front home chal hide
	glColor3ub(228,132,0);
	glVertex2f(-0.74f,0.15f);
	glVertex2f(-0.54f, 0.15f);
	glVertex2f(-0.63f,0.33f);
	glEnd();



    glBegin(GL_TRIANGLES); ///front home chal
	glColor3ub(226, 154, 60);
	glVertex2f(-0.72f,0.15f);
	glVertex2f(-0.490f, 0.15f);
	glVertex2f(-0.61f,0.38f);
	glEnd();


	glBegin(GL_TRIANGLES); ///front home get up
	glColor3ub(244, 249, 238);
	glVertex2f(-0.71f,0.15f);
	glVertex2f(-0.51f, 0.15f);
	glVertex2f(-0.61f,0.33f);
	glEnd();



    glBegin(GL_QUADS); ///front home chal
	glColor3ub(237, 237, 236);
	glVertex2f(-0.80f,0.25f);
	glVertex2f(-0.73f, 0.25f);
	glVertex2f(-0.73f,0.34f);
	glVertex2f(-0.80f,0.34f);
    glEnd();

    glBegin(GL_QUADS); ///front home chal ar opr
	glColor3ub(130, 77, 53);
	glVertex2f(-0.81f,0.33f);
	glVertex2f(-0.72f, 0.33f);
	glVertex2f(-0.72f,0.36f);
	glVertex2f(-0.81f,0.36f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 1
	glColor3ub(115, 77, 38);
	glVertex2f(-0.88f,0.0f);
	glVertex2f(-0.935f,0.0f);
	glVertex2f(-0.935f,-0.08f);
	glVertex2f(-0.88f,-0.08f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 1
	glColor3ub(150, 220, 244);
	glVertex2f(-0.885f,-0.01f);
	glVertex2f(-0.93f,-0.01f);
	glVertex2f(-0.93f,-0.07f);
	glVertex2f(-0.885f,-0.07f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 2
	glColor3ub(115, 77, 38);
	glVertex2f(-0.86f,0.0f);
	glVertex2f(-0.80f,0.0f);
	glVertex2f(-0.80f,-0.08f);
	glVertex2f(-0.86f,-0.08f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 2
	glColor3ub(150, 220, 244);
	glVertex2f(-0.855f,-0.01f);
	glVertex2f(-0.805f,-0.01f);
	glVertex2f(-0.805f,-0.07f);
	glVertex2f(-0.855f,-0.07f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 3
	glColor3ub(115, 77, 38);
	glVertex2f(-0.785f,0.0f);
	glVertex2f(-0.73f,0.0f);
	glVertex2f(-0.73f,-0.08f);
	glVertex2f(-0.785f,-0.08f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 3
	glColor3ub(150, 220, 244);
	glVertex2f(-0.78f,-0.01f);
	glVertex2f(-0.735f,-0.01f);
	glVertex2f(-0.735f,-0.07f);
	glVertex2f(-0.78f,-0.07f);
    glEnd();

     glBegin(GL_QUADS); ///front home1 window 4
	glColor3ub(115, 77, 38);
	glVertex2f(-0.785f,0.03f);
	glVertex2f(-0.73f,0.03f);
	glVertex2f(-0.73f,0.11f);
	glVertex2f(-0.785f,0.11f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 4
	glColor3ub(150, 220, 244);
	glVertex2f(-0.78f,0.04f);
	glVertex2f(-0.735f,0.04f);
	glVertex2f(-0.735f,0.10f);
	glVertex2f(-0.78f,0.10f);
    glEnd();



    glBegin(GL_QUADS); ///front home1 window 5
	glColor3ub(115, 77, 38);
	glVertex2f(-0.86f,0.03f);
	glVertex2f(-0.80f,0.03f);
	glVertex2f(-0.80f,0.11f);
	glVertex2f(-0.86f,0.11f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 5
	glColor3ub(150, 220, 244);
	glVertex2f(-0.855f,0.04f);
	glVertex2f(-0.805f,0.04f);
	glVertex2f(-0.805f,0.10f);
	glVertex2f(-0.855f,0.10f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 6
	glColor3ub(115, 77, 38);
	glVertex2f(-0.88f,0.03f);
	glVertex2f(-0.935f,0.03f);
	glVertex2f(-0.935f,0.11f);
	glVertex2f(-0.88f,0.11f);
    glEnd();

    glBegin(GL_QUADS); ///front home1 window 6
	glColor3ub(150, 220, 244);
	glVertex2f(-0.885f,0.04f);
	glVertex2f(-0.93f,0.04f);
	glVertex2f(-0.93f,0.10f);
	glVertex2f(-0.885f,0.10f);
    glEnd();
    ///////////////////////////////////////////////////////
    glLineWidth(03); ///window
   glBegin(GL_LINES);
   glColor3ub(115, 77, 38);
/// window 1
    glVertex2f(-0.91f,-0.01f);
	glVertex2f(-0.91f,-0.08f);

	glVertex2f(-0.935f,-0.04f);
	glVertex2f(-0.88f,-0.04f);
/// window 2
	glVertex2f(-0.83f,-0.01f);
	glVertex2f(-0.83f,-0.08f);

	glVertex2f(-0.80f,-0.04f);
	glVertex2f(-0.86f,-0.04f);
/// window 3
    glVertex2f(-0.76f,-0.01f);
	glVertex2f(-0.76f,-0.08f);

	glVertex2f(-0.73f,-0.04f);
	glVertex2f(-0.785f,-0.04f);

/// window 4

    glVertex2f(-0.76f,0.04f);
	glVertex2f(-0.76f,0.10f);

	glVertex2f(-0.73f,0.07f);
	glVertex2f(-0.785f,0.07f);

///  window 5

   glVertex2f(-0.83f,0.04f);
	glVertex2f(-0.83f,0.10f);

	glVertex2f(-0.80f,0.07f);
	glVertex2f(-0.86f,0.07f);

/// window 6

	glVertex2f(-0.91f,0.04f);
	glVertex2f(-0.91f,0.10f);

	glVertex2f(-0.935f,0.07f);
	glVertex2f(-0.88f,0.07f);
///door
    glVertex2f(-0.60f,0.12f);
	glVertex2f(-0.60f, 0.18f);

	glVertex2f(-0.57f,0.15f);
	glVertex2f(-0.635f,0.15f);

    glEnd();

    glBegin(GL_QUADS); ///front home door 1
	glColor3ub(227,218,201);
	glVertex2f(-0.67f,-0.19f);
	glVertex2f(-0.54f, -0.19f);
	glVertex2f(-0.54f,0.05f);
	glVertex2f(-0.67f,0.05f);
    glEnd();


     glBegin(GL_QUADS); ///front home door 2
	glColor3ub(228, 122, 9);
	glVertex2f(-0.65f,0.09f);
	glVertex2f(-0.56f, 0.09f);
	glVertex2f(-0.535f,0.05f);
	glVertex2f(-0.675f,0.05f);
    glEnd();

    glBegin(GL_QUADS); ///front home door 3
	glColor3ub(138, 107, 80);
	glVertex2f(-0.65f,-0.19f);
	glVertex2f(-0.56f, -0.19f);
	glVertex2f(-0.56f,0.04f);
	glVertex2f(-0.65f,0.04f);
    glEnd();

    glBegin(GL_QUADS); ///front home door 4
	glColor3ub(218,193,160);
	glVertex2f(-0.64f,-0.17f);
	glVertex2f(-0.572f, -0.17f);
	glVertex2f(-0.572f,0.02f);
	glVertex2f(-0.64f,0.02f);
    glEnd();

     glBegin(GL_QUADS); ///front home door up window 5
	glColor3ub(115, 77, 38);
	glVertex2f(-0.64f,0.11f);
	glVertex2f(-0.565f, 0.11f);
	glVertex2f(-0.565f,0.19f);
	glVertex2f(-0.64f,0.19f);
    glEnd();

     glBegin(GL_QUADS); ///front home door up window 5
	glColor3ub(150, 220, 244);
	glVertex2f(-0.635f,0.12f);
	glVertex2f(-0.57f, 0.12f);
	glVertex2f(-0.57f,0.18f);
	glVertex2f(-0.635f,0.18f);
    glEnd();

    glLineWidth(03);
   glBegin(GL_LINES);
   glColor3ub(138, 107, 80);

 ///door
    glVertex2f(-0.605,-0.18);
    glVertex2f(-0.605,0.04);


    ///door
    glColor3ub(115, 77, 38);
    glVertex2f(-0.60f,0.12f);
	glVertex2f(-0.60f, 0.18f);

	glVertex2f(-0.57f,0.15f);
	glVertex2f(-0.64f,0.15f);

      glEnd();






////////////////////////////////////(+++++++++++++++++++++++++)///////////////////////////////////////////


    glBegin(GL_QUADS); ///front home
	glColor3ub(236, 238, 225);
	glVertex2f(0.70f,-0.15f);
	glVertex2f(0.95f,- 0.15f);
	glVertex2f(0.95f,0.15f);
	glVertex2f(0.70f,0.15f);
    glEnd();


    glBegin(GL_QUADS); ///front home chal
	glColor3ub(120, 95, 125);
	glVertex2f(0.65f,0.15f);
	glVertex2f(0.96f, 0.15f);
	glVertex2f(0.88f,0.29f);
	glVertex2f(0.65f,0.29f);
    glEnd();

    glBegin(GL_QUADS); ///front home hind
	glColor3ub(219, 226, 215);
	glVertex2f(0.72f,-0.20f);
	glVertex2f(0.55f, -0.20f);
	glVertex2f(0.55f,0.15f);
	glVertex2f(0.72f,0.15f);
    glEnd();

   glBegin(GL_QUADS); ///front home
	glColor3ub(244, 249, 238);
	glVertex2f(0.71f,-0.20f);
	glVertex2f(0.51f, -0.20f);
	glVertex2f(0.51f,0.15f);
	glVertex2f(0.71f,0.15f);
    glEnd();

    glBegin(GL_TRIANGLES); ///front home chal hide
	glColor3ub(102, 79, 108);
	glVertex2f(0.74f,0.15f);
	glVertex2f(0.54f, 0.15f);
	glVertex2f(0.63f,0.33f);
	glEnd();



    glBegin(GL_TRIANGLES); ///front home chal
	glColor3ub(149, 123, 153);
	glVertex2f(0.72f,0.15f);
	glVertex2f(0.50f, 0.15f);
	glVertex2f(0.618f,0.38f);
	glEnd();

	glBegin(GL_QUADS); ///front home chal ar opr
	glColor3ub(237, 237, 236);
	glVertex2f(0.77f,0.25f);
	glVertex2f(0.73f, 0.25f);
	glVertex2f(0.73f,0.34f);
	glVertex2f(0.77f,0.34f);
    glEnd();

	glBegin(GL_QUADS); ///front home ar opr
	glColor3ub(128, 110, 137);
	glVertex2f(0.78f,0.33f);
	glVertex2f(0.72f, 0.33f);
	glVertex2f(0.72f,0.36f);
	glVertex2f(0.78f,0.36f);
    glEnd();


    glBegin(GL_TRIANGLES); ///front home dorojar opr
	glColor3ub(244, 249, 238);
	glVertex2f(0.705f,0.15f);
	glVertex2f(0.52f, 0.15f);
	glVertex2f(0.615f,0.33f);
	glEnd();


	 glBegin(GL_QUADS); ///front home window 1
	glColor3ub(115, 77, 38);
	glVertex2f(0.73f,-0.10f);
	glVertex2f(0.78f,- 0.10f);
	glVertex2f(0.78f,0.13f);
	glVertex2f(0.73f,0.13f);
    glEnd();

    glBegin(GL_QUADS); ///front home window 1
	glColor3ub(150, 220, 244);
	glVertex2f(0.735f,-0.09f);
	glVertex2f(0.775f,- 0.09f);
	glVertex2f(0.775f,0.12f);
	glVertex2f(0.735f,0.12f);
    glEnd();



     glBegin(GL_QUADS); ///front home window 2
	glColor3ub(115, 77, 38);
	glVertex2f(0.80f,-0.10f);
	glVertex2f(0.85f,- 0.10f);
	glVertex2f(0.85f,0.13f);
	glVertex2f(0.80f,0.13f);
    glEnd();

    glBegin(GL_QUADS); ///front home window 2
	glColor3ub(150, 220, 244);
	glVertex2f(0.805f,-0.09f);
	glVertex2f(0.845f,- 0.09f);
	glVertex2f(0.845f,0.12f);
	glVertex2f(0.805f,0.12f);
    glEnd();

     glBegin(GL_QUADS); ///front home window 3
	glColor3ub(115, 77, 38);
	glVertex2f(0.87f,-0.10f);
	glVertex2f(0.92f,- 0.10f);
	glVertex2f(0.92f,0.13f);
	glVertex2f(0.87f,0.13f);
    glEnd();

   glBegin(GL_QUADS); ///front home window 3
	glColor3ub(150, 220, 244);
	glVertex2f(0.875f,-0.09f);
	glVertex2f(0.915f,- 0.09f);
	glVertex2f(0.915f,0.12f);
	glVertex2f(0.875f,0.12f);
    glEnd();

    glLineWidth(03);
   glBegin(GL_LINES);
   glColor3ub(115, 77, 38);
///window 1
    glVertex2f(0.895,-0.09);
    glVertex2f(0.895,0.12);

    glVertex2f(0.875,0.0);
    glVertex2f(0.915,0.0);

    /////////////////////////////////
///window 2
    glVertex2f(0.825,-0.09);
    glVertex2f(0.825,0.12);

    glVertex2f(0.805,0.0);
    glVertex2f(0.845,0.0);

///////////////////////////////////
///window 3

    glVertex2f(0.755f,-0.09f);
	glVertex2f(0.755f,0.12f);

	glVertex2f(0.775f,0.0f);
	glVertex2f(0.735f,0.0f);


    glEnd();


////////////////////////////////////////////////////
    glBegin(GL_QUADS); ///front home door 1
	glColor3ub(214,202,221);
	glVertex2f(0.68f,-0.20f);
	glVertex2f(0.55f, -0.20f);
	glVertex2f(0.55f,0.09f);
	glVertex2f(0.68f,0.09f);
    glEnd();


    glBegin(GL_QUADS); ///front home door 2
	glColor3ub(244, 249, 238);
	glVertex2f(0.675f,-0.20f);
	glVertex2f(0.555f, -0.20f);
	glVertex2f(0.555f,0.09f);
	glVertex2f(0.675f,0.09f);
    glEnd();


    glBegin(GL_QUADS); ///front home door 3
	glColor3ub(149, 123, 153);
	glVertex2f(0.69f,0.09f);
	glVertex2f(0.54f,0.09f);
	glVertex2f(0.565f,0.13f);
	glVertex2f(0.67f,0.13f);
    glEnd();

     glBegin(GL_QUADS); ///front home door 4
	glColor3ub(160,82,45);
	glVertex2f(0.66f,-0.19f);
	glVertex2f(0.57f, -0.19f);
	glVertex2f(0.57f,0.06f);
	glVertex2f(0.66f,0.06f);
    glEnd();

    glBegin(GL_QUADS); ///front home door 5
	glColor3ub(221, 172, 133);
	glVertex2f(0.65f,-0.17f);
	glVertex2f(0.58f, -0.17f);
	glVertex2f(0.58f,0.04f);
	glVertex2f(0.65f,0.04f);
    glEnd();

/////////////////////////////////////
     glLineWidth(03);///door
   glBegin(GL_LINES);
   glColor3ub(160,82,45);

    glVertex2f(0.615,-0.18);
    glVertex2f(0.615,0.05);
    glEnd();

//////////////////////////////////////////////////////////////
///BARI 3

    glBegin(GL_QUADS); ///front home middel
	glColor3ub(240, 231, 221);
	glVertex2f(0.35f,-0.20f);
	glVertex2f(-0.35f, -0.20f);
	glVertex2f(-0.35f,0.12f);
	glVertex2f(0.35f,0.12f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel chal
	glColor3ub(57, 115, 129);
	glVertex2f(0.37f,0.10f);
	glVertex2f(-0.37f,0.10f);
	glVertex2f(-0.30f,0.25f);
	glVertex2f(0.30f,0.25f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel chal up
	glColor3ub(240, 231, 221);
	glVertex2f(-0.23f,0.20f);
	glVertex2f(-0.19f,0.20f);
	glVertex2f(-0.19f,0.27f);
	glVertex2f(-0.23f,0.27f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel chal up
	glColor3ub(240, 231, 221);
	glVertex2f(0.23f,0.20f);
	glVertex2f(0.19f,0.20f);
	glVertex2f(0.19f,0.27f);
	glVertex2f(0.23f,0.27f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel chal up
	glColor3ub(146, 103, 70);
	glVertex2f(-0.24f,0.27f);
	glVertex2f(-0.18f,0.27f);
	glVertex2f(-0.18f,0.30f);
	glVertex2f(-0.24f,0.30f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel chal up
	glColor3ub(146, 103, 70);
	glVertex2f(0.24f,0.27f);
	glVertex2f(0.18f,0.27f);
	glVertex2f(0.18f,0.30f);
	glVertex2f(0.24f,0.30f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel 2
	glColor3ub(238, 221, 209);
	glVertex2f(0.10f,-0.20f);
	glVertex2f(-0.10f, -0.20f);
	glVertex2f(-0.10f,0.10f);
	glVertex2f(0.10f,0.10f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel 2
	glColor3ub(240, 231, 221);
	glVertex2f(0.09f,-0.20f);
	glVertex2f(-0.09f, -0.20f);
	glVertex2f(-0.09f,0.10f);
	glVertex2f(0.09f,0.10f);
    glEnd();

   glBegin(GL_TRIANGLES); ///front home middel 2
	glColor3ub(40, 94, 106);
	glVertex2f(-0.13f,0.10f);
	glVertex2f(0.13f,0.10f);
	glVertex2f(0.0f,0.280f);
    glEnd();

    glBegin(GL_TRIANGLES); ///front home middel 2
	glColor3ub(93, 148, 166);
	glVertex2f(-0.10f,0.10f);
	glVertex2f(0.10f,0.10f);
	glVertex2f(0.0f,0.30f);
    glEnd();

    glBegin(GL_TRIANGLES); ///front home middel 2
	glColor3ub(240, 231, 221);
	glVertex2f(-0.08f,0.10f);
	glVertex2f(0.08f,0.10f);
	glVertex2f(0.0f,0.26f);
    glEnd();

     glBegin(GL_QUADS); ///front home middel get
	glColor3ub(216, 180, 157);
	glVertex2f(0.05f,-0.20f);
	glVertex2f(-0.05f, -0.20f);
	glVertex2f(-0.05f,0.06f);
	glVertex2f(0.05f,0.06f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel get
	glColor3ub(146, 103, 70);
	glVertex2f(0.04f,-0.18f);
	glVertex2f(-0.04f, -0.18f);
	glVertex2f(-0.04f,0.03f);
	glVertex2f(0.04f,0.03f);
    glEnd();


    glBegin(GL_QUADS); ///front home middel get 1
	glColor3ub(227,218,201);
	glVertex2f(0.03f,-0.17f);
	glVertex2f(-0.03f, -0.17f);
	glVertex2f(-0.03f,0.02f);
	glVertex2f(0.03f,0.02f);
    glEnd();


    glLineWidth(03);
   glBegin(GL_LINES);
   glColor3ub(115, 77, 38);///door

    glVertex2f(0.0,-0.17);
    glVertex2f(0.0,0.02);
   glEnd();


     glBegin(GL_QUADS); ///front home middel get up
	glColor3ub(93, 148, 166);
	glVertex2f(0.07f,0.06f);
	glVertex2f(-0.07f,0.06f);
	glVertex2f(-0.04f,0.11f);
	glVertex2f(0.04f,0.11f);
    glEnd();



    glBegin(GL_QUADS); ///front home middel window 1
	glColor3ub(146, 103, 70);
	glVertex2f(-0.33f,-0.15f);
	glVertex2f(-0.28f, -0.15f);
	glVertex2f(-0.28f,0.05f);
	glVertex2f(-0.33f,0.05f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 1
	glColor3ub(146, 103, 70);
	glVertex2f(0.33f,-0.15f);
	glVertex2f(0.28f, -0.15f);
	glVertex2f(0.28f,0.05f);
	glVertex2f(0.33f,0.05f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 1
	glColor3ub(150, 220, 244);
	glVertex2f(-0.325f,-0.14f);
	glVertex2f(-0.285f, -0.14f);
	glVertex2f(-0.285f,0.04f);
	glVertex2f(-0.325f,0.04f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 1
	glColor3ub(150, 220, 244);
	glVertex2f(0.325f,-0.14f);
	glVertex2f(0.285f, -0.14f);
	glVertex2f(0.285f,0.04f);
	glVertex2f(0.325f,0.04f);
    glEnd();



    glBegin(GL_QUADS); ///front home middel window 2
	glColor3ub(146, 103, 70);
	glVertex2f(-0.25f,-0.15f);
	glVertex2f(-0.20f, -0.15f);
	glVertex2f(-0.20f,0.05f);
	glVertex2f(-0.25f,0.05f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 2
	glColor3ub(146, 103, 70);
	glVertex2f(0.25f,-0.15f);
	glVertex2f(0.20f, -0.15f);
	glVertex2f(0.20f,0.05f);
	glVertex2f(0.25f,0.05f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 2
	glColor3ub(150, 220, 244);
	glVertex2f(-0.245f,-0.14f);
	glVertex2f(-0.205f, -0.14f);
	glVertex2f(-0.205f,0.04f);
	glVertex2f(-0.245f,0.04f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 2
	glColor3ub(150, 220, 244);
	glVertex2f(0.245f,-0.14f);
	glVertex2f(0.205f, -0.14f);
	glVertex2f(0.205f,0.04f);
	glVertex2f(0.245f,0.04f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 3
	glColor3ub(146, 103, 70);
	glVertex2f(-0.17f,-0.15f);
	glVertex2f(-0.12f, -0.15f);
	glVertex2f(-0.12f,0.05f);
	glVertex2f(-0.17f,0.05f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 3
	glColor3ub(146, 103, 70);
	glVertex2f(0.17f,-0.15f);
	glVertex2f(0.12f, -0.15f);
	glVertex2f(0.12f,0.05f);
	glVertex2f(0.17f,0.05f);
    glEnd();


    glBegin(GL_QUADS); ///front home middel window 3
	glColor3ub(150, 220, 244);
	glVertex2f(-0.165f,-0.14f);
	glVertex2f(-0.125f, -0.14f);
	glVertex2f(-0.125f,0.04f);
	glVertex2f(-0.165f,0.04f);
    glEnd();

    glBegin(GL_QUADS); ///front home middel window 3
	glColor3ub(150, 220, 244);
	glVertex2f(0.165f,-0.14f);
	glVertex2f(0.125f, -0.14f);
	glVertex2f(0.125f,0.04f);
	glVertex2f(0.165f,0.04f);
    glEnd();


   glLineWidth(03);
   glBegin(GL_LINES);
   glColor3ub(115, 77, 38);/// window 1

    glVertex2f(-0.305,-0.15);
    glVertex2f(-0.305,0.05);

/// window 2

    glVertex2f(-0.225,-0.15);
    glVertex2f(-0.225,0.05);

/// window 3

    glVertex2f(-0.145,-0.15);
    glVertex2f(-0.145,0.05);
/////////////////////////////////////////////
    glColor3ub(115, 77, 38);/// window 1

    glVertex2f(0.305,-0.15);
    glVertex2f(0.305,0.05);

/// window 2

    glVertex2f(0.225,-0.15);
    glVertex2f(0.225,0.05);

/// window 3

    glVertex2f(0.145,-0.15);
    glVertex2f(0.145,0.05);

    glEnd();

    glPopMatrix();








    ///============================================================================================Bus2
	glPushMatrix();
    glTranslatef(position5,0.0f, 0.0f);

	glTranslatef(0.0, -0.65, 0.0);
    glScalef(0.63,0.63,0.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.5f, -0.166f);
	glVertex2f(1.0f, -0.166f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.55f, 0.0f);
	glVertex2f(0.5f, -0.033f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.5f, -0.1f);
	glVertex2f(0.5166f, -0.1f);
	glVertex2f(0.5166f, -0.066f);
	glVertex2f(0.5f, -0.066f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.55f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(1.0f, 0.116f);
	glVertex2f(0.55f, 0.116f);
	glEnd();


	glBegin(GL_POLYGON);///Buswindows
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(0.5833f, 0.016f);
	glVertex2f(0.633f, 0.016f);
	glVertex2f(0.633f, 0.1f);
	glVertex2f(0.5833f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(0.65f, 0.016f);
	glVertex2f(0.7f, 0.016f);
	glVertex2f(0.7f, 0.1f);
	glVertex2f(0.65f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(0.716f, 0.016f);
	glVertex2f(0.766f, 0.016f);
	glVertex2f(0.766f, 0.1f);
	glVertex2f(0.716f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(0.783f, 0.016f);
	glVertex2f(0.833f, 0.016f);
	glVertex2f(0.833f, 0.1f);
	glVertex2f(0.783f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(0.85f, 0.016f);
	glVertex2f(0.9f, 0.016f);
	glVertex2f(0.9f, 0.1f);
	glVertex2f(0.85f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(0.916f, 0.016f);
	glVertex2f(0.966f, 0.016f);
	glVertex2f(0.966f, 0.1f);
	glVertex2f(0.916f, 0.1f);
	glEnd();


	GLfloat p16= 0.58f;  GLfloat q16= -0.18f;  GLfloat r16= 0.05f;
    int triangle16=40;
    GLfloat tp16 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p16,q16);
    for(int i= 0;i<=triangle16; i++)
    {
        glVertex2f (
                    p16+(r16*cos(i*tp16/triangle16)),
                    q16+(r16*sin(i*tp16/triangle16))
                    );
    }
    glEnd ();


    GLfloat p17= 0.88f;  GLfloat q17= -0.18f;  GLfloat r17= 0.05f;
    int triangle17=40;
    GLfloat tp17 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p17,q17);
    for(int i= 0;i<=triangle17; i++)
    {
        glVertex2f (
                    p17+(r17*cos(i*tp17/triangle17)),
                    q17+(r17*sin(i*tp17/triangle17))
                    );
    }
    glEnd ();


    if(position1>= 0.0)
        {
            glBegin(GL_TRIANGLES);
            glColor3ub ( 255, 255, 0);
            glVertex2f(0.5f,-0.08f);
            glVertex2f(0.3f,-0.18f);
            glVertex2f(0.3f,0.02f);

            glEnd();
        }

	glLoadIdentity();
	glPopMatrix();







	///============================================================================================Bus1
	glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);

	glTranslatef(0.55, -0.42, 0.0);
    glScalef(0.63,0.63,0.0);

	glBegin(GL_POLYGON);
	glColor3ub(255 ,165 ,0);
	glVertex2f(-0.5f, -0.166f);
	glVertex2f(-1.0f, -0.166f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(-0.55f, 0.0f);
	glVertex2f(-0.5f, -0.033f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.5166f, -0.1f);
	glVertex2f(-0.5166f, -0.066f);
	glVertex2f(-0.5f, -0.066f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(255 ,165 ,0);
	glVertex2f(-0.55f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(-1.0f, 0.116f);
	glVertex2f(-0.55f, 0.116f);
	glEnd();


	glBegin(GL_POLYGON);///Buswindows
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(-0.5833f, 0.016f);
	glVertex2f(-0.633f, 0.016f);
	glVertex2f(-0.633f, 0.1f);
	glVertex2f(-0.5833f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(-0.65f, 0.016f);
	glVertex2f(-0.7f, 0.016f);
	glVertex2f(-0.7f, 0.1f);
	glVertex2f(-0.65f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(-0.716f, 0.016f);
	glVertex2f(-0.766f, 0.016f);
	glVertex2f(-0.766f, 0.1f);
	glVertex2f(-0.716f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(-0.783f, 0.016f);
	glVertex2f(-0.833f, 0.016f);
	glVertex2f(-0.833f, 0.1f);
	glVertex2f(-0.783f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(-0.85f, 0.016f);
	glVertex2f(-0.9f, 0.016f);
	glVertex2f(-0.9f, 0.1f);
	glVertex2f(-0.85f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.26, 0.26, 0.26);
	glVertex2f(-0.916f, 0.016f);
	glVertex2f(-0.966f, 0.016f);
	glVertex2f(-0.966f, 0.1f);
	glVertex2f(-0.916f, 0.1f);
	glEnd();


	GLfloat p18= -0.58f;  GLfloat q18= -0.18f;  GLfloat r18= 0.05f;
    int triangle18=40;
    GLfloat tp18 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p18,q18);
    for(int i= 0;i<=triangle18; i++)
    {
        glVertex2f (
                    p18+(r18*cos(i*tp18/triangle18)),
                    q18+(r18*sin(i*tp18/triangle18))
                    );
    }
    glEnd ();


    GLfloat p19= -0.88f;  GLfloat q19= -0.18f;  GLfloat r19= 0.05f;
    int triangle19=40;
    GLfloat tp19 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 0, 0, 255);
    glVertex2f (p19,q19);
    for(int i= 0;i<=triangle19; i++)
    {
        glVertex2f (
                    p19+(r19*cos(i*tp19/triangle19)),
                    q19+(r19*sin(i*tp19/triangle19))
                    );
    }
    glEnd ();


    if(position1>= 0.0)
        {
            glBegin(GL_TRIANGLES);
            glColor3ub ( 255, 255, 0);
            glVertex2f(-0.5f,-0.08f);
            glVertex2f(-0.3f,-0.18f);
            glVertex2f(-0.3f,0.02f);

            glEnd();
        }


	glLoadIdentity();
	glPopMatrix();







//////////////////////////////////////////////////////////////
///====================================================================================CLOUDS 1

    glPushMatrix();
    glTranslatef(position9,0.0f, 0.0f);

        GLfloat p4 =-0.65; GLfloat q4 =0.80; GLfloat r4 =0.10;
        int triangle4 = 20;
        GLfloat tp4 = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p4 , q4); // center of circle
            for(int i = 0; i <= triangle4;i++) {
            glVertex2f(
            p4 + (r4 * cos(i * tp4 / triangle4)),
            q4 + (r4 * sin(i * tp4 / triangle4))
            );
            }
        glEnd();

        GLfloat p5 =-0.57; GLfloat q5= 0.85; GLfloat r5 =0.10;
        int triangle5 = 20;
        GLfloat tp5 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p5 , q5); // center of circle
            for(int i = 0; i <= triangle5;i++) {
            glVertex2f(
            p5 + (r5 * cos(i * tp5 / triangle5)),
            q5 + (r5 * sin(i * tp5 / triangle5))
            );
            }
        glEnd();

        GLfloat p6 =-0.43; GLfloat q6= 0.80; GLfloat r6 =0.10;
        int triangle6 = 20;
        GLfloat tp6 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p6 , q6); // center of circle
            for(int i = 0; i <= triangle6;i++) {
            glVertex2f(
            p6 + (r6 * cos(i * tp6 / triangle6)),
            q6 + (r6 * sin(i * tp6 / triangle6))
            );
            }
        glEnd();

        GLfloat p7 =-0.55; GLfloat q7= 0.78; GLfloat r7=0.10;
        int triangle7 = 20;
        GLfloat tp7 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3f(255,255,255);
            glVertex2f(p7 , q7); // center of circle
            for(int i = 0; i <= triangle7;i++) {
            glVertex2f(
            p7 + (r7 * cos(i * tp7 / triangle7)),
            q7 + (r7 * sin(i * tp7 / triangle7))
            );
            }
        glEnd();

    glPopMatrix();








////////////////////////////////////////////////////////////////
///====================================================================================== CLOUDS 2

    glPushMatrix();
    glTranslatef(position10,0.0f, 0.0f);

        GLfloat p11 =0.0; GLfloat q11 =0.80; GLfloat r11 =0.10;
        int triangle11 = 20;
        GLfloat tp11 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p11 , q11); // center of circle
            for(int i = 0; i <= triangle11;i++) {
            glVertex2f(
            p11 + (r11 * cos(i * tp11 / triangle11)),
            q11 + (r11 * sin(i * tp11 / triangle11))
            );
            }
        glEnd();

        GLfloat p8 =0.05; GLfloat q8= 0.85; GLfloat r8 =0.10;
        int triangle8= 20;
        GLfloat tp8 = 2.0f * PI;
            glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p8 , q8); // center of circle
            for(int i = 0; i <= triangle8;i++) {
            glVertex2f(
            p8 + (r8 * cos(i * tp8 / triangle8)),
            q8 + (r8 * sin(i * tp8 / triangle8))
            );
            }
        glEnd();


        GLfloat p9 =0.05; GLfloat q9= 0.78; GLfloat r9 =0.10;
        int triangle9 = 20;
        GLfloat tp9 = 2.0f * PI;
            glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p9 , q9); // center of circle
            for(int i = 0; i <= triangle9;i++) {
            glVertex2f(
            p9 + (r9 * cos(i * tp9 / triangle9)),
            q9 + (r9 * sin(i * tp9 / triangle9))
            );
            }
        glEnd();

        GLfloat p10 =0.15; GLfloat q10= 0.78; GLfloat r10=0.10;
        int triangle10 = 20;
        GLfloat tp10 = 2.0f * PI;
            glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3f(255,255,255);
            glVertex2f(p10 , q10); // center of circle
            for(int i = 0; i <= triangle10;i++) {
            glVertex2f(
            p10 + (r10 * cos(i * tp10 / triangle10)),
            q10 + (r10 * sin(i * tp10 / triangle10))
            );
        }
        glEnd();

    glPopMatrix();
//////////////////////////////////////////////////////////////////////






///====================================================================================CLOUDS 3

    glPushMatrix();
    glTranslatef(position11,0.0f, 0.0f);

        GLfloat p20 =0.75; GLfloat q20 =0.80; GLfloat r20 =0.10;
        int triangle20 = 20;
        GLfloat tp20 = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p20 , q20); // center of circle
            for(int i = 0; i <= triangle20;i++) {
            glVertex2f(
            p20 + (r20 * cos(i * tp20 / triangle20)),
            q20 + (r20 * sin(i * tp20 / triangle20))
            );
            }
        glEnd();

        GLfloat p21 =0.67; GLfloat q21= 0.85; GLfloat r21 =0.10;
        int triangle21 = 20;
        GLfloat tp21 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p21 , q21); // center of circle
            for(int i = 0; i <= triangle21;i++) {
            glVertex2f(
            p21 + (r21 * cos(i * tp21 / triangle21)),
            q21 + (r21 * sin(i * tp21 / triangle21))
            );
            }
        glEnd();

        GLfloat p22 =0.53; GLfloat q22= 0.80; GLfloat r22 =0.10;
        int triangle22 = 20;
        GLfloat tp22 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3ub(255,255,255);
            glVertex2f(p22 , q22); // center of circle
            for(int i = 0; i <= triangle22;i++) {
            glVertex2f(
            p22 + (r22 * cos(i * tp22 / triangle22)),
            q22 + (r22 * sin(i * tp22 / triangle22))
            );
            }
        glEnd();

        GLfloat p23 =0.65; GLfloat q23= 0.78; GLfloat r23=0.10;
        int triangle23 = 20;
        GLfloat tp23 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);//chaka1
            glColor3f(255,255,255);
            glVertex2f(p23 , q23); // center of circle
            for(int i = 0; i <= triangle23;i++) {
            glVertex2f(
            p23 + (r23 * cos(i * tp23 / triangle23)),
            q23 + (r23 * sin(i * tp23 / triangle23))
            );
            }
        glEnd();

    glPopMatrix();








glFlush();
}






    void keyboard(unsigned char key, int x, int y)
    {
        switch (key)
        {
            case 'q':
                speed4 = 0.0f;//bus 1
                speed5 = 0.0f;//bus 2
            break;

            case 'a':
                speed2 = 0.02f;//car 1
                speed3 = 0.02f;//car 2
                speed4 = 0.02f;//bus 1
                speed5 = 0.02f;//bus2
            break;

            case 's':
                speed2 = 0.0f;//car 1
                speed3 = 0.0f;//car 2
                speed4 = 0.0f;//bus 1
                speed5 = 0.0f;//bus 2
            break;

            case 'e':
                speed7 = 0.015f;//boat 1
                speed8 = 0.015f;//boat 2
            break;

            case 'r':
                speed7 = 0.0f;//boat 1
                speed8 = 0.0f;//boat 2
            break;

            case 'd':
                position1 = 0.0f;//sun
            break;

            case 'n':
                position1 = 1.0f;//sun
            break;

        glutPostRedisplay();
        }
    }

    void mouse(int button,int state,int x,int y)
    {
        switch(button)
        {
            case GLUT_LEFT_BUTTON:
                 speed1 = 0.001f;//sun 0.001
                 speed2 = 0.02f;
                 speed3 = 0.02f;
                 speed4 = 0.02f;
                 speed5 = 0.02f;
                 speed6 = 0.01f;
                 speed7 = 0.015f;
                 speed8 = 0.015f;
                 speed9 = 0.004f;
                 speed10 = 0.004f;
                 speed11 = 0.004f;
                 speed12 = 0.010f;
            break;

            case GLUT_MIDDLE_BUTTON:

            break;

            case GLUT_RIGHT_BUTTON:
                speed1 += 0.005f;
                speed2 += 0.005f;
                speed3 += 0.005f;
                speed4 += 0.005f;
                speed5 += 0.005f;
                speed6 += 0.005f;
                speed7 += 0.005f;
                speed8 += 0.005f;
                speed9 += 0.005f;
                speed10 += 0.005f;
                speed11 += 0.005f;
                speed12 += 0.005f;
            break;

            default:
                break;
        }
    }


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup");
   // glutInitWindowSize(320, 320);
    glutReshapeWindow(720,405);
    glutPositionWindow(350,200);
    glutDisplayFunc(display);



    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutIdleFunc(spinDisplayReverse);

    glutTimerFunc(100, update1, 0);///sun
    glutTimerFunc(100, update2, 0);///car1
    glutTimerFunc(100, update3, 0);///car2
    glutTimerFunc(100, update4, 0);///bus1
    glutTimerFunc(100, update5, 0);///bus2
    glutTimerFunc(100, update6, 0);///plane
    glutTimerFunc(100, update7, 0);///boat 1
    glutTimerFunc(100, update8, 0);///boat 2
    glutTimerFunc(100, update9, 0);///cloud 1
    glutTimerFunc(100, update10, 0);///cloud 2
    glutTimerFunc(100, update11, 0);///cloud 3
    glutTimerFunc(100, update12, 0);///river flow
    //glutTimerFunc(100, updateRain, 0);
    glutMainLoop();
    return 0;
}
