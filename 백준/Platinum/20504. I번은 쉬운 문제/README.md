# [Platinum IV] I번은 쉬운 문제 - 20504 

[문제 링크](https://www.acmicpc.net/problem/20504) 

### 성능 요약

메모리: 40424 KB, 시간: 244 ms

### 분류

그래프 이론(graphs), 강한 연결 요소(scc)

### 문제 설명

<p>2030년, Farmer John은 선린 인터넷 컴퍼니에서 소프트웨어 개발자이자 검색 팀장으로 근무하고 있다. John의 강한 의지에 따라 검색 팀에서는 모든 소프트웨어의 개발을 테스트 주도 개발(test-driven development) 형태로 수행하고 있다.</p>

<p>검색팀에서는 효율적인 검색을 위해 새로운 프로그램을 만들고 있고, 이 프로그램은 여러 함수로 구성되어 있다. 하나의 함수는 실행되는 동안 0개 이상의 다른 함수를 호출하게 된다.</p>

<p>예를 들어, 프로그램이 다음과 같이 3개의 함수 <code>f</code>, <code>g</code>, <code>h</code>로 이루어져 있다면, <code>f</code>를 호출했을 때는 호출될 가능성이 있는 추가적인 함수가 없고, <code>g</code>를 호출했을 때는 <code>f</code>가 호출될 가능성이 존재하며, <code>h</code>를 실행했을 때는 <code>f</code>, <code>g</code>, <code>h</code>가 호출될 가능성이 존재한다.</p>

<pre>function<void> f(x: int) {
    // do something (다른 함수를 호출하지는 않는다.)
}

function<void> g(x: int) {
    // do something (다른 함수를 호출하지는 않는다.)
    if (condition1) f(x);
}

function<int> h(x: int) {
    if (condition2) f(x);
    else g(x);
    if (condition3) h(x-1);
    return x;
}</pre>

<p>이 프로그램의 테스트를 위해 여러 테스트 케이스가 만들어져 있고, 하나의 테스트 케이스는 어떤 함수 하나를 호출하는 방식으로 구성되어 있다. 하지만, 모든 테스트 케이스를 실행하기에는 테스트 케이스의 수가 많아 비효율적이다. 따라서, John은 테스트 케이스 중 일부만을 선택해 실행해보되, 선택한 테스트 케이스를 실행하는 과정에서 모든 함수가 <u>호출될 가능성이 존재하도록</u> 하고자 한다.</p>

<p>각 함수마다 실행 과정에서 호출할 가능성이 있는 함수들의 목록이 주어질 때, John이 선택해야 하는 테스트 케이스의 최소 개수를 구하여라.</p>

### 입력 

 <p>첫 번째 줄에 함수의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 함수의 호출 관계의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>이 사이에 공백을 두고 주어진다.</p>

<p>이후 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개의 줄에 걸쳐 두 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi><mo>,</mo><mi>v</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$u, v$</span></mjx-container>가 사이에 공백을 두고 주어진다. 이는 함수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$u$</span></mjx-container>를 호출했을 때, 함수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$u$</span></mjx-container>가 실행되는 동안 함수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>v</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$v$</span></mjx-container>를 <u>직접</u> 호출할 가능성이 존재함을 의미한다. 반대로, 입력으로 주어지지 않은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi><mo>,</mo><mi>v</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$u, v$</span></mjx-container> 쌍의 경우, 함수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D462 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$u$</span></mjx-container>가 실행되는 동안 함수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>v</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$v$</span></mjx-container>를 직접 호출할 가능성이 존재하지 않는다고 가정하라.</p>

<p>이후 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>가 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>는 John이 만든 테스트 케이스의 수를 의미한다.</p>

<p>이후 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>개의 줄에 걸쳐 한 줄에 하나씩 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>t</mi><mi>i</mi></msub><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>i</mi><mo>≤</mo><mi>T</mi><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$t_i (1 \le i \le T)$</span></mjx-container>가 주어진다. 이는, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span></mjx-container>번째 테스트 케이스가 함수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>t</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$t_i$</span></mjx-container>를 호출하는 방식으로 구성되어 있음을 의미한다.</p>

### 출력 

 <p>John이 선택해야 하는 테스트 케이스의 최소 개수를 출력한다.</p>

<p>단, 모든 테스트 케이스를 전부 호출해도 테스트 과정에서 호출될 가능성이 없는 함수가 존재한다면, <code>-1</code>을 출력한다.</p>

