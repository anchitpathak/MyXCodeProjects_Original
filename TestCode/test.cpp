#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix, int angle) {
    int n = matrix.size();
    if (n == 0 || matrix[0].size() != n) {
        cout << "Matrix must be square!" << endl;
        return;
    }
    switch (angle) {
        case 90:
            // Transpose
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    swap(matrix[i][j], matrix[j][i]);
            // Reverse rows
            for (int i = 0; i < n; ++i)
                reverse(matrix[i].begin(), matrix[i].end());
            break;
        case 180:
            // Reverse rows
            for (int i = 0; i < n; ++i)
                reverse(matrix[i].begin(), matrix[i].end());
            // Reverse entire matrix
            reverse(matrix.begin(), matrix.end());
            break;
        case 270:
            // Transpose
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    swap(matrix[i][j], matrix[j][i]);
            // Reverse columns
            for (int j = 0; j < n; ++j) {
                int top = 0, bottom = n - 1;
                while (top < bottom) {
                    swap(matrix[top][j], matrix[bottom][j]);
                    ++top;
                    --bottom;
                }
            }
            break;
        default:
            cout << "Rotation angle must be 90, 180, or 270 degrees." << endl;
            break;
    }
}

//int main() {
//    vector<vector<int>> mat = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
//
//    rotateMatrix(mat, 90); // try 180 or 270
//
//    for (auto& row : mat) {
//        for (int val : row)
//            cout << val << " ";
//        cout << endl;
//    }
//
//    return 0;
//}
