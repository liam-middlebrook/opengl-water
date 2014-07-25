#ifndef GAMETIME_H_
#define GAMETIME_H_
#include <thread>
#include <chrono>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class GameTime{
public:
	/** @return the number of milliseconds since the start of the Game
	*/
	long GetElapsedMillis();

	/** @return the number of seconds since the start of the Game
	*/
	double GetElapsedSeconds();

	/** @return the number of seconds since the start of the Game as a float
	*/
	float GetElapsedSecondsF();

	/** @return the number of milliseconds since the last update()
	*/
	long GetDeltaTimeMillis();

	/** @return the number of seconds since the last update()
	*/
	double GetDeltaTimeSeconds();

	/** @return the number of seconds since the last update() as a float
	*/
	float GetDeltaTimeSecondsF();

	/** Limits the updates per second of the current thread by delaying
	* @param desiredFPS the FPS to limit to
	*/
	inline void LimitFPS(unsigned int desiredFPS)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long>(1000/desiredFPS-(GetDeltaTimeSeconds()))));
	}
	void Update();
	GameTime();

private:
	/** Constructs a GameTime
	*/

	/** Updates the gametime
	*/

	/** The total time in seconds that has passed
	*/
	double totalTime;

	/** The time in seconds that has passed between the 2 previous Updates
	*/
	double deltaTime;

	/** The value of totalTime as of the previous Update
	*/
	double lastUpdate;
};
#endif