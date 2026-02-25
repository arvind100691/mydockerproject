# Use an official Ubuntu as a base image
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /app

# Install necessary packages: build-essential for g++ and git
# -y confirms installation
# apt-get update refreshes the list of available packages
# apt-get install installs new packages
RUN apt-get update && \
    apt-get install -y build-essential git && \
    rm -rf /var/lib/apt/lists/*

# Copy the current directory (your Git repo) into the container
# This will copy everything in the directory where the Dockerfile is located
#COPY . .

# Command to run when the container starts
# This will compile and run your C++ program
CMD ["bash", "-c", "g++ main.cpp -o main && ./main"]