#include "FastaHandler.hpp"

int main() {
    std::string fileName("sequences_test.fasta");

    FastaHandler fh(fileName);

    std::vector<FastaSeqHandler*> vect = fh.getSeqsVector();
    for (auto s : vect) {
        // std::cout << "\nHeader : " << s->getHeader() << std::endl;
        // std::cout << "Sequence : " << s->getSequence() << std::endl;
        std::cout << s->getHeader() << " : validity = " << s->getValid() << std::endl;
    }

    // std::cout << "Il y a " << fh.getNbSeqs() << " séquences dans le fichier\
    // fasta. Voici la deuxième séquence :" << std::endl;

    // std::cout << vect[1]->getHeader() << std::endl << vect[1]->getSequence() <<
    // std::endl << vect[1]->getReverse() << std::endl;

    return EXIT_SUCCESS;
}