#pragma once
class Block;

class GCBlocks {
public:
	static void initBlocks();
	static void initFluids();
	static void initMaterials();

	static void registerBlocks();
	static void registerBlock(Block*);
	
	static int getNewRandomID();
	
	static Block* breatheableAir;
	static Block* brightAir;
	static Block* brightBreatheableAir;
	static Block* brightLamp;
	static Block* treasureChestTier1;
	static Block* landingPad;
	static Block* unlitTorch;
	static Block* unlitTorchLit;
	static Block* oxygenDistributor;
	static Block* oxygenPipe;
	static Block* oxygenCollector;
	static Block* oxygenCompressor;
	static Block* oxygenSealer;
	static Block* oxygenDetector;
	static Block* nasaWorkbench;
	static Block* fallenMeteor;
	static Block* basicBlock;
	static Block* airLockFrame;
	static Block* airLockSeal;
	static Block* crudeOilStatic;
	static Block* crudeOilDynamic;
	static Block* fuelStatic;
	static Block* fuelDynamic;
	static Block* refinery;
	static Block* fuelLoader;
	static Block* landingPadFull;
	static Block* spaceStationBase;
	static Block* fakeBlock;
	static Block* sealableBlock;
	static Block* cargoLoader;
	static Block* parachest;
	static Block* solarPanel;
	static Block* radioTelescope;
	static Block* machineBase;
	static Block* machineBase2;
	static Block* machineTiered;
	static Block* aluminumWire;
	static Block* glowstoneTorch;
	static Block* blockMoon;
	static Block* cheeseBlock;
	static Block* spinThruster;
	static Block* screen;
	static Block* telemetry;
	static Block* slabGCHalf;
	static Block* slabGCDouble;
	static Block* tinStairs1;
	static Block* tinStairs2;
	static Block* moonStoneStairs;
	static Block* moonBricksStairs;
	static Block* wallGC;
};
