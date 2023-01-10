#include <iostream> 
#include <algorithm>
#include <vector> 
#include <cstring>
#include <deque> 
#include <set>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 10101;
int a[MAX], dp[MAX][2];
vector <int> result[MAX][2];
vector <int> arr[MAX];

void dfs(int cur,int p) {
    for (auto nxt : arr[cur]) {
        if (nxt == p) {
            continue;
        }

        dfs(nxt, cur);
        if (dp[nxt][0] > dp[nxt][1]) {
            dp[cur][0] += dp[nxt][0];
            for (auto i : result[nxt][0]) {
                result[cur][0].push_back(i);
            }
        }
        else {
            dp[cur][0] += dp[nxt][1];
            for (auto i : result[nxt][1]) {
                result[cur][0].push_back(i);
            }
        }

        dp[cur][1] += dp[nxt][0];
        for (auto i : result[nxt][0]) {
            result[cur][1].push_back(i);
        }
    }

    dp[cur][1] += a[cur];
    result[cur][1].push_back(cur);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int st, en;
        cin >> st >> en;
        arr[st].push_back(en);
        arr[en].push_back(st);
    }

    dfs(1, 0);

    if (dp[1][0] > dp[1][1]) {
        cout << dp[1][0] << "\n";
        sort(result[1][0].begin(), result[1][0].end());
        for (auto i : result[1][0]) {
            cout << i << " ";
        }
    }
    else {
        cout << dp[1][1] << "\n";
        sort(result[1][1].begin(), result[1][1].end());
        for (auto i : result[1][1]) {
            cout << i << " ";
        }
    }
 

    return 0;
}