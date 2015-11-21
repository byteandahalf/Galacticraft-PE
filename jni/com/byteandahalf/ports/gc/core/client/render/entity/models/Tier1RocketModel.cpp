#include "Tier1RocketModel.h"
#include "com/mojang/minecraftpe/client/model/geom/ModelPart.h"
#include "com/mojang/minecraftpe/world/phys/Vec3.h"

Tier1RocketModel::Tier1RocketModel():
	Model(),
	insideRoof(0, 59, 256, 256),
	rocketBase1(0, 0, 256, 256),
	rocketBase2(0, 15, 256, 256),
	tip(248, 144, 256, 256),
	wing4d(66, 0, 256, 256),
	wing4c(66, 0, 256, 256),
	wing4e(66, 0, 256, 256),
	wing4b(66, 0, 256, 256),
	wing4a(74, 0, 256, 256),
	wing1a(60, 0, 256, 256),
	wing1b(66, 0, 256, 256),
	wing1c(66, 0, 256, 256),
	wing1e(66, 0, 256, 256),
	wing1d(66, 0, 256, 256),
	wing2e(66, 0, 256, 256),
	wing2d(66, 0, 256, 256),
	wing2c(66, 0, 256, 256),
	wing2b(66, 0, 256, 256),
	wing2a(74, 0, 256, 256),
	wing3e(66, 0, 256, 256),
	wing3d(66, 0, 256, 256),
	wing3c(66, 0, 256, 256),
	wing3b(66, 0, 256, 256),
	wing3a(60, 0, 256, 256),
	top1(192, 60, 256, 256),
	top2(200, 78, 256, 256),
	top3(208, 94, 256, 256),
	top4(216, 108, 256, 256),
	top5(224, 120, 256, 256),
	top6(232, 130, 256, 256),
	top7(240, 138, 256, 256),
	insideBottom(85, 18, 256, 256),
	insideLeft(103, 0, 256, 256),
	insidetop(85, 0, 256, 256),
	rocketBase3(0, 28, 256, 256),
	insideRight(103, 42, 256, 256),
	insideSideLeft(119, 57, 256, 256),
	insideSideRight(120, 0, 256, 256),
	insideSideBack(120, 114, 256, 256),
	insideFloor(0, 40, 256, 256) {
	
	insideRoof.addBox({-9, -45, -9}, {18, 1, 18}, 1.0);
	insideRoof.setPos({0, 23, 0});
	insideRoof.mirror = true;
	setPartAngles(insideRoof, 0, 0, 0);
	rocketBase1.addBox({-7, -1, -7}, {14, 1, 14}, 1.0);
	rocketBase1.setPos({0, 24, 0});
	rocketBase1.mirror = true;
	setPartAngles(rocketBase1, 0, 0, 0);
	rocketBase2.addBox({-6, -2, -6}, {12, 1, 12}, 1.0);
	rocketBase2.setPos({0, 24, 0});
	rocketBase2.mirror = true;
	setPartAngles(rocketBase2, 0, 0, 0);
	tip.addBox({-1, -76, -1}, {2, 18, 2}, 1.0);
	tip.setPos({0, 24, 0});
	tip.mirror = true;
	setPartAngles(tip, 0, 0, 0);
	wing4d.addBox({11, -14, -1}, {2, 8, 2}, 1.0);
	wing4d.setPos({0, 24, 0});
	wing4d.mirror = true;
	setPartAngles(wing4d, 0, 0, 0);
	wing4c.addBox({13, -12, -1}, {2, 8, 2}, 1.0);
	wing4c.setPos({0, 24, 0});
	wing4c.mirror = true;
	setPartAngles(wing4c, 0, 0, 0);
	wing4e.addBox({9.1, -15, -1}, {2, 8, 2}, 1.0F);
	wing4e.setPos({0, 24, 0});
	wing4e.mirror = true;
	setPartAngles(wing4e, 0, 0, 0);
	wing4b.addBox({15, -9, -1}, {2, 8, 2}, 1.0);
	wing4b.setPos({0, 24, 0});
	wing4b.mirror = true;
	setPartAngles(wing4b, 0, 0, 0);
	wing4a.addBox({17, -14, -1}, {1, 15, 2}, 1.0);
	wing4a.setPos({0, 24, 0});
	wing4a.mirror = true;
	setPartAngles(wing4a, 0, 0, 0);
	wing1a.addBox({-1, -14, -18}, {2, 15, 1}, 1.0);
	wing1a.setPos({0, 24, 0});
	wing1a.mirror = true;
	setPartAngles(wing1a, 0, 0, 0);
	wing1b.addBox({-1, -9, -17}, {2, 8, 2}, 1.0);
	wing1b.setPos({0, 24, 0});
	wing1b.mirror = true;
	setPartAngles(wing1b, 0, 0, 0);
	wing1c.addBox({-1, -12, -15}, {2, 8, 2}, 1.0);
	wing1c.setPos({0, 24, 0});
	wing1c.mirror = true;
	setPartAngles(wing1c, 0, 0, 0);
	wing1e.addBox({-1, -15, -11.1}, {2, 8, 2}, 1.0);
	wing1e.setPos({0, 24, 0});
	wing1e.mirror = true;
	setPartAngles(wing1e, 0, 0, 0);
	wing1d.addBox({-1, -14, -13}, {2, 8, 2}, 1.0);
	wing1d.setPos({0, 24, 0});
	wing1d.mirror = true;
	setPartAngles(wing1d, 0, 0, 0);
	wing2e.addBox({-11.1, -15, -1}, {2, 8, 2}, 1.0);
	wing2e.setPos({0, 24, 0});
	wing2e.mirror = true;
	setPartAngles(wing2e, 0, 0, 0);
	wing2d.addBox({-13, -14, -1}, {2, 8, 2}, 1.0);
	wing2d.setPos({0, 24, 0});
	wing2d.mirror = true;
	setPartAngles(wing2d, 0, 0, 0);
	wing2c.addBox({-15, -12, -1}, {2, 8, 2}, 1.0);
	wing2c.setPos({0, 24, 0});
	wing2c.mirror = true;
	setPartAngles(wing2c, 0, 0, 0);
	wing2b.addBox({-17, -9, -1}, {2, 8, 2}, 1.0);
	wing2b.setPos({0, 24, 0});
	wing2b.mirror = true;
	setPartAngles(wing2b, 0, 0, 0);
	wing2a.addBox({-18, -14, -1}, {1, 15, 2}, 1.0);
	wing2a.setPos({0, 24, 0});
	wing2a.mirror = true;
	setPartAngles(wing2a, 0, 0, 0);
	wing3e.addBox({-1, -15, 9.1}, {2, 8, 2}, 1.0);
	wing3e.setPos({0, 24, 0});
	wing3e.mirror = true;
	setPartAngles(wing3e, 0, 0, 0);
	wing3d.addBox({-1, -14, 11}, {2, 8, 2}, 1.0);
	wing3d.setPos({0, 24, 0});
	wing3d.mirror = true;
	setPartAngles(wing3d, 0, 0, 0);
	wing3c.addBox({-1, -12, 13}, {2, 8, 2}, 1.0);
	wing3c.setPos({0, 24, 0});
	wing3c.mirror = true;
	setPartAngles(wing3c, 0, 0, 0);
	wing3b.addBox({-1, -9, 15}, {2, 8, 2}, 1.0);
	wing3b.setPos({0, 24, 0});
	wing3b.mirror = true;
	setPartAngles(wing3b, 0, 0, 0);
	wing3a.addBox({-1, -14, 17}, {2, 15, 1}, 1.0);
	wing3a.setPos({0, 24, 0});
	wing3a.mirror = true;
	setPartAngles(wing3a, 0, 0, 0);
	top1.addBox({-8, -48, -8}, {16, 2, 16}, 1.0);
	top1.setPos({0, 24, 0});
	top1.mirror = true;
	setPartAngles(top1, 0, 0, 0);
	top2.addBox({-7, -50, -7}, {14, 2, 14}, 1.0);
	top2.setPos({0, 24, 0});
	top2.mirror = true;
	setPartAngles(top2, 0, 0, 0);
	top3.addBox({-6, -52, -6}, {12, 2, 12}, 1.0);
	top3.setPos({0, 24, 0});
	top3.mirror = true;
	setPartAngles(top3, 0, 0, 0);
	top4.addBox({-5, -54, -5}, {10, 2, 10}, 1.0);
	top4.setPos({0, 24, 0});
	top4.mirror = true;
	setPartAngles(top4, 0, 0, 0);
	top5.addBox({-4, -56, -4}, {8, 2, 8}, 1.0);
	top5.setPos({0, 24, 0});
	top5.mirror = true;
	setPartAngles(top5, 0, 0, 0);
	top6.addBox({-3, -58, -3}, {6, 2, 6}, 1.0);
	top6.setPos({0, 24, 0});
	top6.mirror = true;
	setPartAngles(top6, 0, 0, 0);
	top7.addBox({-2, -60, -2}, {4, 2, 4}, 1.0);
	top7.setPos({0, 24, 0});
	top7.mirror = true;
	setPartAngles(top7, 0, 0, 0);
	insideBottom.addBox({-3.9, -22, -8.9}, {8, 17, 1}, 1.0);
	insideBottom.setPos({0, 24, 0});
	insideBottom.mirror = true;
	setPartAngles(insideBottom, 0, 0, 0);
	insideLeft.addBox({3.9, -46, -8.9}, {5, 41, 1}, 1.0);
	insideLeft.setPos({0, 24, 0});
	insideLeft.mirror = true;
	setPartAngles(insideLeft, 0, 0, 0);
	insidetop.addBox({-3.9, -46, -8.9}, {8, 17, 1}, 1.0);
	insidetop.setPos({0, 24, 0});
	insidetop.mirror = true;
	setPartAngles(insidetop, 0, 0, 0);
	rocketBase3.addBox({-5, -4, -5}, {10, 2, 10}, 1.0);
	rocketBase3.setPos({0, 24, 0});
	rocketBase3.mirror = true;
	setPartAngles(rocketBase3, 0, 0, 0);
	insideRight.addBox({-8.9, -46, -8.9}, {5, 41, 1}, 1.0);
	insideRight.setPos({0, 24, 0});
	insideRight.mirror = true;
	setPartAngles(insideRight, 0, 0, 0);
	insideSideLeft.addBox({8.1, -46, -7.9}, {1, 41, 17}, 1.0);
	insideSideLeft.setPos({0, 24, 0});
	insideSideLeft.mirror = true;
	setPartAngles(insideSideLeft, 0, 0, 0);
	insideSideRight.addBox({-8.9, -46, -7.9}, {1, 41, 16}, 1.0);
	insideSideRight.setPos({0, 24, 0});
	insideSideRight.mirror = true;
	setPartAngles(insideSideRight, 0, 0, 0);
	insideSideBack.addBox({-8.9, -46, 8.1}, {17, 41, 1}, 1.0);
	insideSideBack.setPos({0, 24, 0});
	insideSideBack.mirror = true;
	setPartAngles(insideSideBack, 0, 0, 0);
	insideFloor.addBox({-9, -4, -9}, {18, 1, 18}, 1.0);
	insideFloor.setPos({0, 23, 0});
	insideFloor.mirror = true;
	setPartAngles(insideFloor, 0, 0, 0);
}

void Tier1RocketModel::render(Entity& rocketmodel, float x, float y, float z, float f1, float f2, float f3) {
	Model::render(rocketmodel, x, y, z, f1, f2, f3);
	insideRoof.render(*this, f2);
	rocketBase1.render(*this, f2);
	rocketBase2.render(*this, f2);
	tip.render(*this, f2);
	wing4d.render(*this, f2);
	wing4c.render(*this, f2);
	wing4e.render(*this, f2);
	wing4b.render(*this, f2);
	wing4a.render(*this, f2);
	wing1a.render(*this, f2);
	wing1b.render(*this, f2);
	wing1c.render(*this, f2);
	wing1e.render(*this, f2);
	wing1d.render(*this, f2);
	wing2e.render(*this, f2);
	wing2d.render(*this, f2);
	wing2c.render(*this, f2);
	wing2b.render(*this, f2);
	wing2a.render(*this, f2);
	wing3e.render(*this, f2);
	wing3d.render(*this, f2);
	wing3c.render(*this, f2);
	wing3b.render(*this, f2);
	wing3a.render(*this, f2);
	top1.render(*this, f2);
	top2.render(*this, f2);
	top3.render(*this, f2);
	top4.render(*this, f2);
	top5.render(*this, f2);
	top6.render(*this, f2);
	top7.render(*this, f2);
	insideBottom.render(*this, f2);
	insideLeft.render(*this, f2);
	insidetop.render(*this, f2);
	rocketBase3.render(*this, f2);
	insideRight.render(*this, f2);
	insideSideLeft.render(*this, f2);
	insideSideRight.render(*this, f2);
	insideSideBack.render(*this, f2);
	insideFloor.render(*this, f2);
}

void Tier1RocketModel::setPartAngles(ModelPart& part, float x, float y, float z) {
	part.rotationAngles.set(x, y, z);
	registerParts(part);
}
