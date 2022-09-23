#include "Header.h"

boolean Game::CheckCollision(RECT a, RECT b) {
	if (a.bottom < b.top) return false;
	if (a.top > b.bottom) return false;
	if (a.right < b.left) return false;
	if (a.left > b.right) return false;

	return true;
}

void Game::UpdateMouse()
{
	mouse.top = mouseY;
	mouse.left = mouseX;
	mouse.bottom = mouse.top + 24;
	mouse.right = mouse.left + 24;
}

void Game::CleanUp()
{
	font->Release();
	font = NULL;

	texture->Release();
	texture = NULL;
}

Game::Game() {

}

Game::~Game() {

}

void Game::Initialize() {

}

void Game::Render() {

}

void Game::Update() {

}

void Game::Input() {

}
