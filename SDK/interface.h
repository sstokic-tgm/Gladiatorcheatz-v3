#pragma once

using CreateInterfaceFn = void*(*)(const char* name, int* returnCode);
using InstantiateInterfaceFn = void*(*)();

class InterfaceReg
{
public:
	InstantiateInterfaceFn createFn;
	const char* name;
	InterfaceReg* next;
};