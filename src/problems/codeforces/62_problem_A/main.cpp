/**
 * αυτός που σκέφτεται αυτό που βλέπει
 */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
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

bool canHoldHands(int g, int b) {
  // g = girl fingers, b = boy fingers
  // Need at least (g-1) boy fingers to separate girl fingers
  // Can have at most 2*(g+1) boy fingers (at most 2 in each of g+1 gaps)
  return (g - 1 <= b) && (b <= 2 * g + 2);
}

void solve() {
  int al, ar, bl, br;
  cin >> al >> ar >> bl >> br;

  // Configuration 1: Boy goes left (boy's right hand with girl's left hand)
  bool config1 = canHoldHands(al, br);

  // Configuration 2: Boy goes right (boy's left hand with girl's right hand)
  bool config2 = canHoldHands(ar, bl);

  if (config1 || config2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
