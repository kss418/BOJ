#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 33;
const ll MID = 50101;
ll n, m, a[MAX], b[MAX];
ll dp[MAX][101010];


ll solve(ll cur, ll num){
    if(num < 0 || num > 101010) return 0;
    ll& ret = dp[cur][num];
    if(ret != -1) return ret;
    if(cur == 0) return ret = (num == MID ? 1 : 0);

    ret = max(ret, solve(cur - 1, num));
    ret = max(ret, solve(cur - 1, num + a[cur]));
    ret = max(ret, solve(cur - 1, num - a[cur]));

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> m;
    for(int i = 1;i <= m;i++) cin >> b[i];

    for(int i = 0;i <= n;i++){
        for(int j = 0;j < 101010;j++) dp[i][j] = -1;
    }

    for(int i = 1;i <= m;i++){
        cout << (solve(n, b[i] + MID) ? "Y" : "N") << " ";
    }

    return 0;
}

