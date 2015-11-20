#pragma once
struct Matrix;

struct MatrixStack {
	struct Ref {
		MatrixStack* stack;
		Matrix* matrix;
	};

	static MatrixStack Projection;
	static MatrixStack World;

	MatrixStack::Ref push();
	void pop();
};