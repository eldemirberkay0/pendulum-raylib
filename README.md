# Pendulum Raylib
A basic pendulum like simulation written in C with Raylib. All circles are connected to each other with a solid line and rotating at a fixed angular speed around previous ones.
<p align="left">
  <img src="https://github-production-user-asset-6210df.s3.amazonaws.com/99734746/530541642-335945b7-dada-47a5-a767-8b0a2e54bc0c.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAVCODYLSA53PQK4ZA%2F20251228%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20251228T112836Z&X-Amz-Expires=300&X-Amz-Signature=e8d6e43f1d60b05fdd30555df06ab6f4bed24215ecc2df73cd6a3d8b67a3be60&X-Amz-SignedHeaders=host" width="50%" title="Pendulum Preview">
</p>

## Features
* **GUI Control Panel:** Add/Remove circles using the buttons in the control panel GUI. You can add circles with spesific or random parameters like radius, rod length, angular speed and color. Also control the visibility of lines and outlines.

* **Zooming Controls:** Use the mouse wheel (or the gui slider) to zoom in/zoom out

* **Pause:** Press **"Space"** to pause/unpause the game

### My Favourite Feature: Save/Load System
If you created a good-looking pendulum pattern and  don't want to lose it, you can save it to anywhere you want in your computer with the **"Save"** button. Then, you can load your save files with the **"Load"** button and continue to work on it or just watch the scene.

Note: Save file format is  **JSON** format. There are some example saves in /saves directory.

## How to Compile
### Prerequisites
* CMake
* A build system (make, ninja etc.)
* Any C compiler
***

Firstly, clone the repo
```
git clone https://github.com/eldemirberkay0/pendulum-raylib.git
```

If you have a UNIX system or a bash installed to your Windows you can just do,
```
cd pendulum-raylib
bash build.sh
```
And it will compile the project and open the compiled program.
Other compile options without the build.sh:

### Windows
```
cd pendulum-raylib
mkdir build
cd build
cmake ..
cmake --build .
.\pendulum_raylib.exe
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
./pendulum_raylib
```

*** 
*CMake script automatically downloads raylib and links all the libraries to the main program.*