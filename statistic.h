#ifndef STATISTIC_H 
#define STATISTIC_H
#include <fstream>
#include <string>
#include <ctime>
#include "typeLevel.h"

class Statistic : public TypeLevel {
	int sub_state;
	int stat_state = 0;
	static bool done_[12 * 15];		// эти списки объ€вл€лись в main
	static bool results_[12 * 15];
public:
	void SetSubState(int s) {
		this->sub_state = s;
	}

	bool* GetDone() {
        return this->done_;
    }

    bool* GetResults() {
        return this->results_;
    }

	int GetStatState() {
		return this->stat_state;
	}

	void actions(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr) override;

	void results(RenderWindow& window, Vector2i pos_mouse, bool mouse_pr);
	
	void ReadStatistic();
	void WriteStatistic();
	void ClearStatistic();
};


#endif STATISTIC_H