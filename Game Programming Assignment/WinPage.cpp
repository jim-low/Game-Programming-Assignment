#include "WinPage.h"

WinPage::~WinPage() {
}

void WinPage::Initialize() {

	HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/win_Title.png", &winTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Title texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Title texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	winWidth = 375;
	winHeight = 245;
	winRect.top = 0;
	winRect.bottom = winHeight;
	winRect.left = 0;
	winRect.right = winWidth;

	position = D3DXVECTOR2((MyWindowWidth/2) - (winWidth/2), (MyWindowHeight / 2) - (winHeight / 2)); 
	centre = D3DXVECTOR2(winWidth / 2, winHeight / 2);
	scaling = D3DXVECTOR2(1.8f, 1.8f);
}

void WinPage::Render() {
	//clear screen
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//start screen 
	d3dDevice->BeginScene();

	//draw sprite
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//set matrix to title

	D3DXMatrixTransformation2D(&winMat, &centre, 0.0, &scaling, NULL, NULL, &position);
	sprite->SetTransform(&winMat);
	sprite->Draw(winTexture, &winRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void WinPage::Update() {

}

void WinPage::Input() {

}