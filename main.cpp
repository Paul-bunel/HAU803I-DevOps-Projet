//TODO - TOTHINK : TEMPLATE INSTEAD OF INHERITANCE
#include "include/FastaHandler.hpp"

int main() {
    std::string fileName("../test/sequences_test.fasta");

    FastaHandler fh(fileName);

    std::cout << "Fichier " << fileName << " ouvert" << std::endl;

    std::vector<SequenceHandler*> vect = fh.getSeqsVector();
    std::cout << "Vecteur récupéré, taille = " << vect.size() << std::endl;
    // for (auto s : vect) {
        // std::cout << "\nHeader : " << s->getHeader() << std::endl;
        // std::cout << "Sequence : " << s->getSequence() << std::endl;
        // std::cout << s->getHeader() << " : validity = " << s->getValid() << std::endl;
    // }

    std::cout << "Il y a " << fh.getNbSeqs() << " séquences dans le fichier\
    fasta. Voici la deuxième séquence :" << std::endl;

    std::cout << vect[0]->getHeader() << std::endl << vect[0]->getSequence() <<
    std::endl << vect[0]->getReverse() << std::endl;

    return EXIT_SUCCESS;
}