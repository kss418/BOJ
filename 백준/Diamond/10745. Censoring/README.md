# [Diamond IV] Censoring - 10745 

[문제 링크](https://www.acmicpc.net/problem/10745) 

### 성능 요약

메모리: 24168 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 문자열, 트리, 스택, 트라이, 아호-코라식

### 제출 일자

2026년 1월 7일 15:11:08

### 문제 설명

<p>Farmer John has purchased a subscription to Good Hooveskeeping magazine for his cows, so they have plenty of material to read while waiting around in the barn during milking sessions. Unfortunately, the latest issue contains a rather inappropriate article on how to cook the perfect steak, which FJ would rather his cows not see (clearly, the magazine is in need of better editorial oversight).</p>

<p>FJ has taken all of the text from the magazine to create the string S of length at most 10^5 characters. He has a list of censored words t_1 ... t_N that he wishes to delete from S. To do so Farmer John finds the earliest occurrence of a censored word in S (having the earliest start index) and removes that instance of the word from S. He then repeats the process again, deleting the earliest occurrence of a censored word from S, repeating until there are no more occurrences of censored words in S. Note that the deletion of one censored word might create a new occurrence of a censored word that didn't exist before.</p>

<p>Farmer John notes that the censored words have the property that no censored word appears as a substring of another censored word. In particular this means the censored word with earliest index in S is uniquely defined.</p>

<p>Please help FJ determine the final contents of S after censoring is complete.</p>

### 입력 

 <p>The first line will contain S. The second line will contain N, the number of censored words. The next N lines contain the strings t_1 ... t_N. Each string will contain lower-case alphabet characters (in the range a..z), and the combined lengths of all these strings will be at most 10^5.</p>

### 출력 

 <p>The string S after all deletions are complete. It is guaranteed that S will not become empty during the deletion process.</p>

