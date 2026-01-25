/**
 * αυτός που σκέφτεται αυτό που βλέπει
 */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

// ----------------------<SHORT>--------------------------
#define ll long long int
#define ld long double
#define si set<long long int>
#define vi vector<long long int>
#define pii pair<long long int, long long int>
#define vpi vector<pii>
#define vpp vector<pair<long long int, pii>>
#define mii map<long long int, long long int>
#define mci map<char, long long int>
#define mpi map<pii, long long int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((long long int)x.size())
#define all(p) p.begin(), p.end()
#define que_max priority_queue<long long int>
#define que_min priority_queue<long long int, vi, greater<long long int>>
// ----------------------</SHORT>--------------------------

// ----------------------<CONST>--------------------------

#define PI 3.1415926535897932384626433832795l

constexpr int MAX_N = 1e5 + 5;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9;
constexpr ld EPS = 1e-9;
constexpr int N = 200005;

// ----------------------</CONST>--------------------------

// ----------------------<MATH>---------------------------
template <typename T>
T gcd(T a, T b) {
  while (b) {
    T temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}

// ----------------------</MATH>--------------------------

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  int minRow = n, maxRow = -1;
  int minCol = m, maxCol = -1;

  // Find bounding box of all shaded squares
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '*') {
        minRow = min(minRow, i);
        maxRow = max(maxRow, i);
        minCol = min(minCol, j);
        maxCol = max(maxCol, j);
      }
    }
  }

  // Output the rectangle
  for (int i = minRow; i <= maxRow; i++) {
    for (int j = minCol; j <= maxCol; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef ONLINE_JUDGE
  freopen(SRC_PATH "/input.txt", "r", stdin);
  freopen(SRC_PATH "/output.txt", "w", stdout);
#endif

  clock_t z = clock();
  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  cerr << "Run Time : " << (static_cast<double>(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}
