**SAPID**:590027010

# Matchstick Game

A strategic command-line game implemented in C where players compete against the computer in a matchstick removal challenge.

## 🎮 Game Description

The Matchstick Game is a classic strategy game where players take turns removing matchsticks from a pool. The game starts with **101 matchsticks** and players can remove **1 to 9 matchsticks** per turn. The player who is forced to take the **last matchstick loses** the game.

## 📋 Rules

- **Total Matchsticks**: 101
- **Pickup Range**: 1-9 matchsticks per turn
- **Objective**: Force your opponent to take the last matchstick
- **Turns**: Alternate between player and computer
- **Winning Strategy**: Leave your opponent with multiples of 10

## 🚀 Quick Start

### Prerequisites
- GCC Compiler
- Terminal/Command Prompt

### Installation & Running

1. **Clone or download the project files**:
   ```
   matchstick_game/
   ├── matchstick_game.h
   ├── main.c
   ├── game_logic.c
   └── README.md
   ```

2. **Compile the game**:
   ```bash
   gcc -o matchstick_game main.c game_logic.c -I.
   ```

3. **Run the game**:
   ```bash
   ./matchstick_game
   ```

## 🎯 How to Play

1. The game randomly decides who starts first
2. On your turn, enter a number between 1 and 9
3. The computer will make its move
4. Continue until one player takes the last matchstick
5. View your statistics and play again!

## 🧠 Winning Strategy

**Mathematical Insight**: The optimal strategy is to always leave your opponent with a multiple of 10 matchsticks. Since players can pick 1-9 matchsticks, controlling the game to leave 10, 20, 30, etc., matchsticks ensures your opponent will eventually be forced to take the last one.

## 📁 File Structure

- **matchstick_game.h**: Header file with constants and function prototypes
- **main.c**: Main program with game loop and user interface
- **game_logic.c**: Game mechanics, computer AI, and helper functions

## 🔧 Features

- ✅ Intelligent computer opponent
- ✅ Input validation and error handling
- ✅ Game statistics tracking
- ✅ Multiple rounds support
- ✅ Visual matchstick display
- ✅ Randomized starting player
- ✅ Strategic AI with occasional imperfections for balance

## 🎲 Sample Gameplay

```
=== ENHANCED MATCHSTICK GAME ===
Rules:
- There are 101 matchsticks
- Each turn, pick 1 to 9 matchsticks
- Player who takes the last matchstick LOSES!

>>> You start first! <<<

Remaining matchsticks: 101
Matchsticks: ||||||||||||||||||||... (101 total)

Your turn! Pick 1-9 matchsticks: 3
You picked 3 matchstick(s)
```

## 📊 Game Statistics

After each game, view your performance:
- Wins and losses
- Total games played
- Win percentage

## 🛠️ Development

### Compilation Options
```bash
# Basic compilation
gcc -o matchstick_game main.c game_logic.c -I.

# With debugging symbols
gcc -g -o matchstick_game main.c game_logic.c -I.

# With optimization
gcc -O2 -o matchstick_game main.c game_logic.c -I.
```

### Code Style
- Modular design with separate concerns
- Comprehensive error handling
- Clean, readable code structure
- Consistent naming conventions

## 🎓 Educational Value

This project demonstrates:
- C programming fundamentals
- Algorithm design and implementation
- User input handling
- Modular programming practices
- Mathematical strategy in game design

---

**Enjoy playing and may the best strategist win!** 🏆
