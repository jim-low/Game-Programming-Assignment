#include "Button.h"


void Button::Update() {
	//idk wtf to do here
	if (Game::CheckCollision(mouse, colRect)) {
		//when hovered, light up the button and set to a selection based on the hovered button
		animRect.left = buttonWidth;
		animRect.right = buttonWidth * 2;
	}

	else {
		//else, dim button
		animRect.left = 0;
		animRect.right = buttonWidth;
	}	
}

void Button::Render() {
	//render thy butt on
	D3DXMatrixTransformation2D(&buttonMat, NULL, 0.0, &scaling, &centre, NULL, &position);
	sprite->SetTransform(&buttonMat);
	sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

}
