# [Platinum III] City Attractions - 14875 

[문제 링크](https://www.acmicpc.net/problem/14875) 

### 성능 요약

메모리: 57340 KB, 시간: 572 ms

### 분류

자료 구조, 깊이 우선 탐색, 데이크스트라, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 함수형 그래프, 그래프 이론, 그래프 탐색, 최단 경로, 슬라이딩 윈도우, 희소 배열, 트리

### 제출 일자

2026년 1월 11일 16:31:59

### 문제 설명

<p>In the beautiful country of Moldova there are N cities, indexed from 1 to N, with bidirectional roads connecting some of them. In order to be more economical, the government built exactly N - 1 roads connecting these cities, such that you can go between any two cities by walking through some of the roads.</p>

<p>By a national decree, each of the N cities in Moldova has been assigned a non-negative beauty factor. For city i this beauty factor is equal to a<sub>i</sub>. Different cities could have equal beauty factors.</p>

<p>Our hero Gigel has arrived to Moldova and he’s currently in city number 1. He’s really eager to visit all the beautiful cities, but he’s quite indecisive and can’t decide which ones to visit, mainly because he has limited time. He will be staying in Moldova for K more days, and on each day he’ll visit some city. On the i<sup>th</sup> day, he will start from city x in which he ended up the previous day (x = 1 if it’s his first day), and he’ll find another city y ≠ x such that a<sub>y</sub> - d(x, y) is maximal. Here d(x, y) denotes the minimum number of roads you need to travel starting from city x in order to reach city y. If there are multiple such cities, he’ll choose the one with the minimal index. After this he’ll go to city y and will stay there to admire the local attractions for the remaining time of day i. The next day he’ll repeat this process again.</p>

<p>Gigel is wondering in which city will he end up at the end of the K<sup>th</sup> day, and he’s asking for your help!</p>

<p>Write a program that will calculate in which city Gigel will end up after K days.</p>

### 입력 

 <p>The first line of the standard input contains two integers N and K the number of cities and the number of days Gigel will be visiting. The next line of the standard input will contain N integers a<sub>i</sub> where a<sub>i</sub> denotes the beauty of the i<sup>th</sup> city. The next N - 1 lines of the standard input contain two integers u<sub>i</sub> and v<sub>i</sub>, with the meaning that there is a bidirectional road between cities u<sub>i</sub> and v<sub>i</sub>.</p>

### 출력 

 <p>Write in the standard output one integer - the index of the city Gigel will end up at the end of the K<sup>th</sup> day.</p>

