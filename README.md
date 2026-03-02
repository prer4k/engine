# OpenGL Playground

Small modern OpenGL playground with a simple renderer-style architecture.

Built with:

- GLFW — window + OpenGL context
- GLAD — OpenGL loader
- GLM — math library
- CMake — build system

The project renders animated geometry using a basic rendering pipeline with
model / view / projection matrices and a small scene system.

---

## Build

```
cmake -S . -B build
cmake --build build
```

## Run

```
./build/main
```

or

```
sh run
```
---

## Features

- Modern OpenGL (Core profile)
- Shader class with file loading
- Mesh abstraction (VAO / VBO wrapper)
- Transform system (position / rotation / scale)
- Animation system
- Camera with view / projection matrices
- Scene with multiple objects
- Renderer that draws the scene
- RGB vertex colors
- Modular C++ structure

---
