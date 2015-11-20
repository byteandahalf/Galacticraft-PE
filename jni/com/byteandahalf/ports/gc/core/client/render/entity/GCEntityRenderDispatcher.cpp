#include "GCEntityRenderDispatcher.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/renderer/entity/EntityRenderDispatcher.h"

#include "Tier1RocketRenderer.h"

bool GCEntityRenderDispatcher::_Initialized = false;

EntityRenderer* GCEntityRenderDispatcher::_Tier1RocketRenderer;

void GCEntityRenderDispatcher::initRenderers(EntityRenderDispatcher* dispatcher) {
	_Tier1RocketRenderer = new Tier1RocketRenderer(dispatcher->client.getTextures());
	
	_Initialized = true;
}

EntityRenderer* GCEntityRenderDispatcher::getRenderer(EntityRenderDispatcher* dispatcher, int rendererId) {
	if(!_Initialized)
		initRenderers(dispatcher);

	switch(rendererId) {
	case 100:
		return _Tier1RocketRenderer;
		
	default:
		return NULL;
	}
}

