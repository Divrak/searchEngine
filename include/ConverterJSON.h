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
    std::vector<std::string> getTextDocuments() const;

    //determinate limit quantity answers on one request
    int getResponsesLimit() const;

    //get list requests from file requests.json
    std::vector<std::string> getRequests() const;

    //put results search requests on file answers.json
    void putAnswer(std::vector<std::vector<std::pair<int, float>>>) const;

    //get file config
    nlohmann::json getConfig() const;
};