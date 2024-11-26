# [Gold III] Space Junk - 11641 

[문제 링크](https://www.acmicpc.net/problem/11641) 

### 성능 요약

메모리: 3612 KB, 시간: 4 ms

### 분류

기하학, 3차원 기하학, 수학, 삼분 탐색

### 제출 일자

2024년 11월 26일 17:34:40

### 문제 설명

<p>According to NASA’s web page, there are more than 500 000 pieces of “space junk” that are tracked. Care must be taken in mission planning so satellites and other spacecrafts do not collide with these pieces of space junk.</p>

<p>For this problem, we will consider the simplified case in which both the spacecraft and the space junk can be modelled as spheres that are travelling in a straight line. Given the current locations of the two spheres as well as their velocities, when would they collide in the future, if ever?</p>

### 입력 

 <p>The first line of input contains a single positive integer T ≤ 500 indicating the number of test cases. Each test case is specified by two lines. The first line specifies the sphere representing the spacecraft, while the second line specifies the sphere representing the space junk. Each sphere is specified by the seven integers x, y, z, r, vx, vy, vz. The center of the sphere is currently located at (x, y, z), the radius of the sphere is r, and the sphere is travelling along the direction specified by the vector (vx, vy, vz). If the vector is (0, 0, 0), the sphere is stationary.</p>

<p>The absolute value of all integers are at most 100, and r is positive. All coordinates and radius are measured in meters, and the velocities are measured in meters/second.</p>

<p>You may assume that the two spheres do not touch each other initially.</p>

### 출력 

 <p>For each test case, output a line containing the time (in seconds) at which the spacecraft first collides with the space junk. If they never collide, print No collision instead. Answers within 0.01 of the correct result are acceptable.</p>

