#include "Header.h";

void AudioManager::InitializeAudio()
{
	result = FMOD::System_Create(&system);
	result = system->init(64, FMOD_INIT_NORMAL, extraDriverData);
	result = system->createChannelGroup(channelGroup, &bgGroup);
}

void AudioManager::PlayMainMenuSoundTrack(){
	result = system->playSound(bgSoundTrack, bgGroup, false, &channel);
	bgGroup->setVolume(0.03);
	bgGroup->setPitch(1.5);
	}

void AudioManager::StopBackgroundSound() {
	bgGroup->stop();
}

void AudioManager::PlayCreditsSound(){
	result = system->playSound(creditSoundTrack, bgGroup, false, &channel);
}

void AudioManager::PlayWinSoundTrack(){
	result = system->playSound(winSoundTrack, 0, false, &channel);
}

void AudioManager::PlayLoseSoundTrack() {
	result = system->playSound(loseSoundTrack, 0, false, &channel);
}

void AudioManager::PlayGameplaySoundTrack() {
	result = system->playSound(gameplaySound, 0, false, &channel);
}

void AudioManager::PlayBossSoundTrack() {
	result = system->playSound(bossSoundTrack, 0, false, &channel);
}

void AudioManager::PlayPlayerShootSound() {
	result = system->playSound(playerShootSound, 0, false, &channel);
}

void AudioManager::PlayEnemyShootSound() {
	result = system->playSound(enemyShootSound, 0, false, &channel);
}

void AudioManager::PlayPickUpSound() {
	result = system->playSound(pickUpSound, 0, false, &channel);
}

void AudioManager::PlayCollisionSound() {
	result = system->playSound(collideSound, 0, false, &channel);
}

void AudioManager::PlayDamagedSound() {
	result = system->playSound(damagedSound, 0, false, &channel);
}

void AudioManager::PlaySwingSound() {
	result = system->playSound(swingSound, 0, false, &channel);
}

void AudioManager::PlayExplosionSound() {
	result = system->playSound(explosionSound, 0, false, &channel);
}

void AudioManager::PlayClickSound() {
	result = system->playSound(clickSound, 0, false, &channel);
	channel->setVolume(0.1);
}

void AudioManager::PlayHoverButtonSound() {
	result = system->playSound(clickSound, 0, false, &channel);
	//cut off sound after 1 sec
}

void AudioManager::LoadSounds()
{

	result = system->createSound("../Assets/Audio/bg1.mp3", FMOD_DEFAULT, 0, &bgSoundTrack);
	result = bgSoundTrack->setMode(FMOD_LOOP_NORMAL);

	result = system->createSound("../Assets/Audio/Credits_Music_Loop.wav", FMOD_DEFAULT, 0, &creditSoundTrack);
	result = creditSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Win_Music.wav", FMOD_DEFAULT, 0, &winSoundTrack);
	result = winSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Lose_Music", FMOD_DEFAULT, 0, &loseSoundTrack);
	result = loseSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Player_Shoot.wav", FMOD_DEFAULT, 0, &playerShootSound);
	result = playerShootSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Enemy_Shoot.wav", FMOD_DEFAULT, 0, &enemyShootSound);
	result = enemyShootSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Power_Up_Collect.wav", FMOD_DEFAULT, 0, &pickUpSound);
	result = pickUpSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Enemy_Damaged.wav", FMOD_DEFAULT, 0, &collideSound);
	result = collideSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Player_Damaged.wav", FMOD_DEFAULT, 0, &damagedSound);
	result = damagedSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Sword_Swing.wav", FMOD_DEFAULT, 0, &swingSound);
	result = swingSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Ship_Explosion.wav", FMOD_DEFAULT, 0, &explosionSound);
	result = explosionSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Fight_Music_Loop", FMOD_DEFAULT, 0, &gameplaySound);
	result = gameplaySound->setMode(FMOD_LOOP_NORMAL);

	result = system->createStream("../Assets/Audio/Boss_Music.mp3", FMOD_DEFAULT, 0, &bossSoundTrack);
	result = bossSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/click-electronic.wav", FMOD_DEFAULT, 0, &clickSound);
	result = clickSound->setMode(FMOD_LOOP_OFF);
}

void AudioManager::UpdateSound()
{
	result = system->update();
}

AudioManager::AudioManager()
{
}

AudioManager::~AudioManager()
{
}


