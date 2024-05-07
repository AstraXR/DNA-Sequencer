/**
 * CISC 187 - Data Structures in C++ 
 * Professor Dave Parillo
 * @author Sophia Su
 * ID: 0005623258
 */ 
#include "fragment_list.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept> 

/**
 * @brief Construct a new Fragment List:: Fragment List object
 * 
 * @param size Size of the fragment list
 */
FragmentList::FragmentList(int size)
    : fragments(size) {}


/**
 * @brief Insert a sequence at a given position
 * 
 * @param pos Position to insert the sequence
 * @param type Type of the sequence (DNA or RNA)
 * @param sequence The sequence string
 */
void FragmentList::insert(int pos, SequenceType type, const std::string& sequence) {
    // Check that the position is within the valid range
    if (pos < 0 || pos >= fragments.size()) {
        std::cerr << "The position out of range.\n";
        return;
    }

    // Check that the sequence contains only appropriate letters for its type
    for (char c : sequence) {
        if (type == SequenceType::DNA && c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            std::cerr << "Invalid sequence. The sequence \"" << sequence << "\" contains invalid characters for the DNA sequence.\n";
            return;
        }
        if (type == SequenceType::RNA && c != 'A' && c != 'C' && c != 'G' && c != 'U') {
            std::cerr << "Invalid sequence. The sequence \"" << sequence << "\" contains invalid characters for the RNA sequence.\n";
            return;
        }
    }

    // If there is already a sequence at pos, the new sequence replaces the old one
    fragments[pos] = std::make_shared<SequenceFragment>(type, sequence);
}

/**
 * @brief Remove a sequence at a given position
 * 
 * @param pos Position to remove the sequence
 */
void FragmentList::remove(int pos) {
    // Check that the position is within the valid range
    if (pos < 0 || pos >= fragments.size()) {
        std::cerr << "The position out of range.\n";
        return;
    }

    // Check if there is a sequence at pos
    if (fragments[pos] == nullptr) {
        std::cerr << "There is no sequence at this position.\n";
        return;
    }

    // Remove the sequence at pos and set the sequence type to EMPTY
    fragments[pos] = std::make_shared<SequenceFragment>(SequenceType::EMPTY, "");
}

/**
 * @brief Print all sequences
 */
void FragmentList::print() {
    for (int i = 0; i < fragments.size(); ++i) {
        if (fragments[i] != nullptr && fragments[i]->getType() != SequenceType::EMPTY) {
            std::cout << "Position: " << i << ", Type: ";
            switch (fragments[i]->getType()) {
                case SequenceType::DNA:
                    std::cout << "DNA, ";
                    break;
                case SequenceType::RNA:
                    std::cout << "RNA, ";
                    break;
                default:
                    break;
            }
            std::cout << "Sequence: " << fragments[i]->getSequence() << "\n";
        }
    }
}

/**
 * @brief Print a sequence at a given position
 * 
 * @param pos Position to print the sequence
 */
void FragmentList::print(int pos) {
    // Check that the position is within the valid range
    if (pos < 0 || pos >= fragments.size()) {
        std::cerr << "The position out of range.\n";
        return;
    }

    // Check if there is a sequence at pos
    if (fragments[pos] == nullptr || fragments[pos]->getType() == SequenceType::EMPTY) {
        std::cerr << "There is no sequence at this position.\n";
        return;
    }

    // Print the sequence and its type
    std::cout << "Position: " << pos << ", Type: ";
    switch (fragments[pos]->getType()) {
        case SequenceType::DNA:
            std::cout << "DNA, ";
            break;
        case SequenceType::RNA:
            std::cout << "RNA, ";
            break;
        default:
            break;
    }
    std::cout << "Sequence: " << fragments[pos]->getSequence() << "\n";
}

/**
 * @brief Clip a sequence at a given position from a start index
 * 
 * @param pos Position of the sequence
 * @param start Start index to clip the sequence
 */
void FragmentList::clip(int pos, int start) {
    // Check that the position is within the valid range
    if (pos < 0 || pos >= fragments.size()) {
        std::cerr << "The position out of range.\n";
        return;
    }

    // Check if there is a sequence at pos
    if (fragments[pos] == nullptr || fragments[pos]->getType() == SequenceType::EMPTY) {
        std::cerr << "There is no sequence at this position.\n";
        return;
    }

    // Check that start is within the valid range
    if (start < 0 || start >= fragments[pos]->getSequence().size()) {
        std::cerr << "The start position out of range.\n";
        return;
    }

    // Replace the sequence at pos with the clipped version of the sequence
    std::string clippedSequence = fragments[pos]->getSequence().substr(start);
    fragments[pos]->setSequence(clippedSequence);
}

/**
 * @brief Copy a sequence from one position to another
 * 
 * @param pos1 Source position
 * @param pos2 Destination position
 */
void FragmentList::copy(int pos1, int pos2) {
    // Check that the positions are within the valid range
    if (pos1 < 0 || pos1 >= fragments.size() || pos2 < 0 || pos2 >= fragments.size()) {
        std::cerr << "The position out of range.\n";
        return;
    }

    // Check if there is a sequence at pos1
    if (fragments[pos1] == nullptr || fragments[pos1]->getType() == SequenceType::EMPTY) {
        std::cerr << "There is no sequence at the source position.\n";
        return;
    }

    // Copy the sequence from pos1 to pos2
    SequenceType type = fragments[pos1]->getType();
    std::string sequence = fragments[pos1]->getSequence();
    fragments[pos2] = std::make_shared<SequenceFragment>(type, sequence);
}

/**
 * @brief Swap the tails of two sequences
 * 
 * @param pos1 Position of the first sequence
 * @param start1 Start index of the tail of the first sequence
 * @param pos2 Position of the second sequence
 * @param start2 Start index of the tail of the second sequence
 */
void FragmentList::swap(int pos1, int start1, int pos2, int start2) {
    // Check that the positions are within the valid range
    if (pos1 < 0 || pos1 >= fragments.size() || pos2 < 0 || pos2 >= fragments.size()) {
        std::cerr << "The position out of range.\n";
        return;
    }

    // Check if there are sequences at pos1 and pos2
    if (fragments[pos1] == nullptr || fragments[pos1]->getType() == SequenceType::EMPTY ||
        fragments[pos2] == nullptr || fragments[pos2]->getType() == SequenceType::EMPTY) {
        std::cerr << "One or both positions do not contain a sequence.\n";
        return;
    }

    // Check that the sequences are of the same type
    if (fragments[pos1]->getType() != fragments[pos2]->getType()) {
        std::cerr << "Sequences are not of the same type.\n";
        return;
    }

    // Check that the start positions are within the valid range
    if (start1 < 0 || start1 > fragments[pos1]->getSequence().size() ||
        start2 < 0 || start2 > fragments[pos2]->getSequence().size()) {
        std::cerr << "Start position out of range.\n";
        return;
    }

    // Swap the tails of the sequences
    std::string tail1 = fragments[pos1]->getSequence().substr(start1);
    std::string tail2 = fragments[pos2]->getSequence().substr(start2);
    fragments[pos1]->setSequence(fragments[pos1]->getSequence().substr(0, start1) + tail2);
    fragments[pos2]->setSequence(fragments[pos2]->getSequence().substr(0, start2) + tail1);
}

/**
 * @brief Transcribe a DNA sequence to RNA
 * 
 * @param pos Position of the sequence
 */
void FragmentList::transcribe(int pos) {
    // Check that the position is valid
    if (pos < 0 || pos >= fragments.size() || fragments[pos] == nullptr || fragments[pos]->getType() == SequenceType::EMPTY) {
        std::cerr << " Position does not contain a sequence.\n";
        return;
    }

    // Check that the sequence is DNA
    if (fragments[pos]->getType() != SequenceType::DNA) {
        std::cerr << " Sequence is not DNA.\n";
        return;
    }

    // Change the sequence type to RNA
    fragments[pos]->setType(SequenceType::RNA);

    // Complement and reverse the sequence
    std::string sequence = fragments[pos]->getSequence();
    for (char& c : sequence) {
        switch (c) {
            case 'A': c = 'T'; break;
            case 'C': c = 'G'; break;
            case 'G': c = 'C'; break;
            case 'T': c = 'U'; break;
        }
    }
    std::reverse(sequence.begin(), sequence.end());

    // Update the sequence
    fragments[pos]->setSequence(sequence);
}