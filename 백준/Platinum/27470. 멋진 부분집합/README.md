# [Platinum V] 멋진 부분집합 - 27470 

[문제 링크](https://www.acmicpc.net/problem/27470) 

### 성능 요약

메모리: 4184 KB, 시간: 20 ms

### 분류

수학, 정수론, 무작위화, 소인수분해

### 제출 일자

2026년 2월 3일 01:27:14

### 문제 설명

<p>KSA 학생들은 <strong>멋진 집합</strong>을 좋아한다. <strong>멋진 집합</strong>이란 모든 원소들의 최대공약수가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>보다 큰 정수들의 중복집합이다. 크기가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>인 중복집합이 주어졌을 때, 주어진 중복집합의 부분집합 중 크기가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2308 TEX-S2"></mjx-c></mjx-mo><mjx-mfrac><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mrow size="s"><mjx-mpadded><mjx-block style="margin: 0.86em 0px 0.3em;"><mjx-mrow></mjx-mrow></mjx-block></mjx-mpadded><mjx-mstyle style="font-size: 141.4%;"><mjx-texatom texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-mstyle></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mrow size="s"><mjx-mpadded><mjx-block style="margin: 0.86em 0px 0.3em;"><mjx-mrow></mjx-mrow></mjx-block></mjx-mpadded><mjx-mstyle style="font-size: 141.4%;"><mjx-texatom texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-texatom></mjx-mstyle></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2309 TEX-S2"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">⌈</mo><mfrac><mrow><mpadded height="8.6pt" depth="3pt" width="0"><mrow></mrow></mpadded><mstyle displaystyle="false" scriptlevel="0"><mrow data-mjx-texclass="ORD"><mi>N</mi></mrow></mstyle></mrow><mrow><mpadded height="8.6pt" depth="3pt" width="0"><mrow></mrow></mpadded><mstyle displaystyle="false" scriptlevel="0"><mrow data-mjx-texclass="ORD"><mn>2</mn></mrow></mstyle></mrow></mfrac><mo data-mjx-texclass="CLOSE">⌉</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left\lceil\cfrac{N}{2}\right\rceil$</span></mjx-container>인 <strong>멋진 집합</strong>을 찾아보자!</p>

### 입력 

 <p>첫 번째 줄에 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>두 번째 줄에 중복집합의 원소들인 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 정수가 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 <strong>멋진 집합</strong>이 존재한다면 <code><span style="color:#e74c3c;">YES</span></code>, 아니라면 <code><span style="color:#e74c3c;">NO</span></code>를 출력한다.</p>

<p>만약 <strong>멋진 집합</strong>이 존재한다면, 두 번째 줄에 <strong>멋진 집합</strong>에 속한 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2308 TEX-S2"></mjx-c></mjx-mo><mjx-mfrac><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mrow size="s"><mjx-mpadded><mjx-block style="margin: 0.86em 0px 0.3em;"><mjx-mrow></mjx-mrow></mjx-block></mjx-mpadded><mjx-mstyle style="font-size: 141.4%;"><mjx-texatom texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-mstyle></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mrow size="s"><mjx-mpadded><mjx-block style="margin: 0.86em 0px 0.3em;"><mjx-mrow></mjx-mrow></mjx-block></mjx-mpadded><mjx-mstyle style="font-size: 141.4%;"><mjx-texatom texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-texatom></mjx-mstyle></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2309 TEX-S2"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">⌈</mo><mfrac><mrow><mpadded height="8.6pt" depth="3pt" width="0"><mrow></mrow></mpadded><mstyle displaystyle="false" scriptlevel="0"><mrow data-mjx-texclass="ORD"><mi>N</mi></mrow></mstyle></mrow><mrow><mpadded height="8.6pt" depth="3pt" width="0"><mrow></mrow></mpadded><mstyle displaystyle="false" scriptlevel="0"><mrow data-mjx-texclass="ORD"><mn>2</mn></mrow></mstyle></mrow></mfrac><mo data-mjx-texclass="CLOSE">⌉</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left\lceil\cfrac{N}{2}\right\rceil$</span></mjx-container>개의 정수를 출력한다.</p>

<p>정답이 여러 개 존재한다면 아무거나 출력해도 상관없으며, 각 원소를 출력하는 순서는 상관없다.</p>

