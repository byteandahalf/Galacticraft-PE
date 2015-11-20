#pragma once
class EntityRenderer;
class EntityRenderDispatcher;

struct GCEntityRenderDispatcher {
	static bool _Initialized;
	static EntityRenderer* _TestRenderer;
	
	static void initRenderers(EntityRenderDispatcher*);
	static EntityRenderer* getRenderer(EntityRenderDispatcher*, int);
};

