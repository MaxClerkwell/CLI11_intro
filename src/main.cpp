#include <iostream>
#include <fstream>
#include <vector>
#include "CLI/CLI.hpp"

void printFile(const std::string &filePath, bool invertOutput) {
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (invertOutput) {
            for (auto &ch : line) {
                ch = ~ch; // Zeichen invertieren (Bitweise NOT)
            }
        }
        std::cout << line << std::endl;
    }
    inputFile.close();
}

void copyFileByteByByte(const std::string &inputPath, const std::string &outputPath) {
    std::ifstream inputFile(inputPath, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file " << inputPath << std::endl;
        return;
    }

    std::ofstream outputFile(outputPath, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file " << outputPath << std::endl;
        inputFile.close();
        return;
    }

    char byte;
    while (inputFile.get(byte)) {
        outputFile.put(byte);
    }

    inputFile.close();
    outputFile.close();
    std::cout << "File copied from " << inputPath << " to " << outputPath << std::endl;
}

int main(int argc, char **argv) {
    CLI::App app{"File Processor"};

    std::string filePath;
    app.add_option("-f,--file", filePath, "Input file path")
        ->required()
        ->check(CLI::ExistingFile);

    std::string outputPath;
    app.add_option("-o,--output", outputPath, "Output file path for copying");

    bool invertOutput = false;
    app.add_flag("-i,--invert", invertOutput, "Invert the output behavior");

    //Applies the given parameters to the configured rules for this app
    CLI11_PARSE(app, argc, argv);

    if (!outputPath.empty()) {
        copyFileByteByByte(filePath, outputPath);
    } else {
        printFile(filePath, invertOutput);
    }

    return 0;
}
