#pragma once
class Entity;

class EntityShaderManager {
	char filler[48];

public:
	EntityShaderManager();
	
	virtual ~EntityShaderManager();
	virtual int _getOverlayColor(Entity&, float) const;
};

