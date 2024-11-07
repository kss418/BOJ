#include <bits/stdc++.h>
#define rep(i, a, n) for(auto i = a; i < n; i++)
#define REP(i, a, n) for(auto i = a; i <= n; i++)
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

vector<int> start(1'000'004);
vector<int> en(1'000'004);
int dp[1'000'004];
int MAX = 1'000'003;

int n, q, s, e;

int main(void) {

    FAST_IO;
    int n;
    cin >> n;

    rep(i, 0, n) {
        cin >> s >> e;
        start[s]++;    // 시작 값

        en[e+1]++; // 시간 끝나는 값 + 1 => 끝나는 시간 +1부터 사용할 수 있으니깐
    }


    dp[0] = start[0];
    REP(i, 1, MAX) {
        dp[i] = dp[i - 1] + start[i] - en[i];
     }

    cin >> q;
    rep(i, 0, q) {
        int num; cin >> num;
        cout << dp[num] << endl;
    }

    return 0;
}