#include <iostream>
#include <vector>

using namespace std;

/**
 * Strassen's Matrix Multiplication Algorithm
 * 
 * Logic:
 * 1. Standard matrix multiplication takes O(n^3).
 * 2. Strassen's reduces this to O(n^2.81) using 7 recursive multiplications instead of 8.
 * 
 * Note: This implementation is for 2x2 matrices for clarity, as requested in most DAA labs.
 */

typedef vector<vector<int>> Matrix;

Matrix add(Matrix A, Matrix B, int size) {
    Matrix C(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract(Matrix A, Matrix B, int size) {
    Matrix C(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix strassen(Matrix A, Matrix B, int n) {
    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    Matrix a11(newSize, vector<int>(newSize));
    Matrix a12(newSize, vector<int>(newSize));
    Matrix a21(newSize, vector<int>(newSize));
    Matrix a22(newSize, vector<int>(newSize));
    Matrix b11(newSize, vector<int>(newSize));
    Matrix b12(newSize, vector<int>(newSize));
    Matrix b21(newSize, vector<int>(newSize));
    Matrix b22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Formulas for P1 to P7
    Matrix p1 = strassen(a11, subtract(b12, b22, newSize), newSize);
    Matrix p2 = strassen(add(a11, a12, newSize), b22, newSize);
    Matrix p3 = strassen(add(a21, a22, newSize), b11, newSize);
    Matrix p4 = strassen(a22, subtract(b21, b11, newSize), newSize);
    Matrix p5 = strassen(add(a11, a22, newSize), add(b11, b22, newSize), newSize);
    Matrix p6 = strassen(subtract(a12, a22, newSize), add(b21, b22, newSize), newSize);
    Matrix p7 = strassen(subtract(a11, a21, newSize), add(b11, b12, newSize), newSize);

    // C11, C12, C21, C22
    Matrix c11 = add(subtract(add(p5, p4, newSize), p2, newSize), p6, newSize);
    Matrix c12 = add(p1, p2, newSize);
    Matrix c21 = add(p3, p4, newSize);
    Matrix c22 = subtract(subtract(add(p5, p1, newSize), p3, newSize), p7, newSize);

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
    return C;
}

void printMatrix(const Matrix& m) {
    for (auto row : m) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};

    cout << "Matrix A:\n"; printMatrix(A);
    cout << "Matrix B:\n"; printMatrix(B);

    Matrix C = strassen(A, B, 2);

    cout << "Result of Strassen Multiplication:\n";
    printMatrix(C);

    return 0;
}
