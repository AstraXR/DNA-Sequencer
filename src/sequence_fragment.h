#ifndef SEQUENCE_FRAGMENT_H
#define SEQUENCE_FRAGMENT_H

#include <vector>
#include <string>

/**
 * @enum SequenceType
 * @brief Enum class for the type of a sequence.
 */
enum class SequenceType {
    DNA,   ///< Represents a DNA sequence.
    RNA,   ///< Represents an RNA sequence.
    EMPTY  ///< Represents an empty sequence.
};

/**
 * @class SequenceFragment
 * @brief Class representing a sequence fragment.
 */
class SequenceFragment {
public:
    /**
     * @brief Constructor that initializes a sequence fragment.
     * @param type The type of the sequence.
     * @param sequence The sequence string.
     */
    SequenceFragment(SequenceType type, const std::string& sequence);

    /**
     * @brief Getter for the sequence type.
     * @return The type of the sequence.
     */
    SequenceType getType() const;

    /**
     * @brief Setter for the sequence type.
     * @param newType The new type of the sequence.
     */
    void setType(SequenceType newType);

    /**
     * @brief Getter for the sequence string.
     * @return The sequence string.
     */
    const std::string& getSequence() const;

    /**
     * @brief Setter for the sequence string.
     * @param newSequence The new sequence string.
     */
    void setSequence(const std::string& newSequence);

private:
    SequenceType type; ///< The type of the sequence.
    std::string sequence; ///< The sequence string.
};


#endif // SEQUENCE_FRAGMENT_H