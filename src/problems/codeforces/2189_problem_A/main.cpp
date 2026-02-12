#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Type shortcuts
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

// Common templates
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template <typename T>
T mod_pow(T base, T exp, T mod) {
  T result = 1;
  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
  int n, h, l;
  cin >> n >> h >> l;

  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int minHL = min(h, l);
  int maxHL = max(h, l);

  // Count numbers that can be used for both row and column
  int count_both = 0;
  // Count numbers that can only be used for the larger dimension
  int count_one = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] <= minHL) {
      count_both++;
    } else if (a[i] <= maxHL) {
      count_one++;
    }
  }

  // Maximum pairs: limited by numbers that can be columns (count_both)
  // and total numbers available for pairing (count_both + count_one)
  int ans = min(count_both, (count_both + count_one) / 2);

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
