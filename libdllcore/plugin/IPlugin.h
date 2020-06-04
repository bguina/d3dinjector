#pragma once

#include <string>

class IPlugin
{
public:
	virtual ~IPlugin() = default;;
	virtual std::string getTag() const = 0;

	virtual bool onD3dRender() = 0;
};
