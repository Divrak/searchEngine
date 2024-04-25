#include "InvertedIndex.h"

//update document base, by which we will search
void InvertedIndex::updateDocumentBase(std::vector<std::string> inInputDocs)
{
	docs = inInputDocs;

	//update dictionary
	std::vector<std::thread> threads;
	freqDictionary.clear();
	for (int i {}; i < docs.size(); ++i)
		threads.push_back(std::thread(&InvertedIndex::reindex, this, std::ref(docs[i]), i));

	for (auto &thread : threads)
		thread.join();
}

//method determine quantity match by word in loaded documents base
std::vector<Entry> InvertedIndex::getWordCount(const std::string &inWord)
{
	//if freqDictionary contains inWord, return match quantity inWord
	if (freqDictionary.contains(inWord))
		return freqDictionary.find(inWord)->second;
	else
		return std::vector<Entry>();
}

//Fill freqDictionary
void InvertedIndex::reindex(const std::string &inDoc, size_t inDocID)
{
	//Split text by words
	char *token = {nullptr};
	const char *delimiters = " ,.-?!()#[]<>{};*=\n\t+/: –—”…«»";
	char *currentWord = {nullptr};

	//Get current word by current file
	currentWord = strtok_s(const_cast<char *>(inDoc.c_str()), delimiters, &token);

	//Traversing words from a file
	while (currentWord != nullptr)
	{
		if (freqDictionary.contains(currentWord))
		{//If word already exists into freqDictionary

			auto currentElement = freqDictionary.find(currentWord);
			//If word into current document not exists, create entry; else increment current entry counter
			if (currentElement->second.rbegin()->docID == inDocID)
				++currentElement->second.rbegin()->count;
			else
				currentElement->second.push_back({inDocID, 1});
		}
		else
		{
			freqDictionary.insert(std::make_pair(currentWord, std::vector<Entry>{{inDocID, 1}}));
		}

		currentWord = strtok_s(nullptr, delimiters, &token);
	}
}

std::map<std::string, std::vector<Entry>> InvertedIndex::getFreqDictionary() const
{ return freqDictionary; }

std::vector<std::string> InvertedIndex::getDocs() const
{ return docs; }

void InvertedIndex::setDocs(std::vector<std::string> inDocs)
{ docs = inDocs; }

