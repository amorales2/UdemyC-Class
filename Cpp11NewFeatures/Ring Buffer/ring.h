#pragma once

template<class T>
class ring
{
private:
	int m_pos;
	int m_size;
	T *m_values;

public:
	class iterator;

public:
	ring(int size) :
		m_pos(0),
		m_size(size),
		m_values(0)
	{
		m_values = new T[size];
	}

	~ring()
	{
		//must free the memory when you destroy the object
		delete[] m_values;
	}
	int size()
	{
		return m_size;
	}
	void add(T value)
	{
		m_values[m_pos++] = value;

		if (m_pos == m_size)
		{
			m_pos = 0;
		}
	}

	T& get(int pos)
	{
		return m_values[pos];
	}
};


template<class T>
class ring<T>::iterator
{
public:
	void print()
	{
		std::cout << "Hello from iterator: " << T() << std::endl;
	}
};