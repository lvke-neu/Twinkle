#pragma once

#ifdef TWINKLE_PLATFORM_WINDOWS

extern Twinkle::Application* Twinkle::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Twinkle::CreateApplication();
	app->Run();
	delete app;
}

#endif