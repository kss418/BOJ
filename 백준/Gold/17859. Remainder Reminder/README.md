# [Gold II] Remainder Reminder - 17859 

[문제 링크](https://www.acmicpc.net/problem/17859) 

### 성능 요약

메모리: 3596 KB, 시간: 0 ms

### 분류

중국인의 나머지 정리, 수학, 정수론

### 제출 일자

2024년 10월 25일 19:39:10

### 문제 설명

<p>“Hey Bill, you were in charge of shipping those novelty book remainders to Remainderville, OH, right?” asked Fred. “Those were cute little books weren’t they, each shaped like a cube one inch on each side. I can’t understand why they didn’t sell better. Can you remind me how many we shipped?”</p>

<p>“Well,” started Bill, “I can’t remember the number exactly. I do remember that we tried three different size boxes. When we used the largest box size we had 407 books remaining after filling all of the rest completely. When we tried the second largest box size we had 409 books left over, and when we tried the smallest box size we only had 17 books left over.”</p>

<p>“Okay,” a slightly puzzled Fred continued, “then just let me know the box sizes and the number of boxes you used.”</p>

<p>“Funny thing” replied Bill, “I can’t remember that either. I do remember that the boxes were made from a 16 by 21 inch sheet of cardboard, with squares cut out at each of the four corners. We then folded the sides up to make an open top box, filled each box with books, then used packaging tape to attach a lid. The dimensions of each box were all integer multiples of inches.”</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b05a87e7-dc91-42a2-b667-e7b422cde1ee/-/preview/" style="width: 319px; height: 133px;"></p>

<p style="text-align: center;">Figure H.1: Example of folding a box.</p>

<p>“You seem to have a very selective memory,” a now aggravated Fred complained.</p>

<p>“Well, if it helps, I know that the three different box sizes were the three largest possible to make from those sheets of cardboard. I also know that we had between 20, 000 and 30, 000 books to ship. I think that should give you enough to determine the total number of books.”</p>

<p>“So let me get this straight. You’re giving me the dimensions of the sheets of cardboard, the fact that the box sizes are the three largest that can be made from them, the number of books left over after using each of the box sizes, and a range in which the number of books lies, correct?” said Fred, rubbing his increasingly aching head.</p>

<p>“That’s it,” confirmed Bill.</p>

<p>“Sounds like some grossly convoluted computer programming problem!”</p>

<p>“Yeah. Go figure?”</p>

### 입력 

 <p>Input consists of seven positive integers a b c d e f g, where a and b (a ≤ b, 7 ≤ a, b ≤ 100) are the dimensions of the sheets of cardboard (in inches), c, d and e (1 ≤ c, d, e ≤ 10<sup>9</sup>) are the number of books left over for the three largest size boxes possible for the given size cardboard sheets (in order from largest box size to third largest box size) and f and g specify an inclusive range for the number of books (1 ≤ f < g ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>Output the number of books which satisfy all the conditions of the problem. Each problem is guaranteed to have a unique answer.</p>

