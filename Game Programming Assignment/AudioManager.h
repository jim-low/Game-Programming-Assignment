#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "fmod.hpp"
#include "Header.h"

class AudioManager {
public:
	FMOD::System* system;
	FMOD::Sound* winSoundTrack, * loseSoundTrack, * bgSoundTrack, * creditSoundTrack,  * collideSound, * damagedSound, * explosionSound, * gameplaySound,  * clickSound, * cometSound;
	FMOD::Channel* channel = 0;
	char* channelGroup;
	FMOD::ChannelGroup* panGroup = 0;
	FMOD::ChannelGroup* bgGroup = 0;
	FMOD::ChannelGroup* effectsGroup = 0;
	FMOD_RESULT result;
	float effectVolume;
	float bgVolume;
	void* extraDriverData = 0;

	void InitializeAudio();
	void setEffectsVolume(float volume);

	int getEffectsVolume();
	void setBackgroundVolume(float volume);
	int getBackgroundVolume();
	void PlayMainMenuSoundTrack();
	void StopBackgroundSound();
	void PlayGameplaySoundTrack();
	void SetPanning(float panValue);
	void SetGroupPanning(float panValue);
	void PlayCometSound();
	void PlayCreditsSound();
	void PlayWinSoundTrack();
	void PlayLoseSoundTrack();
	void PlayCollisionSound();
	void PlayDamagedSound();
	void PlayExplosionSound();
	void PlayClickSound();
	void LoadSounds();
	void UpdateSound();

	AudioManager();
	~AudioManager();
};

#endif
