///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>

class Animal
{
private:

public:
	//pure virtual functions
	virtual void run() = 0;
	virtual void speak() = 0;
};

class Dog : public Animal
{
private:

public:
	virtual void speak()
	{
		std::cout << "Woof!" << std::endl;
	}
};

class Labrador : public Dog
{
public:
	Labrador()
	{
		std::cout << "new labrador" << std::endl;
	}
	virtual void run()
	{
		std::cout << "Labrador running" << std::endl;
	}
};
void test(Animal &a)
{
	a.run();
}

int main()
{
	Labrador lab;
	lab.speak();
	lab.run();

	//pointers to animals
	Animal *animals[5];
	animals[0] = &lab;
	animals[0]->speak();

	test(lab);
	return 0;
}