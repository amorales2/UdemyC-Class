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

	//know the difference between lvalues and rvalues
	//and lvalue is anything you can take the address of.
	
	//the lvalue here is value1 and the rvalue is 7.
	int value1 = 7;

	//we can take the address of value1 because it is an lvalue
	//int *pValue1 = &7; this will not compile.
	int *pValue1 = &value1;

	Test *pTest1 = &test1;
	Test *pTest2 = &getTest();

	int *pValue3 = &++value1;
	std::cout << *pValue3 << std::endl;

	return 0;
}