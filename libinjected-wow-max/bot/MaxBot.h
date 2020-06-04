#pragma once

#include <set>

#include "bot/BaseWowBot.h"

class IPathFinder;
class WowUnitObject;

class WowMaxBot : public BaseWowBot
{
public:
	WowMaxBot();
	virtual ~WowMaxBot();

	virtual void onResume() override;
	virtual void onPause() override;
	virtual bool onEvaluate() override;

	virtual bool handleWowMessage(ServerWowMessage& cl) override;

protected:
	virtual void _logDebug() const override;

	std::unique_ptr<IPathFinder> mPathFinder;
	std::shared_ptr<const WowUnitObject> mTargetUnit;
	std::set<WowGuid128> mBlacklistedGuids;
	bool mOpeningCombat = true;
	bool mInteractWith = true;
	bool cacAttack = true;
	int toLoop = 0;
	uint64_t mLastFeedPet;
	uint64_t mLastJump;
};

inline std::ostream& operator<<(
	std::ostream& out,
	const class WowMaxBot& obj
	)
{
	out << dynamic_cast<const BaseWowBot&>(obj);
	return out;
}
