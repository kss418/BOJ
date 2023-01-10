#include <iostream> 
#include <algorithm>
#include <vector> 
#include <cstring>
#include <deque> 
#include <set>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 2010;
int sum[MAX][30];


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 30; j++) {
            if (s[i - 1] - 'a' == j) {
                sum[i][j] = sum[i - 1][j] + 1;
            }
            else {
                sum[i][j] = sum[i - 1][j];
            }
        }
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        char al;
        int st, en;
        cin >> al >> st >> en;
        cout << sum[en + 1][al - 'a'] - sum[st][al - 'a'] << "\n";
    }
    
 

    return 0;
}