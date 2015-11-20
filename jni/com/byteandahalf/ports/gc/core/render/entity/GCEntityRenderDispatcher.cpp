#include "GCEntityRenderDispatcher.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/renderer/entity/EntityRenderDispatcher.h"

#include "TestRenderer.h"

bool GCEntityRenderDispatcher::_Initialized = false;

EntityRenderer* GCEntityRenderDispatcher::_TestRenderer;

void GCEntityRenderDispatcher::initRenderers(EntityRenderDispatcher* dispatcher) {
	_TestRenderer = new TestRenderer(dispatcher->client.getTextures());
	
	_Initialized = true;
}

EntityRenderer* GCEntityRenderDispatcher::getRenderer(EntityRenderDispatcher* dispatcher, int rendererId) {
	if(!_Initialized)
		initRenderers(dispatcher);

	switch(rendererId) {
	case 100:
		return _TestRenderer;
		
	default:
		return NULL;
	}
}

