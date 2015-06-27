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
    void moveBall(Ball &ball);

private:
    const GLfloat MIN_X = -1;
    const GLfloat MAX_X = 1;
    const GLfloat MIN_Y = -1;
    const GLfloat MAX_Y = 1;
    void add(Ball &ball);
    std::vector<Ball*> balls;
};


#endif //FLOATING_BALLS_SCENE_H
