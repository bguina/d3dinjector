#include "pch.h"

#include <cmath>
#include "WowVector3f.h"

const double PI = 3.141592653589793;

float WowVector3f::operator[](int index) const {
	return matrix[index];
}

float WowVector3f::getDistanceTo(const WowVector3f& to) const {
	auto dx = to.position.x - position.x;
	auto dy = to.position.y - position.y;
	auto dz = to.position.z - position.z;
	auto dx2 = dx * dx;
	auto dy2 = dy * dy;
	auto dz2 = dz * dz;

	return sqrt(dx2 + dy2 + dz2);
}

float WowVector3f::getFlightDistanceTo(const WowVector3f& to) const {
	auto dx = to.position.x - position.x;
	auto dy = to.position.y - position.y;
	auto dx2 = dx * dx;
	auto dy2 = dy * dy;

	return sqrt(dx2 + dy2);
}

int WowVector3f::getFacingDegreesTo(const WowVector3f& to) const {
	return atan2(
		to.position.y - position.y,
		to.position.x - position.x
	) * 180 / PI;
}

int WowVector3f::getFacingDeltaDegrees(int angle, const WowVector3f& to) const {
	int targetFacing = getFacingDegreesTo(to);
	int delta = targetFacing - angle;

	if (delta < -180)
		return delta + 360;

	if (delta > 180)
		return delta - 360;

	return delta;
}