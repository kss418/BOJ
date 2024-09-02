#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string word1, word2;
vector <int> arr[1001];
int result[1001][1001];

int main() {
	cin >> word1;
	cin >> word2;

	for (int i = 0; i < word1.size(); i++) {
		for (int j = 0; j < word2.size(); j++) {
			if (word1[i] == word2[j]) {
				result[i + 1][j + 1] = result[i][j] + 1;
			}
			else {
				result[i + 1][j + 1] = max(result[i][j + 1], result[i + 1][j]);
			}
		}
	}

	cout << result[word1.size()][word2.size()];

	return 0;
}

