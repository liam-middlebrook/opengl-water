#include "GameTime.h"
GameTime::GameTime()
{
	totalTime = 0;
	deltaTime = 0;
	lastUpdate = 0;
}

void GameTime::Update()
{
	totalTime = glfwGetTime();
	deltaTime = totalTime - lastUpdate;
	lastUpdate = totalTime;
	deltaTime = deltaTime > 0 ? deltaTime : std::numeric_limits<double>::epsilon();
}
long GameTime::GetElapsedMillis()
{
	return static_cast<long>(totalTime * 1000.0);
}

double GameTime::GetElapsedSeconds()
{
	return totalTime;
}

float GameTime::GetElapsedSecondsF()
{
	return static_cast<float>(GetElapsedSeconds()) > std::numeric_limits<float>::epsilon() ? static_cast<float>(GetElapsedSeconds()) : std::numeric_limits<float>::epsilon();;
}

double GameTime::GetDeltaTimeSeconds()
{
	return deltaTime;
}

float GameTime::GetDeltaTimeSecondsF()
{
	return static_cast<float>(GetDeltaTimeSeconds()) > std::numeric_limits<float>::epsilon() ? static_cast<float>(GetDeltaTimeSeconds()) : std::numeric_limits<float>::epsilon();
}

long GameTime::GetDeltaTimeMillis()
{
	return static_cast<long>(deltaTime * 1000.0);
}