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


//static_casts are compile-time casts. This can introduce bugs into your code
//because there is no runtime checking. If you cast a superclass object into 
//a baseclass pointer for example, you could try to call functions on it
//accidently which will cause the program to crash or not work properly.
int main()
{
	Parent parent;
	Brother brother;

	//if we want to cast back to a subclass object, we need to use a
	//dynamic cast. in this situation, this will return a nullptr because
	//we are trying to cast a parent object to a child variable
	//Parent *ppb = &parent;

	//this will work fine because the cast makes sense.
	//also note that the parent class must have polimorphic behavior in order
	//to do this as well. We added a virtual function to make this compile.
	Parent *ppb = &brother;
	Brother *pbb = dynamic_cast<Brother *>(ppb);

	if (pbb == nullptr)
	{
		std::cout<<"Invalid cast" << std::endl;
	}
	else
	{
		std::cout << pbb << std::endl;
	}
	return 0;
}