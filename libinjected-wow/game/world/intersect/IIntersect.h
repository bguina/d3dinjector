#pragma once

#include <string>

#include "../WowVector3f.h"

class WowGame;

class IIntersect {
public:
	using HitResult = uint32_t;


	virtual ~IIntersect() = default;

	virtual void setFlags(uint32_t flags) = 0;
	virtual void setOrigin(const WowVector3f& position) = 0;
	virtual void setTarget(const WowVector3f& position) = 0;

	virtual HitResult getCollision(WowVector3f& collision) = 0;
	virtual HitResult collides() = 0;
	virtual bool collidesGround() = 0;
	virtual bool collidesObject() = 0;
};
