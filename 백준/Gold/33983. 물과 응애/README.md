# [Gold V] 물과 응애 - 33983 

[문제 링크](https://www.acmicpc.net/problem/33983) 

### 성능 요약

메모리: 4960 KB, 시간: 8 ms

### 분류

그리디 알고리즘, 애드 혹

### 제출 일자

2025년 5월 26일 08:42:24

### 문제 설명

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ce3871b8-bf66-4c3a-9b43-dffbed415ea7/-/preview/" style="height: 340px; width: 600px;"></p>

<p>중세 SCSC의 연금술사들은 아기가 태어나자마자 외치는 소리를 통해 생명의 기원이 물이라는 것을 발견하였다. 현재까지도 그 발견은 전해져 내려와 SCSC의 전통 인사법으로 자리매김하였다.</p>

<p>SCSC의 훌륭한 일원인 종환이는 이를 더 파헤치기 위해 탐사를 나갔고, 서울대학교 63동 438호 유적지에서 고대의 연금술사들이 사용하던 물질을 발견하였다⋯⋯! 들뜬 종환이가 물질을 SCSC의 최첨단 현미경으로 관찰한 결과 수소(<span style="color:#e74c3c;"><code>H</code></span>)와 산소(<span style="color:#e74c3c;"><code>O</code></span>)로 이루어져 있다는 사실을 알게 되었다. 하지만, 산소와 수소로 이루어져 있다고 이 물질이 순수한 물이라고 할 수는 없다. 물질은 하나의 문자열로 나타낼 수 있고, 종환이는 다음 기준에 따라 발견한 물질이 순수한 물인지 아닌지 판단하고자 한다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>HOH</code></span>는 물분자 하나로, 그 자체로 순수한 물이다.</li>
	<li>어떤 부분 수열 <span style="color:#e74c3c;"><code>HOH</code></span>를 제거한 문자열이 순수한 물이라면, 원래 문자열도 순수한 물이다.</li>
</ul>

<p>이해를 위해 다음 예시를 살펴보자.</p>

<p>물분자 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container>개로 이루어진 순수한 물은</p>

<ul>
	<li><code><span style="color:#e74c3c;">HOHHOH</span></code></li>
	<li><code><span style="color:#e74c3c;">HHOHOH</span></code></li>
	<li><code><span style="color:#e74c3c;">HOHOHH</span></code></li>
	<li><code><span style="color:#e74c3c;">HHOOHH</span></code></li>
</ul>

<p>로 총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4$</span></mjx-container>가지이다. 편의상 <span style="color:#e74c3c;"><code>HOHHOH</code></span>는 (<span style="color:#e74c3c;"><code>HOH</code></span>)(<span style="color:#e74c3c;"><code>HOH</code></span>), <span style="color:#e74c3c;"><code>HHOHOH</code></span>는 (<span style="color:#e74c3c;"><code>H</code></span>(<span style="color:#e74c3c;"><code>HOH</code></span>)<span style="color:#e74c3c;"><code>OH</code></span>), <span style="color:#e74c3c;"><code>HOHOHH</code></span>는 (<span style="color:#e74c3c;"><code>HO</code></span>(<span style="color:#e74c3c;"><code>HOH</code></span>)<span style="color:#e74c3c;"><code>H</code></span>)로 나타낼 수 있고, <span style="color:#e74c3c;"><code>HHOOHH</code></span>는 모든 원소가 뒤섞인 형태이다.</p>

<p><span style="color:#e74c3c;"><code>OHH</code></span>, <span style="color:#e74c3c;"><code>HHHOOH</code></span>와 같은 경우는 순수한 물이 아니다.</p>

<p>종환이가 찾은 물질이 순수한 물인지 올바르게 판단할 수 있도록 도와주자!</p>

### 입력 

 <p>첫째 줄에 물질을 나타내는 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>의 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>500</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \leq N \leq 500\,000)$</span> </mjx-container></p>

<p>둘째 줄에 알파벳 대문자 <code><span style="color:#e74c3c;">H</span></code>와 <code><span style="color:#e74c3c;">O</span></code>로만 이루어진 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다.</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>첫째 줄에 종환이가 찾은 물질이 순수한 물이면 <code><span style="color:#e74c3c;">pure</span></code>를, 그렇지 않으면 <code><span style="color:#e74c3c;">mix</span></code>를 출력한다.</p>

