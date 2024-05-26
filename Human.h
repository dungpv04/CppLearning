#pragma once

#include <iostream>

class Human {
	std::string name;
	int age;
	friend std::ostream& operator<<(std::ostream& out, const Human& human);
public:
	std::string getName();
	void setName(std::string name);
	int getAge();
	void setAge(int age);
	Human(std::string name = "", int age = 0);
	bool operator== (const Human& human);

	//default member functions (follow the Zero Rule)
	Human(const Human&) = default;
	Human(Human&&) = default;
	Human& operator=(const Human&) = default;
	Human& operator=(Human&&) = default;
	~Human() = default;
	
};