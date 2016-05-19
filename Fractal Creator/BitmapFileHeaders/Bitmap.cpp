///////////////////////////////////////////////////////////////////////////////
//Bitmap.cpp
//
#include "Bitmap.h"

Bitmap::Bitmap(int width, int height) :
	m_width(width),
	m_height(height),
	m_pPixels(new uchar[m_width * m_height * 3])
{

}

void Bitmap::setPixel(int x, int y, uchar red, uchar green, uchar blue)
{

}

bool Bitmap::write(std::string filename)
{
	//TODO
	return false;
}

Bitmap::~Bitmap()
{
}
