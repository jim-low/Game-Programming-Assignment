#include "Header.h";

void AudioManager::InitializeAudio()
{
	result = FMOD::System_Create(&system);
	result = system->init(64, FMOD_INIT_NORMAL, extraDriverData);
	result = system->createChannelGroup(bgGroup, group);
}

void AudioManager::PlayBackgroundSound(){
	result = system->playSound(bgSoundTrack, 0, false, &channel);
	channel->setVolume(0.01);
	channel->setPitch(1.5);
	
	
}

void AudioManager::StopBackgroundSound() {
	channel->stop();
}

void AudioManager::PlayCreditsSound(){
	result = system->playSound(creditSoundTrack, 0, false, &channel);
}

void AudioManager::PlayWinSoundTrack(){
	result = system->playSound(winSoundTrack, 0, false, &channel);
}

void AudioManager::PlayLoseSoundTrack() {
	result = system->playSound(loseSoundTrack, 0, false, &channel);
}

void AudioManager::PlayShootSound() {
	result = system->playSound(shootSound, 0, false, &channel);
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

void AudioManager::PlayGameplaySoundTrack() {
	result = system->playSound(gameplaySound, 0, false, &channel);
}

void AudioManager::PlayBossSoundTrack() {
	result = system->playSound(bossSoundTrack, 0, false, &channel);
}

void AudioManager::PlayClickSound() {
	result = system->playSound(clickSound, 0, false, &channel);
	channel->setVolume(1);
}

void AudioManager::PlayHoverButtonSound() {
	result = system->playSound(clickSound, 0, false, &channel);
	//cut off sound after 1 sec
}

void AudioManager::LoadSounds()
{
	result = system->createSound("../Assets/Audio/bg1.mp3", FMOD_DEFAULT, 0, &bgSoundTrack);
	result = bgSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createSound("../Assets/Audio/", FMOD_DEFAULT, 0, &creditSoundTrack);
	result = creditSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &winSoundTrack);
	result = winSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &loseSoundTrack);
	result = loseSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &shootSound);
	result = shootSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &pickUpSound);
	result = pickUpSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &collideSound);
	result = collideSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &damagedSound);
	result = damagedSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &swingSound);
	result = swingSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &explosionSound);
	result = explosionSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &gameplaySound);
	result = gameplaySound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/", FMOD_DEFAULT, 0, &bossSoundTrack);
	result = bossSoundTrack->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/click-electronic.wav", FMOD_DEFAULT, 0, &clickSound);
	result = bossSoundTrack->setMode(FMOD_LOOP_OFF);
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


