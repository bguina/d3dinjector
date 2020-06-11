#pragma once

#include <cstdint>

template<typename T>
class MemoryObject {
public:
	MemoryObject(const T* address) :
		mAddress(address)
	{
	}

	MemoryObject(const MemoryObject<T>& other) :
		mAddress(other.mAddress)
	{
	}
	
	MemoryObject& operator=(const MemoryObject& rhs)
	{
		mAddress = rhs.mAddress;
		return *this;
	}
	
	virtual ~MemoryObject<T>() = default;

	const uint8_t* getAddress() const
	{
		return reinterpret_cast<const uint8_t*>(mAddress);
	}

	void rebase(const uint8_t* address)
	{
		mAddress = address;
	}

	bool isNull() const
	{
		return nullptr == mAddress;
	}
	
	const T& get() const {
		return *reinterpret_cast<const T*>(getAddress());
	}
	
	template<typename U>
	const U& get(uint64_t offset) const {
		return *reinterpret_cast<const U*>(getAddress() + offset);
	}

	template<typename U>
	T* getWritable(uint64_t offset) {
		return reinterpret_cast<U*>(getAddress() + offset);
	}

private:
	const T* mAddress;
};
