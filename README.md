# File Processor as intro to CLI11

## Overview
This project is a simple C++ application that uses the CLI11 library to parse file paths and flags from the command line. It provides two main functionalities:

1. **File Content Display:** The application outputs the content of a specified file. An option allows inverting the text character by character.
2. **Byte-by-Byte File Copy:** The application copies the content of one file to another, byte by byte.

### Key Concepts:
1. **CLI11 Library:** CLI11 is a modern C++ library for handling command-line arguments. It provides simple and elegant ways to define and validate options, flags, and parameters. It is more flexible and powerful compared to traditional options like `getopt.h`.

2. **FetchContent:** Using `FetchContent`, the CLI11 library is automatically downloaded and integrated into the project. This removes the need to manually manage or store libraries locally.

---

## How It Works

1. **Display File Content**
   - Use the `-f` or `--file` parameter to specify the input file path.
   - Add the `-i` or `--invert` flag to invert the text character by character.

   **Example:**
   ```shell
   ./CLI11_intro -f example.txt
   ./CLI11_intro -f example.txt -i
   ```

2. **Copy File**
   - Use the `-f` parameter (input file) and `-o` parameter (output file) to copy the content of the input file to the output file byte by byte.

   **Example:**
   ```shell
   ./CLI11_intro -f example.txt -o copy.txt
   ```

---

## Build Instructions
1. Build the project with the following commands:

   ```shell
   cmake -B build && cmake --build ./build
   ```

2. The executable file will be located in the `build` directory.

---

## Code Highlights

### CLI11 Integration
The CLI11 library is used to parse arguments and flags:

```cpp
CLI::App app{"File Processor"};

std::string filePath;
app.add_option("-f,--file", filePath, "Input file path")
    ->required()
    ->check(CLI::ExistingFile);

std::string outputPath;
app.add_option("-o,--output", outputPath, "Output file path for copying");

bool invertOutput = false;
app.add_flag("-i,--invert", invertOutput, "Invert the output behavior");

CLI11_PARSE(app, argc, argv);
```

### FetchContent
The CLI11 library is automatically included using `FetchContent`. The relevant CMake configuration is:

```cmake
include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)

FetchContent_MakeAvailable(CLI11)
```

---

## Suggestions for Students
1. **Explore CLI11:**
   - Experiment with different flags and options.
   - Add new parameters and validation rules, such as file size constraints.

2. **Deepen Understanding of FetchContent:**
   - Extend the project to include additional libraries using `FetchContent`.
   - Understand how FetchContent makes projects modular and maintainable.

