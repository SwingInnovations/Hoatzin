#ifndef LUASCRIPT_H_
#define LUASCRIPT_H_


#include <LuaBridge.h>
#include <iostream>
#include <vector>
extern "C"{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

using namespace luabridge;

class LuaScript{
public:
	LuaScript(){}
	LuaScript(const std::string& file){
		L = luaL_newstate();
		//TODO - Load Swing related functions
		luaL_dofile(L, file.c_str());
		luaL_openlibs(L);
		if(luaL_loadfile(L, file.c_str())||lua_pcall(L, 0, 0, 0)){
			//TODO - implement error message
			std::cout << "Error: Failed to load " << file << std::endl;
		}

	}

	int getVarI(std::string var){
		LuaRef t = getGlobal(L, var.c_str());
		return t.cast<int>();
	}

	int getVarI(std::string tableRef, std::string var){
		LuaRef t = getGlobal(L, tableRef.c_str());
		return t[var.c_str()].cast<int>();
	}

	float getVarF(std::string var){
		LuaRef t = getGlobal(L, var.c_str());
		return (float)t.cast<float>();
	}

	float getVarF(std::string tableRef, std::string var){
		LuaRef t = getGlobal(L, tableRef.c_str());
		return t[var.c_str()].cast<float>();
	}

	double getVarD(std::string var){
		LuaRef t = getGlobal(L, var.c_str());
		return (double)t.cast<double>();
	}

	double getVarD(std::string tableRef, std::string var){
		LuaRef t = getGlobal(L, tableRef.c_str());
		return t[var.c_str()].cast<double>();
	}

	bool getVarB(std::string var){
		LuaRef t = getGlobal(L, var.c_str());
		return (bool)t.cast<bool>();
	}

	bool getVarB(std::string tableRef, std::string var){
		LuaRef t = getGlobal(L, tableRef.c_str());
		return t[var.c_str()].cast<bool>();
	}

	std::string getVarString(std::string var){
		LuaRef t = getGlobal(L, var.c_str());
		return t.cast<std::string>();
	}

	std::string getVarString(std::string tableRef, std::string var){
		LuaRef t = getGlobal(L, var.c_str());
		return t[var.c_str()].cast<std::string>();
	}

private:
	lua_State* L;
};



#endif /* LUASCRIPT_H_ */
