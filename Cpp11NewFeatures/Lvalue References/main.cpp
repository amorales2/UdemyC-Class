///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <ostream>
#include <vector>
#include <string>

class Test
{
private:
	static const int SIZE = 100;
	int *m_pBuffer;

public:
	Test()
	{
		std::cout << "Constructor" << std::endl;
		//added curly braces to zero all the bytes
		m_pBuffer = new int[SIZE] {};
	}

	Test(int i)
	{
		std::cout << "Parameterized constructor" << std::endl;

		for (int i = 0;i < SIZE;++i)
		{
			m_pBuffer[i] = 7 * i;
		}
	}

	Test(const Test &other)
	{
		std::cout << "copy constructor" << std::endl;
		m_pBuffer = new int[SIZE] {};

		memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));

	}

	Test &operator = (const Test &other)
	{
		std::cout << "assignment" << std::endl;
		return *this;
	}

	~Test()
	{
		std::cout << "destructor" << std::endl;
		//use delete with brackets for arrays
		delete[] m_pBuffer;
	}

	friend std::ostream &operator << (std::ostream &out, const Test &test);
};

std::ostream &operator <<(std::ostream &out, const Test &test)
{
	out << "Hello from test";
	return out;
}

Test getTest()
{
	return Test();
}

int main()
{
	Test test1 = getTest();
	std::cout << test1 << std::endl;

	std::vector<Test> vec;
	vec.push_back(Test());

	//we are creating a null reference here and binding it to an lvalue
	Test &rTest1 = test1;
	
	//here, we are binding the reference to an rvalue
	//const is needed here (at least for the gcc compiler)
	const Test &rTest2 = getTest();


	Test test2(Test(1));

	return 0;
}