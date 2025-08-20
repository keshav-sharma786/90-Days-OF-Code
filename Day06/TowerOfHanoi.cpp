#include <iostream>
using namespace std;

// a => source
// b => helper
// c => destination
void hanoi(int n, char a, char b, char c) {
    // base case
    if(n == 0) {
        return;
    }
    // recursive function call
    hanoi(n - 1, a, c, b);
    cout << a << " -> " << c << endl;
    // again a recursive function call
    hanoi(n - 1, b, a, c);
}


int main() {
    // Tower Of Hanoi
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}