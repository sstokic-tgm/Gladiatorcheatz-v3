#pragma once

typedef enum
{
	DPT_Int = 0,
	DPT_Float,
	DPT_Vector,
	DPT_VectorXY,
	DPT_String,
	DPT_Array,
	DPT_DataTable,
	DPT_Int64,
	DPT_NUMSendPropTypes
} Type;

class DVariant
{
public:
	union
	{
		float dvFloat;
		long dvInt;
		char* dvString;
		void* dvData;
		float dvVector[3];
		__int64 dvInt64;
	};
	Type  dvType;
};

class RecvTable;
class RecvProp;

class CRecvProxyData
{
public:
	const RecvProp* recvProp; // The property it's receiving.
	DVariant value; // The value given to you to store.
	int element; // Which array element you're getting.
	int objectID; // The object being referred to.
};

using RecvVarProxyFn = void(*)(const CRecvProxyData* data, void* baseStruct, void* out);
using ArrayLengthRecvProxyFn = void(*)(void* baseStruct, int objectID, int currentArrayLength);
using DataTableRecvVarProxyFn = void(*)(const RecvProp* prop, void** out, void* data, int objectID);

class RecvProp
{
public:
	char* varName;
	Type recvType;
	int flags;
	int stringBufferSize;
	int isInsideArray;
	const void* extraData;
	RecvProp* arrayProp;
	ArrayLengthRecvProxyFn arrayLengthProxy;
	RecvVarProxyFn proxyFn;
	DataTableRecvVarProxyFn dataTableProxyFn;
	RecvTable* dataTable;
	int offset;
	int elementStride;
	int elements;
	const char* parentArrayPropName;

	RecvVarProxyFn GetProxyFn() const;
	void SetProxyFn(RecvVarProxyFn fn);
	DataTableRecvVarProxyFn	GetDataTableProxyFn() const;
	void SetDataTableProxyFn(DataTableRecvVarProxyFn fn);
};

class RecvTable
{
public:
	RecvProp* props;
	int numProps;
	void* decoder;
	char* netTableName;
	bool isInitialized;
	bool isInMainList;
};

inline RecvVarProxyFn RecvProp::GetProxyFn() const
{
	return proxyFn;
}

inline void RecvProp::SetProxyFn(RecvVarProxyFn fn)
{
	proxyFn = fn;
}

inline DataTableRecvVarProxyFn RecvProp::GetDataTableProxyFn() const
{
	return dataTableProxyFn;
}

inline void RecvProp::SetDataTableProxyFn(DataTableRecvVarProxyFn fn)
{
	dataTableProxyFn = fn;
}