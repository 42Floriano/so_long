# 🎮 so_long - 42 Project

**so_long** is a **2D game project** for **42 School**, designed to introduce **graphical programming** using the **MiniLibX library**. It involves rendering a simple top-down view game where the player must navigate through a map, collecting items and reaching the exit while avoiding obstacles.

---

## 📌 Project Overview

- **Language**: C
- **Graphics Library**: MiniLibX
- **Compilation**: `gcc -Wall -Wextra -Werror`
- **Status**: Mandatory part completed + Almost all bonuses implemented ✅

---

## 📁 Repository Structure

```
├── assets/             # Game assets (sprites, textures, etc.)
├── includes/           # Header files
├── mlx/                # MiniLibX library
├── sources/            # Source code files for the main game
├── sources_bonus/      # Source code files for the bonus version
├── Makefile            # Compilation rules
└── README.md           # Project documentation
```

---

## 🚀 Getting Started

### 🔧 Dependencies
Ensure you have **MiniLibX** installed before compiling the project.

For **Linux**:
```sh
sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev
```

For **MacOS**:
```sh
brew install minilibx
```

---

## 🏗️ Installation

Clone the repository and compile the project using Make:

```sh
git clone https://github.com/42Floriano/so_long.git
cd so_long
make
```

For the **bonus version**:
```sh
make bonus
```

This will generate the `so_long` executable.

---

## 🎮 How to Play

Run the game with a `.ber` map file:
```sh
./so_long maps/example.ber
```

### 🕹️ Controls
- `W/A/S/D` → Move player
- `ESC` → Exit game

---

## 🗺️ Map Format
A valid `.ber` file consists of:
- **Walls (`1`)** - Non-walkable areas.
- **Floor (`0`)** - Walkable spaces.
- **Player (`P`)** - The starting position.
- **Collectibles (`C`)** - Items the player must collect.
- **Exit (`E`)** - The goal to reach after collecting all `C`.
- **Enemies (`X`)** _(Bonus only)_ - Moving obstacles that add difficulty.

Example:
```
111111
1P0C01
1C0XE1
1E0001
111111
```

---

## 🌟 Implemented Features
✅ **Basic movement & collision detection**  
✅ **Item collection system**  
✅ **Exit opens after collecting all items**  
✅ **Graphical rendering with MiniLibX**  
✅ **Custom game maps supported**  
✅ **Bonus: Enemy AI movement**  
✅ **Bonus: Animated player & collectibles**  
✅ **Bonus: Score counter & move counter**  
✅ **Bonus: Game over screen**    

---

## 🛑 Known Issues
- The game may not work properly on some Linux distributions without additional dependencies.

---

## 📌 Credits
- **42Floriano** ([@42Floriano](https://github.com/42Floriano))

---

## 🏆 Acknowledgments
This project was built as part of **42 School**, providing an introduction to **game development, event handling, and graphics programming** using **MiniLibX**.

---

🔗 [GitHub Repository](https://github.com/42Floriano/so_long)

