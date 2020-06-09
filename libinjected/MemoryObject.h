#pragma once

#include <cstdint>

class MemoryObject {
public:
	MemoryObject(const uint8_t* address) :
		mAddress(address)
	{
	}
	virtual ~MemoryObject() = default;

	const uint8_t* getAddress() const
	{
		return mAddress;
	}

	void rebase(const uint8_t* address)
	{
		mAddress = address;
	}

	bool isNull() const
	{
		return nullptr == mAddress;
	}

	template<typename T>
	const T& getFunction(uint64_t offset) const {
		return *reinterpret_cast<T*>(getAddress() + offset);
	}
	
	template<typename T>
	const T& get() const {
		return *reinterpret_cast<const T*>(getAddress());
	}
	
	template<typename T>
	const T& get(uint64_t offset) const {
		return *reinterpret_cast<const T*>(getAddress() + offset);
	}

	template<typename T>
	T* getWritable(uint64_t offset) {
		return reinterpret_cast<T*>(getAddress() + offset);
	}

private:
	const uint8_t* mAddress;
};
