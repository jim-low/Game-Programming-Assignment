#include "GameOverPage.h"

void GameOverPage::Initialize() {
	//=====================
	//INITIALIZE LOSE TITLE
	//=====================

	//initialize brush
	HRESULT hr = D3DXCreateFont(d3dDevice, 100, 35, 200, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Bauhaus 93"), &fontBrush);
	if (FAILED(hr)) {
		cout << "Failed to create Lose Title." << endl;
		MessageBox(NULL, TEXT("Failed to create Lose Title."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize position 
	loseTitleRect.top = (MyWindowHeight * 0.2); //change later
	loseTitleRect.left = (MyWindowWidth / 2) - (35);
	loseTitleRect.bottom = loseTitleRect.top + 100;
	loseTitleRect.right = loseTitleRect.left + 340;

	//=====================
	//INITIALIZE LINES
	//=====================
	hr = D3DXCreateLine(d3dDevice, &lineBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create LineBrush for LoseScreen.";
		MessageBox(NULL, TEXT("Failed to create LineBrush for LoseScreen."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//define the coordinates of box 1---- //Coords not set
	boxNTitleGap = 10;
	lBpos1 = D3DXVECTOR2(loseTitleRect.left - boxNTitleGap * 2, loseTitleRect.top - boxNTitleGap);
	lBpos2 = D3DXVECTOR2(loseTitleRect.left - boxNTitleGap * 2, loseTitleRect.bottom + boxNTitleGap);
	lBpos3 = D3DXVECTOR2(loseTitleRect.right + boxNTitleGap * 2, loseTitleRect.bottom + boxNTitleGap);
	lBpos4 = D3DXVECTOR2(loseTitleRect.right + boxNTitleGap * 2, loseTitleRect.top - boxNTitleGap);
	lBVertices[0] = lBpos1;
	lBVertices[1] = lBpos2;
	lBVertices[2] = lBpos3;
	lBVertices[3] = lBpos4;
	lBVertices[4] = lBpos1; //join back the line to the first position

	//=====================
	//INITIALIZE RICK ASTLEY
	//=====================

	//initialize Brush
	hr = D3DXCreateSprite(d3dDevice, &spriteBrush);
	if (FAILED(hr)) {
		std::cout << "Failed to create the Sprite Brush.";
		MessageBox(NULL, TEXT("Failed to create the Sprite Brush."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//texture initialization
	spriteWidth = 2100;
	spriteHeight = 3984;
	spriteCol = 5;
	spriteRow = 8;
	maxFrame = 40;
	textureWidth = spriteWidth / spriteCol;
	textureHeight = spriteHeight / spriteRow;
	currentRow = 1;
	rowFrame = 1;
	scaling = D3DXVECTOR2(0.5f, 0.5f); //make it smaller 
	centre = D3DXVECTOR2(textureWidth / 2, textureHeight / 2);

	//initialize rickTexture
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/rick-astley.png", &rickTexture);
	if (FAILED(hr)) {
		std::cout << "Failed to create Rick texture in Menu.";
		MessageBox(NULL, TEXT("Failed to create Rick texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize current frame
	currentFrame = 1;
	rickRect.top = 0;
	rickRect.bottom = textureHeight;
	rickRect.left = 0;
	rickRect.right = textureWidth;
}

void GameOverPage::Update() {
	//change frame

	//have all frames looped?
	if (currentFrame >= maxFrame) {
		//reset frame, totalframe and currentRow
		currentFrame = 1;
		currentRow = 1;
		rowFrame = 1;
	}


	//has the frame reached the end of the row?
	if ((float)(currentFrame % spriteCol) == (float)0) {
		//yes
		currentRow++; //move on to next row.
		rowFrame = 1; //revert back to the first frame of the row.
	}

	//no
	rickRect.top = textureHeight * (currentRow - 1);
	rickRect.bottom = rickRect.top + textureHeight;
	rickRect.left = textureWidth * (rowFrame - 1);
	rickRect.right = rickRect.left + textureWidth;

	currentFrame++;
	rowFrame++;
}

void GameOverPage::Render() {

	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3dDevice->BeginScene();

	//draw sprite
	spriteBrush->Begin(D3DXSPRITE_ALPHABLEND);

	//set matrix to play button
	position = D3DXVECTOR2((MyWindowWidth / 2) - (textureWidth / 2), MyWindowHeight/6);
	D3DXMatrixTransformation2D(&loseMat, &centre, 0.0, &scaling, NULL, NULL, &position);
	spriteBrush->SetTransform(&loseMat);
	spriteBrush->Draw(rickTexture, &rickRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	spriteBrush->End();

	//draw Lose Title
	fontBrush->DrawText(NULL, "You Lose!", -1, &loseTitleRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	//draw box around Lose Title
	lineBrush->Draw(lBVertices, 5, D3DCOLOR_XRGB(56, 175, 235));

	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GameOverPage::Input() {
}

GameOverPage::~GameOverPage() {
}