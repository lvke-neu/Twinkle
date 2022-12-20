#include <Twinkle.h>

class SandBox : public Twinkle::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};


Twinkle::Application* Twinkle::CreateApplication()
{
	return new SandBox();
}