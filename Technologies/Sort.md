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
* Binary Tree Sort: (Best: O(nlogn), Average: O(nlogn), Worst: O(nlogn))
* Radix Sort: (Best: -, Average: O(n(k/d)), Worst: O(n(k/d)))
* Bucket Sort: (Best: -, Average: O(n+r), Worst: O(n+r))
* Couting Sort: (Best: -, Average: O(n+r), Worst: O(n+r))

####Space
* Bubble Sort (O(1))
* Selection Sort (O（1))
* Insertion Sort (O(1))
* Heap Sort (O(1))
* Merge Sort (O(n))
* Quick Sort (O(logn))
* Shell Sort (O(1))
* Binary Tree Sort: (O(n))
* Radix Sort: (O(n+2^d))
* Bucket Sort: (O(n+r))
* Couting Sort: (O(n+r))

###Reference
[Sorting Algorithm](#https://en.wikipedia.org/wiki/Sorting_algorithm)

Table of Sorting Algorithm
-----------------
1. [Quicksort](#Quicksort)
1. [Features](#features)
1. [Usage](#usage)
1. [Structure](#structure)
1. [Troubleshooting](#troubleshooting)
1. [References](#references)
1. [Deployment](#deployment)

Quicksort
---------
[Quicksort Wikipedia](#https://en.wikipedia.org/wiki/Quicksort)
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