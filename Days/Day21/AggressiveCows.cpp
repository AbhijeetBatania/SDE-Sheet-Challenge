/*
=========================================================
Problem: Aggressive Cows
Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1
=========================================================
*/

// ---------------------------
// Method 1 : Linear Search
// Time Complexity: O((Max Distance) × N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    bool canWePlace(vector<int> &arr, int idx, int k){

        int countCows = 1;
        int lastpos = arr[0];

        for(int i = 1; i < arr.size(); i++){

            if(arr[i] - lastpos >= idx){

                countCows++;
                lastpos = arr[i];
            }
        }

        return countCows >= k;
    }

    int aggressiveCows(vector<int> &arr, int k) {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        int start = 1;
        int end = arr[n-1] - arr[0];

        int ans = 0;

        for(int i = start; i <= end; i++){

            if(canWePlace(arr, i, k)){
                ans = i;
            }
            else
                break;
        }

        return ans;
    }
};


// ---------------------------
// Method 2 : Binary Search
// Time Complexity: O(N log(Max Distance))
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    bool canWePlace(vector<int> &arr, int mid, int k){

        int countCows = 1;
        int lastpos = arr[0];

        for(int i = 1; i < arr.size(); i++){

            if(arr[i] - lastpos >= mid){

                countCows++;
                lastpos = arr[i];
            }
        }

        return countCows >= k;
    }

    int aggressiveCows(vector<int> &arr, int k) {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        int start = 1;
        int end = arr[n-1] - arr[0];

        int ans = 0;

        while(start <= end){

            int mid = start + (end-start)/2;

            if(canWePlace(arr, mid, k)){

                ans = mid;
                start = mid + 1;
            }
            else{

                end = mid - 1;
            }
        }

        return ans;
    }
};