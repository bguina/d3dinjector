#pragma once

#include <cmath>
#include <iostream>

#include "Logger.h"
#include "WowGame.h"
#include "WinVirtualKey.h"

class WowNavigator
{
public:
	WowNavigator(
		WowGame& game
	) : mGame(game)
	{}

	~WowNavigator()
	{
		// fixme: dirty way of releasing any remaining Keydown
		// todo: persist current state as std::map<Keycode, State>
		pressLeftTurn(false);
		pressRightTurn(false);
		pressForward(false);
	}

	void run() {
		if (!mGame.isObjectManagerActive())
			return;

		WowUnitObject self = WowUnitObject(mGame.getObjectManager().getActivePlayer());
		const Vector3f& pos = self.getPosition();

		auto pSomeBoar = mGame.getObjectManager().getSomeBoar();
		if (NULL == pSomeBoar)
			return;

		WowUnitObject someBoar(pSomeBoar);

		if (false) {
			// Say hi to boar
			const uint32_t* boarGuid = someBoar.getGuidPointer();

			interactWith(boarGuid);
		}

		if (true) {
			// Face given position
			const Vector3f& point = someBoar.getPosition();

			int angle = getVectorFacingDegrees(WowObject(mGame.getObjectManager().getActivePlayer()).getPosition(), point);
			int delta = deltaAngleDegrees(point);
			int anglePrecision = 10;

			pressLeftTurn(delta > anglePrecision);
			pressRightTurn(delta < -anglePrecision);
			pressForward(abs(delta) < anglePrecision * 2);

			if (true) {
				std::stringstream ss;
				ss << "facing " << WowObject(mGame.getObjectManager().getActivePlayer()).getFacingDegrees() << ", target angle is " << angle << std::endl;
				ss << "delta " << delta << std::endl;
				Logger::getInstance().log(ss.str().c_str());
			}
		}
	}

	int deltaAngleDegrees(const Vector3f& to) {
		auto self = WowObject(mGame.getObjectManager().getActivePlayer());
		int delta = getVectorFacingDeltaDegrees(self.getPosition(), self.getFacingDegrees(), to);

		return delta;
	}

	uint64_t  interactWith(const uint32_t* targetGuid) {
		uint64_t(__fastcall * UnitInteract)(const uint32_t*) = (uint64_t(__fastcall*)(const uint32_t*))(mGame.getBaseAddress() + 0xD65D60);

		return UnitInteract(targetGuid);
	}

	const WowGame& getGame() const {
		return mGame;
	}

protected:
	WowGame& mGame;

private:
	void pressLeftTurn(bool doMove) {
		pushKey(WinVirtualKey::WVK_A, doMove);
	}

	void pressRightTurn(bool doMove) {
		pushKey(WinVirtualKey::WVK_D, doMove);
	}

	void pressForward(bool doMove) {
		pushKey(WinVirtualKey::WVK_W, doMove);
	}

	void pushKey(WinVirtualKey keycode, bool keyDown) {
		int action = WM_KEYUP;
		int flags = SENDMESSAGE_KEYUP_FLAGS;	

		if (keyDown) {
			action = WM_KEYDOWN;
			flags = SENDMESSAGE_KEYDOWN_FLAGS;
		}

		PostMessage(mGame.getWindow(), action, keycode, flags);
	}

	// Observed SendMessage "legit" flags found with Spy++ app
	const int SENDMESSAGE_KEYUP_FLAGS = 0x00110001;
	const int SENDMESSAGE_KEYDOWN_FLAGS = 0x00110001;
};

inline std::ostream& operator<<(
	std::ostream& out,
	const class WowNavigator& obj
	)
{
	out << "[WowNavigator]";
	// TODO print navigator state
	return out;
}
