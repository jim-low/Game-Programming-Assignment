#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include "fmod.hpp"
#include "Header.h"

class AudioManager {
public:
	FMOD::System* system;
	FMOD::Sound* winSoundTrack, * loseSoundTrack, * bgSoundTrack, * creditSoundTrack, * playerShootSound, * enemyShootSound, * pickUpSound,
		* collideSound, * damagedSound, * swingSound, * explosionSound, * gameplaySound, * bossSoundTrack, * clickSound, * harambeSound;
	FMOD::Channel* channel = 0;
	char* channelGroup;
	FMOD::ChannelGroup* panGroup = 0;
	FMOD::ChannelGroup* bgGroup = 0;
	FMOD_RESULT result;
	void* extraDriverData = 0;

	void InitializeAudio();
	void PlayMainMenuSoundTrack();
	void StopBackgroundSound();
	void PlayGameplaySoundTrack();
	void SetPanning(float panValue);
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
	void PlayMemeDirectionSound();
	void LoadSounds();
	void UpdateSound();

	AudioManager();
	~AudioManager();
};

#endif
