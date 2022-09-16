#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "fmod.hpp"
#include "Header.h"

class AudioManager {
public:
	FMOD::System* system;
	FMOD::Sound* winSoundTrack, * loseSoundTrack, * bgSoundTrack, * creditSoundTrack, * playerShootSound, * enemyShootSound, * pickUpSound,
		* collideSound, * damagedSound, * swingSound, * explosionSound, * gameplaySound, * bossSoundTrack, * clickSound, * cometSound;
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
	void PlayCometSound();
	void PlayCreditsSound();
	void PlayWinSoundTrack();
	void PlayLoseSoundTrack();
	void PlayBossSoundTrack();
	void PlayPlayerShootSound();
	void PlayEnemyShootSound();
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
