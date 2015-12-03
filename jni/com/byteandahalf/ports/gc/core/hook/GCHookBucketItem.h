#pragma once
#include <string>
class BucketItem;
class ItemInstance;
class Player;
#include "com/mojang/minecraftpe/client/renderer/texture/TextureUVCoordinateSet.h"

namespace GCHook {
	struct BucketItem {
		static TextureUVCoordinateSet OilBucketIcon;
		
		static void setupHooks();
		static void setupReals(void**);
		static void postSetup();
		

		static bool (*_useOn)(::BucketItem*, ItemInstance*, Player*, int, int, int, signed char, float, float, float);
		static bool useOn(::BucketItem*, ItemInstance*, Player*, int, int, int, signed char, float, float, float);
		static const TextureUVCoordinateSet& (*_getIcon)(::BucketItem*, int, int, bool);
		static const TextureUVCoordinateSet& getIcon(::BucketItem*, int, int, bool);
		static const std::string (*_buildDescriptionName)(::BucketItem*, const ItemInstance&);
		static const std::string buildDescriptionName(::BucketItem*, const ItemInstance&);
	};
};
