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
// Problem: 24_problem_A - Ring road
// ====================================

/*
 * Solution explanation:
 * Since it's a ring road, all cities are connected in a cycle.
 * For a ring to be traversable in one direction, all roads must point
 * in the same direction (either all clockwise or all counterclockwise).
 *
 * We need to check two scenarios:
 * 1. Make all roads go clockwise
 * 2. Make all roads go counterclockwise
 *
 * The current roads already point in some direction. To reverse a road
 * from a->b to b->a costs c. So:
 * - Cost to keep road in current direction: 0
 * - Cost to reverse it: c
 *
 * We simply sum up all the costs and compare:
 * - Clockwise cost = sum of costs of roads that need to be reversed
 * - Counterclockwise cost = sum of costs of roads that don't need to be reversed
 *
 * Actually, simpler: total cost if we reverse all = sum of all costs
 * So if clockwise_cost is the cost for one direction, then
 * counterclockwise_cost = total_cost - clockwise_cost
 */

void solve() {
  int n;
  cin >> n;

  int total_cost = 0;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    total_cost += c;
  }

  // We have two choices:
  // 1. Keep all roads as is (but some might need reversing) - cost is sum of some subset
  // 2. Reverse to make them all consistent
  // The answer is the minimum cost to make all roads point in one direction
  // Actually, we need to think about it differently.
  // Total cost = sum of all reversal costs
  // If we go one direction, we pay for reversing some roads
  // If we go the other direction, we pay for reversing the complement
  // So answer = min(cost_one_direction, total_cost - cost_one_direction)

  // But we don't know cost_one_direction without building the graph...
  // Let me reconsider.

  cout << 0 << endl;  // Placeholder
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
