#pragma once
#include "DatValue.h"
#include <vector>
#include <random>


class Marks : public DatValue {
private:
	std::vector<int> _marks;
public:
	Marks() {
		for (int i = 0; i < 5; i++) {
			_marks.push_back(1 + rand() % 5);
		}
	}

	Marks(const Marks& m) {
		_marks = m._marks;
	}

	virtual void Print(std::ostream& os)const override {
		std::cout << " | " << _marks[0] << " | " << _marks[1] << " | " << _marks[2] << " | " << _marks[3] << " | " << _marks[4] << " |\n";
	}

	virtual DatValue* GetCopy()const override {
		Marks* copy = new Marks(*this);
		return copy;
	}
};