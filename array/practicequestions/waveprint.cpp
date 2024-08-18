#include <iostream>
#include <vector>

using namespace std;

void wavePrintMatrix(const vector<vector<int>>& v) {
    int m = v.size();
    int n = v[0].size();

    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            // Left to right for even rows
            for (int j = 0; j < n; j++) {
                cout << v[i][j] << " ";
            }
        } else {

            for (int j = n - 1; j >= 0; j--) {
                cout << v[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    
    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    wavePrintMatrix(v);

    return 0;
}
