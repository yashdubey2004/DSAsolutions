class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int count = 1;
        int result = 1;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] + 1 == arr[i + 1]){
                count++;
                result = max(result, count);
            }
            else if(arr[i] == arr[i + 1]) continue;
            else{
                count = 1;
            }
        }
        return result;
    }
};
