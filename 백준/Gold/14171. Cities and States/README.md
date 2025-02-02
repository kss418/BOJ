# [Gold V] Cities and States - 14171 

[문제 링크](https://www.acmicpc.net/problem/14171) 

### 성능 요약

메모리: 32284 KB, 시간: 304 ms

### 분류

자료 구조, 해싱, 해시를 사용한 집합과 맵

### 제출 일자

2025년 2월 2일 11:21:18

### 문제 설명

<p>To keep his cows intellectually stimulated, Farmer John has placed a large map of the USA on the wall of his barn. Since the cows spend many hours in the barn staring at this map, they start to notice several curious patterns. For example, the cities of Flint, MI and Miami, FL share a very special relationship: the first two letters of "Flint" give the state code ("FL") for Miami, and the first two letters of "Miami" give the state code ("MI") for Flint.</p>

<p>Let us say that two cities are a "special pair" if they satisfy this property and come from different states. The cows are wondering how many special pairs of cities exist. Please help them solve this amusing geographical puzzle!</p>

### 입력 

 <p>The first line of input contains N (1≤N≤200,000), the number of cities on the map.</p>

<p>The next N lines each contain two strings: the name of a city (a string of at least 2 and at most 10 uppercase letters), and its two-letter state code (a string of 2 uppercase letters). Note that the state code may be something like ZQ, which is not an actual USA state. Multiple cities with the same name can exist, but they will be in different states.</p>

### 출력 

 <p>Please output the number of special pairs of cities.</p>

