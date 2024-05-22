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

void loadFromFile(string filename, vector<Task>& array) {
    fstream f;
    f.open(filename);
    if (!f.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    
    string line;
    string word = "";
    if (array.size() == 0) {
        for (int i = 0; i < 15; i++) {
            vector <string> ans;
            getline(f, line);
            int j = 0;
            while (line[j] != NULL) {
                if (line[j] == ';' ) {
                    ans.push_back(word);
                    word = "";
                }
                else if (j == line.size() - 1) {
                    word += line[j];
                    ans.push_back(word);
                    word = "";
                }
                else {
                    word += line[j];
                }
                j++;
            }
            Task new_el({ ans[0], ans[1], ans[2], ans[3], ans[4], stoi(ans[5]) });
            array.push_back(new_el);
        }
    }

    

    f.close();
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
    string eng_themes[4] = { "Animals", "Food", "Actions", "Professions"};
    string math_themes[4] = { "+", "-", "*", "/" };

    int st = 1;

    string themes[12] = { "Slovarnie slova", "Udareniya", "Chasti rechi", "Pod sushestv", "Animals", "Food", "Actions", "Professions", "+", "-", "math_x", "math_del" };
    /*string filename;
    vector<vector<Task>> data[12];

    for (int i = 0; i < 12; i++) {
        filename = "resources\\files\\" + themes[i] + ".txt";
        

    }*/


    while (st == 1) {
        Menu start;     // открытие меню
        start.play();
        st = 0;
        if (start.getState() == 1) {
            TypeLevel type; // открытие выбора темы
            type.play();

            if (type.getSubjectState() == 0) {                          // тема - словарные слова
                vector<Task> v1;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v1);
                st = lev_process(v1, type.getSubjectState());
            }
            else if (type.getSubjectState() == 1) {
                vector<Task> v2;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v2);
                st = lev_process(v2, type.getSubjectState());
            }
            else if (type.getSubjectState() == 2) {
                vector<Task> v3;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v3);
                st = lev_process(v3, type.getSubjectState());
            }
            else if (type.getSubjectState() == 3) {
                vector<Task> v4;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v4);
                st = lev_process(v4, type.getSubjectState());
            }
            else if (type.getSubjectState() == 4) {
                vector<Task> v5;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v5);
                st = lev_process(v5, type.getSubjectState());
            }
            else if (type.getSubjectState() == 5) {
                vector<Task> v6;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v6);
                st = lev_process(v6, type.getSubjectState());
            }
            else if (type.getSubjectState() == 6) {
                vector<Task> v7;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v7);
                st = lev_process(v7, type.getSubjectState());
            }
            else if (type.getSubjectState() == 7) {
                vector<Task> v8;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v8);
                st = lev_process(v8, type.getSubjectState());
            }
            else if (type.getSubjectState() == 8) {
                vector<Task> v9;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v9);
                st = lev_process(v9, type.getSubjectState());
            }
            else if (type.getSubjectState() == 9) {
                vector<Task> v10;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v10);
                st = lev_process(v10, type.getSubjectState());
            }
            else if (type.getSubjectState() == 10) {
                vector<Task> v11;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v11);
                st = lev_process(v11, type.getSubjectState());
            }
            else if (type.getSubjectState() == 11) {
                vector<Task> v12;
                loadFromFile("resources\\files\\" + themes[type.getSubjectState()] + ".txt", v12);
                st = lev_process(v12, type.getSubjectState());
            }
            else if (type.getSubjectState() == 12) {
                st = 1; // return to menu
            }

        }
    }
    return 0;
}