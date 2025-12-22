# [Diamond V] Solar Panels - 10136 

[문제 링크](https://www.acmicpc.net/problem/10136) 

### 성능 요약

메모리: 2084 KB, 시간: 780 ms

### 분류

수학, 정수론

### 제출 일자

2025년 12월 22일 17:44:13

### 문제 설명

<p>Having decided to invest in renewable energy, Byteasar started a solar panels factory. It appears that he has hit the gold as within a few days n clients walked through his door. Each client has ordered a single rectangular panel with specified width and height ranges.</p>

<p>The panels consist of square photovoltaic cells. The cells are available in all integer sizes, i.e., with the side length integer, but all cells in one panel have to be of the same size. The production process exhibits economies of scale in that the larger the cells that form it, the more efficient the panel. Thus, for each of the ordered panels, Byteasar would like to know the maximum side length of the cells it can be made of.</p>

### 입력 

 <p>The first line of the standard input contains a single integer n(1 ≤ n ≤ 1,000): the number of panels that were ordered. The following n lines describe each of those panels: the i-th line contains four integers  s<sub>min</sub>,s<sub>max</sub>,w<sub>min</sub>,w<sub>max</sub>(1 ≤ s<sub>min</sub> ≤ s<sub>max</sub> ≤ 10<sup>9</sup>, 1 ≤ w<sub>min</sub> ≤ w<sub>max</sub> ≤ 10<sup>9</sup>), separated by single spaces; these specify the minimum width, the maximum width, the minimum height, and the maximum height of the i-th panel respectively.</p>

<p>In tests worth 75% of the total score, s<sub>max</sub>,w<sub>max</sub> ≤ 10<sup>7</sup> holds for each panel. In their subset worth 20% of the total score, n ≤ 10 holds in addition.</p>

### 출력 

 <p>Your program should print exactly n lines to the standard output. The i-th line is to give the maximum side length of the cells that the i-th panel can be made of.</p>

<p> </p>

