#ifndef FLOATING_BALLS_BALL_H
#define FLOATING_BALLS_BALL_H


#include <GL/gl.h>

class Ball {
public:
    Ball(GLfloat x, GLfloat y, GLfloat speedX, GLfloat speedY);
    Ball(const Ball &ball);
    ~Ball();
    void draw();
    void move();

private:
    const GLfloat RADIUS = 0.2f;
    GLfloat x;
    GLfloat y;
    GLfloat speedX;
    GLfloat speedY;
};


#endif //FLOATING_BALLS_BALL_H
