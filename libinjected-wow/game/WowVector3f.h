#pragma once

#include <fstream>

constexpr  float PI = 3.141592653589793f;

class WowVector3f {
public:
	union {
		struct {
			float x;
			float y;
			float z;
		} position;
		float matrix[3] = { .0f,.0f,.0f };
	};

	float operator[](int index) const;

	WowVector3f translated_by_x(float d) const;
	WowVector3f translated_by_y(float d) const;
	WowVector3f translated_by_z(float d) const;

	WowVector3f& translate_by_x(float d);
	WowVector3f& translate_by_y(float d);
	WowVector3f& translate_by_z(float d);

	float get_distance_to(const WowVector3f& to) const;
	float get_flight_distance_to(const WowVector3f& to) const;

	int get_facing_degrees_to(const WowVector3f& to) const;
	int get_facing_delta_degrees(int angle, const WowVector3f& to) const;
	WowVector3f get_position_at_degrees_by_distance(int angle, float d) const;
};

inline std::ostream& operator<<(
	std::ostream& out,
	const WowVector3f& obj
	)
{
	out << "[Vector3f:" << obj.position.x << "/" << obj.position.y << "/" << obj.position.z << "]";
	return out;
}
