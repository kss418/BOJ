# [Platinum III] Antisymmetry - 8189 

[문제 링크](https://www.acmicpc.net/problem/8189) 

### 성능 요약

메모리: 7604 KB, 시간: 16 ms

### 분류

문자열, 매내처

### 제출 일자

2026년 1월 8일 16:05:51

### 문제 설명

<p>Byteasar studies certain strings of zeroes and ones. Let x be such a string. By x<sup>R</sup> we will denote the reversed (i.e., "read backwards") string x, and by <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-texatom texclass="ORD"><mjx-mover><mjx-over style="padding-bottom: 0.105em; padding-left: 0.314em; margin-bottom: -0.544em;"><mjx-mo class="mjx-n" style="width: 0px; margin-left: -0.25em;"><mjx-c class="mjx-cAF"></mjx-c></mjx-mo></mjx-over><mjx-base><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-base></mjx-mover></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="ORD"><mover><mi>x</mi><mo stretchy="false">¯</mo></mover></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\( \bar {x} \)</span></mjx-container> we will denote the string obtained from x by changing all the zeroes to ones and ones to zeroes.</p>

<p>Byteasar is interested in antisymmetry, while all things symmetric bore him. Antisymmetry however is not a mere lack of symmetry. We will say that a (nonempty) string x is antisymmetric if, for every position i in x, the i-th last character is different than the i-th (first) character. In particular, a string x consisting of zeroes and ones is antisymmetric if and only if <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-texatom texclass="ORD"><mjx-texatom texclass="ORD"><mjx-mover><mjx-over style="padding-bottom: 0.105em; padding-left: 0.314em; margin-bottom: -0.544em;"><mjx-mo class="mjx-n" style="width: 0px; margin-left: -0.25em;"><mjx-c class="mjx-cAF"></mjx-c></mjx-mo></mjx-over><mjx-base><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-base></mjx-mover></mjx-texatom></mjx-texatom><mjx-script style="vertical-align: 0.363em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi><mo>=</mo><msup><mrow data-mjx-texclass="ORD"><mrow data-mjx-texclass="ORD"><mover><mi>x</mi><mo stretchy="false">¯</mo></mover></mrow></mrow><mi>R</mi></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\( x = {\bar {x}}^R \)</span></mjx-container>. For example, the strings 00001111 and 010101 are antisymmetric, while 1001 is not.</p>

<p>In a given string consisting of zeroes and ones we would like to determine the number of contiguous nonempty antisymmetric fragments. Different fragments corresponding to the same substrings should be counted multiple times.</p>

### 입력 

 <p>The first line of the standard input contains an integer n (1 ≤ n ≤ 500,000) that denotes the length of the string. The second line gives a string of 0 and/or 1 of length n. There are no spaces in the string.</p>

### 출력 

 <p>The first and only line of the standard output should contain a single integer, namely the number of contiguous (non empty) fragments of the given string that are antisymmetric.</p>

