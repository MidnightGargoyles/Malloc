/*
Copyright (c) 2014 Victor Karlsson

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
*/

#ifndef CLOAKED_HIPSTER_XMLPARSER_H
#define CLOAKED_HIPSTER_XMLPARSER_H

#include <map>
#include <functional>
#include <string>
#include <vector>

namespace tinyxml2 { class XMLElement; }

namespace ch {

	class HookID {
	private:
		HookID(std::string key, unsigned long int uid) {
			this->key = key;
			this->uid = uid;
		}
		std::string key;
		unsigned int uid;

		friend class XMLParser;
	};

	class HookObject {
	private:
		HookObject(unsigned int uid, std::function<void(tinyxml2::XMLElement*)> func) {
			this->uid = uid;
			this->func = func;
		}

		unsigned int uid;
		std::function<void(tinyxml2::XMLElement*)> func;

		friend class XMLParser;
	};
	
	class XMLParser {
	public:
		bool parse(std::string xmlfile);

		HookID hook(std::string key, std::function<void(tinyxml2::XMLElement*)> func);
		void unhook(HookID& id);

		void clear();
		void clear(std::string key);
	private:
		void parseElement(tinyxml2::XMLElement* element);
		std::map<std::string, std::vector<HookObject>> freg;

	};	
}


#endif