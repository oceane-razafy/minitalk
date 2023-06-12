# Minitalk

This project is part of the curriculum at 42 school and focuses on interprocess communication using signals. The project involves creating a client-server architecture where the client sends messages to the server using signals, and the server receives and displays the messages.

## Table of Contents

- [Project Description](#project-description)
- [Installation](#installation)
- [Usage](#usage)
- [Protocol](#protocol)

## Project Description

The "Minitalk" project aims to create a client and server program that can communicate with each other using signals. The main objectives of the project are:

1. Implementing a server program that waits for incoming messages from the client.
2. Implementing a client program that sends messages to the server.
4. Handling signals to transfer and decode messages between the client and server.
5. Understanding and utilizing bit manipulation techniques for transmitting and reconstructing messages.

## Installation

To install and run the "Minitalk" program, follow these steps:

1. Clone the repository to your local machine:

```
git clone <repo url> minitalk
```

2. Navigate to the project directory:

```
cd minitalk
```

3. Build the server and client programs by running the make command:

```
make
```

4. The executable files, `server` and `client`, will be created in the `bin` directory.

## Usage

To use the "Minitalk" program, follow these steps:

1. Start the server by running the `server` executable:

```
./bin/server
```

2. The server will display its process ID (PID) after starting.

3. In a separate terminal, start the client by running the `client` executable, providing the server's PID as an argument:

```
./bin/client server_pid message
```

- `server_pid`: The process ID of the server obtained from step 2.
- `message`: The message to send to the server.

4. The client will send the message to the server using signals.

5. The server will receive and display the message.

6. Repeat step 3 to send additional messages.

7. Press `Ctrl + C` in the server terminal to stop it.

## Protocol

The "Minitalk" program uses a simple protocol for interprocess communication using signals. Here is a brief overview of the protocol:

- For each bit of the ASCII representation of a character, the client sends a signal to the server.
- The server receives the signals and reconstructs the ASCII representation of this character.
- The server displays the received message.