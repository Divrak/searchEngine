#include "searchEngine.h"

int main(int argc, char **argv)
{
	InvertedIndex inv;
	ConverterJSON conv;

	auto texts = conv.getTextDocuments();
	inv.updateDocumentBase(texts);
	inv.reindex();

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

