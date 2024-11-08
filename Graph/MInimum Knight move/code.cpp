#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>  // For tuple

using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    int minKnightMoves(int targetX, int targetY) {
        // We are only concerned with positive coordinates due to symmetry of the board
        targetX = abs(targetX);
        targetY = abs(targetY);
        
        // BFS queue: store {currentX, currentY, steps}
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0}); // Start from (0, 0) with 0 steps

        // Set to keep track of visited positions
        unordered_set<string> visited;
        visited.insert("0,0");

        while (!q.empty()) {
            // Access tuple elements using std::get<N>
            auto cell = q.front();
            q.pop();

            int x = get<0>(cell);
            int y = get<1>(cell);
            int steps = get<2>(cell);

            // If we reached the target position
            if (x == targetX && y == targetY) {
                return steps;
            }

            // Explore all 8 possible knight moves
            for (auto d : dir) {
                int newX = x + d[0];
                int newY = y + d[1];

                // Generate unique key for visited set
                string key = to_string(abs(newX)) + "," + to_string(abs(newY));

                // Ensure we only move in the positive quadrant and avoid revisiting
                if (!visited.count(key)) {
                    q.push({abs(newX), abs(newY), steps + 1});
                    visited.insert(key);
                }
            }
        }
        
        return -1; // This should never be reached since a knight can always reach any position
    }
};

int main() {
    Solution solution;
    int targetX = 5, targetY = 2;
    cout << "Minimum knight moves: " << solution.minKnightMoves(targetX, targetY) << endl;
    return 0;
}
