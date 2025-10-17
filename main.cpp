#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt"); // text file with x char y per line
    if (!file) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }

    vector<int> xs;
    vector<int> ys;
    vector<char> chars;

    int x, y;
    string ch;

    // Step 1: Read data
    while (file >> x >> ch >> y) {
        xs.push_back(x);
        ys.push_back(y);
        chars.push_back(ch[0]); // take first character
    }

    // Step 2: Determine max X and Y
    int maxX = 0, maxY = 0;
    for (size_t i = 0; i < xs.size(); ++i) {
        if (xs[i] > maxX) maxX = xs[i];
        if (ys[i] > maxY) maxY = ys[i];
    }

    // Step 3: Initialize 2D array with spaces
    vector<vector<char>> grid(maxY + 1, vector<char>(maxX + 1, ' '));

    // Step 4: Fill the grid
    for (size_t i = 0; i < xs.size(); ++i) {
        grid[ys[i]][xs[i]] = chars[i];
    }

    // Step 5: Print the grid
    for (int y = 0; y <= maxY; ++y) {
        for (int x = 0; x <= maxX; ++x) {
            cout << grid[y][x];
        }
        cout << endl;
    }

    return 0;
}
