#pragma once

#include <malloc.h>

#include <rbgo-types.h>

namespace rbgo {
/*
DataSource
Provider of data for testing VPArray in the src/dev zone.
Class DataSource is the interface to table data inside
dev/DataSource.cpp, and the only way to access it.
*/
class TstDsTblEspPs {

	Tu8 itr=0;

public:
	Tu8 colCount();
	const char** colNames();
	Tu8 rowCount();
	const char** rowFms();
	const char* rowSep();
	const char** iterate(bool init=false);
};

}//ns
