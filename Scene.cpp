//
// Created by shepard on 21.06.15.
//

#include "Scene.h"

void Scene::draw() {
    std::vector<Ball*>::iterator iterator = this->balls.begin();
    while (iterator != this->balls.end()) {
        (*iterator)->draw();
        iterator++;
    }
}

Scene::Scene(int ballsCount) {
    Ball ball = Ball(0.9f, 0.0f, 0.05f, 0.01f);
    this->add(ball);
    Ball ball2 = Ball(0.8f, 0.0f, -0.05f, 0.02f);
    this->add(ball2);
    Ball ball3 = Ball(0.7f, 0.0f, -0.05f, 0.03f);
    this->add(ball3);
    Ball ball4 = Ball(0.6f, 0.0f, -0.05f, 0.04f);
    this->add(ball4);
    Ball ball5 = Ball(0.5f, 0.0f, -0.05f, 0.5f);
    this->add(ball5);
}

Scene::~Scene() {

}

void Scene::add(Ball &ball) {
    this->balls.push_back(new Ball(ball));
}

void Scene::tick() {
    std::vector<Ball*>::iterator iterator = this->balls.begin();
    while (iterator != this->balls.end()) {
        (*iterator)->move();
        iterator++;
    }
}
