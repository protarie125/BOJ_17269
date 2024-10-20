#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

const vl kAlphToNum{3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3,
                    2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

ll n, m;
string a, b;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  cin >> a >> b;
  const auto& w = max(n, m);
  auto now = vl(w * 2, 0);
  auto j = 0;
  for (auto i = 0; i < w; ++i) {
    if (i < n) {
      now[j] = kAlphToNum[a[i] - 'A'];
      ++j;
    }
    if (i < m) {
      now[j] = kAlphToNum[b[i] - 'A'];
      ++j;
    }
  }

  for (auto i = 0; i < n + m - 2; ++i) {
    auto nxt = vl(w * 2, 0);
    for (auto j = 0; j < w * 2 - 1; ++j) {
      nxt[j] = now[j] + now[j + 1];
      nxt[j] %= 10;
    }

    now = nxt;
  }

  if (now[0] != 0) {
    cout << now[0];
  }
  cout << now[1] << "%";

  return 0;
}