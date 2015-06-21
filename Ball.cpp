//
// Created by shepard on 21.06.15.
//

#include "Ball.h"
#include <GL/glut.h>

Ball::Ball(GLfloat x, GLfloat y, GLfloat speedX, GLfloat speedY) {
    this->x = x;
    this->y = y;
    this->speedX = speedX;
    this->speedY = speedY;
}

Ball::~Ball() {

}

void Ball::draw() {
    glPushMatrix();
    glTranslatef(this->x, this->y, 0.0f);
    glutSolidSphere(this->RADIUS, 100, 10);
    glPopMatrix();
}


void Ball::move() {
    this->x += this->speedX;
    this->y += this->speedY;

    if (this->x + this->RADIUS > 1) {
        this->speedX = -this->speedX;
        this->x -= this->x + this->RADIUS - 1;
    }

    if (this->y + this->RADIUS > 1) {
        this->speedY = -this->speedY;
        this->y -= this->y + this->RADIUS - 1;
    }

    if (this->x - this->RADIUS < -1) {
        this->speedX = -this->speedX;
        this->x -= this->x - this->RADIUS + 1;
    }

    if (this->y - this->RADIUS < -1) {
        this->speedY = -this->speedY;
        this->y -= this->y - this->RADIUS + 1;
    }
}
