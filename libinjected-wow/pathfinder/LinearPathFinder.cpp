#include "pch.h"

#include <iostream>
#include <vector>
#include <list>
#include <sstream>

#include "LinearPathFinder.h"
#include "Vector3f.h"

std::list<Vector3f>::const_iterator helperGetNearestWaypoint(const std::list<Vector3f>& path, const Vector3f& currentPosition);

LinearPathFinder::LinearPathFinder() = default;

LinearPathFinder::LinearPathFinder(const std::vector<Vector3f>& waypoints)
{
	updatePath(waypoints);
}

LinearPathFinder::~LinearPathFinder() = default;

void LinearPathFinder::updatePath(const std::vector<Vector3f>& waypoints)
{
	mPath.clear();
	std::copy(waypoints.begin(), waypoints.end(), std::back_inserter(mPath));
	mDestinationWaypoint = mPath.end();
	mNextWaypoint = mPath.begin();
}

bool LinearPathFinder::setDestination(const Vector3f& destination) {
	APathFinder::setDestination(destination);
	mDestinationWaypoint = helperGetNearestWaypoint(mPath, *mDestination);
	return mPath.end() != mDestinationWaypoint;
}

void LinearPathFinder::clearDestination() {
	APathFinder::clearDestination();
	mDestinationWaypoint = mPath.end();
}

void LinearPathFinder::reversePath() {
	mPath.reverse();
}

bool LinearPathFinder::getNearestKnownPosition(const Vector3f& currentPosition, Vector3f & result) const {
	const auto nearestWaypoint(helperGetNearestWaypoint(mPath, currentPosition));

	if (nearestWaypoint != mPath.end())
	{
		result = *nearestWaypoint;
		return true;
	}

	return false;
}

bool LinearPathFinder::getNextPosition(const Vector3f & currentPosition, Vector3f & result)
{
	return getNextPositionToDestination(currentPosition, result);
}

bool LinearPathFinder::getNextPositionToDestination(const Vector3f& currentPosition, Vector3f& result)
{
	std::stringstream ss;
	
	if (mPath.empty()) return false;

	if (mNextWaypoint == mPath.end())
	{
		mNextWaypoint = helperGetNearestWaypoint(mPath, currentPosition);
	} else if (currentPosition.getDistanceTo(*mNextWaypoint) < 10)
	{
		// we have reached the target position, proceed to next waypoint
		// fixme: we should proceed to the path leading to the mDestinationWaypoint!
		++mNextWaypoint;

		// fixme: this should never happen since we are supposed to lead to the mDestinationWaypoint (unless destination is not set?)
		if (mNextWaypoint == mPath.end())
		{
			const auto endIsNearStart = currentPosition.getDistanceTo(*mPath.begin()) < 3;

			if (!endIsNearStart)
			{
				// the graph start can't be found, just reverse the list to walk back
				reversePath();
			}

			// otherwise just continue the loop to the graph start
			mNextWaypoint = mPath.begin();
		}
	}
	else {
		// target waypoint is still far
		// target waypoint remains unchanged
	}

	if (mPath.end() == mNextWaypoint)
	{
		return false;
	}

	result = *mNextWaypoint;
	return true;
}

size_t LinearPathFinder::getWaypointsCount() const
{
	return mPath.size();
}

std::list<Vector3f>::const_iterator helperGetNearestWaypoint(const std::list<Vector3f>& path, const Vector3f& currentPosition)
{
	auto nearestWaypoint(path.end());
	float nearestDistance = FLT_MAX;

	for (auto it = path.begin(); it != path.end(); ++it)
	{
		const float waypointDistance = currentPosition.getDistanceTo(*it);

		if (waypointDistance < nearestDistance)
		{
			nearestDistance = waypointDistance;
			nearestWaypoint = it;
		}
	}

	return nearestWaypoint;
}
