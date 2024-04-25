#include "searchEngine.h"

int main(int argc, char **argv)
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	auto inv = InvertedIndex();
	auto conv = ConverterJSON();

	inv.getWordCount("Человек");
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

