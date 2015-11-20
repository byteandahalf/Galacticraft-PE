#pragma once
class EntityRenderer;
class EntityRenderDispatcher;

struct GCEntityRenderDispatcher {
	static bool _Initialized;
	static EntityRenderer* _Tier1RocketRenderer;
	
	static void initRenderers(EntityRenderDispatcher*);
	static EntityRenderer* getRenderer(EntityRenderDispatcher*, int);
};

