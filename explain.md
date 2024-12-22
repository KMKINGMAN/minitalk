# Minitalk Project Explanation

## Project Overview
Minitalk is an inter-process communication project that implements a client-server system using UNIX signals. The project demonstrates low-level system programming concepts and bit manipulation.

## Technical Implementation

### 1. Signal Handling
The project uses two UNIX signals:
- `SIGUSR1`: Represents binary 0
- `SIGUSR2`: Represents binary 1

### 2. Memory Management
The project includes a custom garbage collector with three main components:

#### Garbage Collector Structure
```c
typedef struct s_memory_block {
    void *ptr;                  // Pointer to allocated memory
    struct s_memory_block *next;// Next block in linked list
    int status;                 // Block status
} t_memory_block;
```

#### Key Functions:
- `gc_malloc`: Safe memory allocation with tracking
- `gc_free`: Memory deallocation with list management
- `gc_finish`: Automatic cleanup on program exit
- `gc_realloc`: Safe memory reallocation

### 3. Client Implementation
The client performs these steps:
1. Validates server PID
2. Converts message to binary
3. Sends each bit using signals:
   - SIGUSR1 for 0
   - SIGUSR2 for 1
4. Waits for acknowledgment

### 4. Server Implementation
The server:
1. Displays its PID on startup
2. Sets up signal handlers
3. Reconstructs messages bit by bit
4. Sends acknowledgment signals
5. Handles multiple clients

## Code Structure

### Main Components

1. **Client (`src/client.c`)**
```c
// Key operations:
- Parse command line arguments
- Convert string to binary
- Send signals to server
- Handle acknowledgments
```

2. **Server (`src/server.c`)**
```c
// Key operations:
- Display PID
- Set up signal handlers
- Reconstruct messages
- Handle multiple clients
```

3. **Garbage Collector (`gc_collector/`)**
```c
// Key features:
- Memory tracking
- Automatic cleanup
- Memory leak prevention
- Safe reallocation
```

### Build System
The project uses a sophisticated Makefile system:
- Multiple targets (client, server, bonus versions)
- Automatic dependency generation
- Multiple build modes (release, debug, valgrind)
- Library management (libft, gc_collector)

## Error Handling

1. **Signal Errors**
   - Invalid PID handling
   - Signal delivery failures
   - Timeout management

2. **Memory Errors**
   - Allocation failures
   - Memory leaks prevention
   - Buffer overflow protection

3. **Input Validation**
   - PID validation
   - Message format checking
   - Command line argument validation

## Bonus Features

1. **Unicode Support**
   - Handles multi-byte characters
   - Preserves character encoding

2. **Multiple Clients**
   - Server can handle multiple simultaneous clients
   - Message queuing system
   - Client identification

## Testing

### Test Cases
1. Basic functionality:
   ```bash
   ./server
   ./client [server_pid] "Hello, World!"
   ```

2. Unicode testing:
   ```bash
   ./client [server_pid] "Hello 👋 World 🌍"
   ```

3. Large messages:
   ```bash
   ./client [server_pid] "$(cat large_file.txt)"
   ```

### Memory Testing
```bash
make BUILD=valgrind
valgrind --leak-check=full ./server
valgrind --leak-check=full ./client [pid] "message"
```

## Common Issues and Solutions

1. **Signal Loss**
   - Implementation of acknowledgment system
   - Signal queueing mechanism
   - Timeout and retry logic

2. **Memory Management**
   - Use of garbage collector
   - Regular memory cleanup
   - Memory usage optimization

3. **Performance**
   - Efficient bit manipulation
   - Optimized signal handling
   - Minimal system calls

## Future Improvements

1. Enhanced error reporting
2. Better signal synchronization
3. Performance optimizations
4. Extended character support
5. Network protocol implementation
