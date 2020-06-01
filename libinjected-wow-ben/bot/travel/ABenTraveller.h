#pragma once

#include "../base/ABen.h"
#include "WowPlugin.h"

class ABenTraveller : public ABen
{
public:
	ABenTraveller(const std::string& tag);
	virtual ~ABenTraveller();

	virtual bool supportsHostileEnvironment() const;
};
