#include "MainMenu.h"

MainMenu::~MainMenu() {
}

void MainMenu::Initialize() {

	//=====================
	//INITIALIZE GAME TITLE
	//=====================
	
	//initialize brush
	HRESULT hr = D3DXCreateFont(d3dDevice, 50, 20, 200, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &titleBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create Menu Title.";
		MessageBox(NULL, TEXT("Failed to create Menu Title."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	titleRect.top = 0;
	titleRect.bottom = 0;
	titleRect.left = 0;
	titleRect.right = 0;

	//=====================
	//INITIALIZE LINES
	//=====================
	hr = D3DXCreateLine(d3dDevice, &lineBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create LineBrush for Main menu (left).";
		MessageBox(NULL, TEXT("Failed to create Menu Title."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//define the coordinates of line 1----

	l1StartPoint = D3DXVECTOR2(MyWindowWidth / 3, MyWindowHeight / 5);
	l1EndPoint = D3DXVECTOR2(MyWindowWidth / 3, MyWindowHeight / 5 * 4);
	l1LineVertices[0] = l1StartPoint;
	l1LineVertices[1] = l1EndPoint;


	//define the coordinates of line 2----
	l2StartPoint = D3DXVECTOR2(MyWindowWidth / 4 * 3, MyWindowHeight / 5);
	l2EndPoint = D3DXVECTOR2(MyWindowWidth / 4 * 3, MyWindowHeight / 5 * 4);
	l2LineVertices[0] = l2StartPoint;
	l2LineVertices[1] = l2EndPoint;

	//=====================
	//INITIALIZE PLAY BUTTON
	//=====================
	
	//initialize play (unselected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "Asset/Buttons/playButton(Unselected).png", &butUnPlayTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Unselected Play Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Unselected Play Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);	
	}

	//initialize play (selected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "Asset/Buttons/playButton(Selected).png", &butPlayTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Selected Play Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Selected Play Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	buttonPlayRect.top = 0;
	buttonPlayRect.bottom = 0;
	buttonPlayRect.left = 0;
	buttonPlayRect.right = 0;

	//=====================
	//INITIALIZE SETTINGS BUTTON
	//=====================

	//initialize settings (unselected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "Asset/Buttons/settingsButton(Unselected).png", &butUnSettingsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Unselected Settings Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Unselected Settings Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize settings (selected) button
	hr = D3DXCreateTextureFromFile(d3dDevice, "Asset/Buttons/settingsButton(Selected).png", &butSettingsTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Selected Settings Button texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Selected Settings Button texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	buttonSettingsRect.top = 0;
	buttonSettingsRect.bottom = 0;
	buttonSettingsRect.left = 0;
	buttonSettingsRect.right = 0;


}

void MainMenu::Update() {
	//you have to alter the sprite whenever buttons are hovered over
}

void MainMenu::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw Title
	titleBrush->DrawText(NULL, "Space Game Test!", 25, &titleRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	//start line
	lineBrush->Draw(l1LineVertices, 2, D3DCOLOR_XRGB(255, 255, 255));

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void MainMenu::Input() {

}