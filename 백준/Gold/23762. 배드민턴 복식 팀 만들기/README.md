# [Gold II] 배드민턴 복식 팀 만들기 - 23762 

[문제 링크](https://www.acmicpc.net/problem/23762) 

### 성능 요약

메모리: 14124 KB, 시간: 28 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 정렬

### 제출 일자

2025년 3월 3일 14:38:32

### 문제 설명

<p>고려대학교 배드민턴 동아리원들이 배드민턴을 치려고 한다. 모두가 동시에 재밌게 배드민턴을 치기 위해, 동아리원들의 각각의 실력을 고려하여 다음과 같이 복식 팀을 만들려고 한다.</p>

<p>배드민턴 복식은 2명이 짝을 지어 대결하기 때문에, 양쪽에서 총 4명이 한 팀을 이루어 게임을 진행한다. 또한 모든 사람의 배드민턴 실력을 자연수로 나타낼 수 있다. 이 때 각 팀의 <code>(실력 최댓값) - (실력 최솟값)</code> 을 그 팀의 실력차라 하자. 비슷한 실력대의 사람들끼리 배드민턴을 쳐야 재미있게 칠 수 있으므로, 실력차가 작을수록 게임이 재미있다. 또한 실력차와 별개로 배드민턴을 치지 않는 것이 가장 재미가 없기 때문에, 팀을 가능한 한 많이 만들어야 한다.</p>

<p>지금은 사람이 많아 여러 팀을 만들어야 하므로, 모든 팀의 실력차의 총합이 최소가 되도록 해야 한다. 그런데 배드민턴에 참여한 인원수가 4의 배수가 아닐 수 있으므로, 누군가는 배드민턴을 치지 못할 수 있다.</p>

<p>실력차의 합이 최소가 되도록 팀을 구성할 때, 실력차의 합의 최솟값과 배드민턴을 치지 못하는 사람들이 누군지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 배드민턴에 참가한 인원수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4 \leq N \leq 10^5$</span></mjx-container>)</p>

<p>둘째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명의 배드민턴 실력을 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2026"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>m</mi><mn>0</mn></msub><mo>,</mo><msub><mi>m</mi><mn>1</mn></msub><mo>,</mo><mo>…</mo><mo>,</mo><msub><mi>m</mi><mrow data-mjx-texclass="ORD"><mi>N</mi><mo>−</mo><mn>1</mn></mrow></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m_0,m_1,\ldots ,m_{N-1}$</span></mjx-container>이 공백을 사이에 두고 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msub space="4"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><msub><mi>m</mi><mi>i</mi></msub><mo>≤</mo><msup><mn>10</mn><mn>9</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\leq m_i \leq 10^9$</span></mjx-container>)</p>

<p>실력은 사람의 번호 순서대로 주어지기 때문에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span></mjx-container>번 사람의 실력은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>m</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m_i$</span></mjx-container>이며 번호는 0부터 시작한다.</p>

### 출력 

 <p>첫째 줄에 실력차의 합의 최솟값을 출력한다.</p>

<p>둘째 줄부터 배드민턴을 치지 못하는 사람의 번호를 한 줄에 한 명씩 출력한다. 만약 여러 가지 경우가 있다면 아무 거나 출력한다.</p>

