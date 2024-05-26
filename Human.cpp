#include "Human.h"

	std::string Human::getName() {
		return name;
	}

	void Human::setName(std::string name) {
		this->name = name;
	}

	int Human::getAge() {
		return age;
	}

	void Human::setAge(int age) {
		this->age = age;
	}

	Human::Human(std::string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool Human::operator== (const Human& human) {
		return human.age == age && human.name == name;
	}
	std::ostream& operator<<(std::ostream& out, const Human& human) {
		out << "Age: " << human.age << std::endl;
		out << "Name: " << human.name;
		return out;
	}

	
