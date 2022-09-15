#include "CreditsPage.h"


void CreditsPage::Initialize()
{
	//run the script
	HRESULT hr = D3DXCreateFont(d3dDevice, 25, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);

	//hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/player-spaceship.png", &texture);

	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	colRect.left = 0;
	colRect.top = 0;
	colRect.right = 600;
	colRect.bottom = MyWindowHeight;

	//centre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	scaling = D3DXVECTOR2(1.0f, 1.0f);
	direction = 0;
	position = D3DXVECTOR2(0, 0);  
	credits = "CREDITS SCENE (PRESS SPACE TO EXIT)\n\n\nMUSIC FROM\nTHE INTERNET\n\nCODING:\nJIM LOW LAP HONG\nBRIAN WONG YEE XIANG\nLEONG WEN WEI\n\nDESIGN: \nLEONG WEN WEI\n\nSPECIAL THANKS TO\nMR ANDREW\n\n";

	audioManager->PlayCreditsSound();
}

void CreditsPage::Update()
{
	if (clicked) {
		audioManager->StopBackgroundSound();
		audioManager->PlayClickSound();
		std::cout << "Mouse Click One" << std::endl;
		
	}
	clicked = false;
}

void CreditsPage::Render() {
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, NULL, direction, &position);
	sprite->SetTransform(&mat);
	font->DrawText(sprite, credits, lstrlenA(credits), NULL, 0, D3DCOLOR_XRGB(255, 255, 255));


	sprite->End();

	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void CreditsPage::Input()
{
	dInputMouseDevice->Acquire();
	dInputMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);


	if (BUTTONDOWN(mouseState, 0)) {
		clicked = true;
	}

}

CreditsPage::~CreditsPage()
{
	CleanUp();
}