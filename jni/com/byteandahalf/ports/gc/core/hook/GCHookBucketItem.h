#pragma once
#include <string>
class BucketItem;
class ItemInstance;
#include "com/mojang/minecraftpe/client/renderer/texture/TextureUVCoordinateSet.h"

namespace GCHook {
	struct BucketItem {
		static TextureUVCoordinateSet OilBucketIcon;
		
		static void setupHooks();
		static void setupReals(void**);
		static void postSetup();
		

		static const TextureUVCoordinateSet& (*_getIcon)(::BucketItem*, int, int, bool);
		static const TextureUVCoordinateSet& getIcon(::BucketItem*, int, int, bool);
		static std::string (*_buildDescriptionName)(::BucketItem*, const ItemInstance&);
		static std::string buildDescriptionName(::BucketItem*, const ItemInstance&);
	};
};
