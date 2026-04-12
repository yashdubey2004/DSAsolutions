#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
vector<bool> isPrime(N, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < N; i++){
        if(isPrime[i]){
            for(int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }
}

int nextPrime(int x){
    while(x < N && !isPrime[x]) x++;
    return x;
}

int nextNonPrime(int x){
    while(x < N && isPrime[x]) x++;
    return x;
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sieve();
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                if(!isPrime[nums[i]])
                    count += nextPrime(nums[i]) - nums[i];
            } 
            else{
                if(isPrime[nums[i]])
                    count += nextNonPrime(nums[i]) - nums[i];
            }
        }
        return count;
    }
};
