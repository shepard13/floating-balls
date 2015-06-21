//
// Created by shepard on 21.06.15.
//

#ifndef FLOATING_BALLS_SCENE_H
#define FLOATING_BALLS_SCENE_H


#include <vector>
#include "Ball.h"

class Scene {
public:
    Scene(int ballsCount);
    ~Scene();
    void draw();
    void tick();

private:
    void add(Ball &ball);
    std::vector<Ball*> balls;
};


#endif //FLOATING_BALLS_SCENE_H
