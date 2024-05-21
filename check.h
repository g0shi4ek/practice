#ifndef CHECK_H // include guard
#include "SFML/Graphics.hpp"
#define CHECK_H
#include <iostream>
#include "task.h"

class Check : public Task {
    vector<string> answ;
    int sub_state;
    int check_state;
    int right_ans;
    int chosen_ans;
public:
    void SetAnswers(string a, string a1, string a2, string a3, string a4) {
        this->answ.push_back(a);
        this->answ.push_back(a1);
        this->answ.push_back(a2);
        this->answ.push_back(a3);
        this->answ.push_back(a4);
    }
    void SetSubStateCheck(int s) {
        this->sub_state = s;
    }

    void SetRightAns(int r) {
        this->right_ans = r;
    }

    void SetChosenAns(int a) {
        this->chosen_ans = a;
    }

    int GetCheckState() {
        return this->check_state;
    }

    void actions(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) override;
    void check_answer(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr);
};


#endif CHECK_H