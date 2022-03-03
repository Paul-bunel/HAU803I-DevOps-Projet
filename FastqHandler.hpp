#pragma once

#include "FileHandler.hpp"

class FastqHandler : public virtual FileHandler {
protected:
    void virtual parse();

public:
    FastqHandler(std::ifstream&);
    FastqHandler(const std::string);

    // using FileHandler::FileHandler;
};
