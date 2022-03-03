#include "FileHandler.hpp"

FileHandler::FileHandler(std::ifstream& _file) {
    file = &_file;
}

FileHandler::FileHandler(const std::string _file) {
    file = new std::ifstream(_file);
}

void FileHandler::parse() {}

std::vector<SequenceHandler*> FileHandler::getSeqsVector() const {
    return seqs;
}

SequenceHandler* FileHandler::getSequence(const int i) const {
    return seqs[i];
}

int FileHandler::getNbSeqs() const {
    return nbSeqs;
}

void FileHandler::readFile(std::ifstream& _file) {
    file = &_file;
}

void FileHandler::readFile(const std::string _file) {
    file = new std::ifstream(_file);
}
