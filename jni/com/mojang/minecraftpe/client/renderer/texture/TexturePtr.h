#pragma once
#include <string>
class TextureGroup;

namespace mce {
	struct TexturePtr {
		TextureGroup& textures;
		int idk;
		const std::string& path;
		
		TexturePtr();
		TexturePtr(TextureGroup&, const std::string&);
		
		TexturePtr& operator=(TexturePtr&&);
	};
};

