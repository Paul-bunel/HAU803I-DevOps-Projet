#pragma once

#include "SequenceHandler.hpp"
#include <string>

class FastaSeqHandler : public virtual SequenceHandler {
protected:
    std::string header;

public:
    FastaSeqHandler(const std::string &);
    FastaSeqHandler(const std::string &, const std::string &);

    std::string getHeader() const;
};
