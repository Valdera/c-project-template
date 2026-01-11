/**
  * αυτός που σκέφτεται αυτό που βλέπει
  */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
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
  return (b ? __gcd(a, b) : a);
}

template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}

// ----------------------</MATH>--------------------------

void solve() {
  pair<int, int> barn, lake;

  set<pair<int, int>> rocks;

  string line;
  for (int r = 0; r < 10; r++) {
    cin >> line;
    for (int c = 0; c < 10; c++) {
      if (line[c] == 'B') {
        barn = {r, c};
      } else if (line[c] == 'R') {
        rocks.insert({r, c});
      } else if (line[c] == 'L') {
        lake = {r, c};
      }
    }
  }

  set<pair<int, int>> visited;
  vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  queue<pair<pair<int, int>, int>> q;
  q.push({barn, 0});
  while (!q.empty()) {
    auto [pos, dist] = q.front();
    q.pop();

    auto [r, c] = pos;
    if (pos == lake) {
      cout << dist - 1 << endl;
      return;
    }

    visited.insert(pos);
    for (auto [dr, dc] : moves) {
      int nr = r + dr;
      int nc = c + dc;
      if (nr < 0 || nr >= 10 || nc < 0 || nc >= 10) {
        continue;
      }
      if (visited.find({nr, nc}) != visited.end() ||
          rocks.find({nr, nc}) != rocks.end()) {
        continue;
      }
      q.push({{nr, nc}, dist + 1});
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // freopen(SRC_PATH "/input.txt", "r", stdin);
  // freopen(SRC_PATH "/output.txt", "w", stdout);

  freopen("buckets.in", "r", stdin);
  freopen("buckets.out", "w", stdout);

  clock_t z = clock();
  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  cerr << "Run Time : " << (static_cast<double>(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}