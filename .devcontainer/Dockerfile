# Use an official Ubuntu as a base image
FROM ubuntu:latest

# Avoid interactive prompts during package installs
ENV DEBIAN_FRONTEND=noninteractive

# Set the working directory inside the container
WORKDIR /app

# Recommended VS Code extensions for this C/C++ project (IDs):
# - ms-vscode.cpptools            (C/C++ Intellisense/debugging)
# - ms-vscode.cmake-tools        (CMake integration)
# - llvm-vs-code-extensions.vscode-clangd (clangd language server)
# These are just recommendations; to enable them in a devcontainer, add
# them to a `devcontainer.json` under the `extensions` property.

# Install common development tools for C/C++ projects so the container is
# ready for building, linting, and debugging.
# Packages installed:
#  - build-essential : gcc/g++ toolchain
#  - git             : source control
#  - cmake           : build system generator
#  - clang-format    : code formatting
#  - clang-tidy      : static analysis
#  - clangd          : language server
#  - gdb             : debugger
#  - valgrind        : memory checking
#  - ninja-build     : fast build tool
#  - lcov            : code coverage tool
#  - ca-certificates/wget : for fetching remote resources if needed
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        git \
        cmake \
        clang-format \
        clang-tidy \
        clangd \
        gdb \
        valgrind \
        ninja-build \
        lcov \
        wget \
        ca-certificates && \
    rm -rf /var/lib/apt/lists/*

# Copy the current directory (your Git repo) into the container
# NOTE: left commented per your request — uncomment if you want source copied
#COPY . .

# Default command: compile and run your C++ program if present
CMD ["bash", "-c", "g++ main.cpp -o main && ./main"]