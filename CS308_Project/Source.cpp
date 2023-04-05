#include <GL/glut.h>  
#include <math.h>

int frameNumber = 0;
//Animation
GLfloat animYRot = 0.0;

//variables to move the camera
GLfloat camX = 0.0;
GLfloat camY = 0.0;
GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceX = 0.0;
GLfloat sceY = 0.0;
GLfloat sceZ = 0.0;

//variables to move the snowman
GLfloat objX = 0.0;
GLfloat objY = 0.0;
GLfloat objZ = 0.0;

GLfloat move;
GLfloat moveVehicle;
GLint rotateVehicle=0;
GLfloat move1;
GLfloat move2;
GLfloat move3;
GLfloat lightControl;
GLfloat pi = 3.14;

float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

}


void drawGround() {
    glPushMatrix();
    glColor3f(0.4f,0.2f,0);
    glScalef(30,0.02,30);
    glutSolidCube(1);
    glPopMatrix();
}

void drawRoad() {
    glPushMatrix();
    glColor3f(0,0,0);
    glScalef(4,0.02,30);
    glutSolidCube(1);
    glPopMatrix();

    //draw white line
    /*glPushMatrix();
    glColor3f(1, 1, 1);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex3f(0,0,20);
    glVertex3f(0,0,-20);
    glEnd();
    glPopMatrix();*/
}

//draw house

void ground() {
    glPushMatrix();
    glColor3f(0.5,0.5,0);
    glScalef(1.5,0.02,1.5);
    glutSolidCube(1);
    glPopMatrix();
}

void drawWall() {
    glPushMatrix();
    glScalef(1,1,0.02);
    glutSolidCube(1);
    glPopMatrix();
}

void frontWall(float r, float g, float b) {

    glPushMatrix();

    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(-0.3,0.5,0.5);
    glScalef(0.4,1,1);
    drawWall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0.5, 0.5);
    glScalef(0.4, 1, 1);
    drawWall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.7,0.5);
    glScalef(0.2,0.6,1);
    drawWall(); 
    glPopMatrix();

    glPopMatrix();

}

void door() {
    glPushMatrix();
    glColor3f(1,1,0);
    glRotatef(30,0,1,0);
    glTranslatef(0.1,0,0);
    glScalef(0.2,0.4,1);
    drawWall();
    glPopMatrix();
}

void roofSide() {
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0,0.5,0);
    glVertex3f(-0.75,0,0.75);
    glVertex3f(0.75,0,0.75);
    glEnd();
    glPopMatrix();
}

void roof() {
    glPushMatrix();
    for (int i = 0; i < 360;i+=90) {
        glRotatef(i,0,1,0);
        roofSide();
    }
    glPopMatrix();
}

void drawHouse(float r, float g, float b) {

    glPushMatrix();
    glTranslatef(0,0.02,0);
    ground();
    glPopMatrix();

    glPushMatrix();
    glColor3f(r, g, b);
    glTranslatef(0,0.5,-0.5);
    drawWall();
    glPopMatrix();

    glPushMatrix();
    glColor3f(r, g, b);
    glRotatef(90,0,1,0);
    glTranslatef(0, 0.5, -0.5);
    drawWall();
    glPopMatrix();

    glPushMatrix();
    glColor3f(r, g, b);
    glRotatef(-90, 0, 1, 0);
    glTranslatef(0, 0.5, -0.5);
    drawWall();
    glPopMatrix();

    glPushMatrix();
    frontWall(r,g,b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1,0.2,0.5);
    door();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(0, 1, 0);
    roof();
    glPopMatrix();

}

void drawBigHosuse() {

    glPushMatrix();
    glTranslatef(0,0.015,0);
    glScalef(5,1,5);
    ground();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,0,-1.5);
    glScalef(2, 2, 2);
    drawHouse(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0, 1.5, 0);
    glScalef(3,3,3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 3, 1);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 3, 0);
    glScalef(2, 2, 2);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, 2);
    glScalef(2, 2, 2);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 1);
    glScalef(1, 1, 1);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 2);
    glScalef(1, 1, 1);
    drawHouse(1, 1, 1);
    glPopMatrix();

}

void drawBigHosuse1() {

    glPushMatrix();
    glTranslatef(0, 0.015, 0);
    glScalef(5, 1, 5);
    ground();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, -1.5);
    glScalef(2, 2, 2);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0.7, 0.9);
    glTranslatef(0, 1.5, 0);
    glScalef(3, 3, 3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 3, 1);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 3, 0);
    glScalef(2, 2, 2);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, 2);
    glScalef(2, 2, 2);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 1);
    glScalef(1, 1, 1);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 2);
    glScalef(1, 1, 1);
    drawHouse(1, 1, 1);
    glPopMatrix();

}


//traffic ligth

void drawLight1(double red1,double green1, double blue1) {
    glPushMatrix();
    glColor3f(red1, green1, blue1);
    glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
}

void drawLight2(double red2, double green2, double blue2) {
    glPushMatrix();
    glColor3f(red2, green2, blue2);
    glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
}

void drawLight3(double red3, double green3, double blue3) {
    glPushMatrix();
    glColor3f(red3, green3, blue3);
    glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
}

void drawLight4(double red4, double green4, double blue4) {
    glPushMatrix();
    glColor3f(red4, green4, blue4);
    glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
}

void drawLight5(double red5, double green5, double blue5) {
    glPushMatrix();
    glColor3f(red5, green5, blue5);
    glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
}

void drawLight6(double red6, double green6, double blue6) {
    glPushMatrix();
    glColor3f(red6, green6, blue6);
    glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
}

void drawLights1() {

    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glScalef(1,3,1);
    glutSolidCube(1);
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(0, 0.9, 0.5);
    drawLight1(a,b,c);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    drawLight2(d, e, f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.9, 0.5);
    drawLight3(g, h, i);
    glPopMatrix();

}

void drawLights2() {

    glPushMatrix();
    glColor3f(0.6, 0.6, 0.6);
    glScalef(1, 3, 1);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0.9, 0.5);
    drawLight4(j, k, l);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    drawLight5(m, n, o);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.9, 0.5);
    drawLight6(p, q, r);
    glPopMatrix();

}

void drawTrafficLight1() {
    glPushMatrix();
    glColor3f(0.5, 0.5, 0);
    glTranslatef(0,3,0);
    glScalef(0.1,6,0.1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,5,0);
    drawLights1();
    glPopMatrix();

}

void drawTrafficLight2() {
    glPushMatrix();
    glColor3f(0.5, 0.5, 0);
    glTranslatef(0, 3, 0);
    glScalef(0.1, 6, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5, 0);
    drawLights2();
    glPopMatrix();

}


void drawGrid() {
    GLfloat step = 1.0f;
    GLint line;

    glBegin(GL_LINES);
    for (line = -20; line <= 20; line += step) {
        glVertex3f(line, -0.4, 20);
        glVertex3f(line, -0.4, -20);

        glVertex3f(20, -0.4, line);
        glVertex3f(-20, -0.4, line);
    }
    glEnd();
}

void drawAxes() {

    glBegin(GL_LINES);

    glLineWidth(1.5);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-200, 0, 0);
    glVertex3f(200, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -200, 0);
    glVertex3f(0, 200, 0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -200);
    glVertex3f(0, 0, 200);

    glEnd();
}

void drawVehicle() {
    glPushMatrix();
    glutSolidCube(1);
    glPopMatrix();
}

void drawCircle2(double radius) {
    int d;
    glBegin(GL_POLYGON);
    for (d = 0; d < 32; d++) {
        double angle = 2 * pi / 32 * d;
        glVertex2d(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void drawCylinder2(float r, float h) {
    glPushMatrix();
    glTranslatef(0, 0, -h / 2);
    glPushMatrix();
    GLUquadricObj* qaudratic;
    qaudratic = gluNewQuadric();
    gluCylinder(qaudratic, r, r, h, 100, 100);
    drawCircle2(r);
    glTranslatef(0, 0, h);
    drawCircle2(r);
    glPopMatrix();
    glPopMatrix();

}

void drawSphere1(double r) {
    glPushMatrix();
    glutSolidSphere(r, 100, 100);
    glPopMatrix();
}

void drawCube2(float i) {
    glPushMatrix();
    glutSolidCube(i);
    glPopMatrix();
}

void drawBusSideWindow(int r, int g, int b) {

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslatef(0, -0.75, 0);
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex3f(0, 0.75, 1.25);
    glVertex3f(0, 0.75, -1.25);
    glVertex3f(0, -0.75, -1.25);
    glVertex3f(0, -0.75, 1.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.75, 1.125);
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex3f(0, 0.75, 0.125);
    glVertex3f(0, 0.75, -0.125);
    glVertex3f(0, -0.75, -0.125);
    glVertex3f(0, -0.75, 0.125);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.75, -1.125);
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex3f(0, 0.75, 0.125);
    glVertex3f(0, 0.75, -0.125);
    glVertex3f(0, -0.75, -0.125);
    glVertex3f(0, -0.75, 0.125);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 1.38, 0);
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex3f(0, 0.125, 1.25);
    glVertex3f(0, 0.125, -1.25);
    glVertex3f(0, -0.125, -1.25);
    glVertex3f(0, -0.125, 1.25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.65, 0);
    glBegin(GL_POLYGON);
    glColor4f(0, 0, 1, 0.5);
    glVertex3f(0, 0.65, 1.0);
    glVertex3f(0, 0.65, -1.0);
    glVertex3f(0, -0.65, -1.0);
    glVertex3f(0, -0.65, 1.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

void drawFrontGlass(int r, int g, int b) {

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_CLIP_PLANE0);
    double planeEquation[] = { 0.0, -1.0, 0.0, 1.5 };
    //glClipPlane(GL_CLIP_PLANE0, planeEquation);

    glPushMatrix();

    glScalef(1.1, 1.9, 1);
    glTranslatef(0, 0.28, -4.48);
    glRotatef(45, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0.75, 1.25);
    glVertex3f(0, 0.75, -1.25);
    glVertex3f(0, -0.75, -1.25);
    glVertex3f(0, -0.75, 1.25);
    glEnd();
    glDisable(GL_CLIP_PLANE0);
    glPopMatrix();

    glPopMatrix();
}

void drawBusdoor(int r, int g, int b) {
    glPushMatrix();

    glPushMatrix();
    glEnable(GL_CLIP_PLANE0);
    double planeEquation[] = { 0.0, 1.0, 0.0, 0,0 };
    glClipPlane(GL_CLIP_PLANE0, planeEquation);

    glEnable(GL_CLIP_PLANE1);
    double planeEquation1[] = { 0.0, 0.5, -1.5, -0.75 };
    glClipPlane(GL_CLIP_PLANE1, planeEquation1);

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex3f(0, 1.5, -0.25);
    glVertex3f(0, 1.5, 1.25);
    glVertex3f(0, -1.5, 1.25);
    glVertex3f(0, -1.5, -1.25);
    glVertex3f(0, -0.5, -1.25);
    glEnd();
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.65, 0.4);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(0, 0, 1, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0.65, -0.475);
    glVertex3f(0, 0.65, 0.875);
    glVertex3f(0, -0.65, 0.875);
    glVertex3f(0, -0.65, -0.875);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_CLIP_PLANE2);
    double planeEquation2[] = { 0.0, 1.0, 0.0, -1.3 };
    glClipPlane(GL_CLIP_PLANE2, planeEquation2);

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex3f(0, 1.5, -0.25);
    glVertex3f(0, 1.5, 1.25);
    glVertex3f(0, -1.5, 1.25);
    glVertex3f(0, -1.5, -1.25);
    glVertex3f(0, -0.5, -1.25);
    glEnd();
    glDisable(GL_CLIP_PLANE2);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_CLIP_PLANE3);
    double planeEquation3[] = { 0.0, -1.0, 0.0, 0,0 };
    glClipPlane(GL_CLIP_PLANE3, planeEquation3);

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex3f(0, 1.5, -0.25);
    glVertex3f(0, 1.5, 1.25);
    glVertex3f(0, -1.5, 1.25);
    glVertex3f(0, -1.5, -1.25);
    glVertex3f(0, -0.5, -1.25);
    glEnd();
    glDisable(GL_CLIP_PLANE3);
    glPopMatrix();

    glPopMatrix();
}

void drawSide(int r, int g, int b) {

    glPushMatrix();

    glPushMatrix();
    glPushMatrix();
    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_CLIP_PLANE1);
    glEnable(GL_CLIP_PLANE2);
    glEnable(GL_CLIP_PLANE3);

    double planeEquation0[] = { -1.0, 0.0, 0.0, 1.4 };
    double planeEquation1[] = { 1.0, 0.0, 0.0, 1.4 };
    double planeEquation2[] = { 0.0, -1.0, 2.0, 9.5 };
    double planeEquation3[] = { 0.0, 0.0, -1.0, 4.9 };
    glClipPlane(GL_CLIP_PLANE0, planeEquation0);
    glClipPlane(GL_CLIP_PLANE1, planeEquation1);
    glClipPlane(GL_CLIP_PLANE2, planeEquation2);
    glClipPlane(GL_CLIP_PLANE3, planeEquation3);

    glScalef(3, 3, 10);
    glColor3f(r, g, b);
    drawCube2(1);
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE2);

    glPopMatrix();

    glPushMatrix();
    for (float i = 3.75; i > -2.5; i -= 2.5) {
        glPushMatrix();
        glTranslatef(-1.4, 0, i);
        drawBusSideWindow(r, g, b);
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    for (float i = 3.75; i > -2.5; i -= 2.5) {
        glPushMatrix();
        glTranslatef(1.4, 0, i);
        drawBusSideWindow(r, g, b);
        glPopMatrix();
    }
    glPopMatrix();
    glDisable(GL_CLIP_PLANE3);

    glPopMatrix();

    glPushMatrix();
    glScalef(1.15, 1, 1);
    glTranslatef(0, 0, 4.9);
    glRotatef(90, 0, 1, 0);
    drawBusSideWindow(r, g, b);
    glPopMatrix();

    glPushMatrix();
    drawFrontGlass(r, g, b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4, 0, -3.75);
    drawBusdoor(r, g, b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.4, 0, -3.75);
    drawBusdoor(r, g, b);
    glPopMatrix();

    glPopMatrix();
}

void drawFlow() {

    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(1.4, 0, 5);
    glVertex3f(1.4, 0, -5);
    glVertex3f(-1.4, 0, -5);
    glVertex3f(-1.4, 0, 5);
    glEnd();
    glPopMatrix();
}

void drawSeat() {
    glPushMatrix();
    glColor3f(1, 1, 1);
    drawCube2(1);

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 1, 0.4);
    glScalef(1, 1, 0.2);
    drawCube2(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 1.6, 0.4);
    glScalef(0.5, 0.2, 0.2);
    drawCube2(1);
    glPopMatrix();

    glPopMatrix();
}

void drawSeatRow() {
    glPushMatrix();

    glPushMatrix();
    for (float i = 4.5; i >= -2.5; i--) {
        glPushMatrix();
        glTranslatef(0.7, -0.3, i);
        glScalef(0.6, 0.6, 0.6);
        drawSeat();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    for (float i = 4.5; i >= -2.5; i--) {
        glPushMatrix();
        glTranslatef(-0.7, -0.3, i);
        glScalef(0.6, 0.6, 0.6);
        drawSeat();
        glPopMatrix();
    }
    glPopMatrix();

    glPopMatrix();
}

void drawWheel() {

    glPushMatrix();

    glPushMatrix();
    glScalef(2, 2, 1);
    glRotatef(90, 0, 1, 0);

    glPushMatrix();
    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_CLIP_PLANE1);

    double planeEquation[] = { 1.0, 0.0, 0.0, 0.8 };
    double planeEquation1[] = { -1.0, 0.0, 0.0, 0.8 };

    glClipPlane(GL_CLIP_PLANE0, planeEquation);
    glClipPlane(GL_CLIP_PLANE1, planeEquation1);

    glPushMatrix();
    glColor3f(0, 0, 0);
    //glScalef(1, 2, 2);
    drawSphere1(1);
    glPopMatrix();
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);

    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(90, 0, 1, 0);
    drawCylinder2(0.7, 1);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void drawWhellSet() {
    glPushMatrix();

    glPushMatrix();
    glScalef(0.3, 0.4, 0.4);
    glTranslatef(5, -3.5, 7);
    glRotatef(90, 0, 1, 0);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3, 0.4, 0.4);
    glTranslatef(5, -3.5, -7);
    glRotatef(90, 0, 1, 0);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3, 0.4, 0.4);
    glTranslatef(-5, -3.5, 7);
    glRotatef(90, 0, 1, 0);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3, 0.4, 0.4);
    glTranslatef(-5, -3.5, -7);
    glRotatef(90, 0, 1, 0);
    drawWheel();
    glPopMatrix();

    glPopMatrix();
}

void drawVehicle(int r, int g, int b) {
    glPushMatrix();

    glPushMatrix();
    drawSide(r, g, b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    drawFlow();
    glPopMatrix();

    glPushMatrix();
    drawSeatRow();
    glPopMatrix();

    glPushMatrix();
    drawWhellSet();
    glPopMatrix();

    glPopMatrix();
}

void drawBranch(float r, float h) {
    glPushMatrix();
    glColor3f(0.439, 0.275, 0);

    float k = h - 2;
    glEnable(GL_CLIP_PLANE0);
    double planeEquation[] = { 0,-1,0,k };
    glClipPlane(GL_CLIP_PLANE0, planeEquation);

    glRotatef(-90, 1, 0, 0);
    glutSolidCone(r, h, 50, 50);
    glDisable(GL_CLIP_PLANE0);
    glPopMatrix();
}

void drawLeaves(float r, float h) {
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    glRotatef(55, 0, 0, 1);
    glPushMatrix();

    glPushMatrix();
    drawBranch(r, h);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(0, h - 2, 0);
    glutSolidIcosahedron();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void drawBush(float r, float h) {
    //drawBranch(0.3, 5);
    glPushMatrix();

    glPushMatrix();
    drawBranch(r, h);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, h - 2, 0);
    glRotatef(-55, 0, 0, 1);
    drawLeaves(r - 0.1, h - 0.5);
    glPopMatrix();

    glPushMatrix();
    for (float i = 0; i < 360; i += 60) {
        glPushMatrix();
        glTranslatef(0, h - 2, 0);
        glRotatef(i, 0, 1, 0);
        drawLeaves(r - 0.1, h - 0.5);
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    for (float i = 0; i < 360; i += 90) {
        glPushMatrix();
        glTranslatef(0, h - 3, 0);
        glRotatef(i, 0, 1, 0);
        glScalef(1.35, 1.35, 1.35);
        drawLeaves(r - 0.1, h - 0.5);
        glPopMatrix();
    }
    glPopMatrix();

    glPopMatrix();

}

//light tower

void drawLiGhtTower() {
    glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    glTranslatef(0, 2.5, 0);
    glScalef(0.2,5,0.2);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(0,5,0);
    glRotatef(60,0,0,1);
    glTranslatef(0,1, 0);
    glScalef(0.2, 2, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(0, 5, 0);
    glRotatef(-60, 0, 0, 1);
    glTranslatef(0, 1, 0);
    glScalef(0.2, 2, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(1.5,5.8,0);
    glRotatef(30, 0, 0, 1);
    glPushMatrix();
    //glTranslatef(0, 5, 0);
    //glRotatef(-60, 0, 0, 1);
    glTranslatef(0, 0.1, 0);
    glScalef(0.4,0.2, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,0);
    glutSolidSphere(0.2,30,30);
    glPopMatrix();

    glPopMatrix();
    
    glPushMatrix();

    glTranslatef(-1.5, 5.8, 0);
    glRotatef(-30, 0, 0, 1);
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(0, 0.1, 0);
    glScalef(0.4, 0.2, 0.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 0);
    glutSolidSphere(0.2, 30, 30);
    glPopMatrix();

    glPopMatrix();



}


void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    gluLookAt(0.0+camX, 0.0 + camY, 10.0+camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    //lighting
  


    //
    // drawGrid();
    //drawAxes();

    //vehicle park
    glPushMatrix();
   // glTranslatef(0,0,0);
    glColor3f(0, 0, 0);
    glTranslatef(-9,0.1,-9);
    glScalef(10,0.2,10);
    glutSolidCube(1);
    glPopMatrix();

    //white line
    glPushMatrix();
    glColor3f(1, 1, 1);
    //glTranslatef(-9, 0.1, -9);
    glScalef(0.1, 0.2, 30);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(0.1, 0.2, 30);
    glutSolidCube(1);
    glPopMatrix();

   // glPushMatrix();
   // glColor3f(1, 1, 0);
   //// glRotatef(90, 0, 1, 0);
   // glTranslatef(2,0,0);
   // glScalef(0.5, 0.2, 4);
   // glutSolidCube(1);
   // glPopMatrix();

    for (int i = -2; i < 3; i++) {
        glPushMatrix();
        glColor3f(1, 1, 0);
        // glRotatef(90, 0, 1, 0);
        glTranslatef(i*0.8, 0.08, 11.3);
        glScalef(0.5, 0.05, 2);
        glutSolidCube(1);
        glPopMatrix();
    }

    //vehicle park white line

    for (int i = -3; i < 2; i++) {
        glPushMatrix();
        glTranslatef(-8,0,-7);
        glColor3f(1, 1, 1);
        glTranslatef(0,0.2,i*2);
        glRotatef(90, 0, 1, 0);
        glScalef(0.1, 0.2, 8);
        glutSolidCube(1);
        glPopMatrix();
    }

    //vehicles in the park
    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glScalef(0.2,0.2,0.2);
    glTranslatef(-30,0,-30);
    glRotatef(90, 0, 1, 0);
    drawVehicle(1,0.8,0.9);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0,1,1);
    glTranslatef(0, 0.5, 0);
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(-30, 0, -40);
    glRotatef(90, 0, 1, 0);
    drawVehicle(1, 0.8, 0.9);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(0, 0.5, 0);
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(-50, 0, -50);
    glRotatef(90, 0, 1, 0);
    drawVehicle(1, 0.8, 0.9);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(0, 0.5, 0);
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(-30, 0, -50);
    glRotatef(90, 0, 1, 0);
    drawVehicle(1, 0.8, 0.9);
    glPopMatrix();

    //draw ground
    glPushMatrix();
    drawGround();
    glPopMatrix();

    //draw road around z-axis
    glPushMatrix();
    glTranslatef(0, 0.01, 0);
    drawRoad();
    glPopMatrix();

    //draw road around x-axis
    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(0, 0.01, 0);
    drawRoad();
    glPopMatrix();

    //draw houses
    glPushMatrix();
    glTranslatef(-4,0,6);
    drawHouse(1,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, -8);
    drawHouse(1, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, -6);
    drawHouse(0, 1, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 0, -6);
    drawHouse(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, -10);
    drawHouse(1, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8, 0, -12);
    drawHouse(0.6, 0.2, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, -10);
    drawHouse(0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 0, -6);
    drawHouse(1, 1, 1);
    glPopMatrix();

    //draw big house

    glPushMatrix();
    glTranslatef(6,0,6);
    drawBigHosuse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, 10);
    drawBigHosuse1();
    glPopMatrix();

    //traffic lights

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-4,0,4.5);
    drawTrafficLight1();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(-4, 0, 4.5);
    drawTrafficLight2();
    glPopMatrix();

    double z=0;
    //vehicle
    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glScalef(0.2, 0.2, 0.2);
    glTranslated(-4, 0.5, 70-move);
    drawVehicle(1,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glScalef(0.2, 0.2, 0.2);
    glTranslated(4, 0.5, 70 - move1);
    drawVehicle(1, 1, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glRotatef(-90,0,1,0);
    glScalef(0.2, 0.2, 0.2);
    glTranslated(4, 0.5, 70 - move2);
    drawVehicle(0.9, 0.5, 0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glRotatef(-90, 0, 1, 0);
    glScalef(0.2, 0.2, 0.2);
    glTranslated(4, 0.5, 80 -move3);
    drawVehicle(1, 1, 1);
    glPopMatrix();

    //draw trees
    glPushMatrix();
    glTranslatef(5, 0, 12);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8, 0, 10);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, 10);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, 0, 5);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 0, 5);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 0, 5);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9, 0, 5);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, -5);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8, 0, -8);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 0, -2);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, -6);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9, 0, -12);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5, 0, -5);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, -7);
    drawBush(0.3, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, -13);
    drawBush(0.3, 5);
    glPopMatrix();

    

    //Light towers

    for (int i = -6; i < 6; i++) {
        glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glTranslatef(0,0,i*5);
        drawLiGhtTower();
        glPopMatrix();
    }

    for (int i = -6; i < 6; i++) {
        glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glScalef(0.5, 0.5, 0.5);
        glTranslatef(0, 0, i * 5);
        drawLiGhtTower();
        glPopMatrix();
    }


    glutSwapBuffers();

   


}

void doFrame(int v) {
    frameNumber++;
    if (frameNumber <= 100) {
       
        drawLight1(a = 1, b = 0, c = 0);
        drawLight2(d = 0, e = 0, f = 0);
        drawLight3(g = 0, h = 0, i = 0);
        drawLight4(j = 0, k = 0, l = 0);
        drawLight5(m = 0, n = 0, o = 0);
        drawLight6(p = 0, q = 1, r = 0);

        move += 0.5;
        
        if (frameNumber <= 80) {
            move1 += 0.65;
        }
        
        move2 += 1;

        if (frameNumber > 50) {
            move3 += 1;
        }

    }
    else if (frameNumber < 110) {

        drawLight1(a = 0, b = 0, c = 0);
        drawLight2(d = 1, e = 1, f = 0);
        drawLight3(g = 0, h = 0, i = 0);
        drawLight4(j = 0, k = 0, l = 0);
        drawLight5(m = 0, n = 0, o = 0);
        drawLight6(p = 0, q = 1, r = 0);

        move3 += 1;
        move2 += 1;

    }
    else if (frameNumber < 120) {

        drawLight1(a = 0, b = 0, c = 0);
        drawLight2(d = 1, e = 1, f = 0);
        drawLight3(g = 0, h = 0, i = 0);
        drawLight4(j = 1, k = 0, l = 0);
        drawLight5(m = 0, n = 0, o = 0);
        drawLight6(p = 0, q = 0, r = 0);

        move2 += 1;
    }
    else if (frameNumber < 210) {

        drawLight1(a = 0, b = 0, c = 0);
        drawLight2(d = 0, e = 0, f = 0);
        drawLight3(g = 0, h = 1, i = 0);
        drawLight4(j = 1, k = 0, l = 0);
        drawLight5(m = 0, n = 0, o = 0);
        drawLight6(p = 0, q = 0, r = 0);

        /*move += 0.2;
        move1 += 0.1;

        if (move2 >= 7) {
            move2 = 7;
        }*/
        move += 1;
        move1 += 2;
        move2 += 2;
        

    }
    else if (frameNumber < 220) {
        drawLight1(a = 1, b = 0, c = 0);
        drawLight2(d = 0, e = 0, f = 0);
        drawLight3(g = 0, h = 0, i = 0);
        drawLight4(j = 0, k = 0, l = 0);
        drawLight5(m = 1, n = 1, o = 0);
        drawLight6(p = 0, q = 0, r = 0);

        move2 += 1;

    }
    else if (frameNumber < 250) {
        drawLight1(a = 1, b = 0, c = 0);
        drawLight2(d = 0, e = 0, f = 0);
        drawLight3(g = 0, h = 0, i = 0);
        drawLight4(j = 0, k = 0, l = 0);
        drawLight5(m = 0, n = 0, o = 0);
        drawLight6(p = 0, q = 1, r = 0);

        move2 += 2;
        move3 += 2;
    }

    if (frameNumber == 250) {
        frameNumber = 0;
        move = 0;
        move1 = 0;
        move2 = 0;
        move3 = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(100, doFrame, 0);
}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        camY += 1;

    if (key == GLUT_KEY_DOWN)
        camY -= 1;

    if (key == GLUT_KEY_RIGHT)
        camX += 1;

    if (key == GLUT_KEY_LEFT)
        camX -= 1;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w')
        moveVehicle -= 0.1;
    if (key == 's')
        moveVehicle += 0.1;
    if (key == 'a')
        rotateVehicle --;
    if (key == 'd')
        rotateVehicle ++;
    if (key == 'z')
        camZ++;
    if (key == 'Z')
        camZ--;
    glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Define the Perspective projection frustum 
    // (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
    gluPerspective(120.0, aspect_ratio, 1.0, 100.0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("OpenGL Setup Test");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // keyboard function activation
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);

    glutTimerFunc(100.0, doFrame, 0);
    init();
    glutMainLoop();


    return 0;
}