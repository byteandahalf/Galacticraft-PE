#pragma once

class TextureUVCoordinateSet {
	float minU;
	float minV;
	float maxU;
	float maxV;
	int width;
	int height;
	int index;
	int file;

public:
	TextureUVCoordinateSet();
	TextureUVCoordinateSet(float, float, float, float, int, int);

	float getMinU();
	float getMinV();
	float getMaxU();
	float getMaxV();
	void setUV(float, float, float, float);
	float getInterpolatedU(float);
	float getInterpolatedV(float);
};
