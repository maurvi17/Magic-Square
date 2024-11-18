The provided C++ code generates magic squares of odd and doubly even orders (e.g., 3x3, 4x4, 5x5), ensuring that the sums of all rows, columns, and diagonals are equal. The approach uses structured, rule-based methods, which resemble heuristics in guiding the number placement.

The magic constant M of a magic square can be calculated using the formula M = {n*(n^2+1)}/2 where n is the order of the magic square.

Odd-Order Magic Square: Siamese Method
For odd orders, the code applies the Siamese method, a classic rule-based technique. The process begins by placing 1 in the middle of the top row. Each successive number is placed by moving up one row and right one column. If this move is out of bounds, it wraps around to the opposite side (top to bottom or left to right). If the target cell is occupied, the algorithm moves down instead. This sequence continues until all cells are filled. This method effectively uses positional heuristics — specifically wraparound and downward adjustment — to guide number placement without conflict, guaranteeing a valid magic square.

Doubly Even-Order Magic Square: Pattern Inversion
For doubly even orders, the algorithm fills the grid sequentially, then applies selective inversion based on cell position. Cells in the outer corners and central regions are flipped (converted to n*n + 1 - cell value), a rule that balances sums across rows, columns, and diagonals. This pattern inversion serves as a heuristic by leveraging cell position to determine necessary adjustments, ensuring that the magic constant is achieved across all parts of the grid.
