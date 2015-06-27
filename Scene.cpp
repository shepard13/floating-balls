//
// Created by shepard on 21.06.15.
//

#include <iostream>
#include "Scene.h"

void Scene::draw() {
    std::vector<Ball *>::iterator iterator = this->balls.begin();
    while (iterator != this->balls.end()) {
        (*iterator)->draw();
        iterator++;
    }
}

Scene::Scene(int ballsCount) {
    Ball ball = Ball(0.0f, 0.0f, 0.05f, 0.01f);
    this->add(ball);

    Ball ball2 = Ball(1.0f, 0.0f, 0.05f, 0.003f);
    this->add(ball2);
}

Scene::~Scene() {

}

void Scene::add(Ball &ball) {
    this->balls.push_back(new Ball(ball));
}

void Scene::tick() {
    // Move balls
    std::vector<Ball *>::iterator iterator = this->balls.begin();
    while (iterator != this->balls.end()) {
        this->moveBall(**iterator);
        iterator++;
    }

    // Check for collisions
    std::vector<Ball *>::iterator outerIterator = this->balls.begin();
    while (outerIterator != this->balls.end()) {

        std::vector<Ball *>::iterator innerIterator = this->balls.begin();
        while (innerIterator != this->balls.end()) {
            if (&(*innerIterator) == &(*outerIterator)) {
                innerIterator++;
                continue;
            }

            std::cout << "Is colliding: " <<
                    (*innerIterator)->isColliding(**outerIterator) << std::endl;
            innerIterator++;
        }

        outerIterator++;
    }

}

void Scene::moveBall(Ball &ball) {
    ball.setX(ball.getX() + ball.getSpeedX());
    ball.setY(ball.getY() + ball.getSpeedY());

    if (ball.getX() + ball.getRadius() > 1) {
        ball.setSpeedX(-ball.getSpeedX());
        ball.setX(-ball.getRadius() + 1);
    }

    if (ball.getY() + ball.getRadius() > 1) {
        ball.setSpeedY(-ball.getSpeedY());
        ball.setY(-ball.getRadius() + 1);
    }

    if (ball.getX() - ball.getRadius() < -1) {
        ball.setSpeedX(-ball.getSpeedX());
        ball.setX(ball.getRadius() - 1);
    }

    if (ball.getY() - ball.getRadius() < -1) {
        ball.setSpeedY(-ball.getSpeedY());
        ball.setY(ball.getRadius() - 1);
    }
}
