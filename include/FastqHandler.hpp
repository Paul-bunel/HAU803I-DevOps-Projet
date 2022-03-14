#pragma once

#include "FileHandler.hpp"

/**
 * Classe héritant de FileHandler et permettant la lecture d'un fichier au format
 * FASTQ, en parsant celui-ci afin de stocker les séquences dans des instances
 * de SequenceFastq.
 */
class FastqHandler : public FileHandler {
protected:
    void virtual parse();

public:
    FastqHandler(std::ifstream&);
    FastqHandler(const std::string);
};
