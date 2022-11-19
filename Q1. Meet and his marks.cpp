#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define sz(x) (int)(x.size())

const long long INF = 4e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int S = accumulate(v.begin(), v.end(), 0ll);
  cout << min(S, m) << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(9);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}