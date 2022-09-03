#pragma once
#ifndef FRAMETIMER_H
#define FRAMETIMER_H

#include "Header.h"

class FrameTimer {
public:
	void Init(int);
	int FramesToUpdate();
	int GetFPS();

private:
	LARGE_INTEGER timerFreq;
	LARGE_INTEGER timeNow;
	LARGE_INTEGER timePrevious;
	int requestedFPS;
	float intervalsPerFrame;
	float intervalsSinceLastUpdate;
};

#endif
