#include <iostream>
#include <vector>
#include <map>
#include "ConverterJSON.h"

struct Entry
{
	size_t docID {};
	size_t count {};

	bool operator == (const Entry &inOther) const
	{ return (docID == inOther.docID && count == inOther.count); }
};

class InvertedIndex
{
	std::vector<std::string> docs{}; //There save text documents
	std::map<std::string, std::vector<Entry>> freqDictionary{}; //Store the frequency of match of words
public:
	InvertedIndex() = default;

	//fill document base, by which we will search
	void updateDocumentBase(std::vector<std::string>);

	//method determine quantity match by word in loaded documents base
	std::vector<Entry> getWordCount(const std::string &) const;

	//Fill freqDictionary
	void reindex();
};