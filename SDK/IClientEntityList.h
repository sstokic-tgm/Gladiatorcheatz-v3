#pragma once

class IClientEntity;
class IClientNetworkable;
class CBaseHandle;

class IClientEntityList
{
public:
	virtual IClientNetworkable* GetClientNetworkable(int entNum) = 0;
	virtual void* vtablepad0x1(void) = 0;
	virtual void* vtablepad0x2(void) = 0;
	virtual IClientEntity* GetClientEntity(int entNum) = 0;
	virtual IClientEntity* GetClientEntityFromHandle(CBaseHandle hEnt) = 0;
	virtual int NumberOfEntities(bool isIncludeNonNetworkable) = 0;
	virtual int GetHighestEntityIndex(void) = 0;
	virtual void SetMaxEntities(int maxEnts) = 0;
	virtual int GetMaxEntities() = 0;
};