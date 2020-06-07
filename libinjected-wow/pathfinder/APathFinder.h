#pragma once

#include <memory>

#include "IPathFinder.h"

class APathFinder : public IPathFinder
{
public:
	APathFinder();
	virtual ~APathFinder();

	bool getDestination(Vector3f& result) const override;

	bool setDestination(const Vector3f& destination) override;

	void clearDestination() override;
	
	bool getGuaranteedDestination(Vector3f& result) const override;

	bool isLost(const Vector3f& currentPosition) const override;
	
protected:
	std::unique_ptr<const Vector3f> mDestination;
};
