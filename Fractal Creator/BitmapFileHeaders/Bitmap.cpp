///////////////////////////////////////////////////////////////////////////////
//Bitmap.cpp
//

#include <fstream>
#include <cstdint>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

Bitmap::Bitmap(int width, int height) :
	m_width(width),
	m_height(height),
	m_pPixels(new std::uint8_t[width * height * 3])
{

}

void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue)
{
	std::uint8_t* pPixel = m_pPixels.get();
	pPixel += (y * 3) * m_width + (x * 3);
	
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;

}

bool Bitmap::write(std::string filename)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	std::ofstream file;
	file.open(filename, std::ios::out, std::ios::binary);

	if (!file) 
	{
		return false;
	}

	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), m_width * m_height * 3);

	file.close();
	//this has a bit of code smell to it. 
	//this function returning false could mean 3 different things
	if (!file) {
		return false;
	}

	return true;
}

Bitmap::~Bitmap()
{
}
