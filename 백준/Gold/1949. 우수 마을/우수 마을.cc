#include <iostream> #include <algorithm>
#include <vector> #include <cstring>
#include <deque> #include <set>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 10101;
int a[MAX];
vector <int> arr[MAX];
int dp[MAX][2];

void dfs(int cur, int p) {
    for (auto nxt : arr[cur]) {
        if (nxt == p) {
            continue;
        }
        dfs(nxt, cur);
        dp[cur][1] += dp[nxt][0];
        dp[cur][0] += max(dp[nxt][1], dp[nxt][0]);
    }
    dp[cur][1] += a[cur];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int st, en;
        cin >> st >> en;
        arr[st].push_back(en);
        arr[en].push_back(st);
    }

    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]);

    return 0;
}