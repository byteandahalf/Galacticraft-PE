#pragma once
#include <string>
class Level;
class ChunkSource;
class CompoundTag;
class Packet;
class Weather;
class Seasons;
class CircuitSystem;
class MoveEntityPacketData;
#include "../LevelListener.h"
#include "../GeneratorType.h"
#include "DimensionId.h"

class Dimension : public LevelListener {
public:
	Dimension(Level&, DimensionId);

	char filler[12]; // 4
	DimensionId id; // 16
	bool ultraWarm; // 20
	bool ceiling; // 21
	char filler2[64]; // 24
	Level& level; // 88
	std::unique_ptr<ChunkSource> chunkSource; // 92
	BlockSource& blockSource; // 96 DEPRECATEDUSEPLAYERREGIONINSTEAD
	Weather* weather; // 100
	Seasons* seasons; // 104
	std::unique_ptr<CircuitSystem> circuitSystem; // 108
	char filler3[68];

	virtual ~Dimension();
	virtual void onBlockChanged(BlockSource&, const BlockPos&, FullBlock, FullBlock, int);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
	virtual void onNewChunkFor(Player&, LevelChunk&);
	virtual void init();
	virtual void tick();
	virtual void updateLightRamp();
	virtual bool isNaturalDimension() const;
	virtual bool isValidSpawn(int, int) const;
	virtual const Vec3& getFogColor(float) const;
	virtual float getFogDistanceScale() const;
	virtual bool isFoggyAt(int, int) const;
	virtual int getCloudHeight() const;
	virtual bool mayRespawn() const;
	virtual bool hasGround() const;
	virtual int getSpawnYPosition();
	virtual bool hasBedrockFog();
	virtual float getClearColorScale();
	virtual const std::string& getName() const = 0;
	virtual void load(const CompoundTag&);
	virtual void save(CompoundTag&);
	virtual void sendDimensionPackets();
	virtual void sendBroadcast(const Packet&, Player*);
	virtual void addMoveEntityPacket(const MoveEntityPacketData&);
	virtual void addSetEntityMotionPacket(Entity&);
	virtual long getTimeOfDay(int, float) const;

	std::unique_ptr<ChunkSource> _createGenerator(GeneratorType);
	const Vec3& getSkyColor(const Entity&, float);
	bool hasCeiling();
	void setCeiling(bool);
	bool isUltraWarm();
	void setUltraWarm(bool);
	Level& getLevel() const;

	static std::unique_ptr<Dimension> createNew(DimensionId, Level&);
};
