///////////////////////////////////////////////////////////////////////////////
//main.cpp
//
#include <iostream>


class Parent
{
public:
	virtual void speak()
	{
		std::cout << "Parent Speaking!" << std::endl;
	}
};

class Brother : public Parent
{

};

class Sister : public Parent
{

};

//this type of cast is strange
int main()
{
	Parent parent;
	Brother brother;
	Sister sister;

	//we are basically attempting to cast a brother to a sister object.
	//this makes no sense in the majority of situations. Static_cast works but
	//is dangerious and unclear. reinterpret_cast is used for this situation.
	// this will perform a binary cast with even less checking than static_cast.
	//If this situation arises, you might be doing something wrong.
	Parent *ppb = &brother;
	Sister *pbb = reinterpret_cast<Sister *>(ppb);

	if (pbb == nullptr)
	{
		std::cout << "Invalid cast" << std::endl;
	}
	else
	{
		std::cout << pbb << std::endl;
	}
	return 0;
}