#pragma once
struct Matrix;

struct MatrixStack {
	struct Ref {
		MatrixStack* stack;
		Matrix* matrix;
		
		~Ref();
	};

	static MatrixStack Projection;
	static MatrixStack World;

	MatrixStack::Ref push();
	void pop();
};
