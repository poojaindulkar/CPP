/*
*Print All Permutations of a String/Array
Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.


Example 1: 

Input: arr = [1, 2, 3]

Output: 
[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]

*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Solution{
    private:
    void permutations(vector<int>v, int n, int picked[],vector<vector<int>>& ans , vector<int>&p){
        if(p.size()==n) ans.push_back(p);
        for(int i=0;i<n;i++){
            if(!picked[i]){
                p.push_back(v[i]);
                picked[i]=1;
                permutations(v,n,picked,ans,p);
                picked[i]=0;
                p.pop_back();
            }
        }
    }
    public:
    vector<vector<int>> permute(vector<int> v,int n){
        int picked[n+1];
        memset(picked,0,sizeof(picked));
        vector<vector<int>>ans;
        vector<int>p;
        permutations(v,n,picked,ans,p);
        return ans;
    }

};

int main(){
    Solution obj;
    int n;
    cout<<"Enter Size of array: ";
    cin>>n;
    cout<<"Enter array elements\n";
    vector<int>v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<vector<int>>ans=obj.permute(v,n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}