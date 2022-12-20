#pragma once

#ifdef TWINKLE_PLATFORM_WINDOWS

extern Twinkle::Application* Twinkle::CreateApplication();

int main(int argc, char** argv)
{
	Twinkle::Log::Init();

	//Twinkle::Log::GetClientLogger()->trace("Client Log");
	//Twinkle::Log::GetCoreLogger()->info("Core Log");
	
	LOG_CORE_DEBUG("abc{0} {0}", 1);
	LOG_CORE_TRACE("abc");
	LOG_CORE_INFO("abc");
	LOG_CORE_WARN("abc");
	LOG_CORE_ERROR("abc");
	LOG_CORE_CRITICAL("abc");


	LOG_APP_DEBUG("abc");
	LOG_APP_TRACE("abc");
	LOG_APP_INFO("abc");
	LOG_APP_WARN("abc");
	LOG_APP_ERROR("abc");
	LOG_APP_CRITICAL("abc");

	auto app = Twinkle::CreateApplication();
	app->Run();
	delete app;
}

#endif