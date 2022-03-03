#pragma once

#include "FileHandler.hpp"
#include "FastaSeqHandler.hpp"

class FastaHandler : public virtual FileHandler {
protected:
    virtual void parse();

public:
    FastaHandler(std::ifstream&);
    FastaHandler(const std::string);

    virtual std::vector<FastaSeqHandler*> getSeqsVector() const;
    virtual FastaSeqHandler* getSequence(const int) const;

};
