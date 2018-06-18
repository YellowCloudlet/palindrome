# palindrome
The program that will be the largest number of palindrome, which is the product of two simple five-digit numbers, as well as the factors themselves obtained. Optimize the solution method, the number of iterations to find the right solution, the quality of the code execution, and the time taken to complete this task.

We approach the solution of this problem nontrivially. We know that we have 2 prime numbers whose product should give a palindrome. The maximum 5-digit number is 99999, respectively, our answer / palindrome should not exceed the mark in 99999 * 99999 = 9 999 800 001. In this number we have 10 characters.
What do we know about palindromes, namely, how many? As we see, within 10 ^ 9 - 10 ^ 10 there are no palindromes that would be obtained by multiplying 2 any prime numbers (this can also be proved by the frequency of the appearance of a prime number and the probability of encountering a palindrome).

![Иллюстрация к проекту](https://github.com/YellowCloudlet/palindrome/raw/master/photoes/polinom_kol-vo.png)

From this we conclude that our desired palindrome can be 9-digit. Let's compile a simple table of numbers from 10,000 to 99,000 in steps of l = 1000. We obtain a table of the form:

![Иллюстрация к проекту](https://github.com/YellowCloudlet/palindrome/raw/master/photoes/polinom_1.png)

Copy it and multiply all the numbers in the specified range. We get:

![Иллюстрация к проекту](https://github.com/YellowCloudlet/palindrome/raw/master/photoes/image.png)

We see the averaged boundary, namely 31000 * 31000 gives 961 000 000, has 9 signs, then the products of numbers give only 10-digit numbers.
If we take the 1st column as the matrix A, and the second as the matrix B, then A * B ^ t (transposed) will give 10-digit numbers, which immediately throws away such an algorithm.
Since we took l (step) rather large, our sample may not be exact, for example 31000 * 32000 = 992 000 000. Then we find the admissible boundaries at which the factors will give only 9-digit numbers (I did this on the graph because of the convenience). We have:

![Иллюстрация к проекту](https://github.com/YellowCloudlet/palindrome/raw/master/photoes/график.png)

Where the results that satisfy us lie below the graph, that is, the graph itself is a set of boundary values (10-digit numbers when multiplying values). Let's make a more detailed table on the schedule to see how the product of different multipliers behaves:

![Иллюстрация к проекту](https://github.com/YellowCloudlet/palindrome/raw/master/photoes/image(1).png)

As we see the more the multipliers diverge, the less their product as a result, and since we need to find the maximum palindrome, we can conclude that our factors lie within the approximate range of 31000 to 33000, and considering our l (step = 1000), we expand admission, respectively, to + - l, that is, in the end our factors will lie in such a boundary from 30,000 to 34,000.
Now we know exactly where to find our factors, which means we can speed up the palindrome search algorithm at times, because we do not need to check for numbers 10,000 <x <30000 + 34000 <x <99999. That's how you can simply and effectively optimize this task.



