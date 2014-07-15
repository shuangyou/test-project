// Dxf2VG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#include "dl_dxf.h"
#include "dl_creationadapter.h"
#include "Dxf2VGFile.h"


int _tmain(int argc, _TCHAR* argv[])
{

	if (argc < 3)
	{
		std::cout<<"Usage:Dxf2VG <DXF file> <VG file>\n";
		return 0;
	}


	std::cout << "Reading file " << argv[1] << "...\n";
	Dxf2VGFile* creationClass = new Dxf2VGFile();
	DL_Dxf* dxf = new DL_Dxf();
	std::string strFile = argv[1];
	if (!dxf->in(strFile, creationClass)) { // if file open failed
		std::cerr << strFile << " could not be opened.\n";
		return 0;
	}
	
	creationClass->SaveFile(argv[2]);

	delete dxf;
	delete creationClass;


	return 0;
}

