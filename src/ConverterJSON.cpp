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
		{//iterate all files in the resources directory 
			//put all file contents of the file into std::string
			fileStream.open(p, std::ios_base::in);
			std::string buffer {std::istreambuf_iterator<char>(fileStream), std::istreambuf_iterator<char>()};
			fileStream.close();

			//2) put content into vector
			filesData.push_back(buffer);
		}
	}
	else
		throw std::runtime_error("files in directory ./resources/ not exists");
	
	//3) return 
	return filesData;
}

int ConverterJSON::getResponsesLimit()
{
	//1) open file confing.json
	nlohmann::json jsonConfig;
	std::filesystem::path configPath("config.json");
	std::ifstream configStream;

	if (std::filesystem::exists(configPath))
	{//if file exists
		//2) read file config into jsonConfig variable
		configStream.open(configPath);
		jsonConfig << configStream;
		configStream.close();
	}
	else 
		throw std::runtime_error("file config.json not exists");

	//3) return maxResponse
	return jsonConfig["config"]["maxResponses"];
}

//Get requests list from requests.json
std::vector<std::string> ConverterJSON::getRequests()
{
	nlohmann::json jsonRequests;
	std::vector<std::string> requests;

	//1) Open file
	std::filesystem::path requestsPath("requests.json");
	std::ifstream requestsStream;

	if (std::filesystem::exists(requestsPath))
	{//if file exists
		//put all file content in json
		requestsStream.open(requestsPath, std::ios_base::in);
		requestsStream >> jsonRequests;
		requestsStream.close();

		//2) add requests to vector
		for (auto &[k, v] : jsonRequests.begin()->items())
			requests.push_back(v);
	}
	else
		throw std::runtime_error("file requests.json not exists");
	//3) return
	return requests;
}

void ConverterJSON::putAnswer(std::vector<std::vector<std::pair<int, float>>> answer)
{
}
