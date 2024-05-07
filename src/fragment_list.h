#ifndef FRAGMENT_LIST_H
#define FRAGMENT_LIST_H

#include <vector>
#include <memory> 
#include "sequence_fragment.h"

/**
 * @class FragmentList
 * @brief Class representing a list of sequence fragments.
 */
class FragmentList {
public:
    /**
     * @brief Constructor that initializes a fragment list.
     * @param size The size of the fragment list.
     */
    FragmentList(int size);

    /**
     * @brief Inserts a sequence at a specific position in the fragment list.
     * @param pos The position to insert the sequence at.
     * @param type The type of the sequence.
     * @param sequence The sequence string.
     */
    void insert(int pos, SequenceType type, const std::string& sequence);

    /**
     * @brief Removes a sequence at a specific position in the fragment list.
     * @param pos The position to remove the sequence from.
     */
    void remove(int pos);

    /**
     * @brief Prints all sequences in the fragment list.
     */
    void print();

    /**
     * @brief Prints a sequence at a specific position in the fragment list.
     * @param pos The position of the sequence to print.
     */
    void print(int pos);

    /**
     * @brief Clips a sequence at a specific position in the fragment list.
     * @param pos The position of the sequence to clip.
     * @param start The start position of the clip.
     */
    void clip(int pos, int start);

    /**
     * @brief Copies a sequence from one position to another in the fragment list.
     * @param pos1 The position to copy the sequence from.
     * @param pos2 The position to copy the sequence to.
     */
    void copy(int pos1, int pos2);

    /**
     * @brief Swaps sequences at two positions in the fragment list.
     * @param pos1 The first position.
     * @param start1 The start position of the first sequence.
     * @param pos2 The second position.
     * @param start2 The start position of the second sequence.
     */
    void swap(int pos1, int start1, int pos2, int start2);

    /**
     * @brief Transcribes a sequence at a specific position in the fragment list.
     * @param pos The position of the sequence to transcribe.
     */
    void transcribe(int pos);

private:
    std::vector<std::shared_ptr<SequenceFragment>> fragments; ///< The list of sequence fragments.
};

#endif // FRAGMENT_LIST_H