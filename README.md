# Saper (Minesweeper) — SFML C++

A simple Minesweeper project written in C++ using the **SFML** library.

---

## Description
The game runs in windowed mode and randomly places mines on the board.  
The player can reveal tiles or mark them with flags.  
You win by revealing all tiles that are not mines.

---

## Getting Started

### Requirements
- **Visual Studio 2022** or newer  
- **SFML 2.5.1** (or a compatible version)

### SFML Setup
1. Download SFML: [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)
2. Copy the library to `C:\SFML-2.5.1\` (or update the paths in `.vcxproj`).
3. Make sure the following libraries are linked:
   - `sfml-graphics`
   - `sfml-window`
   - `sfml-system`

### Build
1. Open `Saper.sln` in Visual Studio.
2. Select the `Debug | x64` configuration.
3. Click **Build → Build Solution (Ctrl+Shift+B)**.

---

## Controls
| Action | Key / Button |
|--------|---------------|
| Reveal tile | Right mouse button |
| Toggle flag | Left mouse button |
| Quit | Close the game window |
