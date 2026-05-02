This project has been created as part of the 42 curriculum by tphuwian.
# Minitalk

# Description
Minitalk is a small data exchange program built as part of the 42 curriculum. The goal of this project is to create a communication system between two processes: a Client and a Server. The communication must be established using only UNIX signals (`SIGUSR1` and `SIGUSR2`).

The Client takes a string of text, converts it into binary (bitwise operations), and sends it to the Server signal by signal. The Server listens for these signals, reassembles the binary bits back into characters, and prints the message to the standard output.

## Instructions

### Compilation
A `Makefile` is provided to compile the source files. It uses `cc` with the standard 42 flags (`-Wall -Wextra -Werror`).
To compile both the server and the client, simply run:

# Execution

Start the Server:
Run the server executable first. It will start running, display its Process ID (PID), and wait for incoming signals.

Bash
./server
<!--Example Output: Server PID: 12345-->

Send a Message via the Client:
Open a new terminal window. Run the client executable, providing the Server's PID and the message you want to send as arguments.

Bash
./client <SERVER_PID> "<Your Message>"
<!--Example: ./client 12345 "Hello, 42 Bangkok!"-->

Check the Output:
<!--Return to the terminal window running the server to see your message successfully printed.-->

# Resources
Documentation & References:

1. man 2 kill - Sending signals to processes.

2. man 2 sigaction - Examining and changing a signal action.

3. man 2 pause - Waiting for a signal.

Digital System Design (DSD) principles for understanding bitwise shift operations (<<, >>, |, &).

# AI Usage:
AI (Google Gemini) was utilized during the development of this project primarily as a learning assistant and debugging partner. Specifically, AI was used for:

1. Concept Visualization: Helping to break down and visualize the logic of converting characters to bits and reconstructing them using bitwise operations.

2. Code Debugging: Assisting in identifying minor syntax errors, variable naming typos, and refining the Makefile structure.

3. Logic Verification: Discussing the importance of usleep() for signal stability and verifying the correct mapping of SIGUSR1 and SIGUSR2 to binary 0 and 1.