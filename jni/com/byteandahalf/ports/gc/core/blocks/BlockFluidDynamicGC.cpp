#include "BlockFluidDynamicGC.h"
#include "../includes/leveledit.h"
#include "com/mojang/minecraftpe/world/phys/Vec3.h"

BlockFluidDynamicGC::BlockFluidDynamicGC(const std::string& name, int blockId, const std::string& asset):
	LiquidBlockDynamic(name, blockId, Material::getMaterial(MaterialType::OIL), asset, asset) {
}

int BlockFluidDynamicGC::getTickDelay(LiquidBlock* liquid, BlockSource& region) {
	if(liquid->material.isType(MaterialType::OIL))
		return 25;
		
	return 0;
}

bool BlockFluidDynamicGC::isBlockSolid(LiquidBlock* liquid, BlockSource& region, const BlockPos& pos, int side) {
	Material& material = region.getMaterial(pos);
	return material == liquid->material? false : (side == 1? true : (material == Block::mIce->material? false : region.getBlock(pos)->isSolid()));
}

Vec3 BlockFluidDynamicGC::_getFlow(LiquidBlock* liquid, BlockSource& region, const BlockPos& region) {
	Vec3 myVec(0.0F, 0.0F, 0.0F);
	int renderDepth1 = liquid->getRenderedDepth(region, pos);

    for(int direction = 0; direction < 4; ++direction) {
        int xx = pos.x;
        int yy = pos.z;

        if(direction == 0) xx = pos.x - 1;
        if(direction == 1) yy = pos.z - 1;
		if(direction == 2) ++xx;
        if(direction == 3) ++yy;

        int renderDepth2 = liquid->getRenderedDepth(region, {xx, pos.y, yy});
        int multiplier;

		if(renderDepth2 < 0) {
			if(!region.getMaterial({xx, pos.y, yy}).getBlocksMotion()) {
                renderDepth2 = liquid->getRenderedDepth(region, {xx, pos.y - 1, yy});

                if(renderDepth2 >= 0) {
                    multiplier = renderDepth2 - (renderDepth1 - 8);
                    myVec.extend(((xx - pos.x) * multiplier), ((pos.y - pos.y) * multiplier), ((yy - pos.z) * multiplier));
                }
            }
        }
        else if(renderDepth2 >= 0) {
            multiplier = renderDepth2 - renderDepth1;
            myVec.extend(((xx - pos.x) * multiplier), ((pos.y - pos.y) * multiplier), ((yy - pos.z) * multiplier));
        }
    }

    if(region.getData({pos.x, pos.y, pos.z}) >= 8) {
        bool needsToNormalize = false;

        if (needsToNormalize || isBlockSolid(liquid, region, {pos.x, pos.y, pos.z - 1}, 2))
            needsToNormalize = true;
        if(needsToNormalize || isBlockSolid(liquid, region, {pos.x, pos.y, pos.z + 1}, 3))
            needsToNormalize = true;
        if(needsToNormalize || isBlockSolid(liquid, region, {pos.x - 1, pos.y, pos.z}, 4))
            needsToNormalize = true;
        if(needsToNormalize || isBlockSolid(liquid, region, {pos.x + 1, pos.y, pos.z}, 5))
            needsToNormalize = true;
        if(needsToNormalize || isBlockSolid(liquid, region, {pos.x, pos.y + 1, pos.z - 1}, 2))
            needsToNormalize = true;
        if(needsToNormalize || isBlockSolid(liquid, region, {pos.x, pos.y + 1, pos.z + 1}, 3))
            needsToNormalize = true;
        if(needsToNormalize || isBlockSolid(liquid, region, {pos.x - 1, pos.y + 1, pos.z}, 4))
            needsToNormalize = true;
        if(needsToNormalize || isBlockSolid(liquid, region, {pos.x + 1, pos.y + 1, pos.z}, 5))
            needsToNormalize = true;

        if(needsToNormalize)
            myVec = myVec.normalize().extend(0.0F, -6.0F, 0.0F);
    }

    myVec.normalize();
    return myVec;
}
