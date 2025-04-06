# [Gold III] Family Tree - 15765 

[문제 링크](https://www.acmicpc.net/problem/15765) 

### 성능 요약

메모리: 4176 KB, 시간: 0 ms

### 분류

많은 조건 분기, 그래프 이론, 구현, 최소 공통 조상, 트리

### 제출 일자

2025년 4월 6일 13:31:15

### 문제 설명

<p>Farmer John owns a family-run farm that has been passed down over several generations, with a herd of cows whose familial roots can similarly be traced back several generations on the same farm. By examining old records, Farmer John is curious how the cows in his current herd are related to each-other. Please help him in this endeavor!</p>

### 입력 

 <p>The first line of input contains <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq N \leq 100$</span></mjx-container>) followed by the names of two cows. Cow names are each strings of at most 10 uppercase letters (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2026"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D44D TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi><mo>…</mo><mi>Z</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A \ldots Z$</span></mjx-container>). Farmer John is curious about the relationship between the two cows on this line of input.</p>

<p>The next <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> lines each contain two cow names <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$X$</span></mjx-container> and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44C TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>Y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$Y$</span></mjx-container>, indicating that <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>X</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$X$</span></mjx-container> is the mother of <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44C TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>Y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$Y$</span></mjx-container>.</p>

### 출력 

 <p>You should print one line of output indicating the relationship between the two cows specified on the first line of input (for simplicity, let's call these two cows BESSIE and ELSIE for the examples below). Here are the different types of relationships that are possible:</p>

<ul>
	<li>You should output "SIBLINGS" if BESSIE and ELSIE have the same mother.</li>
	<li>BESSIE might be a direct descendant of ELSIE, meaning that ELSIE is either the mother, grand-mother, great-grand-mother, great-great-grand-mother, etc., of BESSIE. If this is the case, you should print "ELSIE is the (relation) of BESSIE", where (relation) is the appropriate relationship, for example "great-great-grand-mother".</li>
	<li>If ELSIE is a child of an ancestor of BESSIE (and ELSIE is not herself an ancestor or sister of BESSIE), then ELSIE is BESSIE's aunt. You should output "ELSIE is the aunt of BESSIE" if ELSIE is a child of BESSIE's grand-mother, "ELSIE is the great-aunt of BESSIE" if ELSIE is a child of BESSIE's great-grand-mother, "ELSIE is the great-great-aunt of BESSIE" if ELSIE is a child of BESSIE's great-great-grand-mother, and so on.</li>
	<li>If BESSIE and ELSIE are related by any other means (i.e., if they share a common ancestor), they are cousins, and you should simply output "COUSINS".</li>
	<li>You should output "NOT RELATED" if BESSIE and ELSIE have no common ancestor, or neither is directly descended from the other.</li>
</ul>

<p>The following diagram helps illustrate the relationships above, which are the only relationship types you need to consider. Observe that some relationships like "niece" (daughter of sister) are not necessary since if BESSIE is the niece of ELSIE, then ELSIE is BESSIE's aunt.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15765/1.png" style="width: 593px; height: 419px;"></p>

