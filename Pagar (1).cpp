/*
    Jihan Tsabitah      5222600039
    Fadhilah Nur Aisyah 5222600042
*/
#define _USE_MATH_DEFINES
#define SOIL_IMPLEMENTATION

#include <iostream>
#include <cmath>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include "getBMP.h"


GLfloat angle = 0.0f;

static unsigned int texture[1]; // Array of texture ids.
static int id = 0; // Currently displayed texture id.

GLfloat mat_amb_diff[] = { 0.7f, 0.7f, 0.7f, 1.0f };  // Ambien dan Diffuse
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // Spekular
GLfloat mat_shininess[] = { 50.0f };                    // Nilai shininess

// Load external textures.
void loadTextures()
{
    // Local storage for image data.
    imageFile* image[1];

    // Load the image.
    image[0] = getBMP("../../Tugas/bodyMetal.bmp");

    // Create texture object texture[0]. 
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);

    // Set texture parameters for wrapping.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set texture parameters for filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void drawBalok(GLfloat width, GLfloat height, GLfloat depth) {
    GLfloat halfWidth = width / 2.0f;
    GLfloat halfHeight = height / 2.0f;
    GLfloat halfDepth = depth / 2.0f;

    glBegin(GL_QUADS);

    // Sisi depan
    glColor3f(0.7f, 0.7f, 0.7f);    //abu-abu
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glNormal3f(0.0f, 0.0f, 1.0f); // Normal untuk sisi depan
    glTexCoord2f(-1.0, 0.0); glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(2.0, 0.0); glVertex3f(halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(2.0, 2.0); glVertex3f(halfWidth, halfHeight, halfDepth);
    glTexCoord2f(-1.0, 2.0); glVertex3f(-halfWidth, halfHeight, halfDepth);

    // Sisi belakang
    glColor3f(0.7f, 0.7f, 0.7f);    //abu-abu
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1.0, 0.0); glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1.0, 1.0); glVertex3f(halfWidth, halfHeight, -halfDepth);
    glTexCoord2f(0.0, 1.0); glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Sisi kiri
    glColor3f(0.0f, 0.5f, 1.0f);    //warna biru
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1.0, 0.0); glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(1.0, 1.0); glVertex3f(-halfWidth, halfHeight, halfDepth);
    glTexCoord2f(0.0, 1.0); glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Sisi kanan
    glColor3f(0.7f, 0.7f, 0.7f);    //abu-abu
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1.0, 0.0); glVertex3f(halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(1.0, 1.0); glVertex3f(halfWidth, halfHeight, halfDepth);
    glTexCoord2f(0.0, 1.0); glVertex3f(halfWidth, halfHeight, -halfDepth);

    // Sisi atas
    glColor3f(0.0f, 0.5f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(-halfWidth, halfHeight, -halfDepth);
    glTexCoord2f(1.0, 0.0); glVertex3f(halfWidth, halfHeight, -halfDepth);
    glTexCoord2f(1.0, 1.0); glVertex3f(halfWidth, halfHeight, halfDepth);
    glTexCoord2f(0.0, 1.0); glVertex3f(-halfWidth, halfHeight, halfDepth);

    // Sisi bawah
    glColor3f(0.0f, 0.5f, 1.0f);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1.0, 0.0); glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glTexCoord2f(1.0, 1.0); glVertex3f(halfWidth, -halfHeight, halfDepth);
    glTexCoord2f(0.0, 1.0); glVertex3f(-halfWidth, -halfHeight, halfDepth);

    glEnd();

    //GLfloat mat_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f }; // Warna objek
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);


}

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE); // Normalisasi vektor normal
    glEnable(GL_DEPTH_TEST);

    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);  //eye, center, up
    glRotatef(angle, 0.0f, 1.0f, 0.0f);     //berputar pada poros y

    // Activate texture object.
    glBindTexture(GL_TEXTURE_2D, texture[id]);

    //5 horizontal
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    drawBalok(5.0f, 0.15f, 0.15f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    drawBalok(4.5f, 0.15f, 0.15f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    drawBalok(4.5f, 0.15f, 0.15f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0);
    drawBalok(4.5f, 0.15f, 0.15f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
    drawBalok(4.5f, 0.15f, 0.15f);
    glPopMatrix();

    //4 vertikal
    //pojok kanan
    glPushMatrix();
    glTranslatef(2.3, -0.17, 0.0);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //belakang pojok kanan
    glPushMatrix();
    glTranslatef(2.3, -0.3, -1.0);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //pojok kiri
    glPushMatrix();
    glTranslatef(-2.3, -0.17, 0.0);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //belakang pojok kiri
    glPushMatrix();
    glTranslatef(-2.3, -0.3, -1.0);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //kiri kedua
    glPushMatrix();
    glTranslatef(-0.8, -0.17, 0.0);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //kanan kedua
    glPushMatrix();
    glTranslatef(0.8, -0.17, 0.0);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();

    //sambungan kanan
    glPushMatrix();
    glTranslatef(2.3, 0.9, -0.5);
    drawBalok(0.15f, 0.1f, -1.0f);
    glPopMatrix();
    //sambungan kiri
    glPushMatrix();
    glTranslatef(-2.3, 0.9, -0.5);
    drawBalok(0.15f, 0.1f, -1.0f);
    glPopMatrix();

    glutSwapBuffers();

    angle += 0.07f;

    if (angle > 360.0f) angle -= 360.0f;

    /*GLfloat light_position[] = {1.0f, 0.0f, 0.0f, 0.0f}; // Cahaya datang dari arah pandang kamera
    //GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    //GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    */
}

// Initialization routine.
void setup(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    GLfloat light_position[] = { 1.0f, 0.0f, 0.0f, 0.0f }; // Cahaya datang dari arah x positif
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Warna cahaya putih

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);


    // Create texture ids.
    glGenTextures(1, texture);

    // Load external texture. 
    loadTextures();

    // Load internal texture.
    //loadChessboardTexture();

    // Specify how texture values combine with current surface color values.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    // Turn on OpenGL texturing.
    glEnable(GL_TEXTURE_2D);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);   


    glMatrixMode(GL_MODELVIEW);
}


// Main routine.
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pagar");

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutIdleFunc(drawScene);

    glutMainLoop();
}

