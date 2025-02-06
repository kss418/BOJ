# [Platinum V] Paths - 15866 

[문제 링크](https://www.acmicpc.net/problem/15866) 

### 성능 요약

메모리: 97768 KB, 시간: 328 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 그래프 이론

### 제출 일자

2025년 2월 6일 18:31:00

### 문제 설명

<p>A graph is a mathematical structure which consists of a set of vertices, and a set of edges, each connecting two vertices. An example of a graph with 4 vertices and 3 edges is shown in the sample explanation below.</p>

<p>A path in the graph is defined as an ordered list of 2 or more vertices, such that there are edges between consecutive vertices in the list. In this task we are only interested in simple paths in which no vertex occurs more than once. Note that the list is ordered; for example, “5-6-7”, “5-7-6” and “7-6-5” are all treated as different paths.</p>

<p>In this task, each vertex in the graph has one of K colors. The task is to find the number of possible (simple) paths in which no two vertices have the same color.</p>

### 입력 

 <p>The first line of input contains three integers: N (the number of vertices), M (the number of edges), and K (the number of different colors).</p>

<p>The second line of input contains N integers between 1 and K – the colors of each vertex (starting with vertex 1 and ending with vertex N).</p>

<p>Each of the following M lines describes an edge and contains two integers a,b (1 ≤ a, b ≤ N,a ≠ b) – the two vertices connected by the edge. There will be at most one edge between any two vertices.</p>

### 출력 

 <p>Output one integer – the number of paths whose vertices all have distinct colors. This number will always be smaller than 10<sup>18</sup>.</p>

