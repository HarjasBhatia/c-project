# Matchstick Game

A simple C implementation of the classic matchstick picking game.

Overview
- Two players (you and the computer) alternately pick matchsticks.
- Each turn a player may pick between `1` and `9` matchsticks.
- Whoever takes the last matchstick loses.

Build

Use gcc to compile the project from the repository root:

```bash
gcc -o matchstick_game src/main.c src/game_logic.c -I include
```

Run

```bash
./matchstick_game
```

Controls
- Enter a number between `1` and `9` when prompted.
- The program validates the pick and updates the remaining sticks.

Notes
- This repository has had comments removed from source files by design; source is intentionally simple and slightly verbose (student-style helpers included).
- If you want a `.gitignore` for macOS files, add a `.gitignore` containing `.DS_Store`.

Contact
- Repository owner: `HarjasBhatia`

License
- No license specified. Add a `LICENSE` file if you want to declare one.
