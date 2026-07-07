/*
=========================================================
Problem: Allocate Minimum Number of Pages
Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
=========================================================
*/

// ---------------------------
// Method 1 : Linear Search
// Time Complexity: O((Sum-Max) × N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    int count(int maxPages, vector<int> &arr){

        int studentCount = 1;
        int studentPages = 0;

        for(int i = 0; i < arr.size(); i++){

            if(studentPages + arr[i] <= maxPages){
                studentPages += arr[i];
            }
            else{
                studentCount++;
                studentPages = arr[i];
            }
        }

        return studentCount;
    }

    int findPages(vector<int> &arr, int k) {

        if(k > arr.size())
            return -1;

        int low = -1;
        int high = 0;

        for(int i = 0; i < arr.size(); i++){
            low = max(low, arr[i]);
            high += arr[i];
        }

        for(int pages = low; pages <= high; pages++){

            int cnt = count(pages, arr);

            if(cnt <= k)
                return pages;
        }

        return -1;
    }
};


// ---------------------------
// Method 2 : Binary Search
// Time Complexity: O(N log Sum)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    int countStudents(long long maxPages, vector<int> &arr) {

        int studentCount = 1;
        long long studentPages = 0;

        for(int i = 0; i < arr.size(); i++) {

            if(studentPages + arr[i] <= maxPages){
                studentPages += arr[i];
            }
            else{
                studentCount++;
                studentPages = arr[i];
            }
        }

        return studentCount;
    }

    int findPages(vector<int> &arr, int k) {

        if(k > arr.size())
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        while(low <= high){

            long long mid = low + (high-low)/2;

            int students = countStudents(mid, arr);

            if(students > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};