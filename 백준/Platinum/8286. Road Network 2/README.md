# [Platinum V] Road Network 2 - 8286 

[문제 링크](https://www.acmicpc.net/problem/8286) 

### 성능 요약

메모리: 58820 KB, 시간: 832 ms

### 분류

해 구성하기, 차수열, 그래프 이론, 그리디 알고리즘, 트리

### 제출 일자

2024년 12월 30일 10:54:04

### 문제 설명

<p>Byteasar is going for a road trip around Byteland. Unfortunately, he was unable to buy a map of the country. From his friends he learned a few properties of the Bytean road network:</p>

<ul>
	<li>There are n cities in Byteland, numbered 1 through n.</li>
	<li>Each road is bidirectional and connects two different cities.</li>
	<li>Each pair of different cities is connected by exactly one path, consisting of one or more roads, on which no city appears more than once.</li>
	<li>There are exactly d<sub>i</sub> roads starting at the city number i.</li>
</ul>

<p>Byteasar is going to reconstruct the road map of Byteland. The number of possible road networks satisfying the conditions can be quite big, so Byteasar will be satisfied with any correct plan.</p>

### 입력 

 <p>The first line of input contains one integer n (2 ≤ n ≤ 2,000,000). The second line contains n integers d<sub>i</sub> (1 ≤ di ≤ n-1).</p>

### 출력 

 <p>If no road network plan satisfying the conditions from the input exists, the first and only line of output should contain a single word BRAK - i.e., none in Polish. In the opposite case each of the lines in the output should contain a description of one bidirectional road - two different integers in the range [1, n] denoting the numbers of cities connected by this road. Output each road exactly once. The order of roads and cities connected by roads in the output can be arbitrary.</p>

