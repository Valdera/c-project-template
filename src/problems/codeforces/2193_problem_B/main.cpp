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
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;
const int MAX_N = 2e5 + 5;

// Debug
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

// Fast I/O
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

// File I/O setup
void setup_io() {
#ifndef ONLINE_JUDGE
  string input_path = string(SRC_PATH) + "/input.txt";
  string output_path = string(SRC_PATH) + "/output.txt";

  freopen(input_path.c_str(), "r", stdin);
  freopen(output_path.c_str(), "w", stdout);
#endif
}

// ============================================================================
// Solution
// ============================================================================

void solve() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  // Strategy: To get the lexicographically maximum permutation,
  // we want to maximize the prefix.
  // Find the first position where p[i] != n - i
  // Then find the maximum value in the remaining part and reverse to bring it forward

  // Find the first position where we don't have the maximum possible value
  int start = 0;
  for (int i = 0; i < n; i++) {
    // At position i, the maximum possible value we could have is n - i
    // But we need to check if n - i exists in the suffix starting from i
    int target = n - i;

    // Find if target exists from position i onwards
    int pos = -1;
    for (int j = i; j < n; j++) {
      if (p[j] == target) {
        pos = j;
        break;
      }
    }

    // If we found the target and it's not already at position i
    if (pos != -1 && pos != i) {
      // Reverse the segment [i, pos]
      reverse(p.begin() + i, p.begin() + pos + 1);
      break;
    }

    // If p[i] is already the maximum possible at this position, continue
    if (p[i] == target) {
      continue;
    }

    // If we can't place the maximum at this position,    // we should still try to maximize from here
    // Find the maximum in the remaining part
    int max_val = p[i];
    int max_pos = i;
    for (int j = i + 1; j < n; j++) {
      if (p[j] > max_val) {
        max_val = p[j];
        max_pos = j;
      }
    }

    if (max_pos != i) {
      reverse(p.begin() + i, p.begin() + max_pos + 1);
    }
    break;
  }

  // Output the result
  for (int i = 0; i < n; i++) {
    cout << p[i];
    if (i < n - 1)
      cout << " ";
  }
  cout << "\n";
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
