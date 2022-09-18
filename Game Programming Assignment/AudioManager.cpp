#include "Header.h";

void AudioManager::InitializeAudio()
{
	result = FMOD::System_Create(&system);
	result = system->init(64, FMOD_INIT_NORMAL, extraDriverData);
	result = system->createChannelGroup(channelGroup, &bgGroup);
	result = system->createChannelGroup(channelGroup, &panGroup);
	result = system->createChannelGroup(channelGroup, &effectsGroup);
	bgVolume = 0.1;
	effectVolume = 1;
	bgGroup->setVolume(bgVolume);
}

int AudioManager::getEffectsVolume()
{
	return int(effectVolume)*100;
}

void AudioManager::setBackgroundVolume(float volume) {
	bgGroup->setVolume(volume);
}

int AudioManager::getBackgroundVolume()
{
	return int(bgVolume)*100;
}

void AudioManager::setEffectsVolume(float volume) {
	effectsGroup->setVolume(volume);
}

void AudioManager::PlayMainMenuSoundTrack(){
	result = system->playSound(bgSoundTrack, bgGroup, false, &channel);
	
	bgGroup->setPitch(1.5);
}

void AudioManager::StopBackgroundSound() {
	bgGroup->stop();
}

void AudioManager::SetPanning(float panValue) {
	panGroup->setPan(panValue);
}

void AudioManager::PlayCometSound() {
	result = system->playSound(cometSound, panGroup, false, &channel);
}

void AudioManager::PlayCreditsSound(){
	result = system->playSound(creditSoundTrack, bgGroup, false, &channel);
}

void AudioManager::PlayWinSoundTrack(){
	result = system->playSound(winSoundTrack, bgGroup, false, &channel);
}

void AudioManager::PlayLoseSoundTrack() {
	result = system->playSound(loseSoundTrack, bgGroup, false, &channel);
}

void AudioManager::PlayGameplaySoundTrack() {
	result = system->playSound(gameplaySound, bgGroup, false, &channel);
}

void AudioManager::PlayCollisionSound() {
	result = system->playSound(collideSound, effectsGroup, false, &channel);
}

void AudioManager::PlayDamagedSound() {
	result = system->playSound(damagedSound, effectsGroup, false, &channel);
}

void AudioManager::PlayExplosionSound() {
	result = system->playSound(explosionSound, effectsGroup, false, &channel);
}

void AudioManager::PlayClickSound() {
	result = system->playSound(clickSound, effectsGroup, false, &channel);
}
void AudioManager::LoadSounds()
{

	result = system->createSound("../Assets/Audio/bg1.mp3", FMOD_DEFAULT, 0, &bgSoundTrack);
	result = bgSoundTrack->setMode(FMOD_LOOP_NORMAL);

	result = system->createSound("../Assets/Audio/Credit_Tracks.mp3", FMOD_DEFAULT, 0, &creditSoundTrack);
	result = creditSoundTrack->setMode(FMOD_LOOP_NORMAL);

	result = system->createStream("../Assets/Audio/Win_Music.wav", FMOD_DEFAULT, 0, &winSoundTrack);
	result = winSoundTrack->setMode(FMOD_LOOP_NORMAL);

	result = system->createStream("../Assets/Audio/Lose_Music.mp3", FMOD_DEFAULT, 0, &loseSoundTrack);
	result = loseSoundTrack->setMode(FMOD_LOOP_NORMAL);

	result = system->createStream("../Assets/Audio/Enemy_Damaged.wav", FMOD_DEFAULT, 0, &collideSound);
	result = collideSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Player_Damaged.wav", FMOD_DEFAULT, 0, &damagedSound);
	result = damagedSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Ship_Explosion.wav", FMOD_DEFAULT, 0, &explosionSound);
	result = explosionSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/Fight_Music_Loop.wav", FMOD_DEFAULT, 0, &gameplaySound);
	result = gameplaySound->setMode(FMOD_LOOP_NORMAL);

	result = system->createStream("../Assets/Audio/click-electronic.wav", FMOD_DEFAULT, 0, &clickSound);
	result = clickSound->setMode(FMOD_LOOP_OFF);

	result = system->createStream("../Assets/Audio/flyby.mp3", FMOD_DEFAULT, 0, &cometSound);
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


