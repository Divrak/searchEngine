#include <ConverterJSON.h>

std::vector<std::string> ConverterJSON::getTextDocuments()
{
	std::vector<std::string> filesData;
	//1) Open files
	std::filesystem::path filePath("resources\\001.txt");
	if (std::filesystem::exists(filePath))
	{//if file exists, 
		std::ifstream fileStream;
		for (auto &p : std::filesystem::directory_iterator(filePath.parent_path()))
		{//iterate all files in directory resources

			//read all file in std::string
			fileStream.open(p, std::ios_base::in);
			std::string buffer {std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>()};
			fileStream.close();

			//2) put content in vector
			filesData.push_back(buffer);
		}
	}
	else
	{
		std::cout << "file not exists" << std::endl;
	}
	
	//3) return 
	return filesData;
}

int ConverterJSON::getResponsesLimit()
{
	return 0;
}

std::vector<std::string> ConverterJSON::getRequests()
{
	return std::vector<std::string>();
}

void ConverterJSON::putAnswer(std::vector<std::vector<std::pair<int, float>>> answer)
{
}
