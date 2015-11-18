#include "BlockBasic.h"
#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/entity/player/Player.h"
#include "../entity/TestEntity.h"
#include "../includes/leveledit.h"
#include "../items/GCItems.h"

BlockBasic::BlockBasic(const std::string& name, int blockId) :
	Block(name, blockId, "stone", Material::getMaterial(MaterialType::STONE)) {
	setDestroyTime(1.0F);
	setExplodeable(15.0F);
	creativeCategory = 1;
	//initTextures();
}

void BlockBasic::initTextures() {
	iconBuffer[0] = getTextureUVCoordinateSet("deco_aluminium", 1);
	iconBuffer[1] = getTextureUVCoordinateSet("deco_aluminium", 2);
	iconBuffer[2] = getTextureUVCoordinateSet("deco_aluminium", 0);
	iconBuffer[3] = getTextureUVCoordinateSet("deco_aluminium", 2);
	iconBuffer[4] = getTextureUVCoordinateSet("oreCopper", 0);
	iconBuffer[5] = getTextureUVCoordinateSet("oreTin", 0);
	iconBuffer[6] = getTextureUVCoordinateSet("oreAluminum", 0);
	iconBuffer[7] = getTextureUVCoordinateSet("oreSilicon", 0);
	iconBuffer[8] = getTextureUVCoordinateSet("deco_copper_block", 0);
	iconBuffer[9] = getTextureUVCoordinateSet("deco_tin_block", 0);
	iconBuffer[10] = getTextureUVCoordinateSet("deco_aluminium_block", 0);
	iconBuffer[11] = getTextureUVCoordinateSet("deco_meteoriron_block", 0);
}

const TextureUVCoordinateSet& BlockBasic::getTexture(signed char side, int data) {
	switch(data) {
	case 3:
		switch(side) {
		case 0:
			return iconBuffer[1];
		case 1:
			return iconBuffer[0];
		default:
			return iconBuffer[2];
		}
	case 4:
		return iconBuffer[3];
	case 5:
		return iconBuffer[4];
	case 6:
		return iconBuffer[5];
	case 7:
		return iconBuffer[6];
	case 8:
		return iconBuffer[7];
	case 9:
		return iconBuffer[8];
	case 10:
		return iconBuffer[9];
	case 11:
		return iconBuffer[10];
	case 12:
		return iconBuffer[11];
	default:
		return data < 12 ? iconBuffer[data] : iconBuffer[0];
	}
}

int BlockBasic::getResource(Random& random, int data, int fortune) {
	if(data == 8)
		return GCItems::basicItem->itemId;

	return blockId;
}

int BlockBasic::getSpawnResourcesAuxValue(unsigned char data) {
	if(data == 8)
		return 2;

	return data;
}

int BlockBasic::getResourceCount(Random& random, int data, int fortune) {
	return 1; // TODO
}

const ItemInstance& BlockBasic::asItemInstance(BlockSource& region, const BlockPos& pos, int idk) const {
	int data = region.getData(pos);
	if(data == 8)
		return ItemInstance(this, 1, data);

	return Block::asItemInstance(region, pos, idk);
}

bool BlockBasic::use(Player& player, const BlockPos& pos) {
	player.level.addGlobalEntity(std::unique_ptr<Entity>(new TestEntity(player.region, pos)));
}

