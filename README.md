# Magic-Square

The provided C++ code generates magic squares of odd orders (e.g., 3x3, 5x5), ensuring that the sums of all rows, columns, and diagonals are equal. The approach uses structured, rule-based methods, which resemble heuristics in guiding the number placement.

Odd-Order Magic Square: Siamese Method
For odd orders, the code applies the Siamese method, a classic rule-based technique. The process begins by placing 1 in the middle of the top row. Each successive number is placed by moving up one row and right one column. If this move is out of bounds, it wraps around to the opposite side (top to bottom or left to right). If the target cell is occupied, the algorithm moves down instead. This sequence continues until all cells are filled. This method effectively uses positional heuristics — specifically wraparound and downward adjustment — to guide number placement without conflict, guaranteeing a valid magic square.
