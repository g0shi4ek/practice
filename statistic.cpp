#include "statistic.h"

void Statistic::actions(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
	backscreen(window, "menu_back.jpg");
	results(window, pos_mouse, mouse_pr);
	this->ReadStatistic();
}

// чтение данных из файла в два массива (выполнение и правильность)
void Statistic::ReadStatistic() {
	ifstream f("resources\\statistic.txt");
	if (!f.is_open()) {
		cerr << "Error file opening." << endl;
	}
	string line;

	int i = 0;
	while (getline(f, line)) {
		this->done_[i] = line[0] - '0';
		this->results_[i] = line[1] - '0';
		i++;
	}

	time_t now = time(0);
	tm* ltm = localtime(&now);

	if (ltm->tm_wday == 1) {
		cout << "tests update" << endl;
	}
	f.close();
}

// вывод на экран статистики раздела (темы) (какие задания выполнены, какие правильно, неправильно)
void Statistic::results(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) {
	Font font;
	font.loadFromFile("resources\\Lineyka.ttf");

	// всю эту часть можно вынести в отдельную функцию и потом использовать в конце теста для результатов (в end), но в таком случае значение sub_state становится null и всё ломается
	vector <string> opts = { "Slovarnie slova", "Udareniya", "Chasti rechi", "Pod sushestv", "Animals", "Food", "Actions", "Furniture", "+", "-", "*", "|" };
	Message t(opts[this->sub_state], false, 2);
	t.setFont(font);
	t.setPos({ 576 - t.getTxt().getLocalBounds().width / 2,150 });
	t.print(window);

	RectangleShape q({ 750,450 });
	q.setPosition({ 200, 250 });
	q.setFillColor(Color(255, 255, 255, 990));
	window.draw(q);

	vector<ButtonType2> butns;

	float x = 225;
	float y = 125;
	for (int i = 0; i < 15; i++) {
		if (i % 5 == 0) {
			y += 150;
			x = 225;
		}
		if (this->GetDone()[this->sub_state * 15 + i] == 1 && this->GetResults()[this->sub_state * 15 + i] == 1) {
			ButtonType2 btn(font, to_string(i + 1), 50, { x, y }, Color(186, 255, 151), pos_mouse);
			btn.GetBotton()->setOutlineColor(Color(17, 149, 30));
			btn.GetBotton()->setOutlineThickness(3);
			butns.push_back(btn);
			btn.print(window);
		}
		else if (this->GetDone()[this->sub_state * 15 + i] == 1 && this->GetResults()[this->sub_state * 15 + i] == 0) {
			ButtonType2 btn(font, to_string(i + 1), 50, { x, y }, Color(255, 149, 145), pos_mouse);
			btn.GetBotton()->setOutlineColor(Color(223, 52, 58));
			btn.GetBotton()->setOutlineThickness(3);
			butns.push_back(btn);
			btn.print(window);
		}
		else if (this->GetDone()[this->sub_state * 15 + i] == 0) {
			ButtonType2 btn(font, to_string(i + 1), 50, { x, y }, Color(184, 216, 253), pos_mouse);
			btn.GetBotton()->setOutlineColor(Color(81, 161, 181));
			btn.GetBotton()->setOutlineThickness(3);
			butns.push_back(btn);
			btn.print(window);
		}
		x += 150;
	}
	// конец части, которую можно вынести

	ButtonType1 begin(font, (string)"Begin", { 400, 60 }, { 375, 750 }, Color(255, 255, 255, 965), pos_mouse, 1);
	begin.GetBotton()->setOutlineColor(Color(0, 119, 255));
	begin.GetBotton()->setOutlineThickness(3);
	begin.print(window);

	ButtonType1 rtn_menu(font, (string)"Return to menu", { 400, 60 }, { 50, 10 }, Color(255, 255, 255, 965), pos_mouse, 1);
	rtn_menu.print(window);

	if (mouse_pr == true && begin.isMouse(pos_mouse) == true) {
		window.close();
		this->stat_state = 1;
	}
	if (mouse_pr == true && rtn_menu.isMouse(pos_mouse) == true) {
		window.close();
		this->stat_state = 0;
	}
}

// запись в файл статистики, чтобы прогресс запоминался, НО файлик полноценно не меняется и программа запоминает новые данные только на несколько минут.
	// вероятно, нужно как-то по-другому подключить файл
void Statistic::WriteStatistic() {
	fstream f("resources\\statistic.txt");
	if (!f.is_open()) {
		cerr << "Error file opening." << endl;
		return;
	}

	for (int i = 0; i < 180; i++) {
		f << this->GetDone()[i] << this->GetResults()[i] << endl;
	}

	f.close();
}

// очищение прогресса, может пригодится, если сделать обновление тестов каждую неделю
void Statistic::ClearStatistic() {
	ofstream f("resources\\statistic.txt", ios::out);
	if (!f.is_open()) {
		cerr << "Error file opening." << endl;
		return;
	}
	for (int i = 0; i < 180; i++) {
		f << "00" << endl;
	}

	f.close();
}