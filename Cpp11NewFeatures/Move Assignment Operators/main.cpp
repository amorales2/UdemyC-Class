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
	int *m_pBuffer{ nullptr }; //good practice to initialize to nullptr

public:
	Test()
	{
		//added curly braces to zero all the bytes
		m_pBuffer = new int[SIZE] {};
	}

	Test(int i)
	{
		for (int i = 0;i < SIZE;++i)
		{
			m_pBuffer[i] = 7 * i;
		}
	}

	//copy constructor
	Test(const Test &other)
	{
		m_pBuffer = new int[SIZE] {};

		memcpy(m_pBuffer, other.m_pBuffer, SIZE*sizeof(int));

	}

	//move constructor
	Test(Test &&other)
	{
		std::cout << "Move constructor" << std::endl;
		m_pBuffer = other.m_pBuffer;
		other.m_pBuffer = nullptr;
	}


	Test &operator = (const Test &other)
	{
		return *this;
	}

	Test &operator = (Test &&other)
	{
		std::cout << "Move assignment" << std::endl;
		delete[] m_pBuffer;
		m_pBuffer = other.m_pBuffer;
		other.m_pBuffer = nullptr;
		return *this;
	}

	~Test()
	{
		//use delete with brackets for arrays
		delete[] m_pBuffer;
	}

	friend std::ostream &operator << (std::ostream &out, const Test &test);
};

std::ostream &operator <<(std::ostream &out, const Test &test)
{
	return out;
}

Test getTest()
{
	return Test();
}

void check(const Test &value)
{
	std::cout << "lValue function!" << std::endl;
}

void check(const Test &&value)
{
	std::cout << "rValue function!" << std::endl;
}

int main()
{
	std::vector<Test> vec;
	vec.push_back(Test());


	//this will invoke the move assignment operator overload
	Test test;
	test = getTest();


	return 0;
}