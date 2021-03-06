///////////////////////////////////////////////////////////////////////////////
//BitmapFileHeader.h
//

#pragma once
//force 2 byte boundry allignment with no padding bytes
#pragma pack(2)

#include <cstdint>

struct BitmapFileHeader
{
	//2 bytes for header of file
	char header[2]{'B','M'};
	std::int32_t fileSize;
	std::int32_t reserved{0};
	std::int32_t dataOffset;

};
