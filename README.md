# Random Scramble Generator

This is a random scrambbler for Generating valid WCA scrambled rubiks cube states.


## Features

- Generates a random scramble sequence.
- Ensures no consecutive moves are the same or opposites.
- Outputs both standard and readable scramble notations.

## How To Use

Clone the Repository.

```bash
  git clone https://github.com/Rya-man/Valid-Cube-Scrambler
```
Compile the program.

```bash
    g++ -o scramble_generator main.cpp

```
Run the Program.
 ``` bash
    ./scramble_generator
```

## Code

### `Movelist`

The `Movelist` string contains the possible moves:

The `generate()` function generates a single random move:
```cpp
string Movelist = "LDBFUR";
`generate()`

string generate() {
    string a = "";
    int random_index = rand() % 6;
    a += Movelist[random_index];
    random_index = rand() % 3;
    a += to_string(random_index + 1);
    return a;
}
```

The `condition1()` function checks if the third move after a parallel move is parallel or not. This ensures that we do not go back a scrammble state thus making it easier to solve.
```cpp
inline bool cond(char a, char b) {
    if (a > b) swap(a, b);
    return (a == 'L' && b == 'R') || (a == 'B' && b == 'F') || (a == 'D' && b == 'U');
}
```
The `scramble()` function generates a scramble sequence of size mves that is randomly chosen between 20 to 30:
```cpp
pair<vector<string>, vector<string>> scramble(int moves) {
    vector<string> scramble;
    string a = generate();
    scramble.push_back(a);
    while (--moves) {
        if (scramble.size() > 1) {
            while (scramble.back()[0] == a[0] || condition1(scramble.back()[0], a[0])) {
                a = generate();
            }
        } else {
            while (scramble.back()[0] == a[0]) {
                a = generate();
            }
        }
        scramble.push_back(a);
    }
    vector<string> scramble_readable = scramble;
    for (auto& move : scramble_readable) {
        if (move[1] == '1') {
            move.pop_back();
        } else if (move[1] == '3') {
            move.pop_back();
            move += '\'';
        }
    }
    return make_pair(scramble_readable, scramble);
}
```

