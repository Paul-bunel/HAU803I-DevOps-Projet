#pragma once

#include <string>

class SequenceHandler {
protected:
    std::string sequence;
    std::string header;
    std::string reverse;
    bool valid;

    static const std::string nucleotideIUPAC; // "ACGTURYSWKMBDHVN.-";
    static const std::string aaIUPAC; // "ACDEFGHIKLMNPQRSTVWY";

    void setValid(const bool);

public:
    SequenceHandler(const std::string &, const std::string &);

    std::string getSequence() const;
    std::string getHeader() const;
    std::string getReverse();
    bool getValid() const;

    void setSequence(const std::string &);

    static bool isSequenceValid(const std::string &);
};
