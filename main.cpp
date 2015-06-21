#include <iostream>
#include <GL/glut.h>
#include "Ball.h"

#define WINDOW_POSITION_X 50
#define WINDOW_POSITION_Y 25
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define ANIMATION_INTERVAL 20

Ball ball = Ball(0.0f, 0.0f, 0.05f, 0.01f);

void draw(void) {
    std::cout << "Redraw." <<std::endl;

    // Black background
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Add light
    GLfloat position[] = {2.0f, 2.0f, -2.5f, 0.1f};
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    ball.draw();

    glutSwapBuffers();
}

void windowStatusHandler(int windowState) {
    std::cout << "windowStatusHandler - window status! " << windowState << std::endl;
    draw();
}

void timerHandler(int value) {
    ball.move();
    glutPostRedisplay();
    glutTimerFunc(ANIMATION_INTERVAL, timerHandler, value);
}


int main(int argc, char **argv) {
    std::cout << "Initializating..." << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("floatin balls");

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(draw);
    glutWindowStatusFunc(windowStatusHandler);

    glutTimerFunc(ANIMATION_INTERVAL, timerHandler, 0);

    glutMainLoop();
    return 0;
}
