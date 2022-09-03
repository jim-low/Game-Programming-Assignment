#pragma once

#ifndef HEADER_H
#define HEADER_H
#include "Header.h"

// include perpustakaan
#define WIN32_LEAN_AND_MEAN
#define BUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)

#include <iostream>
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

#pragma comment (lib, "d3d9.lib") // this code is NOT standard C++ -> cannot use this code on Linux, only works on Windows
#pragma comment (lib, "d3dx9.lib") // this code is NOT standard C++ -> cannot use this code on Linux, only works on Windows
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

// classes
#include "Game.h"
#include "Spaceship.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Weapon.h"
#include "Melee.h"
#include "Range.h"

// externs

#endif
