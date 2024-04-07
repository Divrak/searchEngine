#include "InvertedIndex.h"

//update or fill document base, by which we will search
void InvertedIndex::updateDocumentBase(std::vector<std::string> inInputDocs)
{
	docs = inInputDocs;
}

//method determine quantity match by word in loaded documents base
std::vector<Entry> InvertedIndex::getWordCount(const std::string &inWord)
{
	if(!freqDictionary.size())
		reindex();
	if (freqDictionary.contains(inWord))
		return freqDictionary.find(inWord)->second;
	else
		return std::vector<Entry>();
}

//Fill freqDictionary
void InvertedIndex::reindex()
{
	//Split text by words
	char *token {nullptr};
	const char *delimiters = " ,.-?!()#[]<>{};*=\n\t+/: –—”…«»";
	char *currentWord {nullptr};

	for (size_t i {}; i < docs.size(); ++i)
	{
		//Get current word by current file
		currentWord = strtok_s(const_cast<char *>(docs[i].c_str()), delimiters, &token);

		//Traversing words from a file
		while (currentWord != nullptr)
		{
			auto currentElement = freqDictionary.find(currentWord);
			if (freqDictionary.contains(currentWord))
			{//If word already exists into freqDictionary
				//If word into current document not exists, create entry; else increment current entry counter
				if (currentElement->second.rbegin()->docID == i)
					++currentElement->second.rbegin()->count;
				else
					currentElement->second.push_back({i, 1});
			}
			else
				freqDictionary.insert(std::make_pair(currentWord, std::vector<Entry>{{i, 1}}));

			currentWord = strtok_s(nullptr, delimiters, &token);
		}
	}
}

