/**
 * CISC 187 - Data Structures in C++ 
 * Professor Dave Parillo
 * @author Sophia Su
 * ID: 0005623258
 */ 
#include "command_processor.h"
#include "fragment_list.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <map>

/**
 * @brief Constructs a new Command Processor object.
 * @param fragmentsCount The number of fragments, default is 8.
 * @param fragmentList The fragment list object.
 */
CommandProcessor::CommandProcessor(int fragmentsCount, FragmentList& fragmentList)  
  : fragmentsCount(fragmentsCount), 
    fragmentList(fragmentList),
    commandMap({
        {"INSERT", CommandType::INSERT},
        {"REMOVE", CommandType::REMOVE},
        {"PRINT", CommandType::PRINT},
        {"CLIP", CommandType::CLIP},
        {"COPY", CommandType::COPY},
        {"SWAP", CommandType::SWAP},
        {"TRANSCRIBE", CommandType::TRANSCRIBE}
    }),
    sequenceTypeMap({ 
        {"DNA", SequenceType::DNA},
        {"RNA", SequenceType::RNA}
    }) {
    
}

/**
 * @brief Processes a command.
 * @param command The command to process.
 */
void CommandProcessor::processCommand(const std::string& command) { 
    // Log the command
    //logger.log(LogLevel::INFO, "Processing command: " + command);
    // Ignore empty lines
    if (command.empty()) {
        return;
    }
    // Convert the command to uppercase for case insensitivity
    std::string uppercaseCommand = command;
    std::transform(uppercaseCommand.begin(), uppercaseCommand.end(), uppercaseCommand.begin(), ::toupper);

    // Parse the command and its parameters
    std::string commandName;
    std::vector<std::string> parameters;
    
    parseCommand(uppercaseCommand, commandName, parameters);
    // Execute the command
    executeCommand(commandName, parameters);
    
}

/**
 * @brief Parses a command.
 * @param command The command to parse.
 * @param commandName The parsed command name.
 * @param parameters The parsed parameters.
 */
void CommandProcessor::parseCommand(const std::string& command, std::string& commandName, std::vector<std::string>& parameters) {
    std::istringstream iss(command); // Convert the command to a stream
    std::vector<std::string> words((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>()); // Split the command into words

    if (!words.empty()) { // If there are words in the command
        commandName = words[0]; // The first word is the command name
        parameters.assign(words.begin() + 1, words.end()); // The rest of the words are parameters
        
        commandName.erase(commandName.begin(), std::find_if(commandName.begin(), commandName.end(), [](unsigned char ch) { // Remove leading whitespace
            return !std::isspace(ch); // Find the first character that is not whitespace
        }));
        commandName.erase(std::find_if(commandName.rbegin(), commandName.rend(), [](unsigned char ch) { // Remove trailing whitespace
            return !std::isspace(ch); // Find the first character that is not whitespace
        }).base(), commandName.end()); // Remove the characters from the first non-whitespace character to the end of the string

        for (auto& parameter : parameters) { // For each parameter
            parameter.erase(parameter.begin(), std::find_if(parameter.begin(), parameter.end(), [](unsigned char ch) { // Remove leading whitespace
                return !std::isspace(ch); // Find the first character that is not whitespace
            }));
            parameter.erase(std::find_if(parameter.rbegin(), parameter.rend(), [](unsigned char ch) { // Remove trailing whitespace
                return !std::isspace(ch); // Find the first character that is not whitespace
            }).base(), parameter.end()); // Remove the characters from the first non-whitespace character to the end of the string
        }
    }
}

/**
 * @brief Executes a command.
 * @param commandName The name of the command to execute.
 * @param parameters The parameters of the command.
 */
void CommandProcessor::executeCommand(const std::string& commandName, const std::vector<std::string>& parameters) {
    if (commandName == "INSERT") {
        int pos = std::stoi(parameters[0]);
        SequenceType type = sequenceTypeMap[parameters[1]];
        std::string sequence = parameters[2];
        fragmentList.insert(pos, type, sequence);
    } else if (commandName == "REMOVE") {
        int pos = std::stoi(parameters[0]);
        fragmentList.remove(pos);
    } else if (commandName == "PRINT") {
        if (!parameters.empty()) {
            int pos = std::stoi(parameters[0]);
            fragmentList.print(pos);
        } else {
            fragmentList.print();
        }
    } else if (commandName == "CLIP") {
        int pos = std::stoi(parameters[0]);
        int start = std::stoi(parameters[1]);
        fragmentList.clip(pos, start);
    } else if (commandName == "COPY") {
        int pos = std::stoi(parameters[0]);
        int pos2 = std::stoi(parameters[1]);
        fragmentList.copy(pos, pos2);
    } else if (commandName == "SWAP") {
        int pos = std::stoi(parameters[0]);
        int start = std::stoi(parameters[1]);
        int pos2 = std::stoi(parameters[2]);
        int start2 = std::stoi(parameters[3]);
        fragmentList.swap(pos, start, pos2, start2);
    } else if (commandName == "TRANSCRIBE") {
        int pos = std::stoi(parameters[0]);
        fragmentList.transcribe(pos);
    } else {
        //logger.log(LogLevel::ERROR, "Unknown command: " + commandName);
        std::cout << "Unknown command: " + commandName << std::endl;
    }
}