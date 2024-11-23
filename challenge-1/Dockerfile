# Use an official Ubuntu base image
FROM ubuntu:20.04

# Install the necessary dependencies for compiling C code, socat, and netcat
RUN apt-get update && \
    apt-get install -y build-essential netcat socat

# Copy your C source code and flag.txt into the container
COPY l2.c /sbudayya/l2.c
COPY flag.txt /sbudayya/flag.txt

# Set the working directory
WORKDIR /sbudayya

# Compile the C source code into a binary called 'l2'
RUN gcc -o l2 l2.c

# Expose the port on which the container will listen
EXPOSE 12345
# PUBLISH 12345 AS port

# Create the start.sh script to start socat listener and execute the 'l2' binary
RUN echo '#!/bin/bash\n\
set -e\n\
socat tcp-listen:12345,reuseaddr,fork EXEC:/sbudayya/l2,stderr' > /opt/start.sh

# Make the start.sh script executable
RUN chmod +x /opt/start.sh

# Now create the special /challenge directory
RUN mkdir /challenge && \
    chmod 700 /challenge

# Create secret challenge metadata
RUN echo "{\"flag\":\"$(cat flag.txt)\"}" > /challenge/metadata.json

# Create artifacts needed. You need to update problem.md
# RUN tar czvf /challenge/artifacts.tar.gz l2.c

# Set the command to run the start.sh script when the container starts
CMD ["/opt/start.sh"]
