///////////////////////////////////////////////////////////////////////////////
//Bitmap.cpp
//
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

Bitmap::Bitmap(int width, int height) :
	m_width(width),
	m_height(height),
	m_pPixels(new uchar[m_width * m_height * 3]{})
{

}

void Bitmap::setPixel(int x, int y, uchar red, uchar green, uchar blue)
{

}

bool Bitmap::write(std::string filename)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	//TODO
	return false;
}

Bitmap::~Bitmap()
{
}
