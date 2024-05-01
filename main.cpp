#include <SFML/Graphics.hpp>
#include "menu.h"
#include "typeLevel.h"
#include "task.h"
#include "end.h"


using namespace sf;
using namespace std;


int lev_process(vector<Task>& vec) {
    int num = 0;
    int st = 0;
    vec[num].setScore(0);
    while (num < vec.size()) {
        vec[num].play();
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
                ending.play();
                st = 1;
                break;
            }
        }
        else if (vec[num].getState() == 0) { // ответ неправильный => окно с результатом 
            End ending(num, vec.size());
            ending.play();
            num = 0;
            st = 1;
            break;
        }
    }
    return st;
}

int main() // мб сделать классом game но хз как
{
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
        if (start.getState() == 1) { // переключение на выбор раздела тут косяк почему-то только со второго нажатия переключает
            TypeLevel type;
            
            if (type.getState() == 1) {
                st = lev_process(rus); // раздел русского
            }
            if (type.getState() == 2) {
                st = lev_process(engl);
            }

            if (type.getState() == 3) {
                st = lev_process(math);
            }

            if (type.getState() == 4) {
                st = 1;
            }
        }
    }

    return 0;
}