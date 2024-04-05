#include "searchEngine.h"

int main(int argc, char **argv)
{
	ConverterJSON conv = ConverterJSON();

	auto req = conv.getRequests();

	try {
		conv.getResponsesLimit();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

