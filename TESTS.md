# Running tests

This project uses CMake and GoogleTest (downloaded automatically via CMake FetchContent).

Build and run the tests from the project root:

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -- -j
ctest --output-on-failure
```

If you don't have CMake >= 3.14, install/upgrade it before running the above.

## Running tests inside the development container

The `.devcontainer/Dockerfile` builds an image that pre-installs build tools and GoogleTest so you can run tests without needing to download GoogleTest at build time.

Build the container image from the project root:

```bash
cd .devcontainer
docker build -t mydockerproject-dev .
cd ..
```

Run an interactive container that mounts your repository and opens a shell:

```bash
docker run --rm -it -v "$(pwd):/workspaces/mydockerproject" -w /workspaces/mydockerproject mydockerproject-dev bash
```

Inside the container run the same CMake/test steps:

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -- -j
ctest --output-on-failure
```

If your environment doesn't have Docker, you can still use the non-container instructions above.
