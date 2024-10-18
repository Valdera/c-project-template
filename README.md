# C++ Project Template

![C++](https://img.shields.io/badge/C%2B%2B-20%2F23-blue)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Linux Build](https://github.com/Valdera/c-project-template/workflows/Ubuntu%20CI%20Test/badge.svg)
[![codecov](https://codecov.io/gh/Valdera/c-project-template/branch/main/graph/badge.svg)](https://codecov.io/gh/Valdera/cpp-project-template)

Clone this repository

```bash
git clone --recursive git@github.com:Valdera/Maker.git
```

Initialize `pre-commit`

```bash
pre-commit install
```

## Software Requirements

- CMake 3.16+
- GNU Makefile
- Doxygen
- Conan or VCPKG
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)
- Code Coverage (only on GNU|Clang): lcov, gcovr
- Recommended code editor: [CLion](https://www.jetbrains.com/clion/)

## Project Structure

Project is structured as follows:

``` text
├── CMakeLists.txt
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── src
│   ├── apps
│   │   ├── app1
│       │   ├── CMakesLists.txt
│   │   │   ├── app1.cpp
│   │   │   └── include
│   │   │       └── app1.h
│   │   ├── ...
│   └── libs
│       ├── lib1
│       │   ├── CMakesLists.txt
│       │   ├── lib1.cpp
│       │   └── include
│       │       └── lib1.h
│       ├── ...
└── tests
    ├── apps
    │   ├── app1
    │   │   ├── CMakesLists.txt
    │   │   ├── app1_test.cpp
    │   ├── ...
    └── libs
        ├── lib1
        │   ├── CMakesLists.txt
        │   ├── lib1_test.cpp
        ├── ...
```

Library code goes into [src/](src/), main program code in [app/](app) and tests go in [tests/](tests/).

## Getting Started

### Build Project

Initialize cmake project

```bash
cmake -S <SOURCE PATH> -B <BUILD PATH> -G <GENERATOR> -DCMAKE_BUILD_TYPE=<BUILD TYPE> ..
```

Build project

```bash
cmake --build ./build --target
```

### Installing Dependencies

#### Using Git Submodule

1. Add submodule

    ```bash
    git submodule add ${github_repo_link} external/${lib_name}
    ```

   Example:

   ```bash
   git submodule add https://github.com/nlohmann/json.git external/json
   ```

2. Lists the dependency in the root `CMakeLists.txt`

    ```cmake
    add_git_submodule(external/${lib_name})
    ```

   Example:

   ```cmake
   add_git_submodule(external/json)
   ```

#### Using Fetch Content

1. Lists the dependency in the root `CMakeLists.txt`

   ```cmake
   FetchContent_Declare(
       ${package_name}
       GIT_REPOSITORY ${git_repository_url}
       GIT_TAG ${git_tag_version}
       GIT_SHALLOW TRUE)
   FetchContent_MakeAvailable(${package_name})
   ```

   Example:

   ```cmake
   FetchContent_Declare(
       nlohmann_json
       GIT_REPOSITORY https://github.com/nlohmann/json
       GIT_TAG v3.11.3
       GIT_SHALLOW TRUE)
   FetchContent_MakeAvailable(nlohmann_json)
   ```

#### Using CPM

1. Lists the dependency in the root `CMakeLists.txt`

   ```cmake
   cpmaddpackage("gh:<git username>:<git repo name>#<version number>")
   ```

   Example:

   ```cmake
   cpmaddpackage("gh:nlohmann:json#3.11.3")
   ```

#### Using Conan

1. Lists the dependency in `conanfile.py`

   ```python
   def requirements(self):
       self.requires("${package_name}/${package_version}")
   ```

   Example:

   ```python
   def requirements(self):
       self.requires("nlohmann_json/3.11.3")
   ```

##### Using VCPKG

1. Lists the dependency in `vcpkg.json`

   ```json
   {
      ...,
      "dependencies": [
         ...,
         {
            "name": "${package_name}",
            "version>=": "${package_version}"
         },
         ...
      ]
   }
   ```

   Example:

   ```json
   {
      ...,
      "dependencies": [
         ...,
         {
            "name": "nlohmann-json",
            "version>=": "3.11.3"
         },
         ...
      ]
   }
   ```

## Different Linking Types

```cmake
add_library(A ...)
add_library(B ...)
add_library(C ...)
```

### PUBLIC

```cmake
target_link_libraries(A PUBLIC B)
target_link_libraries(C PUBLIC A)
```

When A links in B as *PUBLIC*, it says that A uses B in its implementation, and B is also used in A's public API. Hence,
C can use B since it is part of the public API of A.

### PRIVATE

```cmake
target_link_libraries(A PRIVATE B)
target_link_libraries(C PRIVATE A)
```

When A links in B as *PRIVATE*, it is saying that A uses B in its
implementation, but B is not used in any part of A's public API. Any code
that makes calls into A would not need to refer directly to anything from
B.

### INTERFACE

```cmake
add_library(D INTERFACE)
target_include_directories(D INTERFACE {CMAKE_CURRENT_SOURCE_DIR}/include)
```

In general, used for header-only libraries.

## Shared Library vs Static Library

Shared libraries and static libraries are two different types of libraries used in programming to manage and reuse code.
Here’s a detailed comparison:

### Shared Library

- **Definition:** A shared library (also known as a dynamic library) is a collection of functions and data that can be
  loaded and linked into an application at runtime.

- **File Extensions:**
    - **Windows:** `.dll` (Dynamic Link Library)
    - **Linux:** `.so` (Shared Object)
    - **macOS:** `.dylib` (Dynamic Library)

- **Characteristics:**
    - **Dynamic Linking:** Shared libraries are linked to the application at runtime rather than at compile-time. This
      means that the library code is loaded into memory when the application starts or when it's needed.
    - **Single Copy:** Only one copy of the shared library is loaded into memory, regardless of how many programs use
      it. This can save memory and reduce the size of executable files.
    - **Update Flexibility:** If you need to update or fix a bug in the library, you can replace the shared library
      without recompiling the applications that use it, as long as the interface remains compatible.
    - **Versioning:** Shared libraries often support versioning, allowing different applications to use different
      versions of the same library if needed.

- **Usage:**
    - **Memory Efficiency:** Shared libraries are useful for large projects or systems where multiple applications use
      the same library, as they reduce memory usage and disk space.
    - **Plugin Systems:** They are commonly used for plugins or modules that can be dynamically loaded and unloaded.

### Static Library

- **Definition:** A static library is a collection of functions and data that are linked into an application at
  compile-time. The code from the static library becomes part of the final executable.

- **File Extensions:**
    - **Windows:** `.lib`
    - **Linux:** `.a` (Archive)
    - **macOS:** `.a` (Archive)

- **Characteristics:**
    - **Static Linking:** Static libraries are linked directly into the application at compile-time. This means that the
      library code is copied into each executable that uses it.
    - **Separate Copies:** Each executable that uses a static library contains its own copy of the library code, which
      can lead to larger executable files.
    - **Update Inflexibility:** If you need to update the library, you must recompile all the applications that use it,
      as the library code is baked into the executables.

- **Usage:**
    - **Self-contained Executables:** Static libraries are useful when you want to create a self-contained executable
      that does not depend on external libraries at runtime.
    - **Simpler Deployment:** There are no runtime dependencies on external library files, which can simplify
      deployment, especially on systems where shared libraries may not be available.

### Summary

- **Shared Libraries** are more memory-efficient and flexible for updates but require runtime linking and are subject to
  versioning issues.
- **Static Libraries** provide self-contained executables and simpler deployment but can lead to larger executable sizes
  and require recompilation for updates.

Choosing between shared and static libraries depends on factors like memory efficiency, deployment requirements, and
update flexibility.

## Important CMake Variables for Paths

- `CMAKE_SOURCE_DIR`
    - Topmost folder (source directory) that contains a CMakeList.txt file.
- `PROJECT_SOURCE_DIR`
    - Contains the full path to the root of your project source directory.
- `CMAKE_CURRENT_SOURCE_DIR`
    - The directory where the currently processed CMakeLists.txt is located in.
- `CMAKE_CURRENT_LIST_DIR`
    - The directory of the listfile currently being processed. (for example a \*.cmake Module)
- `CMAKE_MODULE_PATH`
    - Tell CMake to search first in directories listed in CMAKE_MODULE_PATH when you use FIND_PACKAGE() or INCLUDE().
- `CMAKE_BINARY_DIR`
    - The filepath to the build directory

## Things you can set on targets

- `target_link_libraries`: Other targets; can also pass library names directly
- `target_include_directories:` Include directories
- `target_compile_features`: The compiler features you need activated, like cxx_std_11
- `target_compile_definitions`: Definitions
- `target_compile_options`: More general compile flags
- `target_link_directories`: Don’t use, give full paths instead (CMake 3.13+)
- `target_link_options`: General link flags (CMake 3.13+)
- `target_sources`: Add source files

## Custom Targets and Commands

- When is needed to use `add_custom_target`?

  Each time we need to run a command to do something in our build system different to build a library or an executable.

- When is a good idea to run a command in `add_custom_target`?

  When the command must be executed always the target is built.

- When is a good idea to use `add_custom_command`?

  We always want to run the command when is needed: if we need to generate a file (or more) or regenerate it if
  something changed in the source folder.

- When is a good idea to use `execute_process`?
  Running a command at configure time.

## Tools Installation

### Mandatory Tools

#### Ubuntu

- Install Python3 (>=3.4)
- Install these packages

    ```bash
    sudo apt-get install gcc
    sudo apt-get install g++
    sudo apt-get install gdb
    sudo apt-get install make
    sudo apt-get install cmake
    sudo apt-get install git
    sudo apt-get install doxygen
    ```

#### MacOS

- Install Python3 (>=3.4)
- Install [Homebrew](https://brew.sh/)
- Install these packages

    ```bash
    brew install git
    brew install make
    brew install cmake
    brew install doxygen
    ```

#### Windows

- Install Python3 (>=3.4)
- Install [Chocolatey](https://chocolatey.org/)
- Install these packages

    ```bash
    choco install cmake
    choco install git
    choco install doxygen.install
    choco install python
    choco install make
    choco install llvm
    ```

### Conan Package Manager Installation

> Official installation guide is [here](https://docs.conan.io/en/latest/installation.html)
>
> The conan database is [here](https://conan.io/center/)

#### Ubuntu

1. Install Python3 (>=3.4)
2. Type ``pip install --user conan==1.59`` into the terminal
3. Append conan to the PATH by: ``source ~/.profile``
4. Type ``conan user`` into the terminal
5. Run the conan command: ``conan``

#### MacOS:

1. Install Python3 (>=3.4)
2. Type ``pip install --user conan==1.59`` into the terminal
3. Append conan to the PATH by: ``source ~/.profile``
4. Type ``conan user`` into the terminal
5. Run the conan command: ``conan``

#### Windows:

1. Install Python3 (>=3.4)
2. Type ``pip install --user conan=`` into the terminal
3. Type ``conan user`` into the terminal
4. Run the conan command: ``conan``

### VCPKG Installation

> Official docs is [here](https://vcpkg.io/en/index.html)

#### Linux and MacOS

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
```

#### Windows

```cmd
cd external
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
```

### LTO and CCache Installation

- [LTO](https://llvm.org/docs/LinkTimeOptimization.html): Link Time Optimization (LTO) is another name for intermodular
  optimization when performed during the link stage.

- [Ccache](https://github.com/ccache/ccache): Ccache (or “ccache”) is a compiler cache. It speeds up recompilation by
  caching previous compilations and detecting when the same compilation is being done again.

#### Ubuntu

```bash
sudo apt-get install ccache
```

#### MacOS

```bash
brew install ccache
```

#### Windows

```bash
choco install ccache
```

### Formatter and Static Analyzer Installation

- [Clang-Format](https://clang.llvm.org/docs/ClangFormat.html): Formatting tool for your C/C++ code
- [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/): Static linting tool for your C/C++ code
- [Cppcheck](https://github.com/danmar/cppcheck): Static linting tool for your C/C++ code

#### Ubuntu

```bash
sudo apt-get install clang-format
sudo apt-get install clang-tidy
sudo apt-get install cppcheck
```

#### MacOS

```bash
brew install clang-format
brew install clang-tidy
brew install cppcheck
```

#### Windows

```bash
choco install llvm
choco install cppcheck
```

### Code Coverage Installation

Tools only for linux and mac.

#### Ubuntu

```bash
sudo apt-get install gcovr
sudo apt-get install lcov
```

#### MacOS

```bash
brew install gcovr
brew install lcov
```

## Setting Up CLion

1. Set Python Interpreter
    - Go to `File > Settings > Build, Execution, Deployment > Python Interpreter`
    - Set python interpreter with your installed python path (use `which python` to check)

2. Install conan plugin
    - Set conan path with your installed conan path (use `which conan` to check)

3. Enable ClangFormat
    - Select the Enable ClangFormat checkbox in `Settings > Editor > Code Style`

5. Add these cmake options in cmake configurations:

    ```bash
    -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES="conan_provider.cmake" -DCONAN_COMMAND="/home/{name}/.local/bin/co
    ```
