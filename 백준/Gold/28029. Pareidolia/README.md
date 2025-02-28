# [Gold I] Pareidolia - 28029 

[문제 링크](https://www.acmicpc.net/problem/28029) 

### 성능 요약

메모리: 22948 KB, 시간: 32 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 28일 14:22:27

### 문제 설명

<p>Pareidolia is the phenomenon where your eyes tend to see familiar patterns in images where none really exist -- for example seeing a face in a cloud. As you might imagine, with Farmer John's constant proximity to cows, he often sees cow-related patterns in everyday objects. For example, if he looks at the string "bqessiyexbesszieb", Farmer John's eyes ignore some of the letters and all he sees is "bessiexbessieb" -- a string that has contains two contiguous substrings equal to "bessie".</p>

<p>Given a string of length at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-msup space="3"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>⋅</mo><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2\cdot 10^5$</span></mjx-container> consisting only of characters a-z, where each character has an associated deletion cost, compute the maximum number of contiguous substrings that equal "bessie" you can form by deleting zero or more characters from it, and the minimum total cost of the characters you need to delete in order to do this.</p>

### 입력 

 <p>The first line contains the string. The second line contains the deletion cost associated with each character (an integer in the range <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c5B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c5D"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">[</mo><mn>1</mn><mo>,</mo><mn>1000</mn><mo stretchy="false">]</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$[1,1000]$</span></mjx-container>).</p>

### 출력 

 <p>The maximum number of occurrences, and the minimum cost to produce this number of occurrences.</p>

