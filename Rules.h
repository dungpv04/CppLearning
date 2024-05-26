#pragma once

#include<iostream>
#include "Human.h"

class Rules {
	Human* human;
public:
	explicit Rules(const Human* iniHuman): human(nullptr) {
		if (iniHuman) human = new Human(*iniHuman);
	}//init constructor

	~Rules() {
		delete human;
	}//destructor

	Rules(const Rules& otherHuman): human(otherHuman.human) {} //copy constructor
	Rules(Rules&& otherHuman) noexcept : human(std::exchange(otherHuman.human, nullptr)){} //move constructor

	Rules& operator=(const Rules& otherHuman) {
		delete human;
		human = new Human(*otherHuman.human);
		return *this;
	}//copy assignment constructor

	Rules& operator=(Rules&& otherHuman) noexcept {
		std::swap(human, otherHuman.human);
		return *this;
	}

	Human* getHuman() {
		return human;
	}
};