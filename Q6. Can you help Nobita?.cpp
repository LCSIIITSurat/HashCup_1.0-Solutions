#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define sz(x) (int)(x.size())

const long long INF = 4e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

int mod_exp(int a, int b, int mod) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
int mod_mul(int a, int b, int m) {
  a = a % m; b = b % m;
  return (((a * b) % m) + m) % m;
}

void solve() {
  int p, q, r; cin >> p >> q >> r;
  vector<int> A(p);
  for (int &i : A) {
    cin >> i;
  }

  vector<int> B(q);
  for (int &i : B) {
    cin >> i;
  }

  vector<int> C(r);
  for (int &i : C) {
    cin >> i;
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  vector<int> PA(p + 1);
  for (int i = 0; i < p; i++) {
    PA[i + 1] = (PA[i] + A[i]) % M;
  }

  vector<int>  PC(r + 1);
  for (int i = 0; i < r; i++) {
    PC[i + 1] = (PC[i] + C[i]) % M;
  }

  int ans = 0;
  for (int i = 0; i < q; i++) {
    int it1 = (int)(upper_bound(A.begin(), A.end(), B[i]) - A.begin());
    int it2 = (int)(upper_bound(C.begin(), C.end(), B[i]) - C.begin());

    if (it1 == 0 || it2 == 0) {
      continue;
    }

    int pa = PA[it1];
    int pc = PC[it2];

    int y2 = mod_exp(B[i], 2, M);
    y2 = mod_mul(y2, it1 * it2, M);

    int xy = mod_mul(it2, pa, M);
    int yz = mod_mul(it1, pc, M);
    int x_z = mod_mul(B[i], xy + yz, M);

    int xz = mod_mul(pa, pc, M);

    ans += y2; ans %= M;
    ans += x_z; ans %= M;
    ans += xz; ans %= M;
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