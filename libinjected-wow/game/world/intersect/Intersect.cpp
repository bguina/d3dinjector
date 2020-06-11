#include "Intersect.h"

#include "../../WowGame.h"
#include "../../dump/WowGameOffsets.h"

Intersect::Intersect(const WowGame& game, const WowVector3f& origin) :
	Intersect(game, origin, origin)
{
}

Intersect::Intersect(const WowGame& game, const WowVector3f& origin, const WowVector3f& target) :
	Intersect(game, origin, target, 0x1A0111)
{
}

Intersect::Intersect(const WowGame& game, const WowVector3f& origin, const WowVector3f& target, const uint32_t filters) :
	mIntersect(game.getFunction<NativeIntersect>(WowGameOffsets::FunctionWorldFrame_Intersect)),
	mOrigin(&origin),
	mTarget(&target),
	mIntersectFilters(filters),
	mComputed(false),
	mHitPosition(),
	mHitResult(0)
{
}

Intersect::~Intersect() = default;

void Intersect::setFlags(const uint32_t flags)
{
	if (flags != mIntersectFilters)
	{
		mComputed = false;
		mIntersectFilters = flags;
	}
}

void Intersect::setOrigin(const WowVector3f & position)
{
	mComputed = false;
	mOrigin = &position;
}

void Intersect::setTarget(const WowVector3f & position)
{
	mComputed = false;
	mTarget = &position;
}

IIntersect::HitResult Intersect::getCollision(WowVector3f& collision)
{
	const auto result(collides());
	if (result)
	{
		collision = mHitPosition;
	}
	return result;
}

IIntersect::HitResult Intersect::collides()
{
	if (!mComputed) compute();
	return mHitResult;
}

bool Intersect::collidesGround()
{
	return collides() & HIT_TYPE_GROUND;
}

bool Intersect::collidesObject()
{
	return collides() & HIT_TYPE_OBJECT;
}

void Intersect::compute()
{
	float d(1);
	mHitResult = mIntersect(mOrigin->matrix, mTarget->matrix, mHitPosition.matrix, &d, mIntersectFilters, 0);
	mComputed = true;
}
