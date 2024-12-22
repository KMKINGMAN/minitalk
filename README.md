# Minitalk

A small data exchange program using UNIX signals.

## Description

Minitalk is a communication program in the form of a client and server. The server must be started first and prints its PID. The client takes two parameters:
- The server PID
- The string to send

The communication between client and server is done using only UNIX signals: SIGUSR1 and SIGUSR2.

## Features

- Server displays its PID on launch
- Server can receive strings from multiple clients
- Client can send strings to server
- Memory-safe implementation with garbage collection
- Support for all characters (including Unicode)
- Clean signal handling

## Requirements

- GCC compiler
- Make
- Unix-based OS (Linux/MacOS)

## Installation

```bash
git clone <repository-url>
cd minitalk
make
```

## Usage

1. Start the server:
```bash
./bin/server
```

2. Note the displayed PID

3. Send a message using the client:
```bash
./bin/client [server-pid] "Your message here"
```

## Project Structure

```
minitalk/
├── src/           # Source files
├── include/       # Header files
├── libft/         # Library with utility functions
├── gc_collector/  # Memory management
├── bin/           # Compiled binaries
└── obj/           # Object files
```

## Memory Management

The project includes a custom garbage collector that:
- Tracks all memory allocations
- Automatically frees memory on program exit
- Prevents memory leaks
- Provides safe memory reallocation

## Technical Details

- Signals used: SIGUSR1 and SIGUSR2
- Bit-by-bit transmission of messages
- Error handling for invalid PIDs and signal failures
- Unicode character support

## Compilation Flags

- Regular: `make`
- Debug mode: `make BUILD=debug`
- Memory check: `make BUILD=valgrind`

## Author

- mkurkar

## License

This project is part of the 42 School curriculum.
