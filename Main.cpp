#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <numeric>
#include "Human.h"
#include "Rules.h"

template<typename T>T Max(T a, T b) {
	return(a > b) ? a : b;
}

void printx2(int a) {
	std::cout << a * 2<<" ";
}

int main()
{
	std::vector<int> a = { 5, 1, 2, 4, 3, 6 };

	sort(a.begin(), a.end(), [](int b, int a) {
		return a > b;
	});

	for_each(a.begin(), a.end(), [](int a) {
		std::cout << a<<" ";
	});

	std::cout << std::endl;
	auto square = [](int i) {
		return i * i;
	};

	std::cout<<square(5);

	int sum = std::accumulate(a.begin(), a.end(),0, [](int a, int b) {
		return a + b;
	});

	

	std::cout << sum;
	std::cout << std::endl;

	for_each(a.begin(), a.end(), [&](int a) {
		a *= 2;
	});

	for_each(a.begin(), a.end(), [](int a) {
		std::cout << a<<" ";
	});

	std::unique_ptr<Human> John(new Human("John", 10));
	std::unique_ptr<Human> Jim(new Human("John", 20));

	if (*John == *Jim) std::cout << "Yes";
	else std::cout << "No";
	
	std::cout <<std::endl<< *Jim;
	std::cout << std::endl << Max<std::string>("dung", "ha")<<std::endl;

	Rules humanA(new Human);
	humanA.getHuman()->setAge(20);
	humanA.getHuman()->setName("Dung");
	std::cout << *humanA.getHuman()<<std::endl;

	Rules humanB(new Human);
	humanB = std::move(humanA);
	std::cout << *humanB.getHuman()<<std::endl;
	std::cout << *humanA.getHuman()<<std::endl;
	Rules humanC(new Human);
	humanC = humanB;
	std::cout << *humanC.getHuman();
	
}

