#include "SettingsPage.h"
#include <string> 

void incBGClick() {
	if (clickDelay == false) { //if there is no clickdelay ongoing. 
		if (bGSoundCounter < 100) {
			bGSoundCounter += 10;
			audioManager->setBackgroundVolume(bGSoundCounter);
			audioManager->PlayClickSound();

		}
		std::cout << bGSoundCounter << std::endl;
		clickDelay = true;
	}

	if (clickDelay == true) {
		if (inputBuffer <= 0) { //end of buffertimer.
			inputBuffer = 2; //reset timer
			clickDelay = false; //revert clickDelay
		}

		else {
			inputBuffer--;
		}
	}
}

void decBGClick() {
	if (clickDelay == false) { //if there is no clickdelay ongoing. 
		if (bGSoundCounter > 0) {
			bGSoundCounter -= 10;
			audioManager->setBackgroundVolume(bGSoundCounter);
			audioManager->PlayClickSound();
		}
		clickDelay = true;
	}

	if (clickDelay == true) {
		if (inputBuffer <= 0) { //end of buffertimer.
			inputBuffer = 2; //reset timer
			clickDelay = false; //revert clickDelay
		}

		else {
			inputBuffer--;
		}
	}
}

void incEffClick() {
	if (clickDelay == false) { //if there is no clickdelay ongoing. 
		if (effSoundCounter < 100) {
			effSoundCounter += 10;
			audioManager->setEffectsVolume(effSoundCounter);
			audioManager->PlayClickSound();
			//increase effect sound volume
		}
		clickDelay = true;
	}

	if (clickDelay == true) {
		if (inputBuffer <= 0) { //end of buffertimer.
			inputBuffer = 2; //reset timer
			clickDelay = false; //revert clickDelay
		}

		else {
			inputBuffer--;
		}
	}
}

void decEffClick() {
	if (clickDelay == false) { //if there is no clickdelay ongoing. 
		if (effSoundCounter > 0) {
			effSoundCounter -= 10;
			audioManager->setEffectsVolume(effSoundCounter);
			audioManager->PlayClickSound();
			//decrease effect sound volume
		}
		clickDelay = true;
	}

	if (clickDelay == true) {
		if (inputBuffer <= 0) { //end of buffertimer.
			inputBuffer = 2; //reset timer
			clickDelay = false; //revert clickDelay

		}

		else {
			inputBuffer--;
		}
	}
}

void SettingsPage::Initialize() {
	//initialize input buffer
	inputBuffer = 2;
	clickDelay = false;

	//=====================
	//INITIALIZE BUTTONS
	//=====================

	//initialize button format
	arrButtonWidth = 110;
	arrButtonHeight = 130;

	incBGVol = new Button(arrButtonWidth, arrButtonHeight, D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) + 200, (MyWindowHeight / 10) * 2), "../Assets/Buttons/rightButton.png", &incBGClick);
	decBGVol = new Button(arrButtonWidth, arrButtonHeight, D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) - 200, (MyWindowHeight / 10) * 2), "../Assets/Buttons/leftButton.png", &decBGClick);
	incEffVol = new Button(arrButtonWidth, arrButtonHeight, D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) + 200, (MyWindowHeight / 10) * 5), "../Assets/Buttons/rightButton.png", &incEffClick);
	decEffVol = new Button(arrButtonWidth, arrButtonHeight, D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) - 200, (MyWindowHeight / 10) * 5), "../Assets/Buttons/leftButton.png", &decEffClick);

	//=====================
	//INITIALIZE LABELS
	//=====================
	
	//initialize bg and effect label
	bgLabel = new Label(D3DXVECTOR2((MyWindowWidth / 2) - (260 / 2), (MyWindowHeight / 10)), "Tw Cen MT Condensed", "BG MUSIC", 30, 80);
	effLabel = new Label(D3DXVECTOR2((MyWindowWidth / 2) - (420 / 2), (MyWindowHeight / 10) * 4), "Tw Cen MT Condensed", "SOUND EFFECTS", 30, 80);

	//initialize the gb and effect count
	bgCount = new Label(D3DXVECTOR2((MyWindowWidth / 2) - (100 / 2), (MyWindowHeight / 10) * 2.3), "Tw Cen MT Condensed", to_string(bGSoundCounter).c_str(), 30, 80);
	effCount = new Label(D3DXVECTOR2((MyWindowWidth / 2) - (100 / 2), (MyWindowHeight / 10) * 5.3), "Tw Cen MT Condensed", to_string(effSoundCounter).c_str(), 30, 80);

	//initialize esc Label
	escLabel = new Label(D3DXVECTOR2(0,0), "News Gothic", "Press the 'ESC' key to go back.", 10, 30);
}

void SettingsPage::Update() {

	incBGVol->Update();
	decBGVol->Update();
	incEffVol->Update();
	decEffVol->Update();

	if (DirectInput::isMouseDown(0)) { //if left key pressed, check if mouse position is on the button texture
		bufferTimer -= 1;

		if (bufferTimer <= 0) {
			if (currentSelection == MINUSBG) {
				if (bGSoundCounter > 0) {
					bGSoundCounter -= 10;
					audioManager->setBackgroundVolume(bGSoundCounter);
					audioManager->PlayClickSound();
				}
				//decrease BG Volume
			}
			else if (currentSelection == ADDBG) {
				if (bGSoundCounter < 100) {
					bGSoundCounter += 10; 
					audioManager->setBackgroundVolume(bGSoundCounter);
					audioManager->PlayClickSound();
					//increase BG Volume
				}
			}
			else if (currentSelection == MINUSEFF) {
				if (effSoundCounter > 0) {
					effSoundCounter -= 10; 
					audioManager->setEffectsVolume(effSoundCounter);
					audioManager->PlayClickSound();
					//decrease effect sound volume
				}
				
			}
			else if (currentSelection == ADDEFF) {
				if (effSoundCounter < 100) {
					effSoundCounter += 10;
					audioManager->setEffectsVolume(effSoundCounter);
					audioManager->PlayClickSound();
					//increase effect sound volume
				}
			}

			bufferTimer = 5;
		}
	}

	if (DirectInput::IsKeyDown(DIK_ESCAPE)) { //if escape key is pressed
		games.pop();
		audioManager->PlayMainMenuSoundTrack();
	}
}



void SettingsPage::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//render buttons
	incBGVol->Render();
	decBGVol->Render();
	incEffVol->Render();
	decEffVol->Render();

	//render labels
	bgLabel->Render();
	effLabel->Render();
	bgCount->RenderWithUpdatingValue(bGSoundCounter);
	effCount->RenderWithUpdatingValue(effSoundCounter);
	escLabel->Render();
	sprite->End();

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

SettingsPage::~SettingsPage() {
}
