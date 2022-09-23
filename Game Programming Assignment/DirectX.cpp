#include "DirectX.h"

DirectX::~DirectX()
{
	sprite->Release();
	sprite = NULL;

	d3dDevice->Release();
	d3dDevice = NULL;
}

void DirectX::Initialize()
{


}

int DirectX::CreateMy3D()
{
	//	Define Direct3D 9. create direct 3d object
	IDirect3D9* direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	//	Define how the screen presents.
	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(d3dPP));

	//	Refer to Direct3D 9 documentation for the meaning of the members.
	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = MyWindowWidth;
	d3dPP.BackBufferHeight = MyWindowHeight;
	d3dPP.hDeviceWindow = g_hWnd;

	//	Create a Direct3D 9 device. virtual graphic card make here
	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

	//	Create sprite. Study the documentation. 
	hr = D3DXCreateSprite(d3dDevice, &sprite);


	//	To Do: Cout out the message to indicate the failure.
	if (FAILED(hr)) {
		cout << "sprite error" << endl;
		return 0;
	}

	return 1;
}
