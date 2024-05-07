/**
 * CISC 187 - Data Structures in C++ 
 * Professor Dave Parillo
 * @author Sophia Su
 * ID: 0005623258
 */ 
#include "sequence_fragment.h"
#include <iostream>

/**
 * @brief Constructs a new Sequence Fragment object.
 * @param type The type of sequence.
 * @param sequence The sequence string.
*/
SequenceFragment::SequenceFragment(SequenceType type, const std::string& sequence)
    : type(type), sequence(sequence) {}

/**
 * @brief Getter for the sequence type (DNA, RNA, or EMPTY).
 * @return The type of sequence.
*/
SequenceType SequenceFragment::getType() const {
    return type;
}

/**
 * @brief Setter for sequence type (DNA, RNA, or EMPTY).
 * @param newType The new type of sequence.
*/
void SequenceFragment::setType(SequenceType newType) {
    type = newType;
}

/**
 * @brief Getter for the sequence string.
 * @return The sequence string.
*/
const std::string& SequenceFragment::getSequence() const {
    return sequence;
}

/**
 * @brief Setter for the sequence string.
*/
void SequenceFragment::setSequence(const std::string& newSequence) {
    sequence = newSequence;
}

