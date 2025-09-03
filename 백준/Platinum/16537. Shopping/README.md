# [Platinum IV] Shopping - 16537 

[문제 링크](https://www.acmicpc.net/problem/16537) 

### 성능 요약

메모리: 11052 KB, 시간: 40 ms

### 분류

확장 유클리드 호제법, 수학, 정수론

### 제출 일자

2025년 9월 3일 13:25:17

### 문제 설명

<p>Deni’s birthday was yesterday and she received a lot of gifts from many friends. It can be considered that due to the gifts she has an unlimited amount of all types of products that are also available in the stores of the Mall. Deni decides to sell some of them in order to get some money. Of course, with that money she will go shopping in the Mall with her friends, but she will buy only the types of products that are different from the sold ones. Deni wants to have a certain amount of money after all (if this can be done only with the selling of some of her presents, then she will postpone the shopping for another time). Since there are a lot of types of products with different prices, she has a hard time deciding which types of products she will sell and which she will buy; so that at the end she will have the decided in advance amount of money she wants.</p>

<p>Let there be k types of products in the stores, which have prices a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, …, a<sub>k</sub> levs (the Bulgariancurrency) respectively and the girl wants to finish with exactly n levs. You have to output how many times she has to buy or sell every type of product (the buying is marked as a negative number and the selling – as a positive), so that at the end Deni to have n levs. Your program has to work for t tests in one example. Since the output numbers can be very large, each number has to be printed as a product of up to 100 whole numbers. If the task has more than one solution, you can print any one of them. If there is no solution, print the text "No solutions" (without quotes). </p>

### 입력 

 <p>On the first line, there is one positive integer number t – the number of tests that your program has to be processed. For each test on one line, there is k, and on the next line, there are k natural numbers – the prices of the types of products a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, …, a<sub>k</sub> in the Mall stores. On the last line for the test, there is the natural number n – the money in levs that Deni wants to have at the end.</p>

### 출력 

 <p>For each test there has to be the text "No solutions" (without quotes) if the task has no solutions, or otherwise: k whole numbers (each of them has to be in this form: num<sub>1</sub> × num<sub>2</sub> × … × num<sub>p</sub>, 1 ≤ p ≤ 100, -10<sup>9</sup> ≤ num<sub>1</sub> ≤ 10<sup>9</sup>, 0 ≤ num<sub>i</sub> ≤ 10<sup>9</sup> for 2 ≤ i ≤ p), which describe how much times every type of product is bought or sold by Deni (if the number is negative then she buys this type of product and if it is positive – she sells it; if it is zero, then she neither buys it, nor sells it). If you have to output for example 1000000002, it can be printed, for example as 2×500000001, but not as 1000000002, because it is bigger than 10<sup>9</sup>.</p>

