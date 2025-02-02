# [Gold II] Dessert - 27081 

[문제 링크](https://www.acmicpc.net/problem/27081) 

### 성능 요약

메모리: 2020 KB, 시간: 204 ms

### 분류

백트래킹, 브루트포스 알고리즘, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 2월 3일 01:54:17

### 문제 설명

<p>FJ has a new rule about the cows lining up for dinner. Not only must the N (3 ≤ N ≤ 15) cows line up for dinner in order, but they must place a napkin between each pair of cows with a "+", "-", or "." on it. In order to earn their dessert, the cow numbers and the napkins must form a numerical expression that evaluates to 0. The napkin with a "." enables the cows to build bigger numbers. Consider this equation for seven cows:</p>

<pre style="text-align: center;">1 - 2 . 3 - 4 . 5 + 6 . 7</pre>

<p>This means 1-23-45+67, which evaluates to 0. You job is to assist the cows in getting dessert. (Note: "... 10 . 11 ...") will use the number 1011 in its calculation.)</p>

### 입력 

 <p>One line with a single integer, N</p>

### 출력 

 <p>One line of output for each of the first 20 possible expressions -- then a line with a single integer that is the total number of possible answers. Each expression line has the general format of number, space, napkin, space, number, space, napkin, etc. etc. The output order is lexicographic, with "+" coming before "-" coming before ".". If fewer than 20 expressions can be formed, print all of the expressions.</p>

