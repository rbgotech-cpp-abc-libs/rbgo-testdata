#pragma once

#include <rbgo-types.h>

namespace rbgo {

#if RTD_Ti8
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
#endif

}//ns
