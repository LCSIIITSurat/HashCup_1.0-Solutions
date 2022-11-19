#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define sort_v(arr) sort(arr.begin() , arr.end());
#define max_el(arr) *max_element(arr.begin() , arr.end());
#define min_el(arr) *min_element(arr.begin() , arr.end());
#define sort_vr(arr) sort(arr.rbegin() , arr.rend());
#define read(arr , n) rep(i , 0 , n) cin >> arr[i]; 
#define print_v(arr , n) rep(i , 0 , n) cout << arr[i] << ' '; 
#define rep_rev(i , a, b) for(int i=a ; i>b ; i--)

long long INFF = 1000000000000000005LL;
double EPS = 1e-9;
const ll N = 10000000;
double PI = acos(-1);
int MOD = 1000000007;

int maxx =0;
int n;
int m;

void solve(int i , int j, int score ,vector<vector<char> > &grid){
    if(j==m){
        j = 0;
        i++;
    }
    if(i==n){
        maxx = max(maxx , score);
        return;
    }

    if(grid[i][j]=='.' or grid[i][j]=='W'){
        solve(i , j+1 , score , grid);
        return;
    }
    if(i-1>=0 and grid[i-1][j]=='W'){
        grid[i-1][j] = '.';
        solve(i , j+1 , score+1 , grid);
        grid[i-1][j] = 'W';
    }
    if(i+1<n and grid[i+1][j]=='W'){
        grid[i+1][j] = '.';
        solve(i , j+1 , score+1 , grid);
        grid[i+1][j] = 'W';
    }
    if(j+1<m and grid[i][j+1]=='W'){
        grid[i][j+1] = '.';
        solve(i , j+1 , score+1 , grid);
        grid[i][j+1] = 'W';
    }
    if(j-1>=0 and grid[i][j-1]=='W'){
        grid[i][j-1] = '.';
        solve(i , j+1 , score+1 , grid);
        grid[i][j-1] = 'W';
    }
    solve(i , j+1 , score , grid);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<char> > grid(n , vector<char>(m));
    rep(i ,0 , n){
        rep(j , 0 , m){
            cin >> grid[i][j];
        }
    }
    solve(0 , 0,  0 , grid);
    cout << maxx << "\n";
    return 0;
}