#include <iostream>
#include "utility/logger.h"

int main(int argc, char* argv[])
{
	std::cout << "Starting FlashFire... \n";

	Log::Init();
	Log::Info("Initialized spdlogger");

	return 0;
}