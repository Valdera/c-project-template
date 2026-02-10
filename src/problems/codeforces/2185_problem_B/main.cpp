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

ll calculateValue(const vector<int>& a) {
  ll value = 0;
  int currentMax = 0;
  for (int i = 0; i < a.size(); i++) {
    currentMax = max(currentMax, a[i]);
    value += currentMax;
  }
  return value;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Strategy: To maximize the sum of prefix maximums, we want the maximum
  // element to appear as early as possible.
  // The best swap is to put the overall maximum at position 0.

  // Find the maximum value and its index
  int maxVal = *max_element(all(a));
  // Calculate the current value without swapping
  ll maxValue = calculateValue(a);

  // Try swapping the first occurrence of the maximum with position 0
  for (int i = 0; i < n; i++) {
    if (a[i] == maxVal) {
      // Swap with position 0
      vector<int> temp = a;
      swap(temp[0], temp[i]);
      ll newValue = calculateValue(temp);
      maxValue = max(maxValue, newValue);
      break;  // Only need to try first occurrence
    }
  }

  cout << maxValue << "\n";
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
