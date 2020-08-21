
# Table of Contents

1.  [Array](#org2d1ecb0)
2.  [Stack](#org817d893)
3.  [Queue](#org1e61a24)
4.  [Singly-Linked List](#orgf54bae9)
5.  [Doubly-Linked List](#org15930fa)
6.  [Skip List](#orgf49e572)
7.  [Hash Table](#orga1869c2)
8.  [Binary Search Tree](#org2cea6af)
    1.  [what is it](#org10bcb10)
    2.  [costs](#org896ac02)
    3.  [operations](#org2781805)
        1.  [insertion](#orgf90eea3)
        2.  [search](#org2c40375)
        3.  [deletion](#org1144b73)
    4.  [pros](#org8769dc0)
    5.  [cons](#org0c55462)
    6.  [use cases](#orgd59a0e3)
9.  [Cartesian Tree](#orgb2d83be)
10. [B-Tree](#org417f9f5)
11. [Red-Black Tree](#org8d1aa71)
12. [Splay Tree](#orgcb54282)
13. [AVL Tree](#org09b3d3b)
14. [KD Tree](#org21e34c1)



<a id="org2d1ecb0"></a>

# Array


<a id="org817d893"></a>

# Stack


<a id="org1e61a24"></a>

# Queue


<a id="orgf54bae9"></a>

# Singly-Linked List


<a id="org15930fa"></a>

# Doubly-Linked List


<a id="orgf49e572"></a>

# Skip List


<a id="orga1869c2"></a>

# Hash Table


<a id="org2cea6af"></a>

# Binary Search Tree

![img](./.img/bst.png)


<a id="org10bcb10"></a>

## what is it

A binary search tree is a tree data structure where:

-   The nodes to the left are smaller than the current node.
-   The nodes to the right are larger than the current node.


<a id="org896ac02"></a>

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
<td class="org-left">\(O(\log(n))\)</td>
<td class="org-left">\(O(n)\)</td>
</tr>


<tr>
<td class="org-left">Search</td>
<td class="org-left">\(O(\log(n))\)</td>
<td class="org-left">\(O(n)\)</td>
</tr>


<tr>
<td class="org-left">Insertion</td>
<td class="org-left">\(O(\log(n))\)</td>
<td class="org-left">\(O(n)\)</td>
</tr>


<tr>
<td class="org-left">Deletion</td>
<td class="org-left">\(O(\log(n))\)</td>
<td class="org-left">\(O(n)\)</td>
</tr>
</tbody>

<tbody>
<tr>
<td class="org-left">Space</td>
<td class="org-left">&#xa0;</td>
<td class="org-left">\(O(n)\)</td>
</tr>
</tbody>
</table>


<a id="org2781805"></a>

## operations


<a id="orgf90eea3"></a>

### insertion

1.  pseudo code
    
        insert(T, k)
          if T == NIL
            T = new Node
            T.key = k
          else if k < T.key
            T.left = insert(T.left, k)
          else
            T.right = insert(T.right, k)
          return T

2.  C code
    
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

3.  C++ code with class
    
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


<a id="org2c40375"></a>

### search


<a id="org1144b73"></a>

### deletion


<a id="org8769dc0"></a>

## pros


<a id="org0c55462"></a>

## cons


<a id="orgd59a0e3"></a>

## use cases


<a id="orgb2d83be"></a>

# Cartesian Tree


<a id="org417f9f5"></a>

# B-Tree


<a id="org8d1aa71"></a>

# Red-Black Tree


<a id="orgcb54282"></a>

# Splay Tree


<a id="org09b3d3b"></a>

# AVL Tree


<a id="org21e34c1"></a>

# KD Tree

