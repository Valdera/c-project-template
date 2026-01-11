/**
 * αυτός που σκέφτεται αυτό που βλέπει
 */

/**
* Title: Two Sets
* Link: https://cses.fi/problemset/task/1092
*/

#include <algorithm>
#include <ctime>  // For clock_t, clock, CLOCKS_PER_SEC
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

// ----------------------<SHORT>--------------------------
#define F first
#define S second
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

#define REP(i, k, n) for (i = k; i < n; i++)
#define REPT(i, k, n) for (i = k; i <= n; i++)
#define REPR(i, k, n) for (i = k; i > n; i--)
#define REPRT(i, k, n) for (i = k; i >= n; i--)

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

int add(int a, int b, int c = MOD) {
  int res = a + b;
  return (res >= c ? res - c : res);
}

int mod_neg(int a, int b, int c = MOD) {
  int res;
  if (abs(a - b) < c)
    res = a - b;
  else
    res = (a - b) % c;
  return (res < 0 ? res + c : res);
}

int mul(int a, int b, int c = MOD) {
  const ll res = static_cast<ll>(a) * b;
  return static_cast<int>(res >= c ? res % c : res);
}

int muln(int a, int b, int c = MOD) {
  const ll res = static_cast<ll>(a) * b;
  return static_cast<int>(((res % c) + c) % c);
}

ll mulmod(ll a, ll b, ll m = MOD) {
  ll q = static_cast<long long int>(
      (static_cast<long double>(a) * static_cast<long double>(b)) /
      static_cast<long double>(m));
  ll r = a * b - q * m;
  if (r > m)
    r %= m;
  if (r < 0)
    r += m;
  return r;
}

template <typename T>
T expo(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1)
      x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}

template <typename T>
T power(T e, T n, T m = MOD) {
  T x = 1, p = e;
  while (n) {
    if (n & 1)
      x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}

template <typename T>
T extended_euclid(T a, T b, T& x, T& y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}

template <typename T>
T mod_inverse(T a, T n = MOD) {
  T x, y, z = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : mod_neg(x, z, n));
}

// ----------------------</MATH>--------------------------

// ----------------------</BITWISE>--------------------------
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a, b) (!!((a) & (1ULL << (b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

// ----------------------</BITWISE END>--------------------------

void solve() {
  ll n;
  vi nums;
  cin >> n;

  const ll sum = n * (n + 1) / 2;

  if (sum % 2 != 0) {
    cout << "NO" << endl;
    return;
  }

  vi nums1 = {};
  vi nums2 = {};

  cout << "YES" << endl;
  ll target = sum / 2;
  for (ll curr = n; curr > 0; --curr) {
    if (target - curr >= 0) {
      nums1.push_back(curr);
      target -= curr;
    } else {
      nums2.push_back(curr);
    }
  }

  cout << nums1.size() << endl;
  for (const auto curr : nums1) {
    cout << curr << " ";
  }
  cout << endl;

  cout << nums2.size() << endl;
  for (const auto curr : nums2) {
    cout << curr << " ";
  }
  cout << endl;
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