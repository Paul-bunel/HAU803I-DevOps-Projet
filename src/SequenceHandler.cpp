#include "../include/SequenceHandler.hpp"
#include <iostream>
#include <cctype>

const std::string SequenceHandler::nucleotideIUPAC = "ACGTU\nRYSWKMBDHVN.-";
const std::string SequenceHandler::aaIUPAC = "ACDEFGHIKLMNPQRSTVWY\n";

SequenceHandler::SequenceHandler(const std::string &_header, const std::string &_sequence = "")
: sequence(_sequence), header(_header) {
    reverse.reserve(sequence.size());
    valid = isSequenceValid(sequence);
}

std::string SequenceHandler::getSequence() const {
    return sequence;
}

std::string SequenceHandler::getHeader() const {
    return header;
}

bool SequenceHandler::getValid() const {
    return valid;
}

std::string SequenceHandler::getReverse() {
    if (reverse.length() == 0) {
        for (int i = sequence.length() - 1; i >= 0; i--) {
            if (sequence[sequence.length() - 1 - i] == 'A'
             or sequence[sequence.length() - 1 - i] == 'a') {reverse.push_back('T');
            } else {
            if (sequence[sequence.length() - 1 - i] == 'T'
             or sequence[sequence.length() - 1 - i] == 't') {reverse.push_back('A');
            } else {
            if (sequence[sequence.length() - 1 - i] == 'C'
             or sequence[sequence.length() - 1 - i] == 'c') {reverse.push_back('G');
            } else {
            if (sequence[sequence.length() - 1 - i] == 'G'
             or sequence[sequence.length() - 1 - i] == 'g') {reverse.push_back('C');
            }}}}
        }
    }
    return reverse;
}

void SequenceHandler::setSequence(const std::string & _sequence) {
    sequence = _sequence;
    reverse.reserve(sequence.size());
    valid = isSequenceValid(sequence);
}

bool SequenceHandler::isSequenceValid(const std::string & sequence) {
    size_t i = 0;
    bool isValid = true;
    while (i < sequence.length() && isValid == true) {
        if (nucleotideIUPAC.find(toupper(sequence[i])) == std::string::npos) {
            std::cout << sequence[i] << std::endl;
            isValid = false;
        }
        ++i;
    }

    return isValid;
}