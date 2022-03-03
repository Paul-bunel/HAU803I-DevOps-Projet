#include "FastaSeqHandler.hpp"
#include <iostream>
#include <cctype>

FastaSeqHandler::FastaSeqHandler(const std::string & _sequence)
: SequenceHandler(_sequence) {}

FastaSeqHandler::FastaSeqHandler(const std::string & _header, const std::string & _sequence)
: SequenceHandler(_sequence) {
    header = _header;
}

std::string FastaSeqHandler::getHeader() const {
    return header;
}