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
// Problem: 33_problem_A - What is for dinner?
// ====================================

/*
 * Solution explanation:
 * Valerie can eat crucians using one tooth row at a time.
 * Each time she eats a crucian with a specific row, all teeth in that row
 * decrease their viability by 1.
 *
 * The maximum number of crucians she can eat with a specific row is limited by
 * the minimum viability of any tooth in that row (the weakest tooth in the row).
 *
 * Strategy:
 * 1. For each row, find the minimum viability among all teeth in that row
 * 2. Sum up all these minimums (this is the max total crucians she can eat)
 * 3. Take the minimum of this sum and k (the available crucians)
 */

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  // For each row, track the minimum viability
  vector<int> min_viability(m + 1, INF);
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    min_viability[r] = min(min_viability[r], c);
  }

  // Calculate total crucians that can be eaten
  ll total = 0;
  for (int i = 1; i <= m; i++) {
    if (min_viability[i] != INF) {
      total += min_viability[i];
    }
  }

  // The answer is the minimum of total capacity and available crucians
  cout << min((ll)k, total) << endl;
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
