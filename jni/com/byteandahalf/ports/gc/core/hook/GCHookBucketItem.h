#pragma once
#include <string>
class BucketItem;
class ItemInstance;
#include "com/mojang/minecraftpe/client/renderer/texture/TextureUVCoordinateSet.h"

namespace GCHook {
	struct BucketItem {
		static TextureUVCoordinateSet OilBucketIcon;
		
		static void setupClass();
		static void initReals(void**);
		static void pushCreativeBuckets();
		
		static const TextureUVCoordinateSet& getIcon(::BucketItem*, int, int, bool);

		static const std::string (*_buildDescriptionName)(::BucketItem*, const ItemInstance&);
		static const std::string buildDescriptionName(::BucketItem*, const ItemInstance&);
	};
};
