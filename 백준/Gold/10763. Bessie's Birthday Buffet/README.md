# [Gold I] Bessie's Birthday Buffet - 10763 

[문제 링크](https://www.acmicpc.net/problem/10763) 

### 성능 요약

메모리: 10164 KB, 시간: 68 ms

### 분류

너비 우선 탐색, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 4월 30일 14:15:48

### 문제 설명

<p>For Bessie the cow’s birthday, Farmer John has given her free reign over one of his best fields to eat grass.</p>

<p>The field is covered in N patches of grass (1≤N≤1000), conveniently numbered 1…N, that each have a distinct quality value. If Bessie eats grass of quality Q, she gains Q units of energy. Each patch is connected to up to 10 neighboring patches via bi-directional paths, and it takes Bessie E units of energy to move between adjacent patches (1≤E≤1,000,000). Bessie can choose to start grazing in any patch she wishes, and she wants to stop grazing once she has accumulated a maximum amount of energy.</p>

<p>Unfortunately, Bessie is a picky bovine, and once she eats grass of a certain quality, she’ll never eat grass at or below that quality level again! She is still happy to walk through patches without eating their grass; in fact, she might find it beneficial to walk through a patch of high-quality grass without eating it, only to return later for a tasty snack.</p>

<p>Please help determine the maximum amount of energy Bessie can accumulate.</p>

### 입력 

 <p>The first line of input contains N and E. Each of the remaining N lines describe a patch of grass. They contain two integers Q and D giving the quality of the patch (in the range 1…1,000,000) and its number of neighbors. The remaining D numbers on the line specify the neighbors.</p>

### 출력 

 <p>Please output the maximum amount of energy Bessie can accumulate.</p>

