#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define sz(x) (int)(x.size())

const long long INF = 4e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

void solve() {
  int n; cin >> n;

  string t = to_string(n);
  int Sum = 0;
  for (auto &c : t) {
    Sum += (c - '0');
  }

  int Length = (int)t.size();
  int P = 1;

  int ans = 0;
  for (int i = 0; i < Length; i++) {
    ans += (Sum * P);
    P *= 10;
  }
  cout << ans << endl;
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