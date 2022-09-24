#include "CreditsPage.h"

void CreditsPage::Initialize()
{
	HRESULT hr = D3DXCreateFont(d3dDevice, 30, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "News Gothic", &font);

	if (FAILED(hr)) {
		cout << "Failed to load font" << endl;
	}

	colRect.left = 0;
	colRect.top = 0;
	colRect.right = 600;
	colRect.bottom = 1800;
	textSpeed = 3;

	// mouse collision area
	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.bottom + 24;

	direction = 0;
	position = D3DXVECTOR2(MyWindowWidth/2 - colRect.right/2, 0); 
	credits = "\n\n\nCREDITS SCENE (PRESS ESC TO EXIT)\n\n\nMUSIC & SOUND FROM:\nTHE INTERNET\n\nLEVEL 1 & 2:\nJIM LOW LAP HONG\n\nMAIN MENU:\nLEONG WEN WEI\n\nWIN & LOSE SCREEN:\nLEONG WEN WEI\n\nDESIGN:\nLEONG WEN WEI\nBRIAN WONG YEE XIANG\nJIM LOW LAP HONG\n\nCREDITS SCREEN:\nBRIAN WONG YEE XIANG\n\nAUDIO MANAGER:\nBRIAN WONG YEE XIANG\n\nSPECIAL THANKS TO OUR TUTOR/LECTURE\nMR ANDREW\n\nSPECIAL LICENSE THAT WE DO NOT HAVE:\nSTAR WARS\n\n\nIN THE MAIN MENU, WE HAVE HOVERING AND CLICKING SOUNDS AND SETTING VOLUMES.\n\nIN THE LEVEL 1, WE HAVE THE NEWTONIAN LAWS AND COLLISION DETECTION AND RESULTS AND PANNING.\n\nIN THIS LEVEL, WE HAVE A FOUR TYPES OF PANNING THAT IS SET DEPENDING ON THE MOUSE POSITION.\n\nI HAVE NO IDEA WHAT TO PUT NEXT TO MAKE IT LONGER AND AT LEAST THE ENTIRE PAGE SO I'LL JUST WRITE A BUNCH OF WORDS FROM THE TOP OF MY HEAD TO FILL UP THIS END CREDITS PART.\nDON'T MIND THIS PART OF THE ESSAY BECAUSE IT'S JUST RANDOM THINGS I AM WRITING BUT HOW ARE YOU DOING ANYWAYS, I HOPE THIS PART WORKS PROPERLY.\nI TESTED IT, AND IT WORKSS. I THINK. \nTHIS CREDITS PART SHOULD BE GOING UP NON-STOP.\n\nTHIS CREDITS PART SHOULD BE CONSTANTLY REPEATING ITSELF WHEN SO IT DOES NOT BECOME EMPTY\n";

	audioManager->PlayCreditsSound();
}

void CreditsPage::Update()
{
	// update mouse collision area
	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.left + 24;

	//sets the panning value depending on the mouse position by cutting the screen into four parts
	if (mouse.left > MyWindowWidth / 2 && mouse.left < MyWindowWidth/2 + MyWindowWidth/4) { 
		audioManager->SetGroupPanning(0.5);
	}
	if (mouse.left > MyWindowWidth / 2 + MyWindowWidth / 4) {
		audioManager->SetGroupPanning(1);
	}
	if (mouse.left < MyWindowWidth / 2 && mouse.left > MyWindowWidth / 4) {
		audioManager->SetGroupPanning(-0.5);
	}
	if (mouse.left < MyWindowWidth / 4) {
		audioManager->SetGroupPanning(-1);
	}

	if (DirectInput::IsKeyDown(DIK_ESCAPE)) {	//when player exits, stop current bg sound and play main menu music
		audioManager->StopBackgroundSound();
		audioManager->PlayMainMenuSoundTrack();
		games.pop();
	}
	position.y -= textSpeed;

	if (position.y + 1800 <= 0) {//makes the credits replay again on screen after passing through
		position.y = MyWindowHeight;
	}
}

void CreditsPage::Render() {
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, direction, &position);
	sprite->SetTransform(&mat);
	font->DrawText(sprite, credits, lstrlenA(credits), &colRect, DT_WORDBREAK | DT_CENTER, D3DCOLOR_XRGB(255, 255, 0));

	sprite->End();

	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

CreditsPage::~CreditsPage()
{
}