#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

//#include "logger.h"
#include "fragment_list.h"
#include <string>
#include <vector>
#include <map>

/**
 * @enum CommandType
 * @brief Enum class for the type of a command used.
*/
enum class CommandType {
    INSERT,         
    REMOVE,         
    PRINT,
    CLIP,
    COPY,
    SWAP,
    TRANSCRIBE
};

/**
 * @class CommandProcessors
 * @brief Class which processes commands.
*/
class CommandProcessor {
public:
    /**
     * @brief Constructs a new Command Processor object.
     * @param fragmentsCount The number of fragments, default is 8.
     * @param logger The logger object.
    */
    CommandProcessor(int fragmentsCount, FragmentList& fragmentList);
    /**
     * @brief Processes a command.
     * @param command The command to process.
    */
    void processCommand(const std::string& command);

private:
    FragmentList fragmentList; 

    int fragmentsCount; ///< The number of fragments.

    std::map<std::string, CommandType> commandMap; ///< Map of command names to command types.
    std::map<std::string, SequenceType> sequenceTypeMap; ///< Map of sequence types to sequence type enum values.
    
    /**
     * @brief Parses a command.
     * @param command The command being parsed.
     * @param commandName The parsed command name.
     * @param parameters The parsed parameters.
    */
    void parseCommand(const std::string& command, std::string& commandName, std::vector<std::string>& parameters);

    void executeCommand(const std::string& commandName, const std::vector<std::string>& parameters);

};
#endif // COMMAND_PROCESSOR_H