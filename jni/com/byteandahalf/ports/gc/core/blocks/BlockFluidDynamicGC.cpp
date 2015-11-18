#include "BlockFluidDynamicGC.h"
#include "com/mojang/minecraftpe/world/material/Material.h"

BlockFluidDynamicGC::BlockFluidDynamicGC(const std::string& name, int blockId, const std::string& asset):
	LiquidBlockDynamic(name, blockId, Material::getMaterial(MaterialType::OIL), asset, asset) {
}

int BlockFluidDynamicGC::getTickDelay(LiquidBlock* liquid, BlockSource& region) {
	if(liquid->material.isType(MaterialType::OIL))
		return 25;
		
	return 0;
}
