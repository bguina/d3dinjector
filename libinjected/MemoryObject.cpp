
#include "MemoryObject.h"

MemoryObject::MemoryObject(const uint8_t* baseAddress) :
	mBaseAddress(baseAddress)
{
}

MemoryObject:: ~MemoryObject() = default;

const uint8_t* MemoryObject::getAddress() const {
	return mBaseAddress;
}

void MemoryObject::rebase(const uint8_t* baseAddress) {
	mBaseAddress = baseAddress;
}

bool MemoryObject::isPresent() const {
	return nullptr != mBaseAddress;
}
