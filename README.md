# Code Documentation For Final Project (Module 8A: Final Project)

This is to explain the code for **Module 8A: Final Project**

## Libraries Imports
I imported the necessary libraries for the code to run.

- `<iostream>` for `cout`, `cerr`
- `<fstream>` for file input `(ifstream)`.
- `<vector>` for dynamic 1D/2D arrays.
- `<string>` for `std::string`.
- `using namespace std;` avoids repeatedly writing` std::`.

```c++
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
```

# The Start Of The Code
## Main
- This `ifstream file("input.txt");` opens the file named `input.txt` for reading.
- `if (!file) `checks whether the file opened successfully. If not, print an error and exit with a non-zero status.
```c++
int main() {
    ifstream file("input.txt"); // text file with x char y per line
    if (!file) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }
```

## Vector
- `xs`, `ys`: parallel vectors storing x and y coordinates.

- `chars`: vector storing the character to place at each `(x,y)`.

- `x`, `y` are temporary `ints` for reading coordinate values.

- `ch` is a `string` used to read the character column from the file.

```c++
    vector<int> xs;
    vector<int> ys;
    vector<char> chars;
    int x, y;
    string ch;
```

##  Step 1: Read data

- This loop reads triples from the file in the pattern x character y, e.g. 87 █ 3.

- file >> x >> ch >> y reads them separated by whitespace.

- For each triple, it appends the values into the parallel vectors.

```c++
    while (file >> x >> ch >> y) {
        xs.push_back(x);
        ys.push_back(y);
        chars.push_back(ch[0]); // take first character
    }
```

## Step 2: Determine max X and Y

- Scan all coordinates to find the largest x and y values.

- `maxX` and `maxY` are used to size the grid so it fits all plotted points.


```c++
    int maxX = 0, maxY = 0;
    for (size_t i = 0; i < xs.size(); ++i) {
        if (xs[i] > maxX) maxX = xs[i];
        if (ys[i] > maxY) maxY = ys[i];
    }

```

## Step 3: Initialize 2D array with spaces

- Creates a 2D grid (vector of rows), with `maxY + 1` rows and` maxX + 1` columns.

- All cells initialize to `' '` (space) so empty spots render as blanks.

- I used `maxY + 1` because coordinates are zero-based.

```c++
vector<vector<char>> grid(maxY + 1, vector<char>(maxX + 1, ' '));
```

## Step 4: Fill the grid
- For every recorded point, place the character into the grid at `[row = y][col = x]`.
- If two input lines specify the same (x,y) the later one overwrites the earlier.

```c++
    for (size_t i = 0; i < xs.size(); ++i) {
        grid[ys[i]][xs[i]] = chars[i];
    }
```

## Step 5: Print the grid
- Print rows from top `(y=0)` to bottom `(y=maxY)`.

- For each row, print every column from `x=0..maxX`.

- `cout << grid[y][x]` prints the stored character (or space).

- After each row, print newline. Program ends returning 0.
```c++
    for (int y = 0; y <= maxY; ++y) {
        for (int x = 0; x <= maxX; ++x) {
            cout << grid[y][x];
        }
        cout << endl;
    }

    return 0;
}
```