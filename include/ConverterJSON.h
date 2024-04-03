#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

class ConverterJSON
{
public:
    ConverterJSON() = default;
    //get text documents no file config.json
    std::vector<std::string> getTextDocuments();

    //determinate limit quantity answers on one request
    int getResponsesLimit();

    //get list requests from file requests.json
    std::vector<std::string> getRequests();

    //put results search requests on file answers.json
    void putAnswer(std::vector<std::vector<std::pair<int, float>>> answer);
};