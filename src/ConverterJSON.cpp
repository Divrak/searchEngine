#include <ConverterJSON.h>

std::vector<std::string> ConverterJSON::getTextDocuments() const
{
	//variables
	auto jsonConfig = getConfig();
	std::vector<std::string> filesData;
	std::vector<std::filesystem::path> resourceDir();

	//Open directories and read files
	for (auto &[k, v] : jsonConfig["directoryFiles"].begin()->items())
	{
		if (std::filesystem::exists(v))
		{//if directory exists, 
			std::ifstream fileStream;
			for (auto &p : std::filesystem::directory_iterator(v))
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
			std::cout << "files in directory " << v << " not exists";
	}
	return filesData;
}

int ConverterJSON::getResponsesLimit() const
{
	auto jsonConfig = getConfig();

	//return maxResponse
	return jsonConfig["config"]["maxResponses"];
}

//Get requests list from requests.json
std::vector<std::string> ConverterJSON::getRequests() const
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
		std::cout << "file requests.json not exists";
	//3) return
	return requests;
}

void ConverterJSON::putAnswer(std::vector<std::vector<std::pair<int, float>>> inAnswer) const
{
}

nlohmann::json ConverterJSON::getConfig() const
{
	//1) Open file confing.json
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
		std::cout << "file config.json not exists";
	return jsonConfig;
}
