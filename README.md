# 🎮 Tetris Game

A C++ implementation of the classic Tetris game built with the `ge211` graphics library.

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()

## 📋 Overview

This project implements a fully functional Tetris game with classic gameplay mechanics, including:
- **5 different block types** with unique orientations
- **Intuitive controls** for movement and rotation
- **Visual preview** of block placement
- **Scoring system** with multipliers
- **Block replacement** feature for strategic gameplay

## 🛠️ Prerequisites

Before building the game, ensure you have:

- **C++17 compatible compiler** (e.g., `g++`, `clang++`)
- **ge211 development library** installed
  - Download from: [ge211 GitHub Repository](https://github.com/cmu-ge211/ge211)
  - Follow the installation instructions in the ge211 documentation

## 🏗️ Building the Game

### Compilation

Compile all source files and link against the `ge211` library:

```bash
g++ -std=c++17 main.cxx board.cxx controller.cxx model.cxx piece.cxx view.cxx -lge211 -o tetris
```

This command will create an executable named `tetris` in the repository root.

### Project Structure

```
tetris/
├── main.cxx          # Main game entry point
├── board.cxx         # Game board logic
├── controller.cxx    # Input handling
├── model.cxx         # Game state management
├── piece.cxx         # Tetris piece implementation
├── view.cxx          # Rendering and display
├── model_test.cxx    # Test suite
└── README.md         # This file
```

## 🎯 Running the Game

### Start the Game

Execute the compiled binary:

```bash
./tetris
```

### Controls

| Key | Action |
|-----|--------|
| `↑` | Rotate piece |
| `←` | Move left |
| `→` | Move right |
| `↓` | Move down |
| `S` | Drop quickly |
| `P` | Pause game |
| `Q` | Quit game |

## 🧪 Testing

The project includes a comprehensive test suite built with **Catch2**.

### Running Tests

Build and execute the test suite:

```bash
g++ -std=c++17 model_test.cxx board.cxx controller.cxx model.cxx piece.cxx view.cxx -DCS211_TESTING -lge211 -o tests
./tests
```

### Test Coverage

The test suite covers:
- Board state management
- Piece movement and rotation
- Collision detection
- Game logic validation

## 🎮 Game Features

### Core Mechanics
- **Random block generation** with 5 different piece types
- **Smooth rotation** with 90-degree increments
- **Boundary detection** preventing out-of-bounds placement
- **Row clearing** with automatic downward shifting
- **Game over detection** when board fills to top

### Enhanced Features
- **Visual placement preview** for strategic planning
- **Block replacement system** (3 times per game)
- **Scoring system** with multipliers for multiple row clears
- **Static first block** allowing planning time

## 📊 Scoring System

| Action | Points |
|--------|--------|
| Single row clear | 10 points |
| Multiple row clear | 10 × 5 multiplier |
| Block replacement | No penalty |

## 🔗 Links


- **Portfolio**: [Myles Gould's Portfolio](https://mylesgould.com)
- **ge211 Library**: [Graphics Engine Documentation](https://github.com/cmu-ge211/ge211)

## 🤝 Contributing

This is a personal project, but suggestions and feedback are welcome! Feel free to:
- Report bugs or issues
- Suggest new features
- Improve documentation

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

---

**Built with ❤️ using C++ and ge211**

*For more detailed information about this project, visit: [https://mylesgould.com/projects/Tetris/](https://mylesgould.com/projects/Tetris/)* 
