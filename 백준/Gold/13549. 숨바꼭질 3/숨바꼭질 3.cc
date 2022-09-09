#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;




int main() {
    int n, k, num, tmp;
    cin >> n >> k;
    int dp[100001];
    for(int i = 0;i < 100001;i++){
        dp[i] = -1;
    }
    dp[n] = 0;
    deque <int> q;
    q.push_back(n);
    while(q.size() > 0){
        num = q.front();
        tmp = num;
        q.pop_front();
        tmp *= 2;
        while(tmp <= 100001 && tmp != 0){
            if (dp[tmp] == -1){
            dp[tmp] = dp[num];
            q.push_back(tmp);
            }
            tmp *= 2;
        }
        if (num+1 <= 100001 && dp[num+1] == -1){
            dp[num+1] = dp[num] + 1;
            q.push_back(num+1);
        }
        if (num-1 >= 0 && dp[num-1] == -1){
            dp[num-1] = dp[num] + 1;
            q.push_back(num-1);
        }
    }
    
    cout << dp[k] << endl;
    return 0;
}