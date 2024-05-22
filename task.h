#ifndef TASK_H // include guard
#include "SFML/Graphics.hpp"
#define TASK_H
#include <iostream>
#include "statistic.h"
#include <vector>

using namespace std;
using namespace sf;

class Task : public  Statistic {
    int state = 0;
    bool ans = true;
    int score = 0;
    int right;
    int chosen;
    int sub_state;
    int th_state;
    int lv_num;
public:
    vector<string> answers;
    vector<string> questions;
    vector<int> rightAnswers;
    Task() {};

    Task(string t, string t1, string t2, string t3, string t4, int right) {
        setVect(t, t1, t2, t3, t4);
        this->right = right;
    }

    void actions(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) override;

    void choose_backscreen(RenderWindow& window, int type);

    int virtual variants(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr, vector<string> ans, int right);
    void question(RenderWindow& window, vector<string> ans);


    void setVect(string t, string t1, string t2, string t3, string t4) {
        this->answers.push_back(t);
        this->answers.push_back(t1);
        this->answers.push_back(t2);
        this->answers.push_back(t3);
        this->answers.push_back(t4);
    }

    void SetThemeState(int s) {
        this->th_state = s;
    }

    void SetSubjectState(int s) {
        this->sub_state = s;
    }

    void SetNum(int num) {
        this->lv_num = num;
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

    int GetRight() {
        return this->right;
    }

    int GetChosen() {
        return this->chosen;
    }

    void loadFromFile(string theme);
    

};

#endif TASK_H