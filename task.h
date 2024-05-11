#ifndef TASK_H // include guard
#include "SFML/Graphics.hpp"
#define TASK_H
#include <iostream>
#include "menu.h"
#include <vector>

using namespace std;
using namespace sf;

class Task {
    int state = 0;
    bool ans = true;
    int score = 0;
    vector<string> answers;
    int right;
public:
    Task() {};

    Task(string t, string t1, string t2, string t3, string t4, int right) {
        setVect(t, t1, t2, t3, t4);
        this->right = right;
    }

    void virtual play(int type);
    void backscreen(RenderWindow& window, int type) ;
    int virtual variants(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr, vector<string> ans, int right);
    void question(RenderWindow& window, vector<string> ans);


    void setVect(string t, string t1, string t2, string t3, string t4) {
        this->answers.push_back(t);
        this->answers.push_back(t1);
        this->answers.push_back(t2);
        this->answers.push_back(t3);
        this->answers.push_back(t4);
    }

    int getState() {
        return this->state;
    }

    void setState(int s) {
        this->state = s;
    }

    int getScore() {
        return this->score;
    }

    void setScore(int s) {
        this->score = s;
    }

    bool getAnswer() {
        return this->ans;
    }

};

#endif MATHTASK_H