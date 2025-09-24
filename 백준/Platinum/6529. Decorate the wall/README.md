# [Platinum V] Decorate the wall - 6529 

[문제 링크](https://www.acmicpc.net/problem/6529) 

### 성능 요약

메모리: 3448 KB, 시간: 44 ms

### 분류

값 / 좌표 압축, 스위핑

### 제출 일자

2025년 9월 24일 15:38:29

### 문제 설명

<p>After building his huge villa, Mr. Rich cannot help but notice that the interior walls look rather blank. To change that, he starts to hang paintings from his wonderful collection. But soon he realizes that it becomes quite difficult to find a place on the wall where a painting can be placed without overlapping other paintings. Now he needs a program which would tell him, given the already placed paintings, where to place the next painting without moving any other paintings (or indicating that this is impossible). Paintings have a rectangular shape and are to be placed parallel to the side of the wall. If you do not mind a nice reward from Mr. Rich, go on and solve the problem.</p>

### 입력 

 <p>The first line of the input file contains a number representing the number of test cases to follow. Each test case starts with a line containing three numbers <em>n</em>, <em>w</em> and <em>h</em>. <em>n</em> is the number of paintings already hanging on the wall, <em>w</em> is the width of the wall and <em>h</em> is the height of the wall. The next <em>n</em> lines contain 4 integers <em>x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub></em> each (<em>0 ≤ x<sub>1</sub> < x<sub>2</sub> ≤ w</em>, <em>0 ≤ y<sub>1</sub> < y<sub>2</sub> ≤ h</em>); the x-coordinates give the distance to the left end of the wall, the y-coordinates give the distance to the bottom of the wall. (<em>x<sub>1</sub>, y<sub>1</sub></em>) is the position of the lower left corner of a painting, (<em>x<sub>2</sub>, y<sub>2</sub></em>) is the position of the upper right corner. The last line of each test case contains the dimensions of the next painting to be placed, first its width <em>w'</em>, then its height <em>h'</em> (<em>1 ≤ w' ≤ w</em>, <em>1 ≤ h' ≤ h</em>). You are not allowed to rotate the painting.</p>

<p>You can assume that <em>0 ≤ n ≤ 200</em> and <em>1 ≤ w, h ≤ 1000000</em>. Moreover, all paintings already hanging do not overlap.</p>

### 출력 

 <p>Produce one line of output for each test case. Write "Fail!" if there is no place left on the wall where the painting could be placed without overlapping other paintings. Otherwise, write the coordinates where the lower left corner of the painting should be placed. In case there is more than one solution, select the solution with a minimum y-coordinate, and break ties using the minimum x-coordinate.</p>

