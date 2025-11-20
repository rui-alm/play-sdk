#pragma once

#include <vector>

#include "model/keys.h"
#include "system/display.h"
#include "system/graphics.h"
#include "system/file_system.h"

namespace ksdk {
	class system
	{
	public:
		system() = default;
		virtual ~system() = default;
		virtual system_display& display() = 0;
		virtual system_graphics& graphics() = 0;
        virtual class file_system& file_system() = 0;
		virtual void draw_fps(int x, int y) = 0;
		virtual void button_state(keys& down
								, keys& pressed
								, keys& released) = 0;
        virtual unsigned int get_current_time_milliseconds() const = 0;
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
