/** -*-c++-*-
 *  \class  testArchive
 *  \file   testArchive.hpp
 *  \author Kenneth R. Sewell III

 treLib is used for the creation and deconstruction of .TRE files.
 Copyright (C) 2006-2009 Kenneth R. Sewell III

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


int main( int argc, char **argv )
{

  treArchive archive;

  archive.addFile( "../tre/bottom.tre" );
  archive.addFile( "../tre/data_animation_00.tre" );
  archive.addFile( "../tre/data_music_00.tre" );
  archive.addFile( "../tre/data_other_00.tre" );
  archive.addFile( "../tre/data_sample_00.tre" );
  archive.addFile( "../tre/data_sample_01.tre" );
  archive.addFile( "../tre/data_sample_02.tre" );
  archive.addFile( "../tre/data_sample_03.tre" );
  archive.addFile( "../tre/data_sample_04.tre" );
  archive.addFile( "../tre/data_skeletal_mesh_00.tre" );
  archive.addFile( "../tre/data_skeletal_mesh_01.tre" );
  archive.addFile( "../tre/data_sku1_00.tre" );
  archive.addFile( "../tre/data_sku1_01.tre" );
  archive.addFile( "../tre/data_sku1_02.tre" );
  archive.addFile( "../tre/data_sku1_03.tre" );
  archive.addFile( "../tre/data_sku1_04.tre" );
  archive.addFile( "../tre/data_sku1_05.tre" );
  archive.addFile( "../tre/data_sku1_06.tre" );
  archive.addFile( "../tre/data_sku1_07.tre" );
  archive.addFile( "../tre/data_static_mesh_00.tre" );
  archive.addFile( "../tre/data_static_mesh_01.tre" );
  archive.addFile( "../tre/data_texture_00.tre" );
  archive.addFile( "../tre/data_texture_01.tre" );
  archive.addFile( "../tre/data_texture_02.tre" );
  archive.addFile( "../tre/data_texture_03.tre" );
  archive.addFile( "../tre/data_texture_04.tre" );
  archive.addFile( "../tre/data_texture_05.tre" );
  archive.addFile( "../tre/data_texture_06.tre" );
  archive.addFile( "../tre/data_texture_07.tre" );
  archive.addFile( "../tre/default_patch.tre" );
  archive.addFile( "../tre/patch_01.tre" );
  archive.addFile( "../tre/patch_02.tre" );
  archive.addFile( "../tre/patch_03.tre" );
  archive.addFile( "../tre/patch_04.tre" );
  archive.addFile( "../tre/patch_05.tre" );
  archive.addFile( "../tre/patch_06.tre" );
  archive.addFile( "../tre/patch_07.tre" );
  archive.addFile( "../tre/patch_08.tre" );
  archive.addFile( "../tre/patch_09.tre" );
  archive.addFile( "../tre/patch_10.tre" );
  archive.addFile( "../tre/patch_11_00.tre" );
  archive.addFile( "../tre/patch_11_01.tre" );
  archive.addFile( "../tre/patch_11_02.tre" );
  archive.addFile( "../tre/patch_11_03.tre" );
  archive.addFile( "../tre/patch_12_00.tre" );
  archive.addFile( "../tre/patch_13_00.tre" );

  archive.printArchiveContents();

  std::stringstream *sstr =
    archive.getFileStream("appearance/mesh/ply_corl_house_lg_s01_fp1_r0_mesh_r0_l2.msh" );

  if( NULL != sstr )
    {
      sstr->seekg( 0, std::ios_base::end );
      std::cout << "Size: " << sstr->tellg() << std::endl;
      delete sstr;
    }

  archive.removeAllFiles();

  return 0;
}
