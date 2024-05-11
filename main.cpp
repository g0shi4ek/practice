#include <SFML/Graphics.hpp>
#include "menu.h"
#include "typeLevel.h"
#include "task.h"
#include "end.h"



using namespace sf;
using namespace std;


int lev_process(vector<Task>& vec, int type) { 
    int num = 0; // уровень
    int st = 0; // продолжаем игру или нет
    vec[num].setScore(0);
    while (num < vec.size()) {
        vec[num].play(type);
        if (vec[num].getState() == 2) { // возврат в меню
            st = 1;
            break;
        }
        else if (vec[num].getState() == 1) { // ответ правильный => на следующий уровень
            num++;
            if (num < vec.size()) {
                vec[num].setScore(num);
            }
            else {
                End ending(num, vec.size());
                ending.play(type);
                st = 1;
                break;
            }
        }
        else if (vec[num].getState() == 0) { // ответ неправильный => окно с результатом 
            End ending(num, vec.size());
            ending.play(type);
            num = 0;
            st = 1;
            break;
        }
    }
    return st;
}

int main() { // мб сделать классом game но хз как
#ifdef WIN32
    system("chcp 65001");
#else
    setlocale(LC_ALL, "Russian");
#endif
    string rus_themes[4] = { "Udareniya", "Slovarnie slova", "Morfemi", "Chasti rechi"};
    string eng_themes[4] = { "Animals", "Food", "Actions", "Furniture?"};
    string math_themes[4] = { "+", "-", "*", "/" };

    int st = 1;
    vector<Task> math; // наверное стоит перенести либо в текстовый файл и от туда брать либо в отдельную функцию
    math.push_back({"100/50 = ?", "20", "2", "4", "25", 2 });
    math.push_back({ "42/7 = ?", "5", "7", "6", "1", 3 });
    math.push_back({ "3645/5 = ?", "729", "855", "467", "1123", 1 });
    math.push_back({ "4/2 = ?", "1", "2", "5", "3", 2 });

    vector<Task> rus;
    rus.push_back({ "rabbit", "biirg", "rhsrg", "srh", "ojo", 1}); // короче тут суть в том что 1 - задание потом 4 варианта ответа и последнее номер отета который правильный
    rus.push_back({ "vugi", "oshrg", "bodthh", "srhs", "srhs", 1});
    

    vector<Task> engl; 
    engl.push_back({ "rabbit", "biirg", "rhsrg", "srh", "ojo", 1 });
    engl.push_back({ "vugi", "oshrg", "bodthh", "srhs", "srhs", 1 });

    while (st == 1) {
        Menu start;
        st = 0;
        if (start.getState() == 1) { // переключение на выбор раздела тут косяк почему-то только со второго нажатия переключает | ИСПРАВЛЕНО (убрала наследование)
            TypeLevel type;
            if (type.getState() == 1) {
                st = lev_process(rus, 1); // раздел русского
            }
            if (type.getState() == 2) {
                st = lev_process(engl, 2);
            }

            if (type.getState() == 3) {
                st = lev_process(math, 3);
            }

            if (type.getState() == 4) {
                st = 1;
            }
        }
    }

    return 0;
}