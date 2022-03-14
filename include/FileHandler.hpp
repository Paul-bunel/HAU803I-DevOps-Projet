#pragma once

#include "SequenceHandler.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * Classe abstraite implémentant les bases pour manipuler un fichier
 */
class FileHandler {
protected:
    std::ifstream* file;
    std::vector<SequenceHandler*> seqs;
    size_t nbSeqs = 0;

    /**
     * @brief Méthode abstraite permettant de parser un fichier
     * 
     * Cette méthode sera implémenté dans les classes filles, afin de permettre,
     * lors de la lecture d'un fichier, de parser ce dernier afin de ranger
     * certains éléments dans des objets précis.
     */
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