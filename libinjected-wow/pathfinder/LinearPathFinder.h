#pragma once

#include <vector>
#include <list>

#include "APathFinder.h"

class LinearPathFinder final : public APathFinder
{
public:
	LinearPathFinder();
	LinearPathFinder(const std::vector<Vector3f>& waypoints);
	virtual ~LinearPathFinder();

	void updatePath(const std::vector<Vector3f>& waypoints);

	// APathFinder interface

	bool setDestination(const Vector3f& destination) override;

	void clearDestination() override;

	bool getNearestKnownPosition(const Vector3f& currentPosition, Vector3f& result) const override;

	bool getNextPosition(const Vector3f& currentPosition, Vector3f& result) override;

	bool getNextPositionToDestination(const Vector3f& currentPosition, Vector3f& result) override;

	// Final class methods

	size_t getWaypointsCount() const;

	void reversePath();

protected:
	std::list<Vector3f> mPath;
	mutable std::list<Vector3f>::const_iterator mNextWaypoint;
	std::list<Vector3f>::const_iterator mDestinationWaypoint;
};

inline std::ostream& operator<<(
	std::ostream& out,
	const class LinearPathFinder& obj
	)
{
	Vector3f destination;

	out << "[LinearPathFinder:" << obj.getWaypointsCount() << " waypoints, destination:";
	if (obj.getDestination(destination)) out << destination; else out << "none";
	out << "]";

	return out;
}
