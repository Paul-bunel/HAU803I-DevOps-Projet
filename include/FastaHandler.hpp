#pragma once

#include "FileHandler.hpp"

/**
 * Classe héritant de FileHandler et permettant la lecture d'un fichier au format
 * FASTA, en parsant celui-ci afin de stocker les séquences dans des instances
 * de SequenceFasta.
 */
class FastaHandler : public FileHandler {
protected:
    virtual void parse();

public:
    FastaHandler(std::ifstream&);
    FastaHandler(const std::string);
};
