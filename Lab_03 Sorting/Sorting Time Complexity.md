Sorting Time Complexity :



1\. Bubble Sort

| Case         | 1,000 Elements | 10,000 Elements | 100,000 Elements |

| ------------ | -------------- | --------------- | ---------------- |

| Worst Case   | 0.002000 sec   | 0.191000 sec    | 16.976000 sec    |

| Best Case    | 0.000000 sec   | 0.000000 sec    | 0.000000 sec     |

| Average Case | 0.001000 sec   | 0.129000 sec    | 20.547000 sec    |





2\. Insertion Sort

| Case         | 1,000 Elements | 10,000 Elements | 100,000 Elements |

| ------------ | -------------- | --------------- | ---------------- |

| Worst Case   | 0.001000 sec   | 0.091000 sec    | 7.970000 sec     |

| Best Case    | 0.000000 sec   | 0.000000 sec    | 0.000000 sec     |

| Average Case | 0.001000 sec   | 0.045000 sec    | 4.214000 sec     |



3\. Selection Sort

| Case         | 1,000 Elements | 10,000 Elements | 100,000 Elements |

| ------------ | -------------- | --------------- | ---------------- |

| Worst Case   | 0.001000 sec   | 0.158000 sec    | 14.998000 sec    |

| Best Case    | 0.002000 sec   | 0.131000 sec    | 12.640000 sec    |

| Average Case | 0.002000 sec   | 0.132000 sec    | 12.382000 sec    |





Analysis :

* Insertion Sort performs better than Bubble Sort and Selection Sort for all input sizes.
* Bubble Sort requires more time as the number of elements increases because it performs many unnecessary swaps.
* Selection Sort shows nearly the same execution time in Best, Average, and Worst cases since it always performs the same number of comparisons.
* Insertion Sort is very efficient for small and partially sorted datasets.
* The execution time increases significantly when the input size grows from 1,000 to 100,000 elements, confirming the quadratic time complexity O(n²) of all three algorithms.
* Best-case execution times for Bubble Sort and Insertion Sort are almost zero because the data is already sorted.
* Selection Sort does not benefit much from already sorted data because it still compares every element with the remaining unsorted elements.





Conclusion :

* Fastest Algorithm: Insertion Sort
* Moderate Performance: Selection Sort
* Slowest Algorithm: Bubble Sort









