# [Platinum IV] Choreography - 17523 

[문제 링크](https://www.acmicpc.net/problem/17523) 

### 성능 요약

메모리: 100664 KB, 시간: 604 ms

### 분류

그리디 알고리즘, 구현, 시뮬레이션

### 제출 일자

2025년 9월 16일 11:40:39

### 문제 설명

<p>Korean idol groups are famous in the world for dynamic and elaborate group dances, called Kalgunmu. A Korean idol group has <em>m</em> members. One day the members practice their choreography in a stage. Suppose that the stage is simplified as a line. There are <em>n</em> closed intervals of identical length on the stage. Here we shall specify seven rules which the members should follow in every moment of choreography as follows:</p>

<ul>
	<li>R1) Each member should stand on one of the intervals.</li>
	<li>R2) No two or more members can stand on the same interval.</li>
	<li>R3) Two intervals on which arbitrary two members stand respectively cannot intersect.</li>
</ul>

<p>Note that two closed intervals [<em>a</em>, <em>b</em>] and [<em>c</em>, <em>d</em>] with <em>a</em> ≤ <em>c</em> intersect if <em>c</em> ≤ <em>b</em>.</p>

<p>The choreography consists of several steps with the following rules:</p>

<ul>
	<li>R4) At any step, only one member can move from her/his current interval to another interval. In other words, two or more members cannot move simultaneously at any step.</li>
	<li>R5) When changing the interval on which she/he stands at some step, a member has to move into one</li>
</ul>

<p>of the intervals that her/his current interval intersects.</p>

<p>Note that a member cannot move into the interval <em>I</em> if <em>I</em> intersects an interval on which another member stands, according to the rule R3.</p>

<ul>
	<li>R6) The set of intervals on which the members stand in the start of choreography should be <em>S</em>.</li>
	<li>R7) The set of intervals on which the members stand in the end of choreography should be <em>E</em>.</li>
</ul>

<p>Note that the sets <em>S</em> and <em>E</em> are given as in the input.</p>

<p>According to the rules of the choreography, the size of <em>S</em> (or <em>E</em>) is <em>m</em> and the intervals in <em>S</em> (or <em>E</em>) do not intersect each other. Also each member shall move from an interval <em>s</em> in <em>S</em> to an interval <em>e</em> in <em>E</em> through the choreography. We are interested in the minimum number of steps to complete the choreography satisfying the above rules R1 to R7.</p>

<p>For example, in Figure E. 1, there are six intervals on a stage, which are denoted by numbers from 1 to 6. The blue intervals 1 and 4 are intervals on which two members stand in the start of choreography and the red intervals 3 and 6 are ones in the end.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a5a7ec2f-08f9-4c83-a135-045bf66faa46/-/preview/" style="width: 280px; height: 117px;"></p>

<p style="text-align: center;">Figure E. 1 Initial configuration <em>S</em> of the choreography on a stage</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fef83e14-8f6c-4bba-9fb2-becae6b29466/-/preview/" style="width: 668px; height: 275px;"></p>

<p style="text-align: center;">Figure E. 2 Four steps of choreography</p>

<p>At the first step, the member standing on the interval 4 moves into the interval 5. Notice that the member on the interval 1 cannot move into the interval 2 at the first step, because the interval 2 intersects the interval 4 that another member stands on. As in Figure E. 2, two members can move into the red intervals in four steps. But if the member on the interval 4 moves into the interval 6 at the first step, then the choreography would be completed in three steps, which is minimum.</p>

<p>Given <em>m</em> members, <em>n</em> intervals, and two sets <em>S</em> and <em>E</em> for the choreography, write a program to find a choreography from <em>S</em> to <em>E</em> with a minimum number of steps, and output all such steps.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, <em>m</em> and <em>n</em> (1 ≤ <em>m</em> ≤ <em>n</em> ≤ 5,000), where <em>m</em> is the number of members and <em>n</em> is the number of intervals on the stage. The intervals are numbered from 1 to <em>n</em> such that the left endpoint of interval <em>i</em> is strictly less than the left one of interval <em>i</em> + 1. The second line contains an integer <em>r</em>, the length of intervals (1 ≤ <em>r</em> ≤ 10,000). The third line contains a sequence of sorted <em>n</em> integers in ascending order where the <em>i</em>-th number is the left endpoint of the interval <em>i</em>, where these numbers are between 0 and 10<sup>9</sup>. The following line contains a sequence of sorted <em>m</em> integers to denote the intervals belonging to the set <em>S</em> in ascending order. The last line contains a sequence of sorted <em>m</em> integers to denote the intervals belonging to the set <em>E</em> in ascending order.</p>

### 출력 

 <p>Your program is to write to standard output. The first line should contain the minimum number MIN of steps to complete the choreography. In the following MIN lines, the <em>i</em>-th line contains two integers <em>a</em> and <em>b</em>, where a member moves from the interval <em>a</em> to the interval <em>b</em> at the step <em>i</em> of the choreography with the minimum number of steps MIN. If there are one or more solutions, then print arbitrary one. If there is no solution, then print −1. </p>

