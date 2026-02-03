# [Diamond IV] 정리정돈 - 12918 

[문제 링크](https://www.acmicpc.net/problem/12918) 

### 성능 요약

메모리: 2364 KB, 시간: 0 ms

### 분류

그래프 이론, 기하학, 최대 유량, 최소 비용 최대 유량

### 제출 일자

2026년 2월 3일 17:25:57

### 문제 설명

<p>대부분의 KAISTIAN들은 방청소를 하지 않아 기숙사에 물건들이 매우 어지럽게 널려있다. 어느 날, 철수는 방이 너무 더러워 오랜만에 물건들을 깔끔하게 정리정돈하기로 결정하였다. 깔끔하다는 것은 방을 정확히 절반으로 나누는 직선을 L이라고 할 때 임의의 물건의 위치에서 L에 선대칭 시킨 위치에 어떤 물건이 있는 것이다. 이때, 현재 위치에 있는 물건의 개수와 선대칭 시킨 위치에 있는 물건의 개수가 같아야 한다. 물건들을 옮기는 일은 매우 힘든 일이다. 따라 철수는 물건들을 하나씩 옮기는데 그 거리들의 합을 최소화 하려고 한다. (철수가 물건을 들지 않고 이동하는 거리는 무시하자)</p>

<p>이 문제에선 L을 y축으로 정의하며, 물건들의 좌표가 2차원상의 좌표로 주어진다고 하자. 철수를 도와서 모든 물건들을 깔끔하게 정리정돈 했을 때, 물건들이 이동하는 거리의 합의 최솟값을 구하자. (거리는 유클리드 거리를 사용한다.) <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-msqrt space="4"><mjx-sqrt><mjx-surd><mjx-mo class="mjx-sop"><mjx-c class="mjx-c221A TEX-S1"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.103em;"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.289em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msub space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.289em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>D</mi><mo>=</mo><msqrt><mo stretchy="false">(</mo><msub><mi>x</mi><mn>1</mn></msub><mo>−</mo><msub><mi>x</mi><mn>2</mn></msub><msup><mo stretchy="false">)</mo><mn>2</mn></msup><mo>+</mo><mo stretchy="false">(</mo><msub><mi>y</mi><mn>1</mn></msub><mo>−</mo><msub><mi>y</mi><mn>2</mn></msub><msup><mo stretchy="false">)</mo><mn>2</mn></msup></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(D = \sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}\)</span> </mjx-container></p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/12918/1.png" style="height:160px; width:165px"></p>

<p>예를 들어, 다음과 같이 물건이 주어진다면 오른쪽의 물건을 1칸 아래로 내리면 정리정돈이 되고, 이때 물건의 이동거리는 1이다.</p>

### 입력 

 <p>입력의 첫 줄에는 정수 N(1 ≤ N ≤ 100)이 주어진다. 그 다음 N줄에 각 물건들의 위치가 차례대로 주어진다. 각 좌표는 −1,000이상 1,000이하의 정수이다. 물건들이 겹쳐있는 경우는 없다.</p>

### 출력 

 <p>모든 물건들을 깔끔하게 정리정돈 했을 때, 물건들이 이동하는 거리의 합의 최솟값을 소수점 셋째자리까지 반올림해 출력한다.</p>

