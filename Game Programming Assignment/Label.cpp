#include "Label.h"
#include <string> 

void Label::Render() {

	if (labelType == TEXT) {
	//text label
		D3DXMatrixTransformation2D(&labelMat, NULL, 0.0, NULL, NULL, NULL, &position);
		sprite->SetTransform(&labelMat);
		font->DrawText(sprite, labelString.c_str(), labelString.length(), &animRect, 0, D3DCOLOR_XRGB(255, 255, 255));
	}

	else if (labelType == IMAGE) {
	//image label
		D3DXMatrixTransformation2D(&labelMat, &centre, 0.0, &scaling, &centre, NULL, &position);
		sprite->SetTransform(&labelMat);
		sprite->Draw(texture, &animRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}

	else {
		MessageBox(NULL, TEXT("There was a error in creating a label"), TEXT("ERROR!"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}
}

void Label::RenderWithUpdatingValue(int a) {

	if (labelType == TEXT) {
		//text label
		D3DXMatrixTransformation2D(&labelMat, NULL, 0.0, NULL, NULL, NULL, &position);
		sprite->SetTransform(&labelMat);
		font->DrawText(sprite, to_string(a).c_str(), labelString.length(), &animRect, 0, D3DCOLOR_XRGB(255, 255, 255));
	}
}


