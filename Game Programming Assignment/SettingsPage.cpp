#include "SettingsPage.h"
#include <string> 

void SettingsPage::Initialize() {
	//=====================
	//INITIALIZE BUTTONS
	//=====================

	//initialize left button
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/leftButton.png", &butLeftTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create left Button texture.";
		MessageBox(NULL, TEXT("Failed to create left Button texture."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize right button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/rightButton.png", &butRightTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create right Button texture.";
		MessageBox(NULL, TEXT("Failed to create right Button texture."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize location
	arrButtonWidth = 110;
	arrButtonHeight = 130;

	buttonRightBGRect.top = 0;
	buttonRightBGRect.bottom = arrButtonHeight;
	buttonRightBGRect.left = 0;
	buttonRightBGRect.right = arrButtonWidth;

	buttonLeftBGRect.top = 0;
	buttonLeftBGRect.bottom = arrButtonHeight;
	buttonLeftBGRect.left = 0;
	buttonLeftBGRect.right = arrButtonWidth;

	buttonRightEffRect.top = 0;
	buttonRightEffRect.bottom = arrButtonHeight;
	buttonRightEffRect.left = 0;
	buttonRightEffRect.right = arrButtonWidth;

	buttonLeftEffRect.top = 0;
	buttonLeftEffRect.bottom = arrButtonHeight;
	buttonLeftEffRect.left = 0;
	buttonLeftEffRect.right = arrButtonWidth;

	//initialize matrix
	centre = D3DXVECTOR2(arrButtonWidth/2, arrButtonHeight/2);
	scaling = D3DXVECTOR2(1.0f, 1.0f);

	//initialize collision rectangles
	leftBGPos = D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) - 200 , (MyWindowHeight / 10) * 2);
	leftBGButtonCol.top = leftBGPos.y;
	leftBGButtonCol.bottom = leftBGButtonCol.top + arrButtonHeight;
	leftBGButtonCol.left = leftBGPos.x;
	leftBGButtonCol.right = leftBGButtonCol.left + arrButtonWidth;

	rightBGPos = D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) + 200 , (MyWindowHeight / 10) * 2);
	rightBGButtonCol.top = rightBGPos.y;
	rightBGButtonCol.bottom = rightBGButtonCol.top + arrButtonHeight;
	rightBGButtonCol.left = rightBGPos.x;
	rightBGButtonCol.right = rightBGButtonCol.left + arrButtonWidth;

	leftEffPos = D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) - 200 , (MyWindowHeight / 10) * 5 );
	leftEffButtonCol.top = leftEffPos.y;
	leftEffButtonCol.bottom = leftEffButtonCol.top + arrButtonHeight;
	leftEffButtonCol.left = leftEffPos.x;
	leftEffButtonCol.right = leftEffButtonCol.left + arrButtonWidth;

	rightEffPos = D3DXVECTOR2((MyWindowWidth / 2) - (arrButtonWidth / 2) + 200, (MyWindowHeight / 10) * 5 );
	rightEffButtonCol.top = rightEffPos.y;
	rightEffButtonCol.bottom = rightEffButtonCol.top + arrButtonHeight;
	rightEffButtonCol.left = rightEffPos.x;
	rightEffButtonCol.right = rightEffButtonCol.left + arrButtonWidth;

	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.bottom + 24;

	//initialize label
	hr = D3DXCreateFont(d3dDevice, 80, 30, 0, 1, false, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tw Cen MT Condensed", &font);
	if (FAILED(hr)) {
		cout << "Failed to create font." << endl;
		MessageBox(NULL, TEXT("Failed to create font."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	hr = D3DXCreateFont(d3dDevice, 30, 10, 0, 1, false, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "News Gothic", &escFont);
	if (FAILED(hr)) {
		cout << "Failed to create esc font." << endl;
		MessageBox(NULL, TEXT("Failed to create esc font."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}
	bGLabelRect.top = 0;
	bGLabelRect.bottom = 80;
	bGLabelRect.left = 0;
	bGLabelRect.right = 260;
	bGLabelPos = D3DXVECTOR2((MyWindowWidth / 2) - (bGLabelRect.right / 2), (MyWindowHeight / 10));

	effLabelRect.top = 0;
	effLabelRect.bottom = 80;
	effLabelRect.left = 0;
	effLabelRect.right = 420;
	effLabelPos = D3DXVECTOR2((MyWindowWidth / 2) - (effLabelRect.right / 2), (MyWindowHeight / 10) * 4);
	
	bGSoundCounter = audioManager->getBackgroundVolume(); //TO BE CHANGED
	effSoundCounter = audioManager->getEffectsVolume(); //TO BE CHANGED

	bGSoundCountRect.top = 0;
	bGSoundCountRect.bottom = 80;
	bGSoundCountRect.left = 0;
	bGSoundCountRect.right = 100;
	bGCountPos = D3DXVECTOR2((MyWindowWidth / 2) - (bGSoundCountRect.right / 2), (MyWindowHeight / 10) * 2.3);

	effSoundCountRect.top = 0;
	effSoundCountRect.bottom = 80;
	effSoundCountRect.left = 0;
	effSoundCountRect.right = 100;
	effCountPos = D3DXVECTOR2((MyWindowWidth / 2) - (effSoundCountRect.right / 2), (MyWindowHeight / 10) * 5.3);

	bufferTimer = 5;

	escLabelRect.top = 0;
	escLabelRect.bottom = 30;
	escLabelRect.left = 0;
	escLabelRect.right = 500;
	escLabelPos = D3DXVECTOR2(0, 0);
}

void SettingsPage::Update() {
	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.left + 24;

	if (Game::CheckCollision(mouse, leftBGButtonCol)) { //check collision with button textures
		buttonLeftBGRect.left = arrButtonWidth;
		buttonLeftBGRect.right = arrButtonWidth * 2;
		
		currentSelection = MINUSBG;
	}
	else {
		buttonLeftBGRect.left = 0;
		buttonLeftBGRect.right = arrButtonWidth;
	}

	if (Game::CheckCollision(mouse, rightBGButtonCol)) {
		buttonRightBGRect.left = arrButtonWidth;
		buttonRightBGRect.right = arrButtonWidth * 2;
		
		currentSelection = ADDBG;
	}
	else {
		buttonRightBGRect.left = 0;
		buttonRightBGRect.right = arrButtonWidth;
	}

	if (Game::CheckCollision(mouse, leftEffButtonCol)) {
		buttonLeftEffRect.left = arrButtonWidth;
		buttonLeftEffRect.right = arrButtonWidth * 2;
		
		currentSelection = MINUSEFF;
	}
	else {
		buttonLeftEffRect.left = 0;
		buttonLeftEffRect.right = arrButtonWidth;
	}

	if (Game::CheckCollision(mouse, rightEffButtonCol)) {
		buttonRightEffRect.left = arrButtonWidth;
		buttonRightEffRect.right = arrButtonWidth * 2;

		currentSelection = ADDEFF;
	}
	else {
		buttonRightEffRect.left = 0;
		buttonRightEffRect.right = arrButtonWidth;
	}

	if (!Game::CheckCollision(mouse, leftBGButtonCol) &&
		!Game::CheckCollision(mouse, rightBGButtonCol) &&
		!Game::CheckCollision(mouse, leftEffButtonCol) &&
		!Game::CheckCollision(mouse, rightEffButtonCol)) {
		currentSelection = UNFOCUS;
	}

	if (leftKeyPressed) {//if left key pressed, check if mouse position is on the button texture
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

		leftKeyPressed = false;	
	}

	if (escKeyPressed) {; //if escape key is pressed
		games.pop();
		audioManager->PlayMainMenuSoundTrack();
		escKeyPressed = false;
	}
}



void SettingsPage::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//set matrix
	D3DXMatrixTransformation2D(&buttonMat, &centre, 0.0, &scaling, NULL, NULL, &leftBGPos);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butLeftTexture, &buttonLeftBGRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//set matrix
	D3DXMatrixTransformation2D(&buttonMat, &centre, 0.0, &scaling, NULL, NULL, &rightBGPos);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butRightTexture, &buttonRightBGRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//set matrix
	D3DXMatrixTransformation2D(&buttonMat, &centre, 0.0, &scaling, NULL, NULL, &leftEffPos);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butLeftTexture, &buttonLeftEffRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//set matrix
	D3DXMatrixTransformation2D(&buttonMat, &centre, 0.0, &scaling, NULL, NULL, &rightEffPos);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butRightTexture, &buttonRightEffRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//labels
	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, NULL, NULL, NULL, &bGLabelPos);
	sprite->SetTransform(&buttonMat);
	font->DrawText(sprite, "BG MUSIC", -1, &bGLabelRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, NULL, NULL, NULL, &effLabelPos);
	sprite->SetTransform(&buttonMat);
	font->DrawText(sprite, "SOUND EFFECTS", -1, &effLabelRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, NULL, NULL, NULL, &bGCountPos);
	sprite->SetTransform(&buttonMat);
	font->DrawText(sprite, to_string(bGSoundCounter).c_str() , -1, &effLabelRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, NULL, NULL, NULL, &effCountPos);
	sprite->SetTransform(&buttonMat);
	font->DrawText(sprite, to_string(effSoundCounter).c_str(), -1, &effLabelRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, NULL, NULL, NULL, &escLabelPos);
	sprite->SetTransform(&buttonMat);
	escFont->DrawText(sprite, "Press the 'ESC' key to go back.", -1, &escLabelRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void SettingsPage::Input() {
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	dInputMouseDevice->Acquire();
	dInputMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);

	if (BUTTONDOWN(mouseState, 0)) //left click
	{
		leftKeyPressed = true;
	}

	if (diKeys[DIK_ESCAPE] & 0x80) {
		escKeyPressed = true;
	}
}

SettingsPage::~SettingsPage() {
}
