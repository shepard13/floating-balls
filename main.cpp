#include <iostream>
#include <GL/glut.h>

void draw(void) {
    std::cout << "Redraw." <<std::endl;

    // Black background
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Add light
    GLfloat position[] = {2.0f, 2.0f, -2.5f, 0.1f};
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    // Teapot
    glutSolidSphere(0.1, 100, 10);

    glutSwapBuffers();
}

void windowStatusHandler(int windowState) {
    std::cout << "windowStatusHandler - window status! " << windowState << std::endl;
    draw();
}

int main(int argc, char **argv) {
    std::cout << "Initializating..." << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(600, 600);
    glutCreateWindow("floatin balls");

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(draw);
    glutWindowStatusFunc(windowStatusHandler);

    glutMainLoop();
    return 0;
}
