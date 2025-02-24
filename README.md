# Minishell - A Detailed Shell Implementation

<img src="https://img.shields.io/badge/Language-C-blue" alt="Language C"> <img src="https://img.shields.io/badge/Project-42-lightgrey" alt="Project 42">

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Command Examples](#command-examples)
- [Technical Implementation Details](#technical-implementation-details)
  - [Lexical Analysis (Lexer)](#lexical-analysis-lexer)
  - [Parsing & AST Construction](#parsing--ast-construction)
  - [Command Execution](#command-execution)
  - [Built-in Commands](#built-in-commands)
  - [Signal Handling](#signal-handling)
  - [Redirection Implementation](#redirection-implementation)
  - [Pipe Implementation](#pipe-implementation)
  - [Environment Variable Management](#environment-variable-management)
  - [Memory Management](#memory-management)
  - [Error Handling](#error-handling)
- [Project Structure](#project-structure)
- [Technical Challenges & Solutions](#technical-challenges--solutions)
- [Contributors](#contributors)

## 🔍 Overview

Minishell is a comprehensive shell implementation inspired by bash. This project recreates a functioning command interpreter that handles command execution, built-in commands, environment variables, pipes, redirections, and more. The implementation follows a modular design with distinct components working together to provide a robust shell experience.

## ✨ Features

- **Command Execution**: Run external programs with argument parsing
- **Pipes**: Process pipeline implementation using `|` for connecting commands
- **Redirections**: Support for input `<`, output `>`, and append `>>` redirections
- **Environment Variables**: Complete management system with expansion and variable substitution
- **Signal Handling**: Proper handling of keyboard signals (CTRL+C, CTRL+D, CTRL+\)
- **Quote Handling**: Support for both single quotes (literal) and double quotes (variable expansion)
- **Error Handling**: Comprehensive error messages and appropriate exit status codes
- **History Management**: Command history navigation using readline library

### Built-in Commands
- `echo`: Text display with `-n` option support
- `cd`: Directory navigation with path resolution and environment updates
- `pwd`: Current directory information
- `export`: Environment variable setting with proper validation
- `unset`: Environment variable removal with system protection
- `env`: Environment variable listing
- `exit`: Shell termination with optional exit status

## 🛠️ Installation

### Prerequisites
- GCC Compiler
- Make
- GNU Readline library

### Compiling
```bash
# Clone the repository
git clone <repository-url>
cd minishell

# Compile the project
make

# Run minishell
./minishell
```

## 🚀 Usage

Once you launch minishell, you'll be presented with a prompt (`minishell> `) where you can start entering commands.

```bash
./minishell
```

## 💻 Command Examples

Here are some examples of commands you can run in minishell:

```bash
# Basic commands
minishell> ls -l
minishell> pwd
minishell> echo Hello, World!

# Pipes
minishell> ls | grep .c
minishell> cat file.txt | wc -l

# Redirections
minishell> ls > files.txt
minishell> cat < files.txt
minishell> ls >> files.txt

# Environment variables
minishell> echo $HOME
minishell> export MY_VAR=value
minishell> echo $MY_VAR

# Built-in commands
minishell> cd ..
minishell> pwd
minishell> env
minishell> export NAME=value
minishell> unset NAME
minishell> exit 42
```

## 🔩 Technical Implementation Details

### Lexical Analysis (Lexer)

The lexer is implemented in `src/lexer/` and is responsible for breaking input strings into meaningful tokens. Key technical aspects include:

- **Token Types**: We define different token types (TOKEN_WORD, TOKEN_PIPE, TOKEN_REDIR_IN, TOKEN_REDIR_OUT, TOKEN_APPEND, TOKEN_HEREDOC, TOKEN_EOF) in `lexer.h`.
- **Tokenization Process**: The main tokenization logic in `lexer_init.c` and `tokenizer.c`:
  - Character-by-character analysis with state tracking
  - Special handling for operators, quotes, and word characters
  - Quote state tracking to handle nested quotes correctly
- **Quote Handling**: Implemented in `lexer_word.c` and `lexer_word_utils.c`:
  - Differentiates between single quotes (literal) and double quotes (with variable expansion)
  - Tracks unmatched quotes and reports syntax errors
- **Environment Variable Expansion**: Implemented in `lexer_expand.c`:
  - Detects `$VAR` patterns and expands them with values from environment
  - Special handling for `$?` to return the last command's exit status
  - Conditional expansion inside double quotes but not single quotes

### Parsing & AST Construction

The parser is implemented in `src/parser/` and constructs an Abstract Syntax Tree (AST) from the token stream:

- **AST Node Types**: Defined in `includes/parsing.h`:
  - CMD: Simple command node (with arguments)
  - PIPE: Pipeline connector node
  - REDIR_IN/REDIR_OUT/APPEND: Redirection nodes
  - FILENAME: File reference node
- **Recursive Descent Parsing**: Implemented in `parser.c`:
  - Builds a tree structure with proper operator precedence
  - Handles nested commands, pipes, and redirections
  - Validates syntax and detects errors during parsing
- **AST Traversal**: Walking the tree to execute commands in the correct order
- **Command Argument Handling**: Collecting arguments for command execution

### Command Execution

The execution engine is implemented in `src/execution/`:

- **Process Creation**: Creates child processes for command execution
- **Execution Strategy**: Uses fork/exec model to execute external commands
- **Path Resolution**: Uses environment PATH to find executable binaries
- **Exit Status Tracking**: Captures and stores command exit status for `$?` expansion
- **Command Validation**: Checks executable permissions before attempting execution

### Built-in Commands

Built-in commands are implemented in `src/builtins/`:

- **echo**: Supports `-n` flag to suppress newline
- **cd**: Directory navigation with path resolution:
  - Supports relative and absolute paths
  - Updates PWD and OLDPWD environment variables
  - Handles HOME directory when no argument is provided
- **pwd**: Returns current working directory using getcwd
- **export**: Environment variable management:
  - Variable name validation according to POSIX standards
  - Sorted environment variable display
  - Proper handling of quotes in variable values
- **unset**: Removes variables from environment with protection for system variables
- **env**: Lists all environment variables
- **exit**: Shell termination with optional status code:
  - Validates numeric arguments
  - Handles error cases for non-numeric input

### Signal Handling

Signal handling is implemented in `src/signals/signals.c`:

- **SIGINT (Ctrl+C)**: Interrupts current command execution
- **SIGQUIT (Ctrl+\\)**: Ignored in interactive mode, terminates with core dump in child processes
- **Custom Signal Behavior**: Different signal behaviors in parent shell vs child processes
- **Readline Integration**: Proper interaction with readline library for signal handling

### Redirection Implementation

File redirection is handled in `src/execution/redirection_handling.c`:

- **Input Redirection (`<`)**: Redirects file content to command stdin
- **Output Redirection (`>`)**: Redirects command stdout to file (truncate)
- **Append Redirection (`>>`)**: Redirects command stdout to file (append)
- **File Descriptor Management**: Proper handling of file descriptors using dup2
- **Permission Checking**: Validates file permissions before attempting redirection

### Pipe Implementation

Pipe handling is implemented in `src/execution/setup_pipes.c`:

- **Pipe Creation**: Uses pipe() system call to create communication channels
- **Process Management**: Creates multiple processes connected by pipes
- **File Descriptor Redirection**: Connects stdout of one process to stdin of another
- **Pipeline Execution Flow**: Ensures proper execution order in pipelines
- **Exit Status Propagation**: Captures exit status from the last command in the pipeline

### Environment Variable Management

Environment management is implemented across multiple files:

- **Environment Initialization**: Creates a copy of the system environment
- **Variable Lookup**: Fast variable retrieval by name
- **Variable Setting**: Validation and storage of new variables
- **Variable Expansion**: Replaces $VAR with its value during command processing
- **Special Variables**: Handling of special variables like $? (exit status)

### Memory Management

Custom memory management to prevent leaks:

- **Safe Allocation**: Wrapper functions for malloc in `utils_mem.c`
- **Systematic Deallocation**: Structured cleanup of data structures
- **Resource Tracking**: Tracking allocated resources for proper cleanup
- **Leak Prevention**: Careful free() calls throughout the codebase

### Error Handling

Comprehensive error handling approach:

- **Syntax Errors**: Detected during parsing (unclosed quotes, invalid redirections)
- **Execution Errors**: Command not found, permission denied, etc.
- **System Call Errors**: Checking return values of all system calls
- **Error Reporting**: User-friendly error messages with appropriate context
- **Exit Status Codes**: Standards-compliant exit codes for different error types

## 📁 Project Structure

The project follows a modular organization:

- **src/**: Main source files
  - **builtins/**: Built-in command implementations
    - `ft_echo.c`: Echo command implementation
    - `ft_cd.c`: Directory change implementation
    - `ft_pwd.c`: Working directory display
    - `ft_export.c`: Environment variable setting
    - `ft_unset.c`: Environment variable removal
    - `ft_env.c`: Environment variable listing
    - `ft_exit.c`: Shell exit implementation
  - **execution/**: Command execution logic
    - `execute_ast.c`: AST traversal and execution
    - `execute_cmd.c`: Command execution
    - `setup_pipes.c`: Pipe implementation
    - `env_handle.c`: Environment management
    - `get_set_env.c`: Environment variable utilities
    - `exec_cmd.c`: External command execution
    - `exec_utils.c`: Execution utilities
    - `redirection_handling.c`: File redirection implementation
  - **lexer/**: Lexical analysis
    - `lexer_init.c`: Lexer initialization
    - `lexer_token.c`: Token creation and management
    - `lexer_word.c`: Word token handling
    - `lexer_utils.c`: Lexer utilities
    - `lexer_expand.c`: Variable expansion
    - `tokenizer.c`: Token stream generation
  - **parser/**: Syntax analysis and AST construction
    - `parser.c`: Main parsing logic
    - `utilslist.c`: List utilities for token processing
    - `parser_utils.c`: Parser helper functions
  - **signals/**: Signal handling
    - `signals.c`: Signal handler implementations
  - **input_validation/**: Input checking and validation
    - `input_validation.c`: Input syntax validation
    - `input_validation_utils.c`: Validation utilities
  - **utils/**: General utilities
    - `utils.c`: General utility functions
    - `utils_mem.c`: Memory management utilities
    - `printbanner.c`: UI elements
    - `token_utils.c`: Token manipulation utilities
- **includes/**: Header files
  - `minishell.h`: Main header with data structures
  - `lexer.h`: Lexer definitions
  - `parsing.h`: Parser definitions
  - `builtins.h`: Built-in command declarations
  - `utils.h`: Utility function declarations
- **libraries/libft/**: Custom C library implementation

## 🔧 Technical Challenges & Solutions

1. **Quote Handling**: 
   - Challenge: Properly handling nested quotes and variable expansion inside quotes
   - Solution: Implemented a state machine to track quote context and selectively perform variable expansion

2. **Pipe Implementation**:
   - Challenge: Creating proper process hierarchy and connecting standard I/O
   - Solution: Careful file descriptor management and process synchronization

3. **AST Construction**:
   - Challenge: Converting a linear token stream into a hierarchical command structure
   - Solution: Implemented a recursive descent parser with proper precedence rules

4. **Environment Variable Expansion**:
   - Challenge: Expanding variables at the right time in the processing pipeline
   - Solution: Two-phase approach with initial expansion during lexing and final resolution during execution

5. **Memory Management**:
   - Challenge: Preventing memory leaks in a complex application
   - Solution: Systematic allocation/deallocation patterns and resource tracking

6. **Signal Handling**:
   - Challenge: Different signal behaviors in interactive mode vs command execution
   - Solution: Context-aware signal handlers and proper terminal state management

7. **Error Recovery**:
   - Challenge: Recovering from errors without crashing the shell
   - Solution: Comprehensive error checking and graceful fallback mechanisms

## 👥 Contributors

This project was developed by:
- kmoundir ([@kmoundir](https://github.com/kmoundir))
- rjaada ([@rjaada](https://github.com/rjaada))

---

Minishell represents a deep dive into system programming concepts including process management, file descriptors, signal handling, and parsing techniques. The implementation provides a solid foundation for understanding how shells work internally while offering a functional command-line interface.
