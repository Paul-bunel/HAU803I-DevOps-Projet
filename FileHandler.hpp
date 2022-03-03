#pragma once

#include "SequenceHandler.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class FileHandler {
protected:
    std::ifstream* file;
    std::vector<SequenceHandler*> seqs;
    size_t nbSeqs = 0;

    virtual void parse();

public:
    FileHandler(std::ifstream&);
    FileHandler(const std::string);

    virtual std::vector<SequenceHandler*> getSeqsVector() const;
    virtual SequenceHandler* getSequence(const int) const;
    int getNbSeqs() const;

    void readFile(std::ifstream&);
    void readFile(const std::string);
};
