# [Platinum III] Unique Activities - 21218 

[문제 링크](https://www.acmicpc.net/problem/21218) 

### 성능 요약

메모리: 46396 KB, 시간: 2260 ms

### 분류

이분 탐색, 해싱, 매개 변수 탐색, 라빈–카프, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 9월 22일 16:09:32

### 문제 설명

<p>Emily is tired of having studied at home throughout 2020. She has noticed the same tasks occur over and over: she has to cook and wash the dishes. Then it's time for her class; afterwards she resumes washing the dishes, has to attend another class, washes some more dishes before cooking and washing the dishes for the last time of the day.</p>

<p>There is a part of her day she loves, though: it's when the sequence of activities she is currently carrying out happens only once during her day. She rejoices the most when that activity sequence is unique and really short.</p>

<p>Each activity is represented by an uppercase letter. Given the list of activities Emily has to carry out today, help Emily find the best moment of her day by finding the shortest substring that only occurs once in the input.</p>

<p>If Cooking is C, Dishes is D, and Studying is S, the list of activities in the example above are C D S D S D C D, and the shortest substring that occurs only once is D C. (All the one-letter substrings and the other two-letter substrings occur at least twice).</p>

### 입력 

 <p>The input consists of a single line, with a sequence of <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> uppercase letters (from 'A' to 'Z'). The line is terminated by a newline character which is not considered to be part of the input string.</p>

### 출력 

 <p>The output should contain a single line with the shortest substring that happens only once in the input string. If there are multiple shortest substrings (with the same length), output the one that occurs first.</p>

