# So_long

## Project Description
`So_long` is a simple 2D game built using the MiniLibX library, where the player navigates a character through a map to collect items and reach the exit. The game demonstrates handling textures, sprites, and basic gameplay mechanics in C.

## Table of Contents
- [Objectives](#objectives)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Features](#features)
- [Maps](#maps)
- [Controls](#controls)
- [Known Issues](#known-issues)
- [License](#license)

## Objectives
The `So_long` project helps improve skills in:
- 2D window and image rendering using MiniLibX
- Keyboard event handling
- Game logic and pathfinding
- Memory management and handling potential leaks

## Installation
### Prerequisites
- A Mac system (since this project is for Mac only)

### Building the Project
1. Clone this repository:
    ```bash
    git clone https://github.com/ganievv/So_long.git
    cd so_long
    ```
2. Build the project using `make`:
    ```bash
    make
    ```

### Cleaning
To clean up object files:
```bash
make clean
```
To clean up all built files:
```bash
make fclean
```

## Usage
To run the game, use:
```bash
./so_long path/to/map_file.ber
```
The map file must follow the specified `.ber` format described in the [Maps](#maps) section.

## Game Rules
- The player's goal is to collect all collectibles and then reach the exit.
- The player moves using the `WASD` keys.
- The number of moves is displayed in the terminal.
- Pressing `ESC` or clicking the window close button exits the game cleanly.

## Features
- Top-down 2D view rendering
- Dynamic rendering of characters, walls, and collectibles
- Smooth window management and handling of minimization, focus changes, etc.
- Error handling for invalid map configurations

## Maps
### Map Requirements
- The map must be rectangular and surrounded by walls (`1`).
- It contains:
  - `0`: Empty space
  - `1`: Wall
  - `C`: Collectible
  - `E`: Exit
  - `P`: Player start position
- Example of a valid map:
    ```
    111111
    1P0C01
    100001
    1C00E1
    111111
    ```
- The game will check for valid paths, and an error message will be displayed if the map is invalid.

## Controls
- `W`, `A`, `S`, `D`: Move the player (up, left, down, right)
- `ESC`: Exit the game
