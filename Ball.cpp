//
// Created by shepard on 21.06.15.
//

#include "Ball.h"
#include <GL/glut.h>
#include <cmath>

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

Ball::Ball(const Ball &ball) {
    this->x = ball.x;
    this->y = ball.y;
    this->speedX = ball.speedX;
    this->speedY = ball.speedY;
}

bool Ball::isColliding(Ball &ball) {
    GLfloat deltaX = ball.getX() - this->getX();
    GLfloat deltaY = ball.getY() - this->getY();

    GLfloat minimalDistance = this->getRadius() + ball.getRadius();

    GLfloat distance = (GLfloat)sqrt(deltaX * deltaX + deltaY * deltaY);

    return distance <= minimalDistance;
}

GLfloat Ball::getX() {
    return this->x;
}

GLfloat Ball::getY() {
    return this->y;
}

GLfloat Ball::getRadius() {
    return this->RADIUS;
}

void Ball::setX(GLfloat x) {
    this->x = x;
}

void Ball::setY(GLfloat y) {
    this->y = y;
}

void Ball::setSpeedX(GLfloat speedX) {
    this->speedX = speedX;
}

void Ball::setSpeedY(GLfloat speedY) {
    this->speedY = speedY;
}

GLfloat Ball::getSpeedX() {
    return this->speedX;
}

GLfloat Ball::getSpeedY() {
    return this->speedY;
}
