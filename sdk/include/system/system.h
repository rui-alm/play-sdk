#pragma once

namespace ksdk {

	class system_display
	{
	public:
		system_display() = default;
		virtual ~system_display() = default;
		// virtual int getWidth();
		// virtual int getHeight();
		
		// virtual void setRefreshRate(float rate);

		// virtual void setInverted(int flag);
		// virtual void setScale(unsigned int s);
		// virtual void setMosaic(unsigned int x, unsigned int y);
		// virtual void setFlipped(int x, int y);
		// virtual void setOffset(int x, int y);
	};

	class system
	{
	public:
		system() = default;
		virtual ~system() = default;
		virtual system_display* display() = 0;
		virtual void drawFPS(int x, int y) = 0;
	};

	typedef enum system_event
	{
		init,
		// initlua,
		lock,
		unlock,
		pause,
		resume,
		terminate,
		key_pressed, // arg is keycode
		key_released,
		low_power
	} system_event;
};