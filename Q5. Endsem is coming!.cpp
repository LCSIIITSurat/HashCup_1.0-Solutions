#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define in insert
int main()
{
    int t,tt;
    cin>>tt;
    for(t = 1;t<=tt;t++)
        {
        int i,j,n,k,p,l;
    cin>>n>>k>>p;
   
    vector<vector<int>> v(n+1);

    for(i = 1;i<=n;i++)
    {
         v[i].pb(0);
        for(j = 1;j<=k;j++)
        {
            int num;
            cin>>num;
            v[i].pb(v[i][j-1] + num);
        }
    }
    int dp[n+1][p+1];
    for(i = 0;i<=p;i++)   dp[0][i] = 0;
    for(i = 0;i<=n;i++) dp[i][0] = 0;
    for(i = 1;i<=n;i++)
    {
        for(j= 1;j<=p;j++)
        {
            dp[i][j] = dp[i-1][j];
           for(l = 1;l<= min(j,k);l++)
              dp[i][j] = max(dp[i][j],v[i][l] + dp[i-1][j-l] );   
        } 
    }
    cout<<dp[n][p]<<endl;
    }   
}