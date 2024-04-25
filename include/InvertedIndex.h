#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include <mutex>
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
	std::vector<std::thread> threads;
	mutable std::mutex guardFreqDictionary;
public:
	InvertedIndex() = default;

	//fill document base, by which we will search
	void updateDocumentBase(std::vector<std::string>);

	//method determine quantity match by word in loaded documents base
	std::vector<Entry> getWordCount(const std::string &);

	//Fill freqDictionary
	void reindex(const std::string &, size_t);

	std::map<std::string, std::vector<Entry>> getFreqDictionary() const;

	std::vector<std::string> getDocs() const;

	void setDocs(std::vector<std::string> inDocs);
};