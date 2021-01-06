// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0#
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void subarrayWithGivenSum(int sz,int sum,int arr[]) {
    int minElem = INT_MAX;
    for(int i=0;i<sz;i++){
        minElem = min(arr[i], minElem);
    }
    
    int minAbs = abs(minElem);
    int left = 0, temp = 0;
    
    for(int right = 0; right<sz;right++){
        int extra = ((right - left) + 1) * minAbs;
        temp+=arr[right] + minAbs;
        while(temp-extra>sum){
            temp-=(arr[left++] + minAbs);
            extra-=minAbs;
        }
        if(temp-extra==sum){
            cout<<left+1<<' '<<right+1<<endl;
            return;
        }
    }
    
    cout<<-1<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int sz, sum, arr[100000];
	    cin>>sz>>sum;
	    for(int i=0;i<sz;i++){
	        cin>>arr[i];
	    }
	    subarrayWithGivenSum(sz, sum, arr);
	}
	return 0;
}

/** 
 * NOTE: Handles -ve numbers also
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/