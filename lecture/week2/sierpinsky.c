//
// Created by Dominic Furchert on 25.02.2025.
//
#include <time.h>
#include <GL/glut.h>


// Triangle coordinates (centered at origin)
float triX1 = 0, triY1 = 1;
float triX2 =  -1, triY2 = -1;
float triX3 =  1, triY3 =  -1;


void displayTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);  // Red color

    glBegin(GL_TRIANGLES);
    glVertex2f(triX1, triY1);
    glVertex2f(triX2, triY2);
    glVertex2f(triX3, triY3);
    glEnd();

    glFlush();
}

void sierp(float x, float y, float h, int d) {
    if (d>0) {

        float r = (float)rand()/(float)RAND_MAX;
        float g = (float)rand()/(float)RAND_MAX;
        float b = (float)rand()/(float)RAND_MAX;

        glColor3f(r, g, b);  // Red color

        glBegin(GL_TRIANGLES);
        glVertex2f(x, y + h);      // Top vertex
        glVertex2f(x - h, y - h);  // Bottom-left
        glVertex2f(x + h, y - h);  // Bottom-right
        glEnd();

        glFlush();

        sierp(x, y + h / 2, h / 2, d - 1);    // Top sub-triangle
        sierp(x - h / 2, y - h / 2, h / 2, d - 1);  // Bottom-left sub-triangle
        sierp(x + h / 2, y - h / 2, h / 2, d - 1);  // Bottom-right sub-triangle

    }
}

void display() {
    displayTriangle();
    sierp(0,0,1,7);
}

// Function to set new triangle coordinates
void setTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    triX1 = x1; triY1 = y1;
    triX2 = x2; triY2 = y2;
    triX3 = x3; triY3 = y3;
    glutPostRedisplay();  // Redraw the window with new coordinates
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT Dynamic Shapes");
    srand(time(NULL));

    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color
    glutDisplayFunc(display);

    glutMainLoop();  // Start event loop
    return 0;
}
