#include "BaseWowBot.h"

#include "../game/WowGame.h"
#include "../game/world/object/WowActivePlayerObject.h"
#include "../pathfinder/LinearPathFinder.h"

BaseWowBot::BaseWowBot(const std::string& tag) :
	mGame(nullptr),
	mLog(tag)
{
}

BaseWowBot::~BaseWowBot() = default;

void BaseWowBot::attach(const std::shared_ptr<WowGame> game)
{
	mGame = game;
}

const std::string& BaseWowBot::getTag() const
{
	return mLog.getTag();
}

void BaseWowBot::onResume()
{
}

bool BaseWowBot::onEvaluate()
{
	return false;
}

void BaseWowBot::onPause()
{
}

bool BaseWowBot::handleWowMessage(ServerWowMessage& cl)
{
	return false;
}

void BaseWowBot::_logDebug() const
{
	std::shared_ptr<const WowActivePlayerObject> self = mGame->getObjectManager().getActivePlayer();
	mLog << FileLogger::info;

	if (nullptr != self) {
		// show info relative to self
		mLog << "Self position is " << self->getPosition() << " angle is " << self->getFacingDegrees() << std::endl;
		mLog << "Self in combat: " << self->isInCombat() << std::endl;
		const auto&  targetGuid = *self->getTargetGuid();

		if (0 != targetGuid)
		{
			const std::shared_ptr<const WowUnitObject> target = mGame->getObjectManager().getObjectByGuid<WowUnitObject>(targetGuid);
			
			if (nullptr != target) {
				mLog << "Target: " << targetGuid.upper() << targetGuid.lower() << " can be attacked? " << self->canAttack(*target) << std::endl;
			}
			else {
				mLog << FileLogger::err << "Target: " << targetGuid.upper() << targetGuid.lower() << " can be attacked? " << (uint32_t)self->canAttack(*target) << FileLogger::info << std::endl;
			}
		}

		// show info relative to a random unit around, if any
		const std::shared_ptr<const WowUnitObject> any = mGame->getObjectManager().anyOfType<WowUnitObject>(WowObjectType::Unit);
		
		if (nullptr != any) {
			mLog << "any-unit position is " << any->getPosition()
				<< " facing it requires angle of " << self->getFacingDegreesTo(*any)
				<< " angle delta is " << self->getFacingDeltaDegrees(*any) << std::endl;
		}
	}
	mLog << FileLogger::normal;
}
