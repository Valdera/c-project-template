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
  return (b ? __gcd(a, b) : a);
}

template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}

// ----------------------</MATH>--------------------------

int countDistinctPrimeDivisors(int n) {
  int count = 0;

  // Check for factor 2
  if (n % 2 == 0) {
    count++;
    while (n % 2 == 0) {
      n /= 2;
    }
  }

  // Check for odd factors from 3 onwards
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      count++;
      while (n % i == 0) {
        n /= i;
      }
    }
  }

  // If n is still greater than 1, then it's a prime factor
  if (n > 1) {
    count++;
  }

  return count;
}

void solve() {
  int n;
  cin >> n;

  int almostPrimeCount = 0;
  for (int i = 1; i <= n; i++) {
    if (countDistinctPrimeDivisors(i) == 2) {
      almostPrimeCount++;
    }
  }

  cout << almostPrimeCount << endl;
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
