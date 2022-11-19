#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int k) {
        vector<int>v(k,0);
        for(int i=0;i<N;i++)
        {
            v[arr[i]%k]++;
        }
        int i=1,j=k-1,ans=0;
        while(i<j)
        {
            ans+=max(v[i],v[j]);
            i++;
            j--;
        }
        if(i==j &&v[i]>0)
        {
            ans+=1;
        }
        if(v[0]>0)
        {
            ans+=1;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}