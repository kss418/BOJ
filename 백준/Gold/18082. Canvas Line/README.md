# [Gold III] Canvas Line - 18082 

[문제 링크](https://www.acmicpc.net/problem/18082) 

### 성능 요약

메모리: 5568 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 구현

### 제출 일자

2024년 10월 18일 01:50:45

### 문제 설명

<p>Your friend Charmion asked you to hang some canvases out to dry on a straight washing line for an art project she has been working on. The canvases are artfully arranged such that none of them overlap, although they may touch along the edges. For stability, each canvas must be held by two pegs, but because the canvases are very rigid, they can be held from anywhere.</p>

<p>Each canvas is an integral number of centimetres wide (at least 10 cm). Each peg is slightly less than 1 cm wide. Canvases and pegs are all placed at integral centimetre positions along the line.</p>

<p>Unnecessary things touching any canvas is a smudge risk, thus every canvas should be held by exactly two pegs, no more and no less. Given all of the pegs that are already attached to the line, place as few as possible additional pegs as necessary to hold all of the canvases.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2546bbd1-89f9-447b-ac86-95d6327de241/-/preview/" style="width: 614px; height: 146px;"></p>

<p style="text-align: center;">Figure C.1: Illustration of a solution to Sample Input 2. Pre-existing pegs are marked in white.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer n (1 ≤ n ≤ 10<sup>3</sup>), the number of canvases on the line.</li>
	<li>n lines, the ith of which contains two integers ℓ<sub>i</sub> and r<sub>i</sub> (0 ≤ ℓ<sub>i</sub> < r<sub>i</sub> ≤ 10<sup>9</sup> and ℓ<sub>i</sub> + 10 ≤ r<sub>i</sub>), the positions of the left and the right end of the ith canvas in centimetres.</li>
	<li>One line with an integer p (0 ≤ p ≤ 2 · 10<sup>3</sup>), the number of pegs already used.</li>
	<li>One line with p integers x<sub>1</sub>, . . . , x<sub>p</sub> (0 ≤ x<sub>i</sub> < x<sub>i+1</sub> ≤ 10<sup>9</sup> for each i), the position of each existing peg in centimetres.</li>
</ul>

<p>Canvases are given from left to right and may touch only at edges, that is r<sub>i</sub> ≤ ℓ<sub>i+1</sub> for each i.</p>

### 출력 

 <p>If the canvases can be secured, output the smallest number of extra pegs needed to secure all of the canvases while touching each exactly twice. On the next line output the integer positions of all of the new pegs.</p>

<p>Otherwise, output “impossible”.</p>

<p>If there are multiple optimal solutions, you may output any one of them.</p>

