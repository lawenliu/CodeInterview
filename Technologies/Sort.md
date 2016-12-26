##Sorting
###Stable Sorting and Not Stable Sorting
If a sorting algorithm, after sorting the contents, does not change the sequence of similar content in which they appear, it is called stable sorting.
####Stable
* Merge Sort
* In-place Merge Sort
* Insertion Sort
* Bubble Sort
* Binary Tree Sort
* Radix Sort
* Bucket Sort
* Couting Sort

####Not Stable
* Quicksort
* Heapsort
* Selection Sort
* Shell Sort

###In-place Sorting and Not-in-place Sorting
Sorting algorithms may require some extra space for comparison and temporary storage of few data elements. These algorithms don't require any extra space and sorting is said to happen in-place, or for example, within array itself.

###Time and Space
####Time
* Bubble Sort (Best: O(n), Average: O(n^2), Worst: O(n^2))
* Selection Sort (Best: O(n^2), Average: O(n^2), Worst: O(n^2))
* Insertion Sort (Best: O(n), Average: O(n^2), Worst: O(n^2))
* Heap Sort (Best: O(nlogn), Average: O(nlogn), Worst: O(nlogn))
* Merge Sort (Best: O(nlogn), Average: O(nlogn), Worst: O(nlogn))
* Quick Sort (Best: O(nlogn), Average: O(nlogn), Worst: O(n^2))
* Shell Sort (Best: O(nlogn), Average: O(nlog^2(n)), Worst: O(nlog^2(n))
* Binary Tree Sort: (Best: O(nlogn), Average: O(nlogn), Worst: O(n^2)
* Radix Sort: (Best: -, Average: O(nk)), Worst: O(nk)))
* Bucket Sort: (Best: -, Average: O(n+k), Worst: O(n^2))
* Couting Sort: (Best: -, Average: O(n+k), Worst: O(n+k))

####Space
* Bubble Sort (O(1))
* Selection Sort (O（1))
* Insertion Sort (O(1))
* Heap Sort (O(1))
* Merge Sort (O(n))
* Quick Sort (O(log(n)))
* Shell Sort (O(1))
* Binary Tree Sort: (O(n))
* Radix Sort: (O(n+k))
* Bucket Sort: (O(n))
* Couting Sort: (O(k))

###Reference
* [Wikipedia](#https://en.wikipedia.org/wiki/Sorting_algorithm)
* [Big O CheatSheet](#http://bigocheatsheet.com/)
* [CMU Lecture] (#https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html)

Table of Sorting Algorithm
-----------------
1. [Quicksort](#quicksort)
1. [Merge Sort](#merge sort)

Quicksort
---------
[Quicksort Wikipedia](https://en.wikipedia.org/wiki/Quicksort)
###Introduction
Quicksort is an efficient sorting algorithm, serving as a systematic method for placing the element of an array in order. When implement well, it can be about two or three times faster than its main competitors, merge sort and heapsort.
Quciksort is a comparison sort, meaning that it can sort items of any type for which a "less-than" relation is defined. In efficient implementations it is not a stable sort, meaning that the relative order of equal sort items is not preserved. Quicksort can operate in-place on an array, requiring small additional amounts of memory to perform the sorting.
Mathematical analysis of quicksort shows that, on average, the algorithm takes O(nlogn) comparisons to sort n items. In the worst case, it makes O(n^2) comparisons, though this behavior is rare.
###Algorithm
####Steps
1. Pick an element, called a pivot, from the array.
1. Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
1. Recursively apply the above steps to the sub-array of elements with smaller values and seperately to the sub-array of elements with greater values.

####Pseudocode
```
algorithm quicksort(A, low, high) is
	if (l < h) then
		pivot = partition(A, low, high);
		quicksort(A, l, pivot - 1ow);
		quicksort(A, pivot + 1, high);
```
```
algorithm partition(A, low, high) is
	pivot = A[high];
	i = low;
	for j = low to high - 1 do
		if A[j] <= pivot then
			swap(A[i], A[j]);
			i = i + 1;
	swap(A[i], A[j])
	return i;
```
####Time Analysis
#####Worst-case analysis
The most unbalanced partition occurs when the pivot divides the list into two sublists of sizes 0 and n - 1. This may occur if the pivot happens to be the smallest or largest element in the list, or in some implementations (such as Lomuto partition schema) when all the elements are equals
#####Best-case analysis
In the most balanced case, each time we perform a partition we divide the list into nearly equal pieces. This means each recursive call processes a list of half the size. Consequently, we can make only logn nested calls befor we reach a list of size 1. This means that the depth of the call tree is logn. But no two calls at the same level of the call tree process the same part of the originial list. Thus, each level of calls need only O(n) time all together (each call has some constant overhead, but since there are only O(n) calls at each level, this is subsumed in the O(n) factor). The result is that the algorithm uses only O(nlogn) time.
#####Average-case analaysis
To sort an array of n distinct elements, quicksort take O(n log n) time in expectation, averaged over all n! permutations of n elements with equal probability.
```
T(n) = O(n) + 2T(n/2)
```
####Space Analysis
The space used by quicksort depends on the version used.
The in-place version of quicksort has a space complexity of O(logn), even in the worst case, when it is carefully implemented using the following strategies:
* In-place partitioning is used. This unstable partition requires O(1) space.
* After partitioning, the partition with the fewest elements is (recursively) sorted first, requiring at most O(log n) space.

Merge Sort
----------
[Wikipedia](https://en.wikipedia.org/wiki/Merge_sort#Top-down_implementation)
###Introduction
Merge sort is an efficient, general-purpose, comparison-based sorting algorithm. Most implementations produce a stable sort. which means that the implementation preserves the input order of equal elements in the sorted output. Merge sort is a divide and conquer algorithm.
###Algorithm
####Steps
1. Get middle index of sub-array.
1. Recursion on the left sub-array from left to middle.
1. Recursion on the right sub-array from middle + 1 to right.
1. Merge the left sub-array and right sub-array.
1. Recursion until left > right
####Pseudocode
```
algorithm mergesort(A, left, right) is
	if left < right then
		middle = (left + right) / 2;
		mergeSort(A, left, middle);
		mergeSort(A, middle + 1, right);
		merge(A, left, middle, right);
```
```
algorithm merge(A, left, middle, right) is
	tempA[right - left + 1];
	k = 0;
	i = left;
	j = middle + 1;
	while i <= middle && j <= right do
		if A[i] < A[j] then
			tempA[k++] = A[i++];
		else
			tempA[k++] = A[j++];
	while i <= middle do
		tempA[k++] = A[i++];
	while j <= right do
		tempA[k++] = A[j++];
	k = 0;
	while k < tempA.size() do
		A[left + k] = tempA[k];
```
