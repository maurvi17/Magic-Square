#include <iostream>
#include <vector>

using namespace std;

class MagicSquare {
private:
    int n; // Size of the magic square
    vector<vector<int>> square; // 2D vector to store the magic square

public:
    // Constructor to initialize the magic square of size n
    MagicSquare(int n) : n(n), square(n, vector<int>(n, 0)) {}

    // Generate magic square based on order type
    void generate() {
        if (n % 2 == 1) {
            generateOddOrder();
        } else if (n % 4 == 0) {
            generateDoublyEvenOrder();
        } else {
            cout << "Magic square generation for singly even order (e.g., 6x6) is not supported.\n";
        }
    }

    // Generate odd-order magic square using the Siamese method
    void generateOddOrder() {
        int i = 0;
        int j = n / 2;
        for (int num = 1; num <= n * n; ++num) {
            square[i][j] = num;
            int newI = (i - 1 + n) % n;
            int newJ = (j + 1) % n;

            if (square[newI][newJ] != 0) {
                i = (i + 1) % n;
            } else {
                i = newI;
                j = newJ;
            }
        }
    }

    // Generate doubly even-order magic square (4x4, 8x8, etc.)
    void generateDoublyEvenOrder() {
        int num = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                square[i][j] = num++;
            }
        }

        // Inverting the values in specific cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i < n / 4 || i >= 3 * n / 4) && (j < n / 4 || j >= 3 * n / 4) ||
                    (i >= n / 4 && i < 3 * n / 4 && j >= n / 4 && j < 3 * n / 4)) {
                    square[i][j] = (n * n + 1) - square[i][j];
                }
            }
        }
    }

    // Function to print the magic square
    void printSquare() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << square[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Function to verify if the generated square is a magic square
    bool isMagicSquare() const {
        int magicConstant = n * (n * n + 1) / 2;

        // Check rows and columns
        for (int i = 0; i < n; ++i) {
            int rowSum = 0, colSum = 0;
            for (int j = 0; j < n; ++j) {
                rowSum += square[i][j];
                colSum += square[j][i];
            }
            if (rowSum != magicConstant || colSum != magicConstant) return false;
        }

        // Check diagonals
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < n; ++i) {
            diag1 += square[i][i];
            diag2 += square[i][n - i - 1];
        }

        return diag1 == magicConstant && diag2 == magicConstant;
    }
};

int main() {
    int n;
    cout << "Enter the size of the magic square (odd or doubly even integer): ";
    cin >> n;

    MagicSquare magicSquare(n);
    magicSquare.generate();
    cout << "Generated Magic Square of size " << n << ":\n";
    magicSquare.printSquare();

    if (magicSquare.isMagicSquare()) {
        cout << "The generated square is a valid magic square.\n";
    } else {
        cout << "The generated square is NOT a valid magic square.\n";
    }

    return 0;
}
