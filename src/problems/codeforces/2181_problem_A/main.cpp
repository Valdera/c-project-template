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
` typedef vector<pll> vpll;

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
  int n, m;
  cin >> n >> m;

  vector<string> streets(n);
  vector<map<char, int>> freq(n);
  map<char, int> total_freq;

  // Read streets and count character frequencies
  for (int i = 0; i < n; i++) {
    cin >> streets[i];
    for (char c : streets[i]) {
      freq[i][c]++;
      total_freq[c]++;
    }
  }

  // For each street ℓ (the one whose order was lost)
  for (int l = 0; l < n; l++) {
    int k_max = m;
    bool possible = true;

    // For each character that appears in street ℓ
    for (auto& [c, count_l] : freq[l]) {
      // sum_except_l = total count of char c in all streets except ℓ
      int sum_except_l = total_freq[c] - count_l;

      if (sum_except_l == 0) {
        // Cannot create even one copy of street ℓ
        possible = false;
        break;
      }

      // Constraint: (m - k) * sum_except_l >= count_l
      // => k <= m - ceil(count_l / sum_except_l)
      int ceil_div = (count_l + sum_except_l - 1) / sum_except_l;
      int k_constraint = m - ceil_div;
      k_max = min(k_max, k_constraint);
    }

    if (!possible || k_max < 0) {
      cout << -1;
    } else {
      cout << k_max;
    }

    if (l < n - 1)
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
