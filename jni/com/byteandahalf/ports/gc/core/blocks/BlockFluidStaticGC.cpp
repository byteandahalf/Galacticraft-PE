#include "BlockFluidStaticGC.h"
#include "com/mojang/minecraftpe/world/material/Material.h"

BlockFluidStaticGC::BlockFluidStaticGC(const std::string& name, int blockId, const std::string& asset):
	LiquidBlockStatic(name, blockId, blockId - 1, Material::getMaterial(MaterialType::OIL), asset, asset) {
}

