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

// IO setup
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void setup_io() {
#ifndef ONLINE_JUDGE
  freopen(SRC_PATH "/input.txt", "r", stdin);
  freopen(SRC_PATH "/output.txt", "w", stdout);
#endif
}

// ============================================================================
// Solution
// ============================================================================

void solve() {
  int n;
  cin >> n;

  // Special cases: if we can only form one team
  if (n == 2 || n == 3) {
    cout << n << "\n";
    return;
  }

  // For n >= 4:
  // If n is even, we can split evenly using teams of 2
  // If n is odd, best we can do is difference of 1
  if (n % 2 == 0) {
    cout << 0 << "\n";
  } else {
    cout << 1 << "\n";
  }
}

// ============================================================================
// Main
// ============================================================================

int main() {
  fast_io();
  setup_io();

  clock_t start_time = clock();

  int t = 1;
  cin >> t;  // Comment this line if single test case

  while (t--) {
    solve();
  }

#ifndef ONLINE_JUDGE
  clock_t end_time = clock();
  cerr << "\nTime: " << fixed << setprecision(6)
       << (double)(end_time - start_time) / CLOCKS_PER_SEC << " sec\n";
#endif

  return 0;
}
