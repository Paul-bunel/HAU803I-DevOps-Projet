#pragma once

#include "FileHandler.hpp"

class FastaHandler : public FileHandler {
protected:
    virtual void parse();

public:
    FastaHandler(std::ifstream& _file);
    FastaHandler(const std::string _file);

    // using FileHandler::FileHandler;
};
