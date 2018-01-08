#ifndef __PluginTapcoreJS_h__
#define __PluginTapcoreJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginTapcoreJS_PluginTapcore(JSContext *cx, JS::HandleObject global);
void register_all_PluginTapcoreJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginTapcoreJS_PluginTapcore(JSContext *cx, JSObject* global);
void register_all_PluginTapcoreJS(JSContext* cx, JSObject* obj);
#endif
#endif

