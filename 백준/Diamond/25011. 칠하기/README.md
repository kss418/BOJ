# [Diamond V] 칠하기 - 25011 

[문제 링크](https://www.acmicpc.net/problem/25011) 

### 성능 요약

메모리: 158296 KB, 시간: 232 ms

### 분류

그래프 이론, 방향 비순환 그래프, 위상 정렬, 강한 연결 요소

### 제출 일자

2025년 7월 9일 03:17:24

### 문제 설명

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times M$</span></mjx-container> 칸으로 이루어진 격자가 있다. 격자의 일부 칸들은 막혀서 갈 수 없는 칸들이고, 다른 칸들은 갈 수 있는 칸들이다. 이제 다음 규칙을 따라서 갈 수 있는 칸들에 색을 칠하려고 한다.</p>

<ol>
	<li><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times M$</span></mjx-container> 칸 중 한 칸을 현재 칸으로 잡고 시작한다. 시작하는 현재 칸은 갈 수 있는 칸 중 어떤 것이든 가능하다.</li>
	<li>현재 칸에서 한 방향(위/아래/왼쪽/오른쪽 중 하나)을 정하고, 격자의 왼쪽/오른쪽/위/아래 경계에 도착하거나 이동하려는 칸이 막혀 있을 때까지 <strong>계속</strong> 이동한다. 중간에 멈출 수 없음에 유의하시오.</li>
	<li>정지할 때까지 만약 가로 방향(왼쪽 또는 오른쪽)으로 이동했다면 가로로 이동했던 칸들이 모두 노란 색으로 칠해진다. 이동을 시작한 칸도 노란 색으로 칠해진다. 만약 정지할 때까지 세로 방향(위 또는 아래)으로 이동했다면 세로로 이동했던 칸들이 모두 파란 색으로 칠해진다. 이동을 시작한 칸도 파란 색으로 칠해진다. (이동하려는 방향이 바로 막혀 있어서 한 칸도 이동할 수 없었던 경우에도 시작하는 칸에 색이 칠해지는 것으로 정한다.)</li>
	<li>모든 갈 수 있는 칸을 적어도 한 번 이상 노란 색으로 칠했고, 또 적어도 한 번 이상 파란 색으로 칠했다면 성공이며 종료한다.</li>
	<li>만약 그렇지 않다면, 2번 과정이 끝났을 때 정지한 칸, 즉 마지막으로 이동할 수 있었던 칸으로부터 시작하여 다시 2-4번 과정을 반복한다. 이 과정을 무한히 반복하더라도 모든 갈 수 있는 칸을 적어도 한 번 이상 노란색으로, 또 적어도 한 번 이상 파란 색으로 칠할 방법이 없다면 실패이다.</li>
</ol>

<p>예를 들어 다음 예를 살펴보자. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>×</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \times 3$</span></mjx-container> 격자의 모든 칸이 갈 수 있는 칸들인 다음 예제에서, 가장 왼쪽 위인 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>0</mn><mo>,</mo><mn>0</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(0, 0)$</span></mjx-container>에서 출발하면 왼쪽 그림과 가운데 그림의 예와 같이, 어떻게 이동하더라도 모든 갈 수 있는 칸을 적어도 한 번 파란색, 그리고 적어도 한 번 노란색으로 칠할 수 없다. 반면, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>0</mn><mo>,</mo><mn>1</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(0, 1)$</span></mjx-container>에서 출발하여 오른쪽 그림처럼 이동하면 모든 갈 수 있는 칸을 적어도 한 번 파란색, 그리고 적어도 한 번 노란색으로 칠할 수 있음을 알 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a4f1d967-d254-47be-9da3-a7da219c5e50/-/preview/" style="width: 574px; height: 115px;"></p>

<p>격자의 크기와 배치가 주어졌을 때, <strong>모든 갈 수 있는 칸을 파란색과 노란색으로 칠할 수 있는 지</strong>를 구하려 한다. 여러분은 이 문제를 풀기 위해서 다음 함수를 구현해야만 한다.</p>

<ul>
	<li><code>int yellowblue( int N, int M, vector<string><string> V ) ;</string></code> 단 한번 호출되는 함수 이다. <code>N</code>과 <code>M</code>은 격자의 크기를 나타낸다. <code>V</code>는 격자의 상태를 나타내는 크기 <code>N</code>인 <code>string</code> 의 배열(<code>vector</code>)이다. <code>V</code>의 각 <code>string</code>의 길이는 <code>M</code>이다. 격자의 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mi>i</mi><mo>,</mo><mi>j</mi><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(i, j)$</span></mjx-container>번째 칸이 갈 수 있는 칸이라면 <code>V[</code><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span> </mjx-container><code>]</code>의 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>j</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$j$</span></mjx-container>번째 글자는 ‘<code>.</code>’이고, 막혀 있는 칸이면 ‘<code>#</code>’이다. 만약 어떤 위치에 서 시작하여 격자의 모든 갈 수 있는 칸을 적어도 한 번 파란색, 적어도 한 번 노란색으로 칠할 수 있다면 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>을, 그렇지 않다면 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>을 return해야 한다.</li>
</ul>

### 입력 

 Empty

### 출력 

 Empty

