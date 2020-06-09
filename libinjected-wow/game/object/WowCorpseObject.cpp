#include "WowCorpseObject.h"

WowCorpseObject::WowCorpseObject(const uint8_t* baseAddress) :
	WowObject(baseAddress)
{

}

const WowCorpseDescriptor& WowCorpseObject::getCorpseData() const
{
	return get<WowCorpseDescriptor>();
}
