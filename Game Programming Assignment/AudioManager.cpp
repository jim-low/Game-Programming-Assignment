#include "Header.h";

void AudioManager::InitializeAudio()
{
	result = FMOD::System_Create(&system);
	result = system->init(64, FMOD_INIT_NORMAL, extraDriverData);
	result = system->createChannelGroup(channelGroup, &bgGroup);
	result = system->createChannelGroup(channelGroup, &panGroup);
	result = system->createChannelGroup(channelGroup, &effectsGroup);
	bgVolume = 0;
	effectVolume = 0;
	bgGroup->setVolume(bgVolume);
	effectsGroup->setVolume(effectVolume);
	LoadSounds();
}

int AudioManager::getEffectsVolume() //this is to retrieve current volume set to the effects channel group
{
	return float(effectVolume)*100;
}

void AudioManager::setBackgroundVolume(float volume) { //this is to set a new background volume to the bg channel group
	bgVolume = volume/100;
	
	bgGroup->setVolume(bgVolume);
}

int AudioManager::getBackgroundVolume() //this is to retrieve current volume set to the background channel group
{
	return float(bgVolume)*100;
}

void AudioManager::setEffectsVolume(float volume) { //this is to set a new effects volume to the effect channel group
	effectVolume = volume/100;
	effectsGroup->setVolume(effectVolume);
}

void AudioManager::PlayMainMenuSoundTrack(){ 
	result = system->playSound(bgSoundTrack, bgGroup, false, &channel);
	
	bgGroup->setPitch(1);
}

void AudioManager::StopBackgroundSound() { //stops the background sound track
	bgGroup->stop();
}

void AudioManager::SetPanning(float panValue) { //sets a pan value from the pass in value
	panGroup->setPan(panValue);
}
void AudioManager::SetGroupPanning(float panValue) {
	bgGroup->setPan(panValue);
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
