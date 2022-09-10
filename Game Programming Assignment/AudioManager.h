#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "fmod.hpp"
#include "Header.h"

class AudioManager {
public:
	FMOD::System* system;
	FMOD::Sound* winSoundTrack, * loseSoundTrack, * bgSoundTrack, * creditSoundTrack, * shootSound, * pickUpSound,
		* collideSound, * damagedSound, * swingSound, * explosionSound, * gameplaySound, * bossSoundTrack, * clickSound;
	FMOD::Channel* channel = 0;
	char* bgGroup;
	FMOD::ChannelGroup* group = 0;
	FMOD_RESULT result;
	void* extraDriverData = 0;

	void InitializeAudio();
	void PlayBackgroundSound();
	void StopBackgroundSound();
	void PlayGameplaySoundTrack();
	void StopGameplaySoundTrack();
	void PlayCreditsSound();
	void StopCreditsSound();
	void PlayWinSoundTrack();
	void StopWinSoundTrack();
	void PlayLoseSoundTrack();
	void StopLoseSoundTrack();
	void PlayBossSoundTrack();
	void StopBossSoundTrack();
	void PlayShootSound();
	void PlayPickUpSound();
	void PlayCollisionSound();
	void PlayDamagedSound();
	void PlaySwingSound();
	void PlayExplosionSound();
	void PlayClickSound();
	void PlayHoverButtonSound();
	void LoadSounds();
	void UpdateSound();

	AudioManager();
	~AudioManager();
};

#endif
