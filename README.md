
# Table of Contents

1.  [Array](#orgf523cbe)
2.  [Stack](#orga7e94d0)
3.  [Queue](#org0fff86e)
4.  [Singly-Linked List](#org05ef637)
5.  [Doubly-Linked List](#orge5db4dc)
6.  [Skip List](#orgb736b49)
7.  [Hash Table](#org68c4f32)
8.  [Binary Search Tree](#orgc4665ca)
    1.  [what is it](#orgcb35d1e)
    2.  [costs](#orgb0a1754)
    3.  [operations](#orgb6347d2)
        1.  [insertion](#org45059db)
        2.  [search](#org30dba85)
        3.  [deletion](#orgd9f5c4e)
    4.  [pros](#org49c67c3)
    5.  [cons](#org0310adc)
    6.  [use cases](#orgefd916f)
9.  [Cartesian Tree](#org8711dff)
10. [B-Tree](#orge8a8202)
11. [Red-Black Tree](#orgdac1893)
12. [Splay Tree](#org4f1a89a)
13. [AVL Tree](#orgf0826e2)
14. [KD Tree](#org53a981f)



<a id="orgf523cbe"></a>

# Array


<a id="orga7e94d0"></a>

# Stack


<a id="org0fff86e"></a>

# Queue


<a id="org05ef637"></a>

# Singly-Linked List


<a id="orge5db4dc"></a>

# Doubly-Linked List


<a id="orgb736b49"></a>

# Skip List


<a id="org68c4f32"></a>

# Hash Table


<a id="orgc4665ca"></a>

# Binary Search Tree

<img src="./.img/bst.png" width="333" height="333">


<a id="orgcb35d1e"></a>

## what is it

A binary search tree is a tree data structure where:

-   The nodes to the left are smaller than the current node.
-   The nodes to the right are larger than the current node.


<a id="orgb0a1754"></a>

## costs

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">BST</th>
<th scope="col" class="org-left">avarage</th>
<th scope="col" class="org-left">worst</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">Access</td>
<td class="org-left">O(log(n))</td>
<td class="org-left">O(n)</td>
</tr>


<tr>
<td class="org-left">Search</td>
<td class="org-left">O(log(n))</td>
<td class="org-left">O(n)</td>
</tr>


<tr>
<td class="org-left">Insertion</td>
<td class="org-left">O(log(n))</td>
<td class="org-left">O(n)\)</td>
</tr>


<tr>
<td class="org-left">Deletion</td>
<td class="org-left">O(log(n))</td>
<td class="org-left">O(n)</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Space</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">O(n)</td>
</tr>
</tbody>
</table>


<a id="orgb6347d2"></a>

## operations


<a id="org45059db"></a>

### insertion

1.  pseudo code

    ```c
        // T: Tree root
        // k: new value
        insert(T, k)
          if T == NIL
            T = new Node
            T.key = k
          else if k < T.key
            T.left = insert(T.left, k)
          else
            T.right = insert(T.right, k)
          return T
    ```

2.  C code
    
    ```c
        // T: Tree root
        // k: new value
        struct Node *insert(struct Node *T, int k) {
            if ( T == NULL ){
                T = (struct Node*)malloc(sizeof(struct Node));
                T->key = k;
            }
            else if (k < T->key){
                T->left = insert(T->left, k);
            }
            else {
                T->right = insert(T->right, k);
            }
            return T;
        }
    ```

3.  C++ code with class
    
    ```cpp
        class Node {
            public:
                Node( int k ) {
                    key = k;
                    left = right = nullptr;
                }
                int key;
                Node *left;
                Node *right;
        };
        
        class BST {
            private:
                Node *insert(Node *T, int k) {
                    if ( T == NULL ){
                        T = new Node(k);
                    }
                    else if (k < T->key){
                        T->left = insert(T->left, k);
                    }
                    else {
                        T->right = insert(T->right, k);
                    }
                    return T;
                }
            public:
                Node *root;
                BST() {
                    root = nullptr;
                }
                void insert( int k ) {
                    root = insert( root, k);
                }
        };
    ```

<a id="org30dba85"></a>

### search


<a id="orgd9f5c4e"></a>

### deletion


<a id="org49c67c3"></a>

## pros


<a id="org0310adc"></a>

## cons


<a id="orgefd916f"></a>

## use cases


<a id="org8711dff"></a>

# Cartesian Tree


<a id="orge8a8202"></a>

# B-Tree


<a id="orgdac1893"></a>

# Red-Black Tree


<a id="org4f1a89a"></a>

# Splay Tree


<a id="orgf0826e2"></a>

# AVL Tree


<a id="org53a981f"></a>

# KD Tree

