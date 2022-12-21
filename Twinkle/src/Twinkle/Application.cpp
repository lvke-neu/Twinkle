#include "TwinklePch.h"
#include "Application.h"
#include "Twinkle/Events/ApplicationEvent.h"
#include "Twinkle/Log.h"

namespace Twinkle
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LOG_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			LOG_CORE_TRACE(e);
		}

		while (true);
	}
}