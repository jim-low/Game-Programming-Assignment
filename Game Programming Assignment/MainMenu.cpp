#include "Level2.h"
#include "MainMenu.h"

MainMenu::~MainMenu() {
}

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

	menuButtonWidth = 351;
	menuButtonHeight = 163;
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

	//A AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA - Jim 16 September 2022
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

	//initialize position 
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

	//initialize position
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

	//initialize position 
	buttonQuitRect.top = 0;
	buttonQuitRect.bottom = buttonQuitRect.top + menuButtonHeight;
	buttonQuitRect.left = 0;
	buttonQuitRect.right = buttonQuitRect.left + menuButtonWidth;

	playPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 5);
	playCol.left = playPosition.x;
	playCol.top = playPosition.y;
	playCol.right = playCol.left + menuButtonWidth;
	playCol.bottom = playCol.top + menuButtonHeight;

	settingsPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 8); 
	settingsCol.left = settingsPosition.x;
	settingsCol.top = settingsPosition.y;
	settingsCol.right = settingsCol.left + menuButtonWidth;
	settingsCol.bottom = settingsCol.top + menuButtonHeight;

	creditsPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 11);
	creditsCol.left = creditsPosition.x;
	creditsCol.top = creditsPosition.y;
	creditsCol.right = creditsCol.left + menuButtonWidth;
	creditsCol.bottom = creditsCol.top + menuButtonHeight;

	quitPosition = D3DXVECTOR2((MyWindowWidth / 2) - (menuButtonWidth / 2), MyWindowHeight / 20 * 14);
	quitCol.left = quitPosition.x;
	quitCol.top = quitPosition.y;
	quitCol.right = quitCol.left + menuButtonWidth;
	quitCol.bottom = quitCol.top + menuButtonHeight;

	//audioManager->PlayMainMenuSoundTrack();
}

void MainMenu::Update() {
	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.left + 24;

	if (Game::CheckCollision(mouse, playCol)) {
		cout << "mouse has hovered over play" << endl;
	}

	if (Game::CheckCollision(mouse, settingsCol)) {
		cout << "mouse has hovered over settings" << endl;
	}

	if (Game::CheckCollision(mouse, creditsCol)) {
		cout << "mouse has hovered over credits" << endl;
	}

	if (Game::CheckCollision(mouse, quitCol)) {
		cout << "mouse has hovered over quit" << endl;
	}

	//you have to alter the sprite whenever buttons are hovered over

	//focus feature (using arrow keys to navigate through the menu, pressing enter will select the option)

	if (enterPressed) { //its not updating, idk why
		if (currentSelection == PLAY) {
			//IDK WHAT TO DO HERE FAK
		}
		else if (currentSelection == SETTINGS){

		}
		else if (currentSelection == CREDITS) {
		
		}
		else if (currentSelection == QUIT) {
		
		}
		enterPressed = false;
	}

	//...

	if (currentSelection == PLAY) {
		//highlight play
		buttonPlayRect.left += menuButtonWidth;
		buttonPlayRect.right += menuButtonWidth * 2;
		//unhighlight the previous button
		buttonSettingsRect.left = 0;
		buttonSettingsRect.right = menuButtonWidth;
	}

	else if (currentSelection == SETTINGS) {
		//highlight settings
		buttonSettingsRect.left += menuButtonWidth;
		buttonSettingsRect.right += menuButtonWidth * 2;
		//unhighlight the previous buttons
		buttonPlayRect.left = 0;
		buttonPlayRect.right = menuButtonWidth;
		buttonCreditsRect.left = 0;
		buttonCreditsRect.right = menuButtonWidth;
	}

	else if (currentSelection == CREDITS) {
		//highlight settings
		buttonCreditsRect.left += menuButtonWidth;
		buttonCreditsRect.right += menuButtonWidth * 2;
		//unhighlight the previous buttons
		buttonSettingsRect.left = 0;
		buttonSettingsRect.right = menuButtonWidth;
		buttonQuitRect.left = 0;
		buttonQuitRect.right = menuButtonWidth;
	}

	else if (currentSelection == QUIT) {
		//highlight play
		buttonPlayRect.left += menuButtonWidth;
		buttonPlayRect.right += menuButtonWidth * 2;
		//unhighlight the previous button
		buttonSettingsRect.left = 0;
		buttonSettingsRect.right = menuButtonWidth;
	}

	if (upPressed || arrowUpPressed) { 
		if (currentSelection != PLAY) currentSelection - 1;
		else currentSelection = PLAY;


		//highlight play
		buttonPlayRect.left = menuButtonWidth;
		buttonPlayRect.right = menuButtonWidth * 2;

		//unhighlight the previous button
		buttonSettingsRect.left = 0;
		buttonSettingsRect.right = menuButtonWidth;
		buttonCreditsRect.left = 0;
		buttonCreditsRect.right = menuButtonWidth;
		buttonQuitRect.left = 0;
		buttonQuitRect.right = menuButtonWidth;


		upPressed = false;
		arrowUpPressed = false;
		std::cout << "upPressed" << std::endl;
	}

	if (downPressed || arrowDownPressed) { 
		if (currentSelection != QUIT) currentSelection + 1;
		else currentSelection = QUIT;
		downPressed = false;
		arrowDownPressed = false;
		std::cout << "downPressed" << std::endl;
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
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	// movement WASD
	if (diKeys[DIK_W] & 0x80) {
		upPressed = true;
	}

	if (diKeys[DIK_S] & 0x80) {
		downPressed = true;
	}

	// movement ARROWKEYS
	if (diKeys[DIK_UP] & 0x80) {
		arrowUpPressed = true;
	}

	if (diKeys[DIK_DOWN] & 0x80) {
		arrowDownPressed = true;
	}

	//Enter key
	if (diKeys[DIK_RETURN] & 0x80) {
		enterPressed = true;
	}
}