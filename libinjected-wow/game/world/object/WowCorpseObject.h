#pragma once

#include "WowObject.h"
#include "descriptor/WowCorpseDescriptor.h"

class WowCorpseObject : public WowObject
{
public:
	WowCorpseObject(const WowObjectStruct* baseAddress, WowGame& game);

	const WowCorpseDescriptor& getCorpseData() const;
	
protected:

};

inline std::ostream& operator<<(std::ostream& out, const WowCorpseObject& obj)
{
	out << (WowObject)obj;
	return out;
}
