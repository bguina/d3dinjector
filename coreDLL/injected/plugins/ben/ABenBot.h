#pragma once

#include "../../plugins/wow/AWowBot.h"
#include "../../process/wow/object/WowGuid128.h"

class IPathFinder;

class ABenBot : public AWowBot 
{
public:
	ABenBot(WowGame& game, const std::string& tag);
	virtual ~ABenBot();

	virtual bool pause(bool paused) override;

protected:
	virtual void _onPaused() override;
	virtual void _onResumed() override;

	std::unique_ptr<IPathFinder> mPathFinder;

	virtual void _logDebug() const override;
};

inline std::ostream& operator<<(std::ostream& out,const class ABenBot& obj) {
	out << dynamic_cast<const AWowBot&>(obj);
	return out;
}
