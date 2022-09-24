#include "Level1.h"
#include "CreditsPage.h"
#include "MainMenu.h"
#include "SettingsPage.h"
#include "Button.h"

void playClick() {
	audioManager->StopBackgroundSound();
	games.push(new Level1());
}

void creditsClick() {
	audioManager->StopBackgroundSound();
	games.push(new CreditsPage());
}

void settingsClick() {
	games.push(new SettingsPage());
}

void quitClick() {
	exit(0);
}


void MainMenu::Initialize() {
	//=====================
	//INITIALIZE GAME TITLE
	//=====================
	
	//initialize gametitle
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

	////initialize playbutton
	playButton = new Button(351, 163, D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2) + 15, MyWindowHeight / 20 * 5), "../Assets/Buttons/playButton.png", &playClick);
	//adjust the collision rectangle (by hard code, since it is inaccurate)
	playButton->presetColRect(25, -75, 15, -90);

	
	//// dont mind this normal comment
	//// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA - Jim 16 September 2022

	//=====================
	//INITIALIZE SETTINGS BUTTON
	//=====================
	
	////initialize settings button
	settingsButton = new Button(351, 163, D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2) + 15, MyWindowHeight / 20 * 8), "../Assets/Buttons/settingsButton.png", &settingsClick);
	////adjust the collision rectangle (by hard code, since it is inaccurate)
	settingsButton->presetColRect(10, -75, 15, -90);

	//=====================
	//INITIALIZE CREDITS BUTTON
	//=====================

	//initialize credits button
	creditsButton = new Button(351, 163, D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2) + 15, MyWindowHeight / 20 * 11), "../Assets/Buttons/creditsButton.png", &creditsClick);
	//adjust the collision rectangle (by hard code, since it is inaccurate)
	creditsButton->presetColRect(0, -75, 15, -90);

	//=====================
	//INITIALIZE QUIT BUTTON
	//=====================

	////initialize quit (selected) button
	quitButton = new Button(351, 163, D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2) + 15, MyWindowHeight / 20 * 14), "../Assets/Buttons/quitButton.png", &quitClick);
	
	//adjust the collision rectangle (by hard code, since it is inaccurate)
	quitButton->presetColRect(0, -80, 15, -90);
	
	audioManager->PlayMainMenuSoundTrack();
}

void MainMenu::Update() {

	playButton->Update(); 
	settingsButton->Update();
	creditsButton->Update();
	quitButton->Update();
}

void MainMenu::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	playButton->Render();
	settingsButton->Render();
	creditsButton->Render();
	quitButton->Render();

	////set matrix to title
	position = D3DXVECTOR2((MyWindowWidth / 2) - (titleWidth / 2), MyWindowHeight/30); 
	centre = D3DXVECTOR2(menuButtonWidth / 2, menuButtonHeight / 2);
	D3DXMatrixTransformation2D(&mat, &centre, 0.0, NULL, NULL, NULL, &position);
	sprite->SetTransform(&mat);
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
}

MainMenu::~MainMenu() {
}