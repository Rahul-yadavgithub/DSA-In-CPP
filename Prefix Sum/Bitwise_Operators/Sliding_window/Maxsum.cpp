// #include <iostream>
// #include <vector>

// using namespace std;

// // Function to find the subarray with the greatest sum
// vector<int> maxSumSubarray(vector<int>& arr) {
//     int maxSum = arr[0];
//     int currentSum = arr[0];
//     int start = 0;
//     int maxStart = 0;
//     int maxEnd = 0;

//     for (int i = 1; i < arr.size(); i++) {
//         // Update current sum or start index if the current element increases the sum
//         if (arr[i] > currentSum + arr[i]) {
//             currentSum = arr[i];
//             start = i;
//         } else {
//             currentSum += arr[i];
//         }

//         // Update maxSum and indices if currentSum is greater
//         if (currentSum > maxSum) {
//             maxSum = currentSum;
//             maxStart = start;
//             maxEnd = i;
//         }
//     }

//     // Return the subarray with the greatest sum
//     return vector<int>(arr.begin() + maxStart, arr.begin() + maxEnd + 1);
// }

// int main() {
//     vector<int> arr = {1, -3, 2, 1, -1, 5, -3};
    
//     vector<int> result = maxSumSubarray(arr);

//     cout << "Subarray with maximum sum: ";
//     for (int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }


#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[] = {1, -3, 2, 1, -1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = INT_MIN;
    
    // Calculate maxSum using Kadane's algorithm
    int sum = 0;
    int initialIdx = 0;
    int endIdx = 0;
    int tempIdx = 0;

    for (int j = 0; j < n; j++) {
        sum += arr[j];
        
        // Update maxSum and indices if sum is greater
        if (sum > maxSum) {
            maxSum = sum;
            initialIdx = tempIdx;
            endIdx = j;
        }
        
        // If sum becomes negative, reset sum and update tempIdx
        if (sum < 0) {
            sum = 0;
            tempIdx = j + 1;
        }
    }

    // Output the subarray with maximum sum
    cout << "Subarray with maximum sum: ";
    for (int i = initialIdx; i <= endIdx; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the maximum sum
    cout << "Maximum sum: " << maxSum << endl;

    return 0;
}
