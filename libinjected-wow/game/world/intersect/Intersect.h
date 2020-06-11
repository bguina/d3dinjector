#pragma once

#include <string>

#include "IIntersect.h"

class WowGame;

class Intersect final :public IIntersect {
public:
	enum HitFilter
	{
		HIT_FILTER_NOTHING = 0x0,
		HIT_FILTER_GROUND = 0x1,
		HIT_FILTER_OBJECTS = 0x2,
		HIT_FILTER_UNITS = 0x4,
		HIT_FILTER_PLAYERS = 0x8,
		HIT_FILTER_ME = 0x10,
		HIT_FILTER_PARTY = 0x10000,
		HIT_FILTER_FRIENDS = 0x20000,
		HIT_FILTER_ENEMIES = 0x40000,
		HIT_FILTER_LIVE = 0x100000,
		HIT_FILTER_DEAD = 0x200000,
		HIT_FILTER_ALL_OBJECTS_EXCEPT_ME = 0xe,
		HIT_FILTER_ALL_OBJECTS = 0x1e,
		HIT_FILTER_ALL_EXCEPT_ME = 0xf,
		HIT_FILTER_ALL = 0x1f,
	};

	Intersect(const WowGame& game, const WowVector3f& origin);
	Intersect(const WowGame& game, const WowVector3f& origin, const WowVector3f& target);
	Intersect(const WowGame& game, const WowVector3f& origin, const WowVector3f& target, uint32_t filters);
	virtual ~Intersect();

	void setFlags(uint32_t flags) override;
	void setOrigin(const WowVector3f& position) override;
	void setTarget(const WowVector3f& position) override;

	HitResult getCollision(WowVector3f& collision) override;
	HitResult collides() override;
	bool collidesGround() override;
	bool collidesObject() override;

protected:
	void compute();

	enum HitResultType {
		HIT_TYPE_NONE = 0x0,
		HIT_TYPE_GROUND = 0x1,
		HIT_TYPE_OBJECT = 0x2,
	};
	
	using NativeIntersect = HitResult(__fastcall)(const float* end, const float* start, float* r, const float* distance, uint32_t f, uint32_t opt);

	NativeIntersect& mIntersect;
	WowVector3f const* mOrigin;
	WowVector3f const* mTarget;
	uint32_t mIntersectFilters;

	bool mComputed;
	WowVector3f mHitPosition;
	uint32_t mHitResult;
};
