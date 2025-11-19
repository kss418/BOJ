# [Diamond V] 퀵 소트 cnt++ - 14894 

[문제 링크](https://www.acmicpc.net/problem/14894) 

### 성능 요약

메모리: 256712 KB, 시간: 820 ms

### 분류

자료 구조, 세그먼트 트리, 분할 정복, 퍼시스턴트 세그먼트 트리

### 제출 일자

2025년 11월 19일 15:24:03

### 문제 설명

<p>구사과는 N개의 서로 다른 양의 정수를 정렬하기 위해 아래와 같은 C++ 코드를 작성했다.</p>

<div><div id="highlighter_739340" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div><div class="line number5 index4 alt2">5</div><div class="line number6 index5 alt1">6</div><div class="line number7 index6 alt2">7</div><div class="line number8 index7 alt1">8</div><div class="line number9 index8 alt2">9</div><div class="line number10 index9 alt1">10</div><div class="line number11 index10 alt2">11</div><div class="line number12 index11 alt1">12</div><div class="line number13 index12 alt2">13</div><div class="line number14 index13 alt1">14</div><div class="line number15 index14 alt2">15</div><div class="line number16 index15 alt1">16</div><div class="line number17 index16 alt2">17</div><div class="line number18 index17 alt1">18</div><div class="line number19 index18 alt2">19</div><div class="line number20 index19 alt1">20</div><div class="line number21 index20 alt2">21</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c color1 bold">long</code> <code class="c color1 bold">long</code> <code class="c plain">cnt = 0;</code></div><div class="line number2 index1 alt1"><code class="c plain">vector<</code><code class="c color1 bold">int</code><code class="c plain">> sort(vector<</code><code class="c color1 bold">int</code><code class="c plain">> &a) {</code></div><div class="line number3 index2 alt2"><code class="c spaces">    </code><code class="c plain">vector<</code><code class="c color1 bold">int</code><code class="c plain">> less, greater;</code></div><div class="line number4 index3 alt1"><code class="c spaces">    </code><code class="c keyword bold">if</code> <code class="c plain">(a.size() <= 1) </code><code class="c keyword bold">return</code> <code class="c plain">a;</code></div><div class="line number5 index4 alt2"><code class="c spaces">    </code><code class="c color1 bold">int</code> <code class="c plain">pivot = a[(a.size()-1)/2];</code></div><div class="line number6 index5 alt1"><code class="c spaces">    </code><code class="c color1 bold">int</code> <code class="c plain">n = a.size();</code></div><div class="line number7 index6 alt2"><code class="c spaces">    </code><code class="c keyword bold">for</code> <code class="c plain">(</code><code class="c color1 bold">int</code> <code class="c plain">i=0; i<n; i++) {</code></div><div class="line number8 index7 alt1"><code class="c spaces">        </code><code class="c plain">cnt += 1;</code></div><div class="line number9 index8 alt2"><code class="c spaces">        </code><code class="c keyword bold">if</code> <code class="c plain">(a[i] < pivot) {</code></div><div class="line number10 index9 alt1"><code class="c spaces">            </code><code class="c plain">less.push_back(a[i]);</code></div><div class="line number11 index10 alt2"><code class="c spaces">        </code><code class="c plain">} </code><code class="c keyword bold">else</code> <code class="c keyword bold">if</code> <code class="c plain">(a[i] > pivot) {</code></div><div class="line number12 index11 alt1"><code class="c spaces">            </code><code class="c plain">greater.push_back(a[i]);</code></div><div class="line number13 index12 alt2"><code class="c spaces">        </code><code class="c plain">}</code></div><div class="line number14 index13 alt1"><code class="c spaces">    </code><code class="c plain">}</code></div><div class="line number15 index14 alt2"><code class="c spaces">    </code><code class="c plain">sort(less); sort(greater);</code></div><div class="line number16 index15 alt1"><code class="c spaces">    </code><code class="c plain">vector<</code><code class="c color1 bold">int</code><code class="c plain">> ans;</code></div><div class="line number17 index16 alt2"><code class="c spaces">    </code><code class="c plain">ans.insert(ans.end(), less.begin(), less.end());</code></div><div class="line number18 index17 alt1"><code class="c spaces">    </code><code class="c plain">ans.push_back(pivot);</code></div><div class="line number19 index18 alt2"><code class="c spaces">    </code><code class="c plain">ans.insert(ans.end(), greater.begin(), greater.end());</code></div><div class="line number20 index19 alt1"><code class="c spaces">    </code><code class="c keyword bold">return</code> <code class="c plain">ans;</code></div><div class="line number21 index20 alt2"><code class="c plain">}</code></div></div></td></tr></tbody></table></div></div>

<p>서로 다른 자연수 N개로 이루어진 배열 <code>A</code>가 주어졌을 때, 이를 <code>sort</code> 함수를 이용해서 정렬했을 때, <code>cnt</code>에 들어있는 값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 배열 A에 들어있는 수가 공백으로 구분해 주어진다. 주어지는 수는 1부터 N까지의 수로 이루어진 순열이다.</p>

### 출력 

 <p>입력으로 주어진 수를 <code>sort</code> 함수를 이용해 정렬했을 때, <code>cnt</code>에 들어있는 값을 출력한다.</p>

