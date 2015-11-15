#pragma once
class BucketItem;
class ItemInstance;

namespace GCHook {
	struct BucketItem {
		static void initHooks();
		static void initReals();
		static void pushCreativeBuckets();

		static const std::string& (*_buildDescriptionName)(BucketItem*, const ItemInstance&);
		static const std::string& buildDescriptionName(BucketItem*, const ItemInstance&);
	};
};
