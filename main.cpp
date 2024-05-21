#include <SFML/Graphics.hpp>
#include <ctime>
#include "menu.h"
#include "typeLevel.h"
#include "statistic.h"
#include "task.h"
#include "check.h"
#include "end.h"



using namespace sf;
using namespace std;

// добавила наследования. в итоге функции play и backscreen определяются только в классе Menu
// TypeLevel наследуется от Menu
// Statistic от TypeLevel
// Task от Statistic
// End наследуется от Task


int lev_process(vector<Task>& vec, int sub_st) { 
    
    int num = 0; // уровень
    int st = 0; // счёт
    int score = 0;// продолжаем игру или нет

    Statistic stat;
    
    stat.SetSubState(sub_st);
    stat.play();
    if (stat.GetStatState() == 1) {
        vec[num].setScore(0);
        vec[num].SetNum(num);
        while (num < vec.size()) {
            Check check;
            check.SetAnswers(vec[num].answers[0], vec[num].answers[1], vec[num].answers[2], vec[num].answers[3], vec[num].answers[4]);
            check.SetSubStateCheck(sub_st);
            check.SetRightAns(vec[num].GetRight());

            vec[num].SetSubjectState(sub_st);
            vec[num].SetNum(num);
            vec[num].play();
            check.SetChosenAns(vec[num].GetChosen());
            if (vec[num].getState() == 2) { // возврат в меню task
                stat.WriteStatistic();
                st = 1;
                break;
            }
            else { // уровень пройден (нажатие на ответ)
                if (vec[num].getState() == 1) {     // правильный ответ = увеличение счёта, просмотр страницы с отмеченным прав ответом и переход на след уровень
                    score++;
                    vec[num].setScore(score);
                }
                      // просмотр страницы с прав ответом, переход на след уровень
                check.play();
                if (check.GetCheckState() == 1) {
                    num++;
                    if (num >= vec.size()) {  // вопросы закончились (отвечены все 15)
                        End ending(score, vec.size());
                        stat.WriteStatistic();
                        ending.play();
                        st = 1;
                        break;
                    }
                    
                }
                else {      // возврат в меню из check
                    stat.WriteStatistic();
                    st = 1;
                    break;
                }
            }
        }
    }
    else {      // возврат в меню из statistic
        st = 1;
    }

    return st;
}

// объявление статических переменных
bool Statistic::done_[12 * 15];   // список заданий по выполнению
bool Statistic::results_[12 * 15]; // список по правильности ответов

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
        Menu start;     // открытие меню
        start.play();
        st = 0;
        if (start.getState() == 1) {
            TypeLevel type; // открытие выбора темы
            type.play();

            if (type.getSubjectState() == 0) {                          // тема - словарные слова
                st = lev_process(rus, type.getSubjectState());
            }
            else if (type.getSubjectState() == 1) {
                st = lev_process(rus, type.getSubjectState());
            }
            else if (type.getSubjectState() == 2) {
                st = lev_process(rus, type.getSubjectState());
            }
            else if (type.getSubjectState() == 3) {
                st = lev_process(rus, type.getSubjectState());
            }
            else if (type.getSubjectState() == 4) {
                st = lev_process(engl, type.getSubjectState());
            }
            else if (type.getSubjectState() == 5) {
                st = lev_process(engl, type.getSubjectState());
            }
            else if (type.getSubjectState() == 6) {
                st = lev_process(engl, type.getSubjectState());
            }
            else if (type.getSubjectState() == 7) {
                st = lev_process(engl, type.getSubjectState());
            }
            else if (type.getSubjectState() == 8) {
                st = lev_process(math, type.getSubjectState());
            }
            else if (type.getSubjectState() == 9) {
                st = lev_process(math, type.getSubjectState());
            }
            else if (type.getSubjectState() == 10) {
                st = lev_process(math, type.getSubjectState());
            }
            else if (type.getSubjectState() == 11) {
                st = lev_process(math, type.getSubjectState());
            }
            else if (type.getSubjectState() == 12) {
                st = 1; // return to menu
            }

        }
    }
    return 0;
}