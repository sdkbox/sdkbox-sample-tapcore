#include "PluginTapcoreLua.hpp"
#include "PluginTapcore/PluginTapcore.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginTapcoreLua_PluginTapcore_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTapcore",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTapcoreLua_PluginTapcore_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginTapcore::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTapcore:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTapcoreLua_PluginTapcore_init'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginTapcoreLua_PluginTapcore_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginTapcore)");
    return 0;
}

int lua_register_PluginTapcoreLua_PluginTapcore(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginTapcore");
    tolua_cclass(tolua_S,"PluginTapcore","sdkbox.PluginTapcore","",nullptr);

    tolua_beginmodule(tolua_S,"PluginTapcore");
        tolua_function(tolua_S,"init", lua_PluginTapcoreLua_PluginTapcore_init);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginTapcore).name();
    g_luaType[typeName] = "sdkbox.PluginTapcore";
    g_typeCast["PluginTapcore"] = "sdkbox.PluginTapcore";
    return 1;
}
TOLUA_API int register_all_PluginTapcoreLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	std::stringstream ss("sdkbox");
    std::vector<std::string> nsvec;
    std::string item;
    while (std::getline(ss, item, '.')) {
        nsvec.push_back(item);
    }
    int nsLen = nsvec.size();
    item = nsvec.front();
    nsvec.erase(nsvec.begin());

    tolua_module(tolua_S, item.c_str(), 0);
    tolua_beginmodule(tolua_S, item.c_str());

    while (nsvec.size() > 0) {
        item = nsvec.front();
        nsvec.erase(nsvec.begin());
        lua_pushstring(tolua_S, item.c_str()); // m name
        lua_rawget(tolua_S, -2);             // m value
        if (!lua_istable(tolua_S, -1)) {
            lua_pop(tolua_S, 1);             // m
            lua_newtable(tolua_S);           // m t
            lua_pushstring(tolua_S, item.c_str()); // m t name
            lua_pushvalue(tolua_S, -2);      // m t name t
            lua_rawset(tolua_S, -4);         // m t
        }
    }

	lua_register_PluginTapcoreLua_PluginTapcore(tolua_S);

	if (nsLen > 1) {
        lua_pop(tolua_S, nsLen - 1); // m
    }
	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

