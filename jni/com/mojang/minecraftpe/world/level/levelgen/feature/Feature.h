#pragma once
class BlockSource;
class BlockPos;
class Random;

class Feature {
	bool manuallyPlaced;
	unsigned char updateNotify;
	
public:
	Feature(bool);
	
	virtual ~Feature();
	virtual bool place(BlockSource&, const BlockPos&, Random&) const = 0;
};

