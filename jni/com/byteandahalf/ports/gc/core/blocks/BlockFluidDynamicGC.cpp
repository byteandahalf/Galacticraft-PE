#include "BlockFluidDynamicGC.h"
#include "com/mojang/minecraftpe/world/material/Material.h"

BlockFluidDynamicGC::BlockFluidDynamicGC(const std::string& name, int blockId, const std::string& asset):
	LiquidBlockDynamic(name, blockId, Material::mMaterials[5], asset, asset) {
}

int BlockFluidDynamicGC::getTickDelay(LiquidBlock* liquid, BlockSource& region) {
	// TODO: Add custom Material for oil, and make this change based on that.
	return 25;
}
