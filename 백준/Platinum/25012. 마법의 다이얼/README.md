# [Platinum II] 마법의 다이얼 - 25012 

[문제 링크](https://www.acmicpc.net/problem/25012) 

### 성능 요약

메모리: 214620 KB, 시간: 2060 ms

### 분류

다이나믹 프로그래밍, 구현, 함수 개형을 이용한 최적화, 스위핑

### 제출 일자

2025년 10월 30일 19:00:46

### 문제 설명

<p>계속되는 알고리즘 공부에 잠시 지친 경근이는 다른 세계에서 몇 일간 쉬고 오면 좋을 것이라는 생각을 했다. 그러던 어느 날, 다른 세계로 떠나는 문이 있는 장소를 상수에게 듣게 되어 그 곳으로 갔다. 그 곳에는 다른 세계로 떠나는 문이 있었는데 잠겨 있었고, 문을 열 수 있는 커다란 다이얼 식 자물쇠가 있었다.</p>

<p>자물쇠는 위아래로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개의 다이얼로 만들어져 있다. 각 다이얼은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>R</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R$</span></mjx-container>개의 칸이 있고 좌우로 칸에 맞추어 돌릴 수 있다. 다이얼의 각 칸에는 점이 있을 수도 있고 점이 없을 수도 있다. 각 다이얼에는 최소 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>개의 점이 있다. 다이얼들을 돌려서 어떤 위치에서든 <strong>세로로 모든 칸에 점이 있도록</strong> 만들면 문이 열린다고 한다. 각각의 다이얼은 따로 돌아간다. 다이얼이 아주 무거워 돌리기 힘들기 때문에 다이얼을 돌리는 칸 수의 합을 최소화하고 싶다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/77f7b509-da9d-48b0-ac58-335f04321c2d/-/preview/" style="width: 319px; height: 150px;"></p>

<p>위 그림은 다이얼의 한 예를 보여 준다. 가능한 최선의 방법 중 하나는, 위에서 첫 번째 다이얼을 왼쪽으로 한 칸, 두 번째 다이얼을 왼쪽으로 두 칸, 세 번째 다이얼을 오른쪽으로 한 칸, 네 번째 다이얼을 돌리지 않아서, 총 4칸을 돌리는 방법이다.</p>

<p>다이얼의 크기와 점들의 위치를 입력으로 받아서 문이 열리도록 최소 칸 수로 다이얼을 돌리는 방법을 알아내는 프로그램을 작성하라. 점들의 위치는 다이얼 번호와 칸 번호의 쌍인 좌표로 주어진다. 제일 위의 다이얼이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>번 다이얼이다. 아래로 가면서 다이얼 번호가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>씩 증가한다. 제일 아래 다이얼이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M-1$</span></mjx-container>번 다이얼이 될 것이다. 칸 번호를 정하기 위해 임의의 동일한 위치의 (즉, 세로로 한 줄에 위치한) 칸들을 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>번으로 잡는다. 오른쪽으로 가면서 칸 번호가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>씩 증가한다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>번 칸의 왼쪽에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>R</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R-1$</span></mjx-container>번 칸이 있을 것이다. 주어진 점들의 좌표가 겹치는 경우는 없다.</p>

<ul>
	<li><code>long long findMinClicks( int M, int R, vector< pair<int, int> > P )</code> : <code>M</code>은 다이얼의 개수이다. <code>R</code>은 한 다이얼의 칸 수이다. <code>P</code>는 크기 <code>N</code>인 <code>int</code> 쌍들의 배열이다. 한 쌍의 첫 자연수는 다이얼 번호, 두 번째 자연수는 칸 번호이다. 주어진 점들의 좌표가 겹치는 경우는 없다. <code>findMinClicks()</code> 함수는 문이 열리도록 최소 칸 수로 다이얼을 돌리는 방법에서 돌리는 칸 수를 리턴해야 한다.</li>
</ul>

### 입력 

 Empty

### 출력 

 Empty

