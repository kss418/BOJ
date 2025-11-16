# [Platinum II] Autonomous Vehicle - 20169 

[문제 링크](https://www.acmicpc.net/problem/20169) 

### 성능 요약

메모리: 17220 KB, 시간: 56 ms

### 분류

구현, 기하학, 이분 탐색, 시뮬레이션

### 제출 일자

2025년 11월 16일 13:30:10

### 문제 설명

<p>One autonomous vehicle <em>V</em> is deployed in a mega factory with vertical and horizontal roads in the figure below. The roads are either horizontal or vertical segments. A vertical road and a horizontal road can meet at most once. If they intersect, then they intersect properly, that is, all the intersections are four-way. The end points of segments have integer coordinates.</p>

<p>The vehicle <em>V</em> starts at one end of some road at time <em>t</em> = 0 and moves at one unit per second according to a driving algorithm. <em>V</em> goes straight along the road until it meets either an intersection point of two roads or an end of the road. If it reaches the intersection, it turns left at that intersection. If it reaches the end of the road, it bounces back at that end and keeps moving according to the algorithm. The vehicle moves forever even when it comes back at the starting point. The time that <em>V</em> needs to take when it bounces back at the end of the road or turns left at the intersection point is negligible.</p>

<p>Let us explain with an example in Figure A.1(a). The starting point of the vehicle is the end point a. Then it first reaches the intersection <em>b</em>, turns left and moves toward the end point <em>c</em>. It bounces back at <em>c</em> and reaches <em>b</em> again. Then it turns left and moves along the part between <em>b</em> and <em>d</em>. It reaches another intersection <em>d</em> and turns left toward <em>e</em>, and so on. As in Figure A.1 (b), some parts of the segments are not traversed by the vehicle due to the turning rule of the algorithm, and the vehicle continues to move even when it comes back to the starting end point.</p>

<p>Given the roads of the factory, the starting end point of the vehicle <em>V</em> and a nonnegative time <em>t</em>, write a program to compute the coordinate (<em>x</em>, <em>y</em>) of the location of <em>V</em> at time <em>t</em>.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0cd48ef3-5660-464e-865d-3089a4689132/-/preview/" style="width: 538px; height: 290px;"></p>

<p style="text-align: center;">Figure A.1 (a) The roads in the factory. (b) The vehicle comes back to the starting point.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5e3b3e28-3377-43dc-bd38-43b940f630fa/-/preview/" style="width: 332px; height: 230px;"></p>

<p style="text-align: center;">Figure A.2 The roads given in the second sample test case below.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, <em>n</em> (2 ≤ <em>n</em> ≤ 500) and <em>t</em> (0 ≤ <em>t</em> ≤ 10<sup>9</sup>), where <em>n</em> is the number of roads, i.e., the number of line segments and <em>t</em> is the time at which you should output the location of the vehicle. In the following <em>n</em> lines, the <em>i</em>-th line contains four nonnegative integers <em>bx<sub>i</sub></em>, <em>by<sub>i</sub></em>, e<em>x<sub>i</sub></em>, <em>ey<sub>i</sub></em> that represent two end points (<em>bx<sub>i</sub></em>, <em>by<sub>i</sub></em>) and (e<em>x<sub>i</sub></em>, <em>ey<sub>i</sub></em>) of a (horizontal or vertical) segment. Two segments intersect at most one point. The starting end point for the vehicle is designated as (<em>bx</em><sub>1</sub>, <em>by</em><sub>1</sub>). All coordinates of the end points are between 0 and 10<sup>7</sup>. No roads share the end points. Note that road segments are not necessarily connected and all the intersections are four-way.</p>

### 출력 

 <p>Your program is to write to standard output. Print two integers <em>x</em> and <em>y</em> representing the coordinate (<em>x</em>, <em>y</em>) of the vehicle at time <em>t</em>.</p>

