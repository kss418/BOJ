#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 303;
const ll INF = 1e9;
ll n, a[MAX], dp[MAX][2];

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    for(int i = 1;i <= n;i++){
		dp[i][1] = dp[i - 1][0] + a[i];
        if(i >= 2) dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
        else dp[i][0] = a[i];
    }

    cout << max(dp[n][0], dp[n][1]);

    return 0;
}

