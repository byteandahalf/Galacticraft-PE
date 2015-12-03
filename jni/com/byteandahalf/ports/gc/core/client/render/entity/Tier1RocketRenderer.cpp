#include "Tier1RocketRenderer.h"
#include "../../../entity/Tier1RocketEntity.h"
#include "com/mojang/minecraftpe/world/phys/Vec3.h"
#include "com/mojang/minecraftpe/client/renderer/renderer/Matrix.h"
#include "com/mojang/minecraftpe/client/renderer/renderer/MatrixStack.h"
#include "com/mojang/minecraftpe/client/renderer/texture/TexturePtr.h"
#include <cmath>

Tier1RocketRenderer::Tier1RocketRenderer(TextureGroup& group):
	EntityRenderer(group, true),
	rocketModel(Tier1RocketModel()) {
	rocketModel._texture = new mce::TexturePtr(group, "entity/minecart.png");
}

void Tier1RocketRenderer::renderTier1Rocket(Tier1RocketEntity& rocket, const Vec3& pos, float f1, float f2) {
	MatrixStack::Ref matref = MatrixStack::World.push();
	Matrix* matrix = matref.matrix;
	//const float fixedPitch = rocket.lastPitch + (rocket.pitch - rocket.lastPitch) * f2;
//	const float fixedYaw = rocket.lastYaw + (rocket.yaw - rocket.lastYaw) * f2;

	matrix->translate(pos);
	/*matrix->rotate(180.0F - f1, {0.0F, 1.0F, 0.0F});
	matrix->rotate(-fixedPitch, {0.0F, 0.0F, 1.0F});
	matrix->rotate(-fixedYaw, {0.0F, 1.0F, 0.0F});
	const float fixedRollAmplitude = rocket.rollAmplitude - f2;
	float fixedShipDamage = rocket.shipDamage - f2;

	if (fixedShipDamage < 0.0F)
		fixedShipDamage = 0.0F;

	if (fixedRollAmplitude > 0.0F) {
		const float i = rocket.hasLaunched()? (5 - floor(rocket.timeUntilLaunch / 85)) / 10 : 0.3F;
		matrix->rotate(sin(fixedRollAmplitude) * fixedRollAmplitude * i * f2, {1.0F, 0.0F, 0.0F});
		matrix->rotate(sin(fixedRollAmplitude) * fixedRollAmplitude * i * f2, {1.0F, 0.0F, 1.0F});
	}

	//this.bindEntityTexture(rocket);
	matrix->scale({-1.0F, -1.0F, 1.0F});*/

	rocketModel.render(rocket, 0.0F, 0.0F, -0.1F, 0.0F, 0.0F, 0.0625F);
}

void Tier1RocketRenderer::render(Entity& entity, const Vec3& pos, float f1, float f2) {
	renderTier1Rocket((Tier1RocketEntity&) entity, pos, f1, f2);
}
