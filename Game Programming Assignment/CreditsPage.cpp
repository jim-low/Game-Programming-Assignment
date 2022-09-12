#include "CreditsPage.h"


void CreditsPage::Initialize()
{
	//run the script
	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/player-spaceship.png", &texture);
	
	if (FAILED(hr)) {
		cout << "Failed to load texture" << endl;
	}

	audioManager->PlayMainMenuSoundTrack();
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

	D3DXMATRIX mat;
	//D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &centre, direction, &position);
	//sprite->SetTransform(&mat);
	//sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));


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