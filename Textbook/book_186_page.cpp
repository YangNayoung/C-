#include <iostream>
using namespace std;

class Animal {
public:
	virtual ~Animal() {}
	virtual void SoundSpeak() = 0;
	virtual void EatDiets(const char* eat) const = 0;
};

class Dog : public Animal {
public:
	virtual void SoundSpeak() {
		cout << "俺家府 港港" << " ";
	}
	virtual void EatDiets(const char* eat) const {
		cout << eat << endl;
	}
};

class Cat : public Animal {
public:
	virtual void SoundSpeak() {
		cout << "绊剧捞 具克" << " ";
	}
	virtual void EatDiets(const char* eat) const {
		cout << eat << endl;
	}
};
