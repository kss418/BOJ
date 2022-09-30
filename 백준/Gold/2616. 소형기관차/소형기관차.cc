#include <iostream>
#include <algorithm>
using namespace std;
int n, k, ord = 0, si = 0;
int arr[50001] = {}, sum[50001] = {};
int dp[50001][4] = { 0, };


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < k; j++) {
            sum[i] += arr[i + j];
        }
    }

    for (int i = 0; i <= n; i++) {
        if(i >= k - 1){
            for (int j = 1; j <= 3; j++) {
                dp[i][j] = max(dp[i - k][j - 1] + sum[i - k], dp[i - 1][j]);
            }
        }
    }

    cout << dp[n][3];


    return 0;
}

