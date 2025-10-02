# [Platinum V] 배 옮기기 - 28079 

[문제 링크](https://www.acmicpc.net/problem/28079) 

### 성능 요약

메모리: 3044 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 최단 경로, 비트마스킹, 데이크스트라, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2025년 10월 2일 17:42:08

### 문제 설명

<p>치훈이는 배 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container>척을 강 건너편으로 옮기려고 한다. 강을 건너가거나 건너오기 위해서는 치훈이가 가지고 있는 배를 운전하여 건너야 한다.</p>

<p>배의 크기가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(X\)</span></mjx-container>라고 할 때, 치훈이가 그 배를 운전하여 강 건너편으로 옮기는 데에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(X\)</span></mjx-container>분이 걸린다.</p>

<p>배를 운전하여 옮길 때, 크기가 더 <strong>작은</strong> 배를 최대 한 척까지 싣고 동시에 옮기는 것도 가능하다. 이 때 배를 옮기는 시간은 큰 배 하나를 옮기는 것과 같은 시간이 걸린다.</p>

<p>이 때, 치훈이가 배 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container>척을 모두 강 건너편으로 옮기는데 필요한 최소 시간을 계산하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 배의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container>이 주어진다.</p>

<p>둘째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(i\)</span></mjx-container>번째 배의 크기를 나타내는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>B</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(B_i\)</span></mjx-container>가 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>치훈이가 모든 배를 강 건너편으로 옮기는데 필요한 최소 시간 (분)을 출력한다.</p>

<p>만약 어떤 방법을 써도 모든 배를 강 건너편으로 옮길 수 없다면 <code>-1</code>을 출력한다.</p>

