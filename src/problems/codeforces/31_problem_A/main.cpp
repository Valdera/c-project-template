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
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// ====================================
// Problem: 31_problem_A - Worms Evolution
// ====================================

void solve() {
  int n;
  cin >> n;
 vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Try all possible triples (i, j, k)
  // We need to find i, j, k such that a[i] = a[j] + a[k]
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        // Check if indices are distinct
        if (i != j && i != k && j != k) {
          if (a[i] == a[j] + a[k]) {
            cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
            return;
          }
        }
      }
    }
  }

  cout << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifdef LOCAL
  freopen("data/input.txt", "r", stdin);
#endif

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

