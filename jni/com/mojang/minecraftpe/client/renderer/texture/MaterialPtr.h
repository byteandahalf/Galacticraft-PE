#pragma once
#include <string>

namespace mce {
	class RenderMaterialGroup;
	
	struct MaterialPtr {
		mce::RenderMaterialGroup& group;
		int idk;
		const std::string& path;
		
		MaterialPtr();
		MaterialPtr(mce::RenderMaterialGroup&, const std::string&);
		MaterialPtr(mce::MaterialPtr&&);
		
		MaterialPtr& operator=(MaterialPtr&&);
	};
};

