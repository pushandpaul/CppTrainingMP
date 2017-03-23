Steps in creating projects in CMake

1. Imitate the folder structure

<project-name>
|__build
|__include
|__source

build - will hold the .exe and CMake binaries
include - will hold header files (.h)
source - will hold the codes (.cpp)

2. Open Cmake-GUI.

3. Change the path of the source code to the project directory.

4. Change the path of the build binaries to: <project directory path>/build

5. Press generate. This will create CMake binaries and project files

Compiling and Building

1. Go to the build binaries path via cmd.

2. Use the "mingw32-make" to compile the file/s. 

3. After compiling, the .exe file will now appear on the build folder of the project.