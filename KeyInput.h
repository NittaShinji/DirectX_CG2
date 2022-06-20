#pragma once
#define DIRECTINPUT_VERSION  0x0800
#include <dinput.h>
#include <cstdint>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

class KeyInput 
{
public:
	KeyInput();
	~KeyInput();

	//�A�N�Z�b�T
	BYTE GetKeys(uint8_t keynumber);
	BYTE GetOldKeys(uint8_t oldKeyNumber);

	//DirectInput�̏�����
	void Initialize(HINSTANCE windowHinstance, HWND hwnd);

	//�O�t���[����ۑ�����֐�
	void SaveFrameKey();

	//�x���֐�
	void KeyAssert();

	//�g���K�[�����֐�
	//�L�[����������Ԃ�
	bool HasPushedKey(int keyNumber);
	//�L�[�𗣂�����Ԃ�
	bool HasReleasedKey(int keyNumber);
	//�L�[���������u�Ԃ�
	bool PushedKeyMoment(int keyNumber);
	//�L�[�𗣂����u�Ԃ�
	bool ReleasedKeyMoment(int keyNumber);

private:

	BYTE keys[256] = {};
	BYTE oldKeys[256] = {};

	IDirectInputDevice8* keyboard;
};

