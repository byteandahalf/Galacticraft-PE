#include "GCBlocks.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "com/mojang/minecraftpe/world/item/BlockItem.h"
#include "com/mojang/minecraftpe/world/material/Material.h"

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
Block* GCBlocks::crudeOilStatic;
Block* GCBlocks::crudeOilDynamic;
Block* GCBlocks::fuelDynamic;
Block* GCBlocks::fuelStatic;
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


void GCBlocks::initBlocks() {
	basicBlock = new BlockBasic("gcBlockCore", getNewRandomID());

	initFluids();
	registerBlocks();
}

void GCBlocks::initFluids() {
	crudeOilDynamic = new BlockFluidDynamicGC("crudeOilFlowing", getNewRandomID(), "oilFlowing");
	crudeOilStatic = new BlockFluidStaticGC("crudeOilStill", getNewRandomID(), "oilStill");
	fuelDynamic = new BlockFluidDynamicGC("fuelFlowing", getNewRandomID(), "fuelFlowing");
	fuelStatic = new BlockFluidStaticGC("fuelStill", getNewRandomID(), "fuelStill");
}

void GCBlocks::initMaterials() {
	std::unique_ptr<Material> oilMaterial(new Material(MaterialType::OIL, Material::Settings::Default, 0.0F));
	oilMaterial->liquid = true;
	oilMaterial->_setReplaceable();
	Material::addMaterial(std::move(oilMaterial));
}

void GCBlocks::registerBlocks() {
	registerBlock(basicBlock);
	registerBlock(crudeOilStatic);
	registerBlock(crudeOilDynamic);
	registerBlock(fuelDynamic);
	registerBlock(fuelStatic);
}

void GCBlocks::registerBlock(Block* block) {
	block->init();
	Block::mBlocks[block->blockId] = block;
	Item::mItems[block->blockId] = new BlockItem(block->getDescriptionId(), block->blockId - 0x100);
}

int GCBlocks::getNewRandomID() {
	int id = 0;
	while(Block::mOwnedBlocks[id] != NULL) {
		id++;
	}	
	return id;
}
