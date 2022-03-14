#pragma once

#include <string>

/**
 * Super classe permettant de stocker différentes données pour une séquence
 * biologique
 */
class SequenceHandler {
protected:
    std::string sequence;
    std::string header;
    std::string reverse;
    bool valid;

    static const std::string nucleotideIUPAC; // "ACGTURYSWKMBDHVN.-";
    static const std::string aaIUPAC; // "ACDEFGHIKLMNPQRSTVWY";

public:
    /**
     * @brief Construit une nouvelle instance de gestionnaire de séquence de
     * 
     * \param header header de la séquence dans le fichier d'où elle provient,
     * par défaut chaine vide
     * 
     * \param sequence séquence de nucléotides
     */
    SequenceHandler(const std::string &, const std::string &);

    std::string getSequence() const;
    std::string getHeader() const;

    /**
     * @brief Renvoie la séquence inverse de celle stockée par l'instance
     * courante, et la stocke en paramètre pour ne pas devoir la recalculer.
     * Si aucune séquence inverse n'est stockée, la méthode en crée une à
     * partir de celle stockée en changeant les caractères selon les
     * correspondances suivantes :
     *   A -> T,
     *   T -> A,
     *   C -> G,
     *   G -> C.
     * 
     * @return std::string reverse, la chaine de caractères représentant
     * l'inverse de la séquence nucléotidique stockée.
     */
    std::string getReverse(); // FASTA
    bool getValid() const;

    void setSequence(const std::string &);
    
    /**
     * @brief Méthode statique jugeant la validité d'une séquence biologique
     * 
     * @return true Si la séquence respecte le standard IUPAC
     * @return false Si la séquence ne respecte pas le standard IUPAC
     */
    static bool isSequenceValid(const std::string &);
};
