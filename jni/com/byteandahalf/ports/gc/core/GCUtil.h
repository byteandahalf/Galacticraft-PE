#pragma once

struct GCUtil {
	static void** getInstanceVtable(void*);
	
	static int getNextAvailableItemID();
};

