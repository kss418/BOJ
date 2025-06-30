# [Diamond V] Strike Zone - 17975 

[문제 링크](https://www.acmicpc.net/problem/17975) 

### 성능 요약

메모리: 2768 KB, 시간: 588 ms

### 분류

자료 구조, 세그먼트 트리, 스위핑, 값 / 좌표 압축, 최대 부분 배열 문제

### 제출 일자

2025년 6월 30일 23:38:57

### 문제 설명

<p>The strike zone in baseball is the volume of space which a baseball must pass through in order to be called a <em>strike</em>, if the batter does not swing. A baseball that misses the strike zone is called a <em>ball</em>, if the batter does not swing. Figure H.1 shows the locations of baseballs at plate which were captured by a ball tracking device during a baseball match. Each blue point was called a strike and each red point was called a ball during the match. This may motivate us to define a rectangular region that represents the strike zone of the match, by analyzing such a ball tracking data of the match.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b99c66f9-41bf-4e51-aaec-397af14b56ce/-/preview/" style="width: 189px; height: 225px;"></p>

<p style="text-align: center;">Figure H.1: The locations of baseballs at plate during a baseball match. Blue points were called strikes and red points were called balls.</p>

<p>In this problem, you are given two sets, <em>P</em><sub>1</sub> and <em>P</em><sub>2</sub>, of points in the plane and two positive constants <em>c</em><sub>1</sub> and <em>c</em><sub>2</sub>. You are asked to find an axis-parallel rectangle <em>R</em> that maximizes the evaluation function eval(<em>R</em>) = <em>c</em><sub>1</sub> × <em>s</em> - <em>c</em><sub>2</sub> × <em>b</em>, where <em>s</em> is the number of points in <em>P</em><sub>1</sub> ∩ <em>R</em> and <em>b</em> is the number of points in <em>P</em><sub>2</sub> ∩ <em>R</em>.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em><sub>1</sub> (1 ≤ <em>n</em><sub>1</sub> ≤ 1,000), where <em>n</em><sub>1</sub> denotes the number of points in <em>P</em><sub>1</sub>. In the following <em>n</em><sub>1</sub> lines, each line consists of two integers, ranging -10<sup>9</sup> to 10<sup>9</sup>, representing the coordinates of a point in <em>P</em><sub>1</sub>. The next line contains an integer <em>n</em><sub>2</sub> (1 ≤ <em>n</em><sub>2</sub> ≤ 1,000), where <em>n</em><sub>2</sub> denotes the number of points in <em>P</em><sub>2</sub>. In the following <em>n</em><sub>2</sub> lines, each line consists of two integers, ranging -10<sup>9</sup> to 10<sup>9</sup>, representing the coordinates of a point in <em>P</em><sub>2</sub>. There are no two points in <em>P</em><sub>1</sub> ∪ <em>P</em><sub>2</sub> that share the same x or y coordinate. Then the next line consists of two integers, <em>c</em><sub>1</sub> and <em>c</em><sub>2</sub>, ranging 1 to 10,000.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line consisting of one integer that is eval(ܴ<em>R</em>), where <em>R</em> is an axis-parallel rectangle with the maximum possible eval value for <em>P</em><sub>1</sub> and <em>P</em><sub>2</sub> with respect to <em>c</em><sub>1</sub> and <em>c</em><sub>2</sub>.</p>

