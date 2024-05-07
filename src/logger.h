#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>

/**
 * @enum LogLevel
 * @brief Enum class for the log level.
*/
enum class LogLevel {
    ERROR,
    WARNING,
    INFO,
    DEBUG
};

/**
 * @class Logger
 * @brief Class for logging messages.
*/
class Logger {
public:
/**
 * @brief Constructs a new Logger object.
 * @param level The log level.
 * @param filename The name of the log file.
*/
    Logger(LogLevel level, const std::string& filename) 
        : level(level), logFile(filename, std::ios_base::app) {
        if (!logFile) {
            throw std::runtime_error("Failed to open log file");
        }
    }

    /**
     * @brief Logs a message.
     * @param logLevel The log level.
     * @param message The message to log.
    */
    void log(LogLevel logLevel, const std::string& message) {
        if (logLevel <= level) {
            logFile << toString(logLevel) << ": " << message << std::endl;
        }
    }


private:
    LogLevel level; ///<The log level.
    std::ofstream logFile; ///<The log file.

    /**
     * @brief Converts a log level to a string.
     * @param logLevel The log level.
     * @return The log level as a string.
    */
    std::string toString(LogLevel logLevel) {
        switch (logLevel) {
            case LogLevel::ERROR: return "ERROR";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::INFO: return "INFO";
            case LogLevel::DEBUG: return "DEBUG";
            default: return "UNKNOWN";
        }
    }
};

#endif // LOGGER_H