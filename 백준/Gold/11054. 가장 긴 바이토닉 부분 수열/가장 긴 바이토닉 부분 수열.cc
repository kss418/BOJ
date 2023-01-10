#include <iostream> 
#include <algorithm>
#include <vector> 
#include <cstring>
#include <deque> 
#include <set>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 1010;
int arr[MAX];
int dp[MAX][2];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
            }
            else if (arr[i] < arr[j]) {
                dp[i][1] = max({ dp[j][1] + 1,dp[j][0] + 1, dp[i][1] });
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = max({ result, dp[i][0], dp[i][1] });
    }
    cout << result;

    return 0;
}