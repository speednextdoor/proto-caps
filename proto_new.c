// set proto caps

uintptr_t maxcappies = 0x3FFFFFF00i64 | 0xFFFFFFFFFFFFFCFFui64; // max caps a2 will be asigned to and its pointer not val

using setcap_def = __int64(__fastcall*)(Proto* a1, uintptr_t* a2); // proto, max caps
setcap_def setprotocap = reinterpret_cast<setcap_def>(offset(0xC3B6C0)); // easily can find this anywhere where execution begins e.g loadstring

// usage

		Closure* closurepointer = (Closure*)topointer(luasexstate, -1); // private not giving topointer, so use lua_topointer :)  index neg 1
		setprotocap((Proto*)closurepointer->l.p, &maxcappies);
