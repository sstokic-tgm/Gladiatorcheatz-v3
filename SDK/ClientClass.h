#pragma once

#include "interface.h"
#include "dt_recv.h"

#include "IClientRenderable.h"
#include "IClientNetworkable.h"

class ClientClass;

using CreateClientClassFn = IClientNetworkable*(*)(int entNum, int serialNum);
using CreateEventFn = IClientNetworkable*(*)();

class ClientClass
{
public:
	CreateClientClassFn createFn;
	CreateEventFn createEventFn;
	char* networkName;
	RecvTable* recvTable;
	ClientClass* next;
	int classID;
};