#pragma once

#include <fstream>

constexpr float PI = 3.141592653589793f;

class WowVector3f {
public:
	union {
		struct {
			float x;
			float y;
			float z;
		} position;
		float matrix[3];
	};

	float operator[](int index) const;

	WowVector3f translatedByX(float d) const;
	WowVector3f translatedByY(float d) const;
	WowVector3f translatedByZ(float d) const;

	WowVector3f& translateByX(float d);
	WowVector3f& translateByY(float d);
	WowVector3f& translateByZ(float d);

	float getDistanceTo(const WowVector3f& to) const;
	float getFlightDistanceTo(const WowVector3f& to) const;

	int getFacingDegreesTo(const WowVector3f& to) const;
	int getFacingDeltaDegrees(int angle, const WowVector3f& to) const;
	WowVector3f getPositionAtDegreesByDistance(int angle, float d) const;
};

inline std::ostream& operator<<(std::ostream& out,const WowVector3f& obj)
{
	out << "[Vector3f:" << obj.position.x << "/" << obj.position.y << "/" << obj.position.z << "]";
	return out;
}

constexpr WowVector3f WOWVECTOR3F_ORIGIN({ {{.0,.0,.0}} });
