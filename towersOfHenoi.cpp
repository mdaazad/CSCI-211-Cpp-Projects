//MD AZAD
//CSCI 211 LAB
//Towers of Hanoi

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3]; //Array of 3 vectors to represent the three towers in the puzzle
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;

    
    int close, far; // Variables to determine the direction of movement (either close or far)
    if (n % 2 != 0) { // If n is odd, close = 1 and far = 2. If n is even, the reverse
        close = 1;
        far = 2;
    } else {
        close = 2;
        far = 1;
    }
    int from = 0, to = close, candidate = 1, move = 0;// Initialize the towers
    
    for (int i = n + 1; i >= 1; --i) { // Start a loop from 'n+1' down to 1
        t[0].push_back(i); // Add each ring to the first tower, starting with the largest (n+1, acting as a base)
    }
    t[1].push_back(n + 1); // Place a base ring on the second tower
    t[2].push_back(n + 1); // Place a base ring on the third tower

    while (t[1].size() < n + 1) { // while t[1] does not contain all of the rings
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 'A') << " to tower " << char(to + 'A') << "\n";

        // Move the ring from "from" to "to" (first copy it, then delete it from "from")
        t[to].push_back(t[from].back());
        t[from].pop_back();

        // from = the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
        if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) {
            from = (to + 1) % 3;
        } 
        else {
            from = (to + 2) % 3;
        }

        // candidate = the ring on top of the from tower
        candidate = t[from].back();

        // to = the closest tower on which the candidate can be placed: (from+close)%3 or (from+far)%3
        if (candidate % 2 != 0) {
            // if candidate is an odd number, move right
            to = (from + close) % 3;
        } else {
            // if candidate is an even number, move left
            to = (from + far) % 3;
        }
    }
    return 0;
}