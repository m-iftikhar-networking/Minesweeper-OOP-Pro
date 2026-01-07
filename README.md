# Minesweeper-OOP-Pro
An advanced C++ OOP-based Minesweeper game featuring User Authentication, File-based data persistence, and real-time countdown mechanics.
**Project Overview**
This is a highly interactive, terminal-based Minesweeper game developed in C++ using Object-Oriented Programming (OOP) principles. Unlike standard versions, this project features a complete User Authentication System, persistent High Score Tracking, and dynamic Difficulty Levels.
**Game Workflow (How it Works)**
The game follows a structured logical flow to ensure a seamless user experience:
**Main Menu:** Upon launching, the user is presented with a professional terminal menu:
**New Game:** Start a fresh session.
**Resume Game:** Placeholder for future save-state functionality.
**High Score:** Fetches the all-time best score from highscore.txt.
**Exit:** Safely closes the application.
**User Authentication:** To play, a user must Sign Up or Sign In.
The system creates/accesses user.txt to store credentials, ensuring each player has a unique identity.
**Difficulty & Grid Generation:** Players choose between Easy, Medium, Hard, or Custom modes.
The backend uses a Recursive Shuffling Algorithm to randomly distribute Mines (Bombs), Coins, Keys, and Empty boxes.
**Gameplay Mechanics:**
A real-time Timer (implemented via time.h) pressures the player to finish before time runs out.
The console uses the Windows API for dynamic coloring and font scaling to improve visibility.
**Scoring & Persistence:**
Finding a Key (+200 pts), Coin (+100 pts), or hitting a Mine (-200 pts) updates the score.
If the final score beats the existing high score, the highscore.txt is updated automatically.
**Technical Features (OOP Pillars)**
**Encapsulation:** Separate classes for Player, Grid, Cell, and Game logic.
**Inheritance:** The Cell class inherits from Grid to manage specialized box behaviors.
**Composition:** The Game class acts as a controller, composed of Player and Cell objects.
**File Handling:** Extensive use of fstream for permanent data storage of users and scores.
**Recursion:** Utilized for efficient array shuffling and randomized grid placement.
**How to Run**
Ensure you have a C++ compiler (like MinGW or Dev-C++) installed.
Clone this repository.
Compile main.cpp.
Run the executable on a Windows terminal (recommended for full color/font support).
