#pragma once

#include "FileHandler.hpp"

class FastqHandler : public FileHandler {
protected:
    void virtual parse();

public:
    using FileHandler::FileHandler;
};
