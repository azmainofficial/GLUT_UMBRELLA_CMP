# 2D Umbrella using OpenGL GLUT in C++

This is a simple OpenGL project that renders a 2D umbrella using the GLUT library in C++. The project is designed to run in Code::Blocks.

## Prerequisites

Before running this project, ensure you have the following installed:
- [Code::Blocks](https://www.codeblocks.org/downloads/) with MinGW compiler
- OpenGL Utility Toolkit (GLUT)

## Setting Up GLUT in Code::Blocks

1. Download `glut.h`, `glut32.lib`, and `glut32.dll` from [GLUT Library](http://www.opengl.org/resources/libraries/glut/).
2. Copy `glut.h` to `C:\Program Files\CodeBlocks\MinGW\include\GL` (create the `GL` folder if it doesn’t exist).
3. Copy `glut32.lib` to `C:\Program Files\CodeBlocks\MinGW\lib`.
4. Copy `glut32.dll` to `C:\Windows\System32` (or `C:\Windows\SysWOW64` for 64-bit systems).

## Running the Project in Code::Blocks

1. Open Code::Blocks and create a new **Console Application** with **C++**.
2. Go to **Project** > **Build Options**.
3. Under the `Linker settings` tab, add the following libraries:
   - `opengl32`
   - `glu32`
   - `glut32`
4. Write your GLUT C++ code or paste the provided source code.
5. Click **Build and Run** to execute the program.

## Expected Output

The program will display a simple 2D umbrella on the OpenGL window.

## Troubleshooting

- If you get `undefined reference to glut...` errors, ensure you correctly linked `glut32` in the linker settings.
- If the program crashes on startup, verify that `glut32.dll` is placed in the correct system directory.

## License

This project is open-source. Feel free to modify and distribute it as needed.

---

Happy Coding! 🚀

