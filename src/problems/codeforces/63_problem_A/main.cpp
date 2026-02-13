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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

struct CrewMember {
  string name;
  string status;
  int order;
  int priority;

  CrewMember(string n, string s, int o) : name(n), status(s), order(o) {
    if (status == "rat") {
      priority = 1;
    } else if (status == "woman" || status == "child") {
      priority = 2;
    } else if (status == "man") {
      priority = 3;
    } else if (status == "captain") {
      priority = 4;
    }
  }

  bool operator<(const CrewMember& other) const {
    if (priority != other.priority) {
      return priority < other.priority;
    }
    return order < other.order;
  }
};

void solve() {
  int n;
  cin >> n;

  vector<CrewMember> crew;
  for (int i = 0; i < n; i++) {
    string name, status;
    cin >> name >> status;
    crew.pb(CrewMember(name, status, i));
  }

  sort(all(crew));

  for (const auto& member : crew) {
    cout << member.name << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
