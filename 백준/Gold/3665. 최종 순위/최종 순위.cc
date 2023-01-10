#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 510;
int a[MAX];
int arr[MAX][MAX];
int indegree[MAX];
bool v[MAX];
int mi, ma;
vector <int> result;
deque <int> q;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(arr, 0, sizeof(arr));
        memset(indegree, 0, sizeof(indegree));
        memset(v, 0, sizeof(v));
        result.clear();

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (i < j) {
                    arr[a[i]][a[j]] = 1;
                    arr[a[j]][a[i]] = 0;
                    indegree[a[j]]++;
                }
                else {
                    arr[a[i]][a[j]] = 0;
                    arr[a[j]][a[i]] = 1;
                    indegree[a[i]]++;
                }
            }
        }

        cin >> m;
        for (int i = 1; i <= m; i++) {
            int st, en;
            cin >> st >> en;
            if (arr[st][en]) {
                indegree[en]--;
                indegree[st]++;
            }
            else {
                indegree[en]++;
                indegree[st]--;
            }

            arr[st][en] ^= 1;
            arr[en][st] ^= 1;
        }

        for (int i = 1; i <= n; i++) {
            if (!indegree[i]) {
                q.push_back(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();
            if (v[cur]) {
                continue;
            }

            cnt++;
            v[cur] = 1;
            result.push_back(cur);
            
            for (int i = 1; i <= n; i++) {
                if (arr[cur][i]) {
                    indegree[i]--;
                    if (!indegree[i]) {
                        q.push_back(i);
                    }
                }
            }
        }

        if (cnt == n) {
            for (auto i : result) {
                cout << i << " ";
            }
        }
        else {
            cout << "IMPOSSIBLE";
        }
        cout << "\n";
    }

    return 0;
}