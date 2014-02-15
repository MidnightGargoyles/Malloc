/*
Copyright (c) 2014 Victor Karlsson

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
*/

#include "XMLParser.h"
#include "tinyxml2.h"

static unsigned int uid = 0;

namespace ch {
	void XMLParser::clear() {
		freg.clear();
	}

	void XMLParser::clear(std::string key) {
		freg[key].clear();
	}

	HookID XMLParser::hook(std::string key, std::function<void(tinyxml2::XMLElement*)> func) {
		uid++;
		freg[key].push_back(HookObject(uid, func));
		return HookID(key,uid);
	}

	void XMLParser::unhook(HookID& id) {
		auto it = freg.find(id.key);
		if( it != freg.end() ) {
			auto& v = it->second;
			for(unsigned int i = 0; i < v.size(); i++) {
				if( id.uid == v[i].uid ) {
					v.erase(v.begin()+i);
					i--;
				}
			}
			if( v.empty() ) freg.erase(id.key);
		}
	}

	bool XMLParser::parse(std::string xmlfile) {
		tinyxml2::XMLDocument doc;
		if( doc.LoadFile(xmlfile.c_str()) != tinyxml2::XML_NO_ERROR ) return false;
		tinyxml2::XMLElement* e = doc.FirstChildElement();
		parseElement(e);
		return true;
	}

	void XMLParser::parseElement(tinyxml2::XMLElement* e) {
		if(!e) return;

		auto it = freg.find(e->Value());
		if( it != freg.end() ) { 
			auto& v = it->second;
			for(auto& f : v ) f.func(e);
		}

		parseElement(e->FirstChildElement());
		parseElement(e->NextSiblingElement());
	}
}