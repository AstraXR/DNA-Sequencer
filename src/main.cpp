#include "command_processor.h"
#include "fragment_list.h"
#include <fstream>  
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unistd.h>

/**
 * @brief Main function for the sequencer program.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return 0 if the program exits successfully, 1 otherwise.
 */
int main(int argc, char* argv[]) {
    int opt;
    int fragmentsCount = 8; ///< The default number of fragments
    std::string log_level = "info"; ///< The default log level
    std::string file_name;

    // Process command line arguments
    while ((opt = getopt(argc, argv, "h:m:l:f:")) != -1) { 
        switch (opt) {
            case 'h': {
                /// Display help message
                std::string helpMessage = "Usage: sequencer [-h] [-m #] [-l log_level] -f <file name>\n"
                                          "Options:\n"
                                          "  -h       Show this text and exit. \n"
                                          "  -m   Max amount of space allocated for sequence fragments.\n"
                                          "       The default is 8\n"
                                          "  -l   Set the log detail level.\n"
                                          "       The default is 'info'\n"
                                          "  -f   File name containing commands for the sequencer\n"
                                          "       The file should be plain text, 1 command per line\n"
                                          "       If no file is specified, the program will exit.\n";
                std::cout << helpMessage;
                break;
            }
            case 'm': {
                /// Set the max amount of space allocated for sequence fragments
                try {
                    fragmentsCount = std::stoi(optarg);
                } catch (std::invalid_argument const &e) {
                    std::cerr << "std::invalid_argument thrown. Please add max amount of space allocated for sequence fragments after -m." << '\n';
                    return 1;
                } catch (std::out_of_range const &e) {
                    std::cerr << "Integer overflow for -m option: std::out_of_range thrown" << '\n';
                    return 1;
                }
                break;
            }
            case 'l': {
                /// Set the log detail level
                log_level = optarg;
                break;
            }
            case 'f': {
                /// Set the file name
                file_name = optarg;
                break;
            }
            default: {
                std::cerr << "Invalid option\n";
                return 1;
            }
        }
    }

    FragmentList fragmentList(fragmentsCount);
    CommandProcessor processor(fragmentsCount, fragmentList);

    if (file_name.empty()) {
        std::cerr << "File name is required\n";
        return 1;
    }

    std::ifstream file(file_name);
    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        processor.processCommand(line);
    }

    return 0;
}
