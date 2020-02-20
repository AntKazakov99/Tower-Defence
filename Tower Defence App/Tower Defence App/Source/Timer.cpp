#include "Timer.h"

void Timer::InvokeEventTick(Object* owner, Uint32 deltaTime)
{
	if (isEnabled)
	{
		if (!isPaused)
		{
			enableTime += deltaTime;
			if (enableTime >= interval)
			{
				if (Tick)
				{
					Tick(owner, this, deltaTime);
				}
				enableTime = 0;
				pauseTime = 0;
			}
		}
		else
		{
			pauseTime += deltaTime;
		}
	}
}

void Timer::SetTick(void Tick(Object*, Timer*, Uint32))
{
	this->Tick = Tick;
}

void Timer::Start()
{
	isEnabled = true;
	isPaused = false;
	pauseTime = 0;
}

void Timer::Pause()
{
	isPaused = true;
}

void Timer::Stop()
{
	enableTime = 0;
	pauseTime = 0;
	isEnabled = false;
	isPaused = false;
}

bool Timer::GetIsEnabled()
{
	return isEnabled;
}

bool Timer::GetIsPaused()
{
	return isPaused;
}

Uint32 Timer::GetEnableTime()
{
	return enableTime;
}

Uint32 Timer::GetPauseTime()
{
	return pauseTime;
}

Uint32 Timer::GetInterval()
{
	return interval;
}

void Timer::SetInterval(Uint32 Interval)
{
	interval = Interval;
}
