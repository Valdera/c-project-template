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
  string s;
  cin >> n >> s;

  // Count the number of students already seated
  int total_students = 0;
  for (char c : s) {
    if (c == '1') {
      total_students++;
    }
  }

  // Special case: if no students initially, we need ceil(n/3) students
  // Each student blocks 3 positions (left, self, right)
  if (total_students == 0) {
    cout << (n + 2) / 3 << "\n";
    return;
  }

  // Find all gaps (consecutive 0s) and determine how many students to add
  int gap_length = 0;
  bool has_left_student = false;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      gap_length++;
    } else {
      // s[i] == '1', process the gap before it
      if (gap_length > 0) {
        // Calculate unblocked positions in the gap
        int unblocked;
        if (has_left_student) {
          // Gap between two students - both ends are blocked
          unblocked = gap_length - 2;
        } else {
          // Gap at the beginning - right end is blocked
          unblocked = gap_length - 1;
        }

        // Add students to cover unblocked positions
        if (unblocked > 0) {
          total_students += (unblocked + 2) / 3;
        }
        gap_length = 0;
      }
      has_left_student = true;
    }
  }

  // Handle trailing gap
  if (gap_length > 0) {
    // Gap at the end - left end is blocked if there's a student on the left
    int unblocked = has_left_student ? gap_length - 1 : gap_length;
    if (unblocked > 0) {
      total_students += (unblocked + 2) / 3;
    }
  }

  cout << total_students << "\n";
}

int main() {
  fast_io();
  setup_io();

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
