#ifndef LUASCRIPT_H_
#define LUASCRIPT_H_


#include <LuaBridge.h>
#include <iostream>
#include <vector>
#include "../STechOne.h"
extern "C"{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class Vector2f;
class Vector3f;

using namespace luabridge;

class LuaScript{
public:
	LuaScript(){
		L = 0;
	}
	LuaScript(const std::string& file){
		L = luaL_newstate();
		luaL_openlibs(L);
		//TODO - Load Swing related functions
		expose();
		luaL_dofile(L, file.c_str());

		if(luaL_loadfile(L, file.c_str())||lua_pcall(L, 0, 0, 0)){
			//TODO - implement error message
			std::cout << "Error: Failed to load " << file << std::endl;
		}
	}

	template<class T> T getValue(std::string ref){
		LuaRef t = getGlobal(L, ref.c_str());
		return t.cast<T>();
	}

	template<class T> T getValue(std::string table, std::string ref){
		LuaRef t = getGlobal(L, table.c_str());
		return t[ref.c_str()].cast<T>();
	}

private:
	void expose(){

		getGlobalNamespace(L)
			.beginNamespace("Math")
			.beginClass<Vector2f>("Vector2f")
			.addConstructor<void(*)(float, float)>()
			.addFunction("setX", &Vector2f::setX)
			.addFunction("setY", &Vector2f::setY)
			.addFunction("length", &Vector2f::getLength)
			.addFunction("normalize", &Vector2f::normalize)
			.addFunction("print", &Vector2f::print)
			.addFunction("getX", &Vector2f::getX)
			.addFunction("getY", &Vector2f::getY)
			.addProperty("x", &Vector2f::getX, &Vector2f::setX)
			.addProperty("y", &Vector2f::getX, &Vector2f::setY)
			.addFunction("info", &Vector2f::info)
			.endClass()
			.beginClass<Vector3f>("Vector3f")
			.addConstructor<void(*)(const float, const float, const float)>()
			.addProperty("x", &Vector3f::getX, &Vector3f::setX)
			.addProperty("y", &Vector3f::getY, &Vector3f::setY)
			.addProperty("z", &Vector3f::getZ, &Vector3f::setZ)
			.addFunction("setX", &Vector3f::setX)
			.addFunction("setY", &Vector3f::setY)
			.addFunction("setZ", &Vector3f::setZ)
			.addFunction("normalize", &Vector3f::normalize)
			.addFunction("length", &Vector3f::getLength)
			.addFunction("dot", &Vector3f::dot)
			.addFunction("cross", &Vector3f::cross)
			.addFunction("rotate", &Vector3f::rotate)
			.addFunction("print", &Vector3f::print)
			.addFunction("getX", &Vector3f::getX)
			.addFunction("getY", &Vector3f::getY)
			.addFunction("getZ", &Vector3f::getZ)
			.addFunction("info", &Vector3f::info)
			.endClass()
			.beginClass<Vector4f>("Vector4f")
			.addConstructor<void(*)(const float, const float, const float, const float)>()
			.addProperty("x", &Vector4f::getX, &Vector4f::setX)
			.addProperty("y", &Vector4f::getY, &Vector4f::setY)
			.addProperty("z", &Vector4f::getZ, &Vector4f::setZ)
			.addProperty("w", &Vector4f::getW, &Vector4f::setW)
			.addFunction("setX", &Vector4f::setX)
			.addFunction("setY", &Vector4f::setY)
			.addFunction("setZ", &Vector4f::setZ)
			.addFunction("setW", &Vector4f::setW)
			.addFunction("length", &Vector4f::getLength)
			.addFunction("normalize", &Vector4f::normalize)
			.addFunction("dot", &Vector4f::dot)
			.addFunction("getX", &Vector4f::getX)
			.addFunction("getY", &Vector4f::getY)
			.addFunction("getZ", &Vector4f::getZ)
			.addFunction("getW", &Vector4f::getW)
			.endClass()
			.endNamespace()
			.beginClass<Input>("Input")
			.addFunction("requestClose", &Input::requestClose)
			.addFunction("addJoystick", &Input::addJoystick)
			.addFunction("getJoystickButton", &Input::getJoystickButton)
			.addFunction("isKeyDown", &Input::isKeyDown)
			.addFunction("isMouseDown", &Input::isMouseDown)
			.addFunction("getScreenWidth", &Input::getScreenWidth)
			.addFunction("getScreenHeight", &Input::getScreenHeight)
			.endClass();
	}
	lua_State* L;
};



#endif /* LUASCRIPT_H_ */
