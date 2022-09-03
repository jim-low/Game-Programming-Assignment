#include "Header.h"

void FrameTimer::Init(int fps)
{

	QueryPerformanceFrequency(&timerFreq);
	QueryPerformanceCounter(&timeNow);
	QueryPerformanceCounter(&timePrevious);
	//init fps time info
	requestedFPS = fps;

	intervalsPerFrame = ((float)timerFreq.QuadPart / requestedFPS);

}

int FrameTimer::FramesToUpdate()
{
	int framesToUpdate = 0;
	QueryPerformanceCounter(&timeNow);
	//getting the delta time
	intervalsSinceLastUpdate = (float)timeNow.QuadPart - (float)timePrevious.QuadPart;
	framesToUpdate = (int)(intervalsSinceLastUpdate / intervalsPerFrame);
	//If we are not updating any frames, 
	//keep the old previous timer count

	if (framesToUpdate != 0) {
		QueryPerformanceCounter(&timePrevious);
	}

	return framesToUpdate;

}

int FrameTimer::GetFPS()
{
	return requestedFPS;
}
