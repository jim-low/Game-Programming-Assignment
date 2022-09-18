#include "Level1.h"
#include "CreditsPage.h"
#include "MainMenu.h"
#include "SettingsPage.h"

void MainMenu::Initialize() {
	//=====================
	//INITIALIZE GAME TITLE
	//=====================

	//initialize playbutton
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/game-title.png", &titleTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Title texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Title texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}
	audioManager->SetGroupPanning(0);
	//initialize position 
	titleWidth = 512;
	titleHeight = 256;
	titleRect.top = 0;
	titleRect.bottom = titleHeight;
	titleRect.left = 0;
	titleRect.right = titleWidth;

	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.bottom + 24;

	//=====================
	//INITIALIZE LINES
	//=====================
	hr = D3DXCreateLine(d3dDevice, &lineBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create LineBrush for Main menu (left).";
		MessageBox(NULL, TEXT("Failed to create LineBrush for Main menu (left)."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//define the coordinates of line 1----

	l1StartPoint = D3DXVECTOR2(MyWindowWidth / 6, MyWindowHeight / 12);
	l1EndPoint = D3DXVECTOR2(MyWindowWidth / 6, MyWindowHeight / 12 * 11);
	l1LineVertices[0] = l1StartPoint;
	l1LineVertices[1] = l1EndPoint;

	//define the coordinates of line 2----
	l2StartPoint = D3DXVECTOR2(MyWindowWidth / 6 * 5, MyWindowHeight / 12);
	l2EndPoint = D3DXVECTOR2(MyWindowWidth / 6 * 5, MyWindowHeight / 12 * 11);
	l2LineVertices[0] = l2StartPoint;
	l2LineVertices[1] = l2EndPoint;

	//=====================
	//INITIALIZE BUTTONS
	//=====================
	//initialize Brush
	hr = D3DXCreateSprite(d3dDevice, &sprite);
	if (FAILED(hr)) {
		std::cout << "Failed to create the Button Brush.";
		MessageBox(NULL, TEXT("Failed to create the Button Brush."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//define button size
	menuButtonWidth = 351;
	menuButtonHeight = 163;
	//define the current selection
	currentSelection = UNFOCUS;

	//initialize Transformations on buttons
	scaling = D3DXVECTOR2(0.9f, 0.9f); //make it smaller 
	centre = D3DXVECTOR2(menuButtonWidth / 2, menuButtonHeight / 2);

	//=====================
	//INITIALIZE PLAY BUTTON
	//=====================

	//initialize playbutton
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/playButton.png", &butPlayTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Play Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Play Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	// dont mind this normal comment
	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA - Jim 16 September 2022

	//initialize rectangle
	buttonPlayRect.top = 0;
	buttonPlayRect.bottom = buttonPlayRect.top + menuButtonHeight;
	buttonPlayRect.left = 0;
	buttonPlayRect.right = buttonPlayRect.left + menuButtonWidth;

	//=====================
	//INITIALIZE SETTINGS BUTTON
	//=====================

	//initialize settings button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/settingsButton.png", &butSettingsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Settings Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Settings Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize rect 
	buttonSettingsRect.top = 0;
	buttonSettingsRect.bottom = buttonSettingsRect.top + menuButtonHeight;
	buttonSettingsRect.left = 0;
	buttonSettingsRect.right = buttonSettingsRect.left + menuButtonWidth;

	//=====================
	//INITIALIZE CREDITS BUTTON
	//=====================

	//initialize credits button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/creditsButton.png", &butCreditsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Credits Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Credits Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize rect
	buttonCreditsRect.top = 0;
	buttonCreditsRect.bottom = buttonCreditsRect.top + menuButtonHeight;
	buttonCreditsRect.left = 0;
	buttonCreditsRect.right = buttonCreditsRect.left + menuButtonWidth;

	//=====================
	//INITIALIZE QUIT BUTTON
	//=====================

	//initialize quit (selected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/quitButton.png", &butQuitTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Quit Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Quit Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize rect 
	buttonQuitRect.top = 0;
	buttonQuitRect.bottom = buttonQuitRect.top + menuButtonHeight;
	buttonQuitRect.left = 0;
	buttonQuitRect.right = buttonQuitRect.left + menuButtonWidth;

	//initialize the collision rectangles and positions
	playPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 5);
	playCol.left = playPosition.x + 15;
	playCol.top = playPosition.y + 25;
	playCol.right = playCol.left + menuButtonWidth - 105;
	playCol.bottom = playCol.top + menuButtonHeight - 75;

	settingsPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 8); 
	settingsCol.left = settingsPosition.x + 15;
	settingsCol.top = settingsPosition.y + 10 ;
	settingsCol.right = settingsCol.left + menuButtonWidth - 105;
	settingsCol.bottom = settingsCol.top + menuButtonHeight - 75;

	creditsPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 11);
	creditsCol.left = creditsPosition.x + 15;
	creditsCol.top = creditsPosition.y;
	creditsCol.right = creditsCol.left + menuButtonWidth - 105;
	creditsCol.bottom = creditsCol.top + menuButtonHeight - 75;

	quitPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 14);
	quitCol.left = quitPosition.x + 15;
	quitCol.top = quitPosition.y;
	quitCol.right = quitCol.left + menuButtonWidth - 105;
	quitCol.bottom = quitCol.top + menuButtonHeight - 80;

	audioManager->PlayMainMenuSoundTrack();
}

void MainMenu::Update() {
	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.left + 24;

	//check if its in collision
	if (Game::CheckCollision(mouse, playCol)) {
		//when hovered, light up the button and set to a selection based on the hovered button
		buttonPlayRect.left = menuButtonWidth;
		buttonPlayRect.right = menuButtonWidth * 2;
		currentSelection = PLAY;
	}
	else {
		//else, dim button
		buttonPlayRect.left = 0;
		buttonPlayRect.right = menuButtonWidth;
	}

	if (Game::CheckCollision(mouse, settingsCol)) {
		buttonSettingsRect.left = menuButtonWidth;
		buttonSettingsRect.right = menuButtonWidth * 2;
		currentSelection = SETTINGS;
	}
	else {
		buttonSettingsRect.left = 0;
		buttonSettingsRect.right = menuButtonWidth;
	}

	if (Game::CheckCollision(mouse, creditsCol)) {
		buttonCreditsRect.left = menuButtonWidth;
		buttonCreditsRect.right = menuButtonWidth * 2;
		currentSelection = CREDITS;
	}
	else {
		buttonCreditsRect.left = 0;
		buttonCreditsRect.right = menuButtonWidth;
	}

	if (Game::CheckCollision(mouse, quitCol)) {
		buttonQuitRect.left = menuButtonWidth;
		buttonQuitRect.right = menuButtonWidth * 2;
		currentSelection = QUIT;	
	}
	else {
		buttonQuitRect.left = 0;
		buttonQuitRect.right = menuButtonWidth;
	}

	//if its not hovered on any button, reset the selection to UNFOCUSED
	if (!Game::CheckCollision(mouse, playCol) &&
		!Game::CheckCollision(mouse, settingsCol) &&
		!Game::CheckCollision(mouse, creditsCol) &&
		!Game::CheckCollision(mouse, quitCol)) {
		currentSelection = UNFOCUS;
	}

	//sound effect
	if (currentSelection != UNFOCUS && leftKeyPressed) {
		audioManager->PlayClickSound();
	}

	if (leftKeyPressed) {
		leftKeyPressed = false;
		if (currentSelection == PLAY) {
			audioManager->PlayClickSound();
			audioManager->StopBackgroundSound(); //stop the BG
			games.push(new Level1()); //push selected GAME
		}

		else if (currentSelection == SETTINGS) {
			audioManager->PlayClickSound();
			games.push(new SettingsPage());
		}

		else if (currentSelection == CREDITS) {
			audioManager->PlayClickSound();
			audioManager->StopBackgroundSound();
			games.push(new CreditsPage());
		}

		else if (currentSelection == QUIT) {
			exit(0);
		}
	}

}

void MainMenu::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//set matrix to play button
	position = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 5); //height follows a 20:4 ratio
	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, &scaling, &centre, NULL, &position);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butPlayTexture, &buttonPlayRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//set matrix to settings button
	position = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 8);
	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, &scaling, &centre, NULL, &position);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butSettingsTexture, &buttonSettingsRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//set matrix the credits button
	position = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 11);
	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, &scaling, &centre, NULL, &position);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butCreditsTexture, &buttonCreditsRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//set matrix to quit button
	position = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 14);
	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, &scaling, &centre, NULL, &position);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(butQuitTexture, &buttonQuitRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//set matrix to title
	position = D3DXVECTOR2((MyWindowWidth / 2) - (titleWidth / 2), MyWindowHeight/30); //height follows a 20:4 ratio
	centre = D3DXVECTOR2(menuButtonWidth / 2, menuButtonHeight / 2);
	D3DXMatrixTransformation2D(&buttonMat, &centre, 0.0, NULL, NULL, NULL, &position);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(titleTexture, &titleRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	
	sprite->End();

	//start line 1
	lineBrush->Draw(l1LineVertices, 2, D3DCOLOR_XRGB(56, 175, 235));

	//start line 2
	lineBrush->Draw(l2LineVertices, 2, D3DCOLOR_XRGB(56, 175, 235));

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void MainMenu::Input() {
	dInputMouseDevice->Acquire();
	dInputMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);

	if (BUTTONDOWN(mouseState, 0)) //left click
	{
		leftKeyPressed = true;
	}
}

MainMenu::~MainMenu() {
}