# [Gold III] 특별한 물리 공격 - 31675 

[문제 링크](https://www.acmicpc.net/problem/31675) 

### 성능 요약

메모리: 8304 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 12월 22일 15:33:21

### 문제 설명

<blockquote>
<p>NLCS Jeju에는 화재 경보가 울리면 모든 커플이 헤어진다는 징크스가 있다...</p>
</blockquote>

<p>시이(swi)는 하라는 공부는 안하고 연애만 하는 학생들이 NLCS Jeju에 너무 많은 것을 보고 이들에게 시이-빔을 쏘아 단죄하기로 하였다.</p>

<p>언제나처럼 화재경보기가 오작동해 학생 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명이 대피하여 운동장에 한 줄로 서있다. 시이는 커플인 두 사람 중 한 명 이상을 단죄하려고 한다. 하지만 이들 중 누가 커플인지 모르기 때문에 시이는 다음 규칙에 따라 학생들을 단죄하기로 하였다.</p>

<ul>
	<li>모든 서로 인접한 두 학생 중 한 명 이상을 단죄해야 한다.</li>
</ul>

<p>하지만 각 학생은 시이-빔에 대한 저항력이 있어 앞에서 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span></mjx-container>번째 학생을 시이-빔으로 단죄하기 위해서는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>R</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R_i$</span></mjx-container>만큼의 에너지가 필요하다.</p>

<p>이러한 시이의 행동에 분노한 학생들은 몇 명의 머리를 대머리로 만들어 시이-빔을 반사하려 한다. 대머리인 학생에게 시이-빔을 쏘면 대머리에 반사되어 시이가 공격을 입게 된다. 따라서 시이는 대머리가 아닌 학생에게만 시이-빔을 쏠 수 있다. 하지만 이웃한 두 학생을 모두 대머리로 만들면 미관상 단죄당하느니만 못하므로 이웃한 두 명의 학생을 모두 대머리로 만들 수 없다.</p>

<p>학생들은 일부 인원을 적절히 대머리로 만들어 시이가 단죄에 성공하기 위해 필요한 최소 에너지를 최대화하려고 한다. 학생들이 대머리가 되어 시이가 단죄하는 데 필요한 에너지가 최대일 때 얼마나 많은 에너지가 필요한지 구해 보자.</p>

### 입력 

 <p>첫 번째 줄에 학생의 수를 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>두 번째 줄에 각 학생의 저항력을 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>R</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R_i$</span></mjx-container>가 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>학생들이 대머리가 되어 시이가 소모해야 하는 최소 에너지가 최대가 되었을 때 시이가 소모해야 하는 총 에너지를 정수로 출력한다.</p>

