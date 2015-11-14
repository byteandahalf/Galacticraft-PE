#include "GCBlocks.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/world/item/BlockItem.h"
#include "BlockBasic.h"
#include "BlockFluidDynamicGC.h"
#include "BlockFluidStaticGC.h"

Block* GCBlocks::breatheableAir;
Block* GCBlocks::brightAir;
Block* GCBlocks::brightBreatheableAir;
Block* GCBlocks::brightLamp;
Block* GCBlocks::treasureChestTier1;
Block* GCBlocks::landingPad;
Block* GCBlocks::unlitTorch;
Block* GCBlocks::unlitTorchLit;
Block* GCBlocks::oxygenDistributor;
Block* GCBlocks::oxygenPipe;
Block* GCBlocks::oxygenCollector;
Block* GCBlocks::oxygenCompressor;
Block* GCBlocks::oxygenSealer;
Block* GCBlocks::oxygenDetector;
Block* GCBlocks::nasaWorkbench;
Block* GCBlocks::fallenMeteor;
Block* GCBlocks::basicBlock;
Block* GCBlocks::airLockFrame;
Block* GCBlocks::airLockSeal;
Block* GCBlocks::crudeOil;
Block* GCBlocks::fuel;
Block* GCBlocks::refinery;
Block* GCBlocks::fuelLoader;
Block* GCBlocks::landingPadFull;
Block* GCBlocks::spaceStationBase;
Block* GCBlocks::fakeBlock;
Block* GCBlocks::sealableBlock;
Block* GCBlocks::cargoLoader;
Block* GCBlocks::parachest;
Block* GCBlocks::solarPanel;
Block* GCBlocks::radioTelescope;
Block* GCBlocks::machineBase;
Block* GCBlocks::machineBase2;
Block* GCBlocks::machineTiered;
Block* GCBlocks::aluminumWire;
Block* GCBlocks::glowstoneTorch;
Block* GCBlocks::blockMoon;
Block* GCBlocks::cheeseBlock;
Block* GCBlocks::spinThruster;
Block* GCBlocks::screen;
Block* GCBlocks::telemetry;
Block* GCBlocks::slabGCHalf;
Block* GCBlocks::slabGCDouble;
Block* GCBlocks::tinStairs1;
Block* GCBlocks::tinStairs2;
Block* GCBlocks::moonStoneStairs;
Block* GCBlocks::moonBricksStairs;
Block* GCBlocks::wallGC;

std::vector<Block*> GCBlocks::creativeBlocks;

void GCBlocks::initBlocks() {
	basicBlock = new BlockBasic(200, /*"gcBlockCore"*/"stone");

	registerFluids();
	registerBlocks();
}

void GCBlocks::registerFluids() {
	crudeOilDynamic = new BlockFluidDynamicGC("crudeOilFlowing", 201, "oil");
	crudeOilStatic = new BlockFluidStaticGC("crudeOilStill", 202, "oil");
	//fuel = new BlockFluidDynamicGC("fuelFlowing", 202, "fuel");
}

void GCBlocks::registerBlocks() {
	registerBlock(basicBlock);
	registerBlock(crudeOil);
	registerBlock(fuel);
}

void GCBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Item::mItems[block->blockId] = new BlockItem(block->blockId - 0x100);
	creativeBlocks.push_back(block);
}
