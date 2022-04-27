#include"DirectInput.h"
#include <cstdint>
#include <cassert>

//�R���X�g���N�^
KeyInput::KeyInput()
{}

//�f�X�g���N�^
KeyInput::~KeyInput()
{}

//�A�N�Z�b�T
uint8_t KeyInput::GetReadKey()
{
	return *keys;
}

uint8_t KeyInput::GetReadOldKey()
{
	return *oldkeys;
}

void KeyInput::Initialize()
{
}

void KeyInput::SaveFrameKey(uint8_t* keys, uint8_t* oldkeys)
{
	assert(SUCCEEDED(keys != nullptr));
	assert(SUCCEEDED(oldkeys != nullptr));

	keyboard->Acquire();


	keyboard->GetDeviceState(sizeof(keys), keys);


	for (int i = 0; i < 256; i++)
	{
		oldkeys[i] = keys[i];
	}
}

//�L�[����������Ԃ�
bool KeyInput::HasPushedKey(uint8_t* keys, uint8_t* oldkeys)
{
	assert(SUCCEEDED(keys != nullptr));
	assert(SUCCEEDED(oldkeys != nullptr));

	if (keys != 0 && oldkeys != 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//�L�[�𗣂�����Ԃ�
bool KeyInput::HasReleasedKey(uint8_t* keys, uint8_t* oldkeys)
{
	assert(SUCCEEDED(keys != nullptr));
	assert(SUCCEEDED(oldkeys != nullptr));

	if (keys == 0 && oldkeys == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//�L�[���������u�Ԃ�
bool KeyInput::PushedKeyMoment(uint8_t* keys, uint8_t* oldkeys)
{
	assert(SUCCEEDED(keys != nullptr));
	assert(SUCCEEDED(oldkeys != nullptr));

	if (keys != 0 && oldkeys == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//�L�[�𗣂����u�Ԃ�
bool KeyInput::ReleasedKeyMoment(uint8_t* keys, uint8_t* oldkeys)
{
	assert(SUCCEEDED(keys != nullptr));
	assert(SUCCEEDED(oldkeys != nullptr));

	if (keys == 0 && oldkeys != 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
