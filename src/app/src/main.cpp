#include <iostream>

#include <Engine/Engine.h>

int main()
{
	md_engine::Engine engine{};
	engine.Init();

	std::cout << "Hello from App\n";

	engine.Run();
	engine.Shutdown();
	return 0;
}
