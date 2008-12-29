/** -*-c++-*-
 *  \class  treDataBlock
 *  \file   treDataBlock.hpp
 *  \author Kenneth R. Sewell III

 treLib is used for the creation and deconstruction of .TRE files.
 Copyright (C) 2006,2007 Kenneth R. Sewell III
 
 This file is part of treLib.
 
 treLib is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 treLib is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with treLib; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <fstream>
#include <string>
#include <vector>

#ifndef TREDATABLOCK_HPP
#define TREDATABLOCK_HPP

class treDataBlock
{
public:
    treDataBlock();
    ~treDataBlock();
    
    bool readAndUncompress(
	std::ifstream &file,
	const int &format,
	const unsigned int &compSize,
	const unsigned int &uncompSize
	);

    bool compressAndWrite(
	std::ofstream &file,
	const int &format
	);

    bool isChecksumCorrect( const unsigned int &csum );
    void calculateMD5sum( const char *mem, const unsigned int &memSize );
    const std::vector<unsigned char> &getMD5sum() const;

    void freeCompressedData();
    void freeUncompressedData();

    char *getCompressedDataPtr();
    char *getUncompressedDataPtr();

    bool allocateUncompressedData( const unsigned int &size );

    bool setUncompressedData( 
	const char *newData,
	const unsigned int &newDataSize
	);

    unsigned int getUncompressedSize() const
	{
	    return uncompressedSize;
	}
    unsigned int getCompressedSize() const
	{
	    return compressedSize;
	}

protected:
    unsigned int checksum;
    unsigned int uncompressedSize;
    unsigned int compressedSize;
    std::vector<unsigned char> md5sum;
    char *data;
    char *compData;
    
};

#endif
