#include "searchEngine.h"

int main(int argc, char **argv)
{

	int z = 0;
	while(z < 20)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
		std::cout << "LOOP" << std::endl;
		++z;
	}
}

