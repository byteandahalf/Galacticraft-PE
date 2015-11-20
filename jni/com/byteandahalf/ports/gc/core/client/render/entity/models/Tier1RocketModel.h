#pragma once
#include "com/mojang/minecraftpe/client/model/models/Model.h"

class Tier1RocketModel : public Model {
	ModelPart insideRoof;
	ModelPart rocketBase1;
	ModelPart rocketBase2;
	ModelPart tip;
	ModelPart wing4d;
	ModelPart wing4c;
	ModelPart wing4e;
	ModelPart wing4b;
	ModelPart wing4a;
	ModelPart wing1a;
	ModelPart wing1b;
	ModelPart wing1c;
	ModelPart wing1e;
	ModelPart wing1d;
	ModelPart wing2e;
	ModelPart wing2d;
	ModelPart wing2c;
	ModelPart wing2b;
	ModelPart wing2a;bv
	ModelPart wing3e;
	ModelPart wing3d;
	ModelPart wing3c;
	ModelPart wing3b;
	ModelPart wing3a;
	ModelPart top1;
	ModelPart top2;
	ModelPart top3;
	ModelPart top4;
	ModelPart top5;
	ModelPart top6;
	ModelPart top7;
	ModelPart insideBottom;
	ModelPart insideLeft;
	ModelPart insidetop;
	ModelPart rocketBase3;
	ModelPart insideRight;
	ModelPart insideSideLeft;
	ModelPart insideSideRight;
	ModelPart insideSideBack;
	ModelPart insideFloor;

	void setPartAngles(ModelPart, float, float, float);

public:
	Tier1RocketModel();

	virtual void render(Entity&, float, float, float, float, float, float);
};
