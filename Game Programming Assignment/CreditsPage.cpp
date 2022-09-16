#include "CreditsPage.h"

void CreditsPage::Initialize()
{
	//run the script
	HRESULT hr = D3DXCreateFont(d3dDevice, 30, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "News Gothic", &font);

	if (FAILED(hr)) {
		cout << "Failed to load font" << endl;
	}

	colRect.left = 50;
	colRect.top = 0;
	colRect.right = 600;
	colRect.bottom = 1800;
	textSpeed = 0.5;
	//centre = D3DXVECTOR2(spriteWidth / 2, spriteHeight / 2);
	scaling = D3DXVECTOR2(1.0f, 1.0f);
	direction = 0;
	position = D3DXVECTOR2(0, 0);  //who design what mechanics coding, sound effect 
	credits = "\n\n\nCREDITS SCENE (PRESS ENTER TO EXIT)\n\n\nMUSIC & SOUND FROM:\nTHE INTERNET\n\nLEVEL 1 & 2:\nJIM LOW LAP HONG\n\nMAIN MENU:\nLEONG WEN WEI\n\nWIN & LOSE SCREEN:\nLEONG WEN WEI\n\nDESIGN:\nLEONG WEN WEI\nBRIAN WONG YEE XIANG\nJIM LOW LAP HONG\n\nCREDITS SCREEN:\nBRIAN WONG YEE XIANG\n\nAUDIO MANAGER:\nBRIAN WONG YEE XIANG\n\nSPECIAL THANKS TO OUR TUTOR/LECTURE\nMR ANDREW\n\nSPECIAL LICENSE THAT WE DO NOT HAVE:\nSTAR WARS\n\n\nI HAVE NO IDEA WHAT TO PUT NEXT TO MAKE IT LONGER AND AT LEAST THE ENTIRE PAGE SO I'LL JUST WRITE A BUNCH OF WORDS FROM THE TOP OF MY HEAD TO FILL UP THIS END CREDITS PART.\nDON'T MIND THIS PART OF THE ESSAY BECAUSE IT'S JUST RANDOM THINGS I AM WRITING BUT HOW ARE YOU DOING ANYWAYS, I HOPE THIS PART WORKS PROPERLY. \nTHIS CREDITS PART SHOULD BE GOING UP NON-STOP BUT IF IT DOESN'T THEN I MIGHT CRY INSTEAD. \nTHE CREDITS SCREEN ALSO CONTAINS THE SOUND PANNING AND COLLISION DETECTION/ RESULTS AS WELL. \nBUT IT'S MOSTLY JUST FOR THE MEME PART. DID THE MEME PART WORK? DID HARAMBE FLEW BY ALREADY? WAS IT FUNNY AT LEAST? I HOPE IT IS. \nI SPEND MOST OF MY TIME THINKING ABOUT THIS ALTHOUGH IT PROBABLY DOES NOT GIVE ME ANY MARK. AND ALSO THIS CREDITS PART SHOULD BE CONSTANTLY REPEATING ITSELF WHEN SO IT DOES NOT BECOME EMPTY\nFEEL FREE TO IGNORE THIS PART THOUGH BECAUSE IT REPRESENTS NOTHING EXCEPT ACTING AS A BOUNDARY AGAINST THE SPACESHIP...";


	//put player in, use harambe put panning
	//use comet
	//set angle fixed
	//
	//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

	audioManager->PlayCreditsSound();

}

void CreditsPage::Update()
{
	if (clicked) {
		audioManager->StopBackgroundSound();
		//games.pop();
	}
	position.y -= textSpeed;

	if (position.y + 1800 <= 0) {
		position.y = MyWindowHeight;
	}

	clicked = false;
}

void CreditsPage::Render() {
	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, NULL, direction, &position);
	sprite->SetTransform(&mat);
	font->DrawText(sprite, credits, lstrlenA(credits), &colRect, DT_WORDBREAK, D3DCOLOR_XRGB(255, 255, 0));
}

void CreditsPage::Input()
{
	dInputKeyboardDevice->Acquire();
	dInputKeyboardDevice->GetDeviceState(256, diKeys);

	if (diKeys[DIK_RETURN] & 0x80) {
		clicked = true;
	}
	
}

CreditsPage::~CreditsPage()
{
}