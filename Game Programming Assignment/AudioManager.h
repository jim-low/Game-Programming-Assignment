#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "fmod.hpp"
#include "Header.h"

class AudioManager {
public:
	// sound variables for AudioManager
	FMOD::System* system;
	FMOD::Sound* winSoundTrack, * loseSoundTrack, * bgSoundTrack, * creditSoundTrack,  * collideSound, * damagedSound, * explosionSound, * gameplaySound,  * clickSound, * cometSound;
	FMOD::Channel* channel = 0;
	char* channelGroup;
	FMOD::ChannelGroup* panGroup = 0;
	FMOD::ChannelGroup* bgGroup = 0;
	FMOD::ChannelGroup* effectsGroup = 0;
	FMOD_RESULT result;

	// sound variables for settings
	float effectVolume;
	float bgVolume;
	void* extraDriverData = 0;

	void InitializeAudio();

	// getters
	int getEffectsVolume();
	int getBackgroundVolume();

	// setters
	void setBackgroundVolume(float volume);
	void SetPanning(float panValue);
	void SetGroupPanning(float panValue);
	void setEffectsVolume(float volume);

	// play methods
	void PlayMainMenuSoundTrack();
	void PlayGameplaySoundTrack();
	void PlayCometSound();
	void PlayCreditsSound();
	void PlayWinSoundTrack();
	void PlayLoseSoundTrack();
	void PlayCollisionSound();
	void PlayDamagedSound();
	void PlayExplosionSound();
	void PlayClickSound();

	// utilities
	void LoadSounds();
	void UpdateSound();
	void StopBackgroundSound();

	AudioManager();
	~AudioManager();
};

#endif
