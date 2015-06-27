#ifndef FLOATING_BALLS_BALL_H
#define FLOATING_BALLS_BALL_H


#include <GL/gl.h>

class Ball {
public:
    Ball(GLfloat x, GLfloat y, GLfloat speedX, GLfloat speedY);
    Ball(const Ball &ball);
    ~Ball();
    void draw();

    bool isColliding(Ball &ball);

    GLfloat getX();
    void setX(GLfloat x);

    GLfloat getY();
    void setY(GLfloat y);

    GLfloat getSpeedX();
    void setSpeedX(GLfloat speedX);

    GLfloat getSpeedY();

    void setSpeedY(GLfloat speedY);

    GLfloat getRadius();

private:
    const GLfloat RADIUS = 0.2f;
    GLfloat x;
    GLfloat y;
    GLfloat speedX;
    GLfloat speedY;
};


#endif //FLOATING_BALLS_BALL_H
