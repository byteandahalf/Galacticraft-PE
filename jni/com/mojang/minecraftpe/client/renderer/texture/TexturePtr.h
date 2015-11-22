#pragma once
#include <string>
class TextureGroup;

namespace mce {
	class Texture;
	
	struct TexturePtr {
		TextureGroup& group;
		mce::Texture* _texture;
		const std::string& path;
		
		TexturePtr();
		TexturePtr(TextureGroup&, const std::string&);
		
		TexturePtr& operator=(TexturePtr&&);
	};
};

