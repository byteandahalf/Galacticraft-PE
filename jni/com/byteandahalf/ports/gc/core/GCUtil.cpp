#include "GCUtil.h"

void** GCUtil::getInstanceVtable(void* instance) {
	return *((void***) instance);
}
