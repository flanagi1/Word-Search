**Includes and Setup:**
It includes necessary libraries and a color manipulation library for terminal output.

**Functions:**
hor: Checks for words horizontally (both right and left) in the grid.
vert: Checks for words vertically (both downwards and upwards).
dia: Checks for words diagonally in four directions (down-right, up-left, down-left, up-right).

**Main Function:**
Reads the dimensions of the grid (vx x vy).
Initializes the grid and a position matrix to keep track of found letters.
Fills the grid with characters from user input.
Iterates over command-line arguments (assumed to be the words to find) and calls the search functions for each word.
Outputs the grid, highlighting found letters in red.
