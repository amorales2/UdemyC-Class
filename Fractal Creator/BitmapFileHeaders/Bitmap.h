#pragma once
#include <string>
#include <cstdint>
#include <memory>
typedef unsigned char uchar;


class Bitmap
{
private:
	int m_width{ 0 };
	int m_height{ 0 };
	std::unique_ptr < uchar[] > m_pPixels{ nullptr };

public:
	Bitmap(int width, int height);

	void setPixel(int x, int y, uchar red, uchar green, uchar blue);
	bool write(std::string filename);

	virtual ~Bitmap();
};