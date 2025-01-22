# [Silver I] Relative Relatives - 4556 

[문제 링크](https://www.acmicpc.net/problem/4556) 

### 성능 요약

메모리: 2036 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 자료 구조, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 해시를 사용한 집합과 맵, 정렬, 트리를 사용한 집합과 맵

### 제출 일자

2025년 1월 22일 15:35:06

### 문제 설명

<p>Today is Ted's 100th birthday. A few weeks ago, you were selected by the family to contact all of Ted's descendants and organize a surprise party. To make this task easier, you created an age-prioritized list of everyone descended from Ted. Descendants of the same age are listed in dictionary order.</p>

<p>The only materials you had to aid you were birth certificates. Oddly enough, these birth certificates were not dated. They simply listed the father's name, the child's name, and the father's exact age when the baby was born.</p>

### 입력 

 <p>Input to this problem will begin with line containing a single integer <i>n</i> indicating the number of data sets. Each data set will be formatted according to the following description.</p>

<p>A single data set has 2 components:</p>

<ol>
	<li><i>Descendant Count</i> - A line containing a single integer <i>X</i> (where 0 < <i>X</i> < 100) indicating the number of Ted's descendants.</li>
	<li><i>Birth Certificate List</i> - Data for <i>X</i> birth certificates, with one certificate's data per line. Each certificate's data will be of the format "<tt>FNAME CNAME FAGE</tt>" where:
	<ul>
		<li><i>FNAME</i> is the father's name.</li>
		<li><i>CNAME</i> is the child's name.</li>
		<li><i>FAGE</i> is the integer age of the father on the date of <i>CNAME</i>s birth.</li>
	</ul>
	</li>
</ol>

<p>Note:</p>

<ul>
	<li>Names are unique identifiers of individuals and contain no embedded white space.</li>
	<li>All of Ted's descendants share Ted's birthday. Therefore, the age difference between any two is an integer number of years. (For those of you that are really picky, assume they were all born at the exact same hour, minute, second, etc... of their birth year.)</li>
	<li>You have a birth certificate for all of Ted's descendants (a complete collection).</li>
</ul>

### 출력 

 <p>For each data set, there will be <i>X</i>+1 lines of output. The first will read, "<i><tt>DATASET Y</tt></i>", where <i>Y</i> is 1 for the first data set, 2 for the second, etc. The subsequent <i>X</i> lines constitute your age-prioritized list of Ted's descendants along with their ages using the format "<i><tt>NAME AGE</tt></i>". Descendants of the same age will be listed in dictionary order.</p>

