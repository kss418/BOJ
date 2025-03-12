# [Gold III] Acowdemia III - 21822 

[문제 링크](https://www.acmicpc.net/problem/21822) 

### 성능 요약

메모리: 10112 KB, 시간: 56 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 3월 12일 12:36:18

### 문제 설명

<p>Bessie is a busy computer science graduate student. However, even graduate students need friends. As a result, Farmer John has opened a pasture with the explicit purpose of helping Bessie and other cows form lasting friendships.</p>

<p>Farmer John's pasture can be regarded as a large 2D grid of square "cells" (picture a huge chess board). Each cell is labeled with:</p>

<ul>
	<li>C if the cell contains a cow.</li>
	<li>G if the cell contains grass.</li>
	<li>. if the cell contains neither a cow nor grass.</li>
</ul>

<p>For two distinct cows to become friends, the cows must choose to meet at a grass-covered square that is directly horizontally or vertically adjacent to both of them. During the process, they eat the grass in the grass-covered square, so future pairs of cows cannot use that square as a meeting point. The same cow may become friends with more than one other cow, but no pair of cows may meet and become friends more than once.</p>

<p>Farmer John is hoping that numerous pairs of cows will meet and become friends over time. Please determine the maximum number of new friendships between distinct pairs of cows that can possibly be created by the end of this experience.</p>

### 입력 

 <p>The first line contains <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>,</mo><mi>M</mi><mo>≤</mo><mn>1000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N,M \leq 1000$</span></mjx-container>).</p>

<p>The next <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> lines each contain a string of <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container> characters, describing the pasture.</p>

### 출력 

 <p>Count the maximum number of pairs of cows that can become friends by the end of the experience.</p>

