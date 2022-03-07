#include "../include/FastaHandler.hpp"

FastaHandler::FastaHandler(std::ifstream& _file): FileHandler(_file) {
    parse();
}
FastaHandler::FastaHandler(const std::string _file): FileHandler(_file) {
    parse();
}

void FastaHandler::parse() {
    // std::string line;
    std::string content;
    std::string sequence, header;

    if (!(*file).is_open()) {
        std::cout << "Error, file couldn't be opened." << std::endl;
    } else {
        content.assign(std::istreambuf_iterator<char>(*file),
                        std::istreambuf_iterator<char>());
    }

    nbSeqs = std::count(content.begin(), content.end(), '>');
    size_t pos = 0, eol = 0;
    for (size_t i = 0; i < nbSeqs; i++) {
        eol = content.find('\n', eol + 1);
        header = content.substr(pos, eol-pos);

        pos = content.find('>', pos+1);
        sequence = content.substr(eol + 1, pos-(eol+1)-2);

        eol = pos;

        SequenceHandler* sh = new SequenceHandler(header, sequence);
        seqs.push_back(sh);
        header.clear();
        sequence.clear();
    }
}

