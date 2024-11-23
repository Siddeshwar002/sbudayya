# CTF Challenge: Lottery Binary

## Description

In this challenge, you need to interact with a C binary 
that has a vulnerability. Your goal is to exploit it and 
retrieve the flag. You will connect to the service using 
netcat on a specific port and execute the binary to solve 
the challenge.

## How It Is Built

This challenge is packaged in a Docker container that:
1. Compiles the C source code (`l2.c`) into a binary (`l2`).
2. Exposes port `12345` and listens for connections.
3. Uses `socat` to forward incoming connections on that 
   port to the `l2` binary.
4. Executes the binary when a connection is made.

The flag file (`flag.txt`) is inside the container and is 
available once the binary is successfully exploited.

## How to Host the CTF Using Docker and let other play

1. Clone or download this repository.
2. Build the Docker image:
   ```bash
   docker build -t sbudayya .
