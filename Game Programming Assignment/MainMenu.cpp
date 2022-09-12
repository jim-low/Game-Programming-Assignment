#include "MainMenu.h"

MainMenu::~MainMenu() {
}

void MainMenu::Initialize() {

	//=====================
	//INITIALIZE GAME TITLE
	//=====================
	
	//initialize brush
	HRESULT hr = D3DXCreateFont(d3dDevice, 80, 25, 200, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Bauhaus 93"), &titleBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create Menu Title.";
		MessageBox(NULL, TEXT("Failed to create Menu Title."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	titleRect.top = 60; //change later
	titleRect.bottom = titleRect.top + 400;
	titleRect.left = (MyWindowWidth / 2 / 2) + 40;
	titleRect.right = titleRect.left + 500;

	//=====================
	//INITIALIZE LINES
	//=====================
	hr = D3DXCreateLine(d3dDevice, &lineBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create LineBrush for Main menu (left).";
		MessageBox(NULL, TEXT("Failed to create Menu Title."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//define the coordinates of line 1----

	l1StartPoint = D3DXVECTOR2(MyWindowWidth / 4, MyWindowHeight / 9);
	l1EndPoint = D3DXVECTOR2(MyWindowWidth / 4, MyWindowHeight / 9 * 8);
	l1LineVertices[0] = l1StartPoint;
	l1LineVertices[1] = l1EndPoint;


	//define the coordinates of line 2----
	l2StartPoint = D3DXVECTOR2(MyWindowWidth / 4 * 3, MyWindowHeight / 9);
	l2EndPoint = D3DXVECTOR2(MyWindowWidth / 4 * 3, MyWindowHeight / 9 * 8);
	l2LineVertices[0] = l2StartPoint;
	l2LineVertices[1] = l2EndPoint;

	//=====================
	//INITIALIZE BUTTONS
	//=====================
	//initialize Brush
	hr = D3DXCreateSprite(d3dDevice, &buttonBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create the Button Brush.";
		MessageBox(NULL, TEXT("Failed to create the Button Brush."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	menuButtonWidth = 351;
	menuButtonHeight = 163;
	int errorWidth = 150; //the program cant properly print out the correct Width. thus adding extra Width when printed later
	int errorHeight = 100; //the program cant properly print out the correct Height. thus adding extra Height when printed later

	//initialize Transformations on buttons
	D3DXMATRIX mat;
	D3DXVECTOR2 scaling = D3DXVECTOR2(0.4f, 0.4f); //make it smaller
	D3DXVECTOR2 spriteCentre = D3DXVECTOR2(menuButtonWidth / 2, menuButtonHeight / 2);
	float rotation = 0.0f;
	//set transformation
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &position);
	//buttonBrush->SetTransform(&mat);

	//=====================
	//INITIALIZE PLAY BUTTON
	//=====================
	
	//initialize play (unselected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/playButton(Unselected).png", &butUnPlayTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Unselected Play Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Unselected Play Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);	
	}

	//initialize play (selected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/playButton(Selected).png", &butPlayTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Selected Play Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Selected Play Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	buttonPlayRect.top = 0;
	buttonPlayRect.bottom = buttonPlayRect.top + menuButtonHeight;
	buttonPlayRect.left = MyWindowWidth/2/2;
	buttonPlayRect.right = buttonPlayRect.left + menuButtonWidth;

	//=====================
	//INITIALIZE SETTINGS BUTTON
	//=====================

	//initialize settings (unselected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/settingsButton(Unselected).png", &butUnSettingsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Unselected Settings Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Unselected Settings Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize settings (selected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/settingsButton(Selected).png", &butSettingsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Selected Settings Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Selected Settings Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	buttonSettingsRect.top = 0;
	buttonSettingsRect.bottom = 0;
	buttonSettingsRect.left = 0;
	buttonSettingsRect.right = 0;

	//=====================
	//INITIALIZE CREDITS BUTTON
	//=====================

	//initialize credits (unselected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/creditsButton(Unselected).png", &butUnCreditsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Unselected credits Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Unselected credits Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize credits (selected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/creditsButton(Selected).png", &butCreditsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Selected credits Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Selected credits Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position
	buttonCreditsRect.top = 0;
	buttonCreditsRect.bottom = 0;
	buttonCreditsRect.left = 0;
	buttonCreditsRect.right = 0;

	//=====================
	//INITIALIZE QUIT BUTTON
	//=====================

	//initialize quit (unselected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/quitButton(Unselected).png", &butUnQuitTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Unselected quit Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Unselected quit Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize quit (selected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/Buttons/quitButton(Selected).png", &butQuitTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Selected quit Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Selected quit Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	buttonQuitRect.top = 0;
	buttonQuitRect.bottom = 0;
	buttonQuitRect.left = 0;
	buttonQuitRect.right = 0;



}

void MainMenu::Update() {
	//you have to alter the sprite whenever buttons are hovered over
}

void MainMenu::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite

	buttonBrush->Begin(D3DXSPRITE_ALPHABLEND);

	buttonBrush->Draw(butUnPlayTexture, &buttonPlayRect, NULL, NULL/*move the brush to a designated position*/, D3DCOLOR_XRGB(255, 255, 255));
	buttonBrush->Draw(butUnSettingsTexture, &buttonSettingsRect, NULL, NULL/*move the brush to a designated position*/, D3DCOLOR_XRGB(255, 255, 255));
	buttonBrush->Draw(butUnCreditsTexture, &buttonCreditsRect, NULL, NULL/*move the brush to a designated position*/, D3DCOLOR_XRGB(255, 255, 255));
	buttonBrush->Draw(butUnQuitTexture, &buttonQuitRect, NULL, NULL/*move the brush to a designated position*/, D3DCOLOR_XRGB(255, 255, 255));
	
	buttonBrush->End();

	//draw Title
	titleBrush->DrawText(NULL, "Space Game!", 25, &titleRect, 0, D3DCOLOR_XRGB(255, 255, 255));

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


}