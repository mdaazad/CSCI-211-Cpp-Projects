// MD AZAD
// CSCI 211 LAB
// Brute-force solution to the Eight Queens problem using a 1D array representation

#include <iostream>
using std::cout;
using std::endl;

// Function to check if the current queen configuration is valid (no two queens attack each other)
bool ok(int q[]) {
    // Compare each queen with every queen to its right to avoid redundancy
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            // Check for row conflict or diagonal conflict
            if (q[i] == q[j] || abs(q[i] - q[j]) == abs(i - j)) {
                return false; // Conflict found: queens are attacking each other
            }
        }
    }
    return true; // No conflicts found: valid configuration
}

int main() {
    int q[8] = {0};  // 1D array to represent queen positions; index = column, value = row
    int solu = 0;    // Counter to track number of valid solutions found

    // Generate all possible board configurations (8^8 = 16,777,216 combinations)
    for (int i0 = 0; i0 < 8; i0++) {
        for (int i1 = 0; i1 < 8; i1++) {
            for (int i2 = 0; i2 < 8; i2++) {
                for (int i3 = 0; i3 < 8; i3++) {
                    for (int i4 = 0; i4 < 8; i4++) {
                        for (int i5 = 0; i5 < 8; i5++) {
                            for (int i6 = 0; i6 < 8; i6++) {
                                for (int i7 = 0; i7 < 8; i7++) {
                                    // Assign each queen's position in its respective column
                                    q[0] = i0;
                                    q[1] = i1;
                                    q[2] = i2;
                                    q[3] = i3;
                                    q[4] = i4;
                                    q[5] = i5;
                                    q[6] = i6;
                                    q[7] = i7;

                                    // Validate configuration using the ok() function
                                    if (ok(q)) {
                                        solu++;  // Valid solution found; increment counter
                                        
                                        // Output the solution number and queen positions
                                        cout << "Solution Number: " << solu << endl;
                                        for (int r = 0; r < 8; r++) {
                                            cout << q[r] << " ";
                                        }
                                        cout << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0; // Program finished
}