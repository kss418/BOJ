# [Gold IV] 부분평균 - 14922 

[문제 링크](https://www.acmicpc.net/problem/14922) 

### 성능 요약

메모리: 9912 KB, 시간: 120 ms

### 분류

수학

### 제출 일자

2024년 10월 25일 13:35:55

### 문제 설명

<p>A를 길이 N인 양의 정수로 구성된 배열이라고 하자.(N>2) 정수 P, Q(0<=P<Q<N) 에 대해서 A의 부분평균 A(P, Q)를 다음과 같이 정의하자.</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-mfrac><mjx-frac type="d"><mjx-num><mjx-nstrut type="d"></mjx-nstrut><mjx-mrow><mjx-munderover limits="false"><mjx-mo class="mjx-sop"><mjx-c class="mjx-c2211 TEX-S1"></mjx-c></mjx-mo><mjx-script style="vertical-align: -0.309em; margin-left: 0px;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D444 TEX-I"></mjx-c></mjx-mi></mjx-texatom><mjx-spacer style="margin-top: 0.18em;"></mjx-spacer><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-script></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c5B"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c5D"></mjx-c></mjx-mo></mjx-texatom></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line type="d"></mjx-line><mjx-row><mjx-den><mjx-dstrut type="d"></mjx-dstrut><mjx-mrow><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D444 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-mrow></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mfrac><mrow><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>i</mi><mo>=</mo><mi>P</mi></mrow><mrow data-mjx-texclass="ORD"><mi>Q</mi></mrow></munderover><mrow data-mjx-texclass="ORD"><mi>A</mi><mo stretchy="false">[</mo><mi>i</mi><mo stretchy="false">]</mo></mrow></mrow><mrow><mi>Q</mi><mo>−</mo><mi>P</mi><mo>+</mo><mn>1</mn></mrow></mfrac></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[\frac{\sum_{i=P}^{Q}{A[i]}}{Q-P+1}\]</span> </mjx-container></p>

<p>예를 들어 주어진 배열 A의 길이가 3이고</p>

<p>A[0]=3, A[1]=1, A[2]=2</p>

<p>라고 하면 A의 가능한 모든 부분평균은 다음과 같다.</p>

<p>A(0,1) = (3+1)/2 = 2</p>

<p>A(0,2) = (3+1+2)/3=2</p>

<p>A(1,2) = (1+2)/2=1.5</p>

<p>위와 같은 경우, 모든 부분평균 중  최솟값은 A(1,2)=1.5이다. 그렇다면 주어진 조건을 만족하는 임의의 배열 A가 주어지면 A의 부분평균 중 최솟값을 가지는 것을 A(u,v) 라고 할 때, u를 출력하는 프로그램을 작성하라. (답이 여러 개일 경우 가장 작은 u의 값을 출력한다.)</p>

### 입력 

 <pre>N

A[0], A[1], ..., A[N-1]</pre>

<p>2 ≤ N ≤ 1,000,000, 0 ≤ A[i] ≤ 7×10<sup>8</sup></p>

### 출력 

 <pre>u</pre>

