#include <iostream>
#include <vector>
#include <map>

struct Entry
{
	size_t docID, count;
};

class InvertedIndex
{
	std::vector<std::string> docID {};
	std::map<std::string, std::vector<Entry>> freqDictionary{};
public:
};