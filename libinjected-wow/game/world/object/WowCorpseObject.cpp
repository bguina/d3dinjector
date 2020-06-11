#include "WowCorpseObject.h"

WowCorpseObject::WowCorpseObject(const WowObjectStruct* baseAddress, WowGame& game) :
	WowObject(baseAddress, game)
{

}

const WowCorpseDescriptor& WowCorpseObject::getCorpseData() const
{
	return getDescriptorData<WowCorpseDescriptor>();
}
