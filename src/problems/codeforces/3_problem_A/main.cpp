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
  string s, t;
  cin >> s >> t;

  // Convert positions to coordinates
  int x1 = s[0] - 'a';  // column (0-7)
  int y1 = s[1] - '1';  // row (0-7)
  int x2 = t[0] - 'a';
  int y2 = t[1] - '1';

  // Calculate differences
  int dx = x2 - x1;
  int dy = y2 - y1;

  // The minimum number of moves is the maximum of absolute differences
  int moves = max(abs(dx), abs(dy));

  cout << moves << "\n";

  // Generate the move sequence
  while (dx != 0 || dy != 0) {
    string move = "";

    // Horizontal component first
    if (dx > 0) {
      move += "R";
      dx--;
    } else if (dx < 0) {
      move += "L";
      dx++;
    }

    // Vertical component second
    if (dy > 0) {
      move += "U";
      dy--;
    } else if (dy < 0) {
      move += "D";
      dy++;
    }

    cout << move << "\n";
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
  // cin >> t;  // Comment this line if single test case

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
