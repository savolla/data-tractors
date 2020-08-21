
# Table of Contents

1.  [Array](#org39b2193)
2.  [Stack](#org329fb3d)
3.  [Queue](#orgc045308)
4.  [Singly-Linked List](#org41666f7)
5.  [Doubly-Linked List](#org4b0e8e4)
6.  [Skip List](#orgf5737b5)
7.  [Hash Table](#orgb65a66b)
8.  [Binary Search Tree](#org71c1db2)
    1.  [what is it](#orgeaed9cd)
    2.  [costs](#org8880420)
    3.  [operations](#org660e7f7)
        1.  [insertion](#org8b669f9)
        2.  [search](#org2e61093)
        3.  [deletion](#org8ae32cf)
    4.  [pros](#org51b9a26)
    5.  [cons](#org790e06b)
    6.  [use cases](#org77aaea7)
9.  [Cartesian Tree](#org4818933)
10. [B-Tree](#org4b4925c)
11. [Red-Black Tree](#org60ee47b)
12. [Splay Tree](#orgd809390)
13. [AVL Tree](#orgbda5cff)
14. [KD Tree](#org9daebd4)



<a id="org39b2193"></a>

# Array


<a id="org329fb3d"></a>

# Stack


<a id="orgc045308"></a>

# Queue


<a id="org41666f7"></a>

# Singly-Linked List


<a id="org4b0e8e4"></a>

# Doubly-Linked List


<a id="orgf5737b5"></a>

# Skip List


<a id="orgb65a66b"></a>

# Hash Table


<a id="org71c1db2"></a>

# Binary Search Tree

![img](./.img/bst.png)


<a id="orgeaed9cd"></a>

## what is it

A binary search tree is a tree data structure where:

-   The nodes to the left are smaller than the current node.
-   The nodes to the right are larger than the current node.


<a id="org8880420"></a>

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
<td class="org-left">O(n)</td>
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


<a id="org660e7f7"></a>

## operations


<a id="org8b669f9"></a>

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


<a id="org2e61093"></a>

### search

1.  pseudo code
    
        treeSearch (x, k)
          if x == NIL or k == x.key
            return x
          if k < x.key
            return treeSearch(x.left, k)
          else
            return treeSearch(x.right, k)
2.  C code
    
        struct Node *search( struct Node *T, int k ) {
            if ( T == NULL || k == T->key ) {
                return T;
            }
            if ( k < T->key ) {
                return search( T->left, k );
            }
            else
                return search( T->right, k );
        }
3.  C++ code with class
    
        class Node {
            public:
                int key;
                Node *left;
                Node *right;
        
                Node() {
                    left = right = nullptr;
                }
        
                Node( int k ) {
                    key = k;
                    left = right = nullptr;
                }
        };
        
        class BST {
            private:
                Node *search( Node *T, int k ) {
                    if ( T == nullptr || k == T->key ) {
                        return T;
                    }
                    if ( k < T->key ) {
                        return search( T->left, k );
                    }
                    else
                        return search( T->right, k );
                }
        
            public:
                Node *root;
                BST() {
                    root = nullptr;
                }
        
                Node *search( int k ) {
                    return search( root, k );
                }
        };


<a id="org8ae32cf"></a>

### deletion


<a id="org51b9a26"></a>

## pros


<a id="org790e06b"></a>

## cons


<a id="org77aaea7"></a>

## use cases


<a id="org4818933"></a>

# Cartesian Tree


<a id="org4b4925c"></a>

# B-Tree


<a id="org60ee47b"></a>

# Red-Black Tree


<a id="orgd809390"></a>

# Splay Tree


<a id="orgbda5cff"></a>

# AVL Tree


<a id="org9daebd4"></a>

# KD Tree

