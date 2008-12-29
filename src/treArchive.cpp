/** -*-c++-*-
 *  \class  treArchive
 *  \file   treArchive.cpp
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

#include <treLib/treArchive.hpp>

treArchive::treArchive()
{
}

treArchive::~treArchive()
{
}

bool treArchive::removeAllFiles()
{
  // Delete and pop all tre files
  while( !treList.empty() )
    {
      delete treList.front();
      treList.pop_front();
    }
  return true;
}

/// Add file to archive
bool treArchive::addFile( const std::string &filename )
{
  // Else open was successful
  treClass *newTRE = new treClass();
  if( newTRE->readFile( filename ) )
    {
      treList.push_front( newTRE );

      return true;
    }
  else
    {
      // Delete failed tre
      delete newTRE;
    }
  
  return false;
}

/// Remove file from archive
bool treArchive::removeFile( const std::string &filename )
{
  // Don't bother looking if list is empty
  if( !treList.empty() )
    {
      for( std::list<treClass *>::iterator i = treList.begin();
	   i != treList.end();
	   ++i 
	   )
	{
	  if( filename == (*i)->getFilename() )
	    {
	      delete (*i);
	      treList.erase(i);
	      // Found and erased file
	      return true;
	    }
	}
    }
  
  // Failed to find/erase file from list
  return false;
}

void treArchive::printArchiveContents() const
{
  // Don't bother if list is empty
  if( !treList.empty() )
    {
      // Loop through all tre files
      for( std::list<treClass *>::const_iterator i = treList.begin();
	   i != treList.end();
	   ++i 
	   )
	{
	  // For each tre file list loop through its contents
	  for( std::vector<treFileRecord>::const_iterator j = 
		 (*i)->getFileRecordList().begin();
	       j != (*i)->getFileRecordList().end();
	       ++j
	       )
	    {
	      std::cout << j->getFileName() << std::endl;
	    }
	}
    }
}

std::stringstream *treArchive::getFileStream( const std::string &filename )
{
  // Don't bother if list is empty
  if( treList.empty() )
    {
      return NULL;
    }

  unsigned int index = 0;
  // Loop through all tre files
  for( std::list<treClass *>::const_iterator i = treList.begin();
       i != treList.end();
       ++i 
       )
    {
      // Ask each treClass to find the file
      if( (*i)->getFileRecordIndex( filename, index ) == true )
	{
	  // First instance of file was found, return stream
	  return ( (*i)->saveRecordAsStream( index ) );
	}
    }

  return NULL;
}
