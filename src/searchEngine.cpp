#include "searchEngine.h"

int main(int argc, char **argv)
{
	ConverterJSON conv = ConverterJSON();

	auto req = conv.getRequests();

	for (auto &el : req)
		std::cout << el << std::endl;

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

