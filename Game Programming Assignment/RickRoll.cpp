#include "RickRoll.h"

void RickRoll::Initialize()
{
	HRESULT hr = D3DXCreateSprite(d3dDevice, &sprite);
	if (FAILED(hr)) {
		std::cout << "Failed to create the Sprite Brush.";
		MessageBox(NULL, TEXT("Failed to create the Sprite Brush."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	//initialize rickTexture
	hr = D3DXCreateTextureFromFile(d3dDevice, "../Assets/rick-astley.png", &texture);
	if (FAILED(hr)) {
		std::cout << "Failed to rick roll the player.";
		MessageBox(NULL, TEXT("Failed to create Rick texture in Menu."), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}

	textureWidth = 2100;
	textureHeight = 3984;
	spriteCol = 5;
	spriteRow = 8;
	maxFrame = 40;
	spriteWidth = textureWidth / spriteCol;
	spriteHeight = textureHeight / spriteRow;
	currentRow = 1;
	rowFrame = 1;
	scaling = D3DXVECTOR2(1, 1); //make it smaller 
	centre = D3DXVECTOR2((spriteWidth * scaling.x) / 2, (spriteHeight * scaling.y) / 2);
	position = D3DXVECTOR2((MyWindowWidth / 2) - (spriteWidth / (scaling.x * 2)), ((MyWindowHeight / 2) - (spriteHeight / (scaling.y * 3))));

	currentFrame = 1;
	animRect.top = 0;
	animRect.bottom = spriteHeight;
	animRect.left = 0;
	animRect.right = spriteWidth;
}

void RickRoll::Update()
{
	//change frame

	//have all frames looped?
	if (currentFrame >= maxFrame) {
		//reset frame, totalframe and currentRow
		currentFrame = 1;
		currentRow = 1;
		rowFrame = 1;
	}


	//has the frame reached the end of the row?
	if ((currentFrame % spriteCol) == 0) {
		//yes
		currentRow++; //move on to next row.
		rowFrame = 1; //revert back to the first frame of the row.
	}

	//no
	animRect.top = spriteHeight * (currentRow - 1);
	animRect.bottom = animRect.top + spriteHeight;
	animRect.left = spriteWidth * (rowFrame - 1);
	animRect.right = animRect.left + spriteWidth;

	currentFrame++;
	rowFrame++;
}

void RickRoll::Render()
{
	D3DXMATRIX mat;
	D3DXMatrixTransformation2D(&mat, &centre, 0.0, &scaling, &centre, direction, &position);
	sprite->SetTransform(&mat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}
