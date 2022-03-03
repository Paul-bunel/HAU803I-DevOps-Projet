#pragma once

#include <string>

class SequenceHandler {
protected:
    std::string sequence;
    std::string reverse;
    bool valid;

    static const std::string nucleotideIUPAC; // "ACGTURYSWKMBDHVN.-";
    static const std::string aaIUPAC; // "ACDEFGHIKLMNPQRSTVWY";

    void setValid(const bool);

public:
    SequenceHandler(const std::string &);

    std::string getSequence() const;
    bool getValid() const;
    std::string getReverse();

    void setSequence(const std::string &);

    static bool isSequenceValid(const std::string &);
};
