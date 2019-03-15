#pragma once

#include "IClientUnknown.h"

typedef unsigned short ClientShadowHandle_t;
typedef unsigned short ClientRenderHandle_t;
typedef unsigned short ModelInstanceHandle_t;

struct model_t;
class matrix3x4_t;
class QAngle;
class Vector;

class IClientRenderable
{
public:
	virtual IClientUnknown* GetIClientUnknown() = 0;
	virtual Vector const& GetRenderOrigin(void) = 0;
	virtual QAngle const& GetRenderAngles(void) = 0;
	virtual bool ShouldDraw(void) = 0;
	virtual int GetRenderFlags(void) = 0;
	virtual void Unused(void) const {}
	virtual ClientShadowHandle_t GetShadowHandle() const = 0;
	virtual ClientRenderHandle_t& RenderHandle() = 0;
	virtual const model_t* GetModel() const = 0;
	virtual int DrawModel(int flags, const int& instance) = 0;
	virtual int GetBody() = 0;
	virtual void GetColorModulation(float* color) = 0;
	virtual bool LODTest() = 0;
	virtual bool SetupBones(matrix3x4_t* boneToWorldOut, int maxBones, int boneMask, float currentTime) = 0;
	virtual void SetupWeights(const matrix3x4_t* boneToWorld, int flexWeightCount, float* flexWeights, float* flexDelayedWeights) = 0;
	virtual void DoAnimationEvents(void) = 0;
	virtual void* GetPVSNotifyInterface() = 0;
	virtual void GetRenderBounds(Vector& mins, Vector& maxs) = 0;
	virtual void GetRenderBoundsWorldspace(Vector& mins, Vector& maxs) = 0;
	virtual void GetShadowRenderBounds(Vector& mins, Vector& maxs, int shadowType) = 0;
	virtual bool ShouldReceiveProjectedTextures(int flags) = 0;
	virtual bool GetShadowCastDistance(float* dist, int shadowType) const = 0;
	virtual bool GetShadowCastDirection(Vector* direction, int shadowType) const = 0;
	virtual bool IsShadowDirty() = 0;
	virtual void MarkShadowDirty(bool isDirty) = 0;
	virtual IClientRenderable* GetShadowParent() = 0;
	virtual IClientRenderable* FirstShadowChild() = 0;
	virtual IClientRenderable* NextShadowPeer() = 0;
	virtual int ShadowCastType() = 0;
	virtual void CreateModelInstance() = 0;
	virtual ModelInstanceHandle_t GetModelInstance() = 0;
	virtual const matrix3x4_t& RenderableToWorldTransform() = 0;
	virtual int LookupAttachment(const char* attachmentName) = 0;
	virtual bool GetAttachment(int number, Vector& origin, QAngle& angles) = 0;
	virtual bool GetAttachment(int number, matrix3x4_t& matrix) = 0;
	virtual float* GetRenderClipPlane(void) = 0;
	virtual int GetSkin() = 0;
	virtual void OnThreadedDrawSetup() = 0;
	virtual bool UsesFlexDelayedWeights() = 0;
	virtual void RecordToolMessage() = 0;
	virtual bool ShouldDrawForSplitScreenUser(int slot) = 0;
	virtual unsigned char OverrideAlphaModulation(unsigned char alpha) = 0;
	virtual unsigned char OverrideShadowAlphaModulation(unsigned char alpha) = 0;
};