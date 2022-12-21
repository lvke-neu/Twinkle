#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Twinkle
{
	class TWINKLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


