#include <iostream>

#include <Engine.h>

int main()
{
	md::Engine engine{};
	engine.Init();

	std::cout << "Hello from App\n";

	engine.Run();
	engine.Shutdown();
	return 0;
}
