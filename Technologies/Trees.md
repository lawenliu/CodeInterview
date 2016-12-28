##Trees
Table of Content
-----------------
1. [n-ary tree](#n-ary-tree)
1. [trie-tree](#trie-tree)
1. [red/black tree](#redblack-tree)
1. [splay tree](#splay-tree)
1. [AVL tree](#avl-tree)
1. [B tree](#b-tree)

n-ary tree
----------
If we relax the restriction that each node can have only one key, we can reduce the height of the tree. Also known as m-way search tree.
```
a. is empty or 
b. consists of a root containing j (1 <= j < m) keys, kj, and
	a set of sub-trees, Ti, (i = 0...j), such that
	i. if k is a key in T0, then k <= k1
	ii. if k is a key in Ti (0 < i < j), then ki <= k <= ki+1
	iii. if k is a key in Tj, then k > kj and 
	iv. all Ti are nonempty m-way search trees or all Ti are emtpy.
```
The height of a complete m-ary tree with n nodes is ceiling(logm(n))
A B-tree of order m is an m-way tree in which:
a. all leaves are on the same level
b. all nodes except the root and the leaves have at least  m / 2 children and at most m children. The root has at least 2 children and at most m children.

A variation of the B-tree, known as B+-tree consider all the keys in nodes except the leaves as dummies. All keys are duplicated in the leaves. This has the advantage that is all the leaves are linke together sequentially, the entire tree may be scanned without visiting the higher nodes at all.

Trie-tree
---------
Trie also called digital tree and somtimes radix tree or prefix tree(as they can be search by prefixes), is a kind of search tree-an ordered tree data structure that is used to store a dynamic set or associative array where the keys are usually strings. Unlike a binary search tree, no node in the tree stores the key associated with that node; instead, its position in the tree defines the key with which it is associated. All the descendants of a node have a common prefix of the string associated with that node, and the root is associated with the empty string. Values are not necessarily associated with eveyr node. Rather, vlaues tend only to be associated with leaves, and with some inner nodes that correspond to keys of interest.

red/black tree
--------------
A red-black tree is a kind of self-balancing binary search tree. Each node of the binary tree has an extra bit, and that bit is oftern interpreted as the color (red or black) of the node. These color bits are used to ensure the tree remains approximately balanced during insertion and deletions.
Balance is preserved by painting each node of the tree with one of two colors (typically called 'red' and 'black') in a way that satisfies certain properties, which collectively constrain how unbalanced the tree can become in the worst case. When the tree is modified, the new tree is subsequently rearranged and repainted to restore the coloring properties. The properties are designed in such a way that this rearranged and recoloring, are also performed in O(log n) time.
Tracking the color of each node requires only 1 bit of information per node because there are only two colors. The tree does not contain any other data specific to its being a red-black tree so its memory footprint is almost identical to  a classic (uncolored) binary search tree. In many cases the additional bit of information can be stored at no additional memory cost.
###Properties
In additional to the requirements imposed on a binary search tree the following must be satisfied by a red-black tree:
* Each node is either red or black.
* The root is black. This rulle is sometimes omitted. Since the root can always be change from red to black, but not necessarily vice versa, this rule has little effect on analysis.
* All leaves (NIL) are black.
* If node is red, then both its children are black.
* Every path from a given node to any of its decendant NIL nodes contains the same number of black nodes. Some difinitions: the number of black nodes from the root to a node is the node's black depth; the uniform number of black nodes in all paths from root to the leaves is called the black-height of the red-black tree.
These constraints enforce a critical property of red-black trees: the path from the root to the farthest leaf is no more than twice as long as the path from root to the nearest leaf. The result is that the tree is roughly height-balanced. Since operations such as inserting, deleting, and finding values require worst-case time proportianal to the height of the tree, this theoretical upper bound on the height allows red-black trees to be efficient in the worst case, unlike ordinary binary search trees.

Splay tree
----------
A splay tree is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again. It perform basic operations such as insertion, look-up and removal in O(log n) amortized time. For many sequences of non-random operations, splay trees perform better than other search trees, even when the specific pattern of the sequence is unknown.
All normal operations on a binary search tree are combined with one basic operation, called splaying. Splaying the tree for a certain element rearranges the tree so that the element is placed at the root of the tree. One way to do this is to first perform a standard binary tree search for the element in question, and then use tree rotations in a specific fashion to bring the element to the top. Alternatively, a top-down algorithm can combine the search and the tree reorganization into a single phase.

###Advantages
Good performance for a splay tree depends on the fact that it is self-optimizing, in that frequently accessed nodes will move nearer to the root where they can be accesses more quickly. The worst-case height-though unlikely - is O(n), with the average being O(log n). Having frequently used nodes near the root is an advantage for many practical application, and is particularly useful for implementating caches and garbage collection algorithms.
Advantages include:
* Comparable performance: Average-case performance is as efficient as other trees.
* Small memory footprint: Splay trees do not need to store any bookkeeping data.
###Disadvantages
The most significant disadvantage of splay trees is that the height of a splay tree can be linear. For example, this will be the case after accessing all n elements in on-descreasing order. Since the height of a tree corresponds to the worst-case access time, this means that the actural cost of an operation can be high. However the amortized access cost of this worst case is logarithmic, O(log n). Also, the expected access cost can be reduced to O(log n) by using a randomized variant.

AVL tree
--------
An AVL tree is a self-balancing binary search tree. It was the first such data structure to be invented. In an AVL tree, the heights of the two child subtrees of any node differ by at most one. If at any time they differ by more than one, rebalancing is done to resotre this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.
The AVL tree is named after its two Soviet inventors, Georgy Adelson-Velsky and Evgenii Landis.
AVL tree are often compared with red-black trees because both support the same set of operations and take O(log n) time for the basic operations. For lookup intensive applications, AVL trees are faster than red-black trees because they are more strictly balanced. Similar to red-black trees. AVL trees are height-balanced. Both are in genearal not weight-balanced nor u-balanced for any u <1/2; that is, sibling nodes can have hugely differing numbers of descendants.

B tree
------
B-tree is a self-balancing tree data structure that keeps data sorted and allows searches, sequential access, insertions, and deletions in logarithmic time. The B-tree is generalization of a binary search tree in that a node can have more than two children. Unlike self-balancing binary search trees, the B-tree is optimized for systems that read and write large blocks of data. B-trees are a good example of a data structure for external moemory. It is commonly used in databases and filesystems.
