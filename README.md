
# Table of Contents

1.  [Array](#orgad2287b)
2.  [Stack](#orgbd8085c)
3.  [Queue](#org1e42fa2)
4.  [Singly-Linked List](#orgcf24672)
5.  [Doubly-Linked List](#org2804bca)
6.  [Skip List](#org25cb8a9)
7.  [Hash Table](#org2fa0c0e)
8.  [Binary Search Tree](#orge9c346e)
    1.  [what is it](#orgc1e4609)
    2.  [costs](#org647470f)
    3.  [operations](#orgfa9cec1)
        1.  [insertion](#org0202f32)
        2.  [search](#orga7baaf9)
        3.  [deletion](#orgc238e5a)
        4.  [inorder Traversal](#orgd3a4e90)
    4.  [pros](#org27c986f)
    5.  [cons](#org38f18a8)
    6.  [use cases](#org659162f)
9.  [Cartesian Tree](#orgbfe9855)
10. [B-Tree](#org525cd41)
11. [Red-Black Tree](#orgef1ff65)
12. [Splay Tree](#org0c8f8ac)
13. [AVL Tree](#orge2a140e)
14. [KD Tree](#orgb894337)



<a id="orgad2287b"></a>

# Array


<a id="orgbd8085c"></a>

# Stack


<a id="org1e42fa2"></a>

# Queue


<a id="orgcf24672"></a>

# Singly-Linked List


<a id="org2804bca"></a>

# Doubly-Linked List


<a id="org25cb8a9"></a>

# Skip List


<a id="org2fa0c0e"></a>

# Hash Table


<a id="orge9c346e"></a>

# Binary Search Tree

![img](./.img/bst.png)


<a id="orgc1e4609"></a>

## what is it

A binary search tree is a tree data structure where:

-   The nodes to the left are smaller than the current node.
-   The nodes to the right are larger than the current node.


<a id="org647470f"></a>

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


<a id="orgfa9cec1"></a>

## operations


<a id="org0202f32"></a>

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


<a id="orga7baaf9"></a>

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


<a id="orgc238e5a"></a>

### deletion


<a id="orgd3a4e90"></a>

### inorder Traversal

1.  pseudo code
    
        iTraversal(T)
          if T != NIL
            iTraversal(T.left)
            print T.key
            iTraversal(T.right)
2.  C code
    
        void inorderTraverse( struct Node *T ) {
            if ( T != NULL ) {
                inorderTraverse( T->left );
                printf("%d, ", T->key);
                inorderTraverse( T->right );
            }
        }
3.  C++ code with classes
    
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
                void inorderTraverse( Node *T ) {
                    if ( T != NULL ) {
                        inorderTraverse( T->left );
                        printf("%d, ", T->key);
                        inorderTraverse( T->right );
                    }
                }
        
            public:
                Node *root;
                BST() {
                    root = nullptr;
                }
        
                void inorderTraverse() {
                    inorderTraverse( root );
                }
        };


<a id="org27c986f"></a>

## pros


<a id="org38f18a8"></a>

## cons


<a id="org659162f"></a>

## use cases


<a id="orgbfe9855"></a>

# Cartesian Tree


<a id="org525cd41"></a>

# B-Tree


<a id="orgef1ff65"></a>

# Red-Black Tree


<a id="org0c8f8ac"></a>

# Splay Tree


<a id="orge2a140e"></a>

# AVL Tree


<a id="orgb894337"></a>

# KD Tree

