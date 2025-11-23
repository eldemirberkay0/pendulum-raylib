# Pendulum Raylib
A basic multi-arm-pendulum like simulation written in C with Raylib.
CMake script automatically downloads raylib and links all the libraries to the main program.

## How to Compile
### Prerequisites
* CMake
* A build system (make, ninja)
* Any C compiler
***
First, clone the repo
```
git clone https://github.com/eldemirberkay0/pendulum-raylib.git
```

If you have a UNIX system or a bash installed to your Windows you can just do,
```
cd pendulum-raylib
bash build.sh
```
And it will compile the project and open the .exe file.
Other compile options without the build.sh:

### Windows
```
cd pendulum-raylib
mkdir build
cd build
cmake ..
cmake --build .
pendulum_raylib.exe
```

### Linux (Debian/Ubuntu)
```
# libgtk-3-dev is required
sudo apt update
sudo apt install libgtk-3-dev -y
cd pendulum-raylib
mkdir build
cd build
cmake ..
cmake --build .
./pendulum_raylib
```

### MacOS
```
cd pendulum-raylib
mkdir build
cd build
cmake ..
cmake --build .
find build -name pendulum_raylib -type f -perm +111 -print -exec {} \;
```

## How to Use Project
![Project View](https://drive.google.com/file/d/19fq9Tb3EdR_JuYyI111BNgK2DBWH4I9Y/view?usp=drive_link)