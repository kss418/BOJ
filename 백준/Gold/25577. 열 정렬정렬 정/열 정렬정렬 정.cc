#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 101010;
bool v[MAX]; 
vector <pair<int, int>> arr;
int a[MAX];

int dfs(int cur, int cnt) {
    if (v[cur]) {
        return cnt;
    }
    v[cur] = 1;

    return dfs(a[cur], cnt + 1);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;    
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        arr.push_back({ num,i });
    }

    sort(arr.begin(), arr.end());
    int cnt = 1;
    for (auto i : arr) {
        a[i.second] = cnt++;
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i]) {
            continue;
        }
        result += dfs(i, 0) - 1;
    }

    cout << result;


    return 0;
}