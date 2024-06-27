#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Movelist = "LDBFUR";

string generate() {
    string a = "";
    int random_index = rand() % 6;
    a += Movelist[random_index];
    random_index = rand() % 3;
    a += to_string(random_index + 1);
    return a;
}

inline bool cond(char a, char b) {
    if (a > b) swap(a, b);
    return (a == 'L' && b == 'R') || (a == 'B' && b == 'F') || (a == 'D' && b == 'U');
}

pair<vector<string>, vector<string>> solve(int moves) {
    vector<string> scramble;
    string a = generate();
    scramble.push_back(a);
    while (--moves) {
        if (scramble.size() > 1) {
            while (scramble.back()[0] == a[0] || cond(scramble.back()[0], a[0])) {
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

int main() {
    srand(time(0));
    int a=20;
    a+= rand()%10;
    auto s = solve(a);
    cout << '\n';
    for (const auto& i : s.first){
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

