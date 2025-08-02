# [Gold II] What are Birds? (Large) - 12688 

[문제 링크](https://www.acmicpc.net/problem/12688) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

기하학

### 제출 일자

2025년 8월 2일 20:48:49

### 문제 설명

<p>You are studying animals in a forest, and are trying to determine which animals are birds and which are not.</p>

<p>You do this by taking two measurements of each animal – their height and their weight. For an animal to be a bird, its height needs to be within some range, and its weight needs to be within another range, but you're not sure what the height and weight ranges are. You also know that <em>every</em> animal that satisfies these ranges is a bird.</p>

<p>You have taken some of the animals you have measured and shown them to biologists, and they have told you which are birds and which are not. This has given you some information on what the height and weight ranges for a bird must be. For the remaining animals, your program should determine if they are definitely birds, definitely not birds, or if you don't know from the information you have.</p>

### 입력 

 <p>One line containing an integer <strong>C</strong>, the number of test cases in the input.</p>

<p>Then for each of the <strong>C</strong> test cases:</p>

<p> </p>

<ul>
	<li>One line containing an integer <strong>N</strong>, the number of animals you have shown to the biologists.</li>
	<li><strong>N</strong> lines, one for each of these animals, each of the format "<strong>H W X</strong>", where <strong>H</strong> is the height of the animal, <strong>W</strong> is the weight of the animal, and <strong>X</strong> is either the string "BIRD" or "NOT BIRD". All numbers are positive integers.</li>
	<li>One line containing an integer <strong>M</strong>, the number of animals you have not shown to the biologists.</li>
	<li><strong>M</strong> lines, one for each of these animals, each of the format "<strong>H W</strong>", where <strong>H</strong> is the height of the animal and <strong>W</strong> is the weight of the animal. All numbers are positive integers.​</li>
</ul>

<p>Limits</p>

<ul>
	<li>1 ≤ <strong>C</strong> ≤ 10</li>
	<li>1 ≤ all heights and weights ≤ 1000000</li>
	<li>1 ≤ <strong>N</strong> ≤ 1000</li>
	<li>1 ≤ <strong>M</strong> ≤ 1000</li>
</ul>

### 출력 

 <p>For each of the <strong>C</strong> test cases:</p>

<ul>
	<li>One line containing the string "Case #<strong>X</strong>:" where <strong>X</strong> is the number of the test case, starting from 1.</li>
	<li>M lines, each containing one of "BIRD", "NOT BIRD", or "UNKNOWN" (quotes are just for clarity and should not be part of the output).</li>
</ul>

