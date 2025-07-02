#include <iostream>
#include "utility/logger.h"
#include "core/game.h"

int main(int argc, char* argv[])
{
	std::cout << "Starting FlashFire... \n";

	Log::Init();
	Log::Info("Initialized spdlogger");
	FF::game game;

	return game.Run();
}