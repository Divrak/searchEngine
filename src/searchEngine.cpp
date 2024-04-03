#include "searchEngine.h"

int main(int argc, char **argv)
{
	auto convJSON = ConverterJSON();


	auto dataFiles = convJSON.getTextDocuments();

	for (auto &el : dataFiles)
		std::cout << el << std::endl;

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

