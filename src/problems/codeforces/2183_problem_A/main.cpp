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
  vector<int> a(n);
  int zeros = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      zeros++;
    }
  }

  // LOGIC EXPLANATION:
  // 1. If there are no zeros (all 1s), Alice takes the whole array.
  //    It becomes 0. Alice wins immediately.
  // 2. If there are zeros:
  //    Alice wins if she can turn the array into "1 1" for Bob.
  //    This requires taking a subarray of length N-1 that includes ALL zeros.
  //    This is impossible ONLY if there is a zero at a[0] AND a[n-1].

  if (zeros == 0) {
    cout << "Alice\n";
  } else {
    // If zeros exist at both ends, Alice cannot eliminate all zeros
    // to force the "1 1" state. She passes a winning state to Bob.
    if (a[0] == 0 && a[n - 1] == 0) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
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
