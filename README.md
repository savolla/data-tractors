
# Table of Contents

1.  [Array](#org42ec9e8)
2.  [Stack](#org613b567)
3.  [Queue](#org2d790e1)
4.  [Singly-Linked List](#org6f0e7f2)
5.  [Doubly-Linked List](#org2dda60b)
6.  [Skip List](#orgca05272)
7.  [Hash Table](#org92315de)
8.  [Binary Search Tree](#org44cef90)
    1.  [what is it](#org51c7e79)
    2.  [costs](#org569533e)
    3.  [operations](#org7cad518)
        1.  [insertion](#orga9528d1)
        2.  [search](#org929fb73)
        3.  [deletion](#orgac2b889)
        4.  [inorder Traversal](#org76f0a9f)
        5.  [preorder Traversal](#org28a36ad)
        6.  [postorder Traversal](#orgcddb811)
    4.  [pros](#org550c7f8)
    5.  [cons](#org21ea9fb)
    6.  [use cases](#orgfe31d33)
9.  [Cartesian Tree](#orga81a83a)
10. [B-Tree](#org7d7055b)
11. [Red-Black Tree](#orga94cd13)
12. [Splay Tree](#org0a058d3)
13. [AVL Tree](#orgbebf06a)
14. [KD Tree](#org756be28)



<a id="org42ec9e8"></a>

# Array


<a id="org613b567"></a>

# Stack


<a id="org2d790e1"></a>

# Queue


<a id="org6f0e7f2"></a>

# Singly-Linked List


<a id="org2dda60b"></a>

# Doubly-Linked List


<a id="orgca05272"></a>

# Skip List


<a id="org92315de"></a>

# Hash Table


<a id="org44cef90"></a>

# Binary Search Tree

![img](./.img/bst.png)


<a id="org51c7e79"></a>

## what is it

A binary search tree is a tree data structure where:

-   The nodes to the left are smaller than the current node.
-   The nodes to the right are larger than the current node.


<a id="org569533e"></a>

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


<a id="org7cad518"></a>

## operations


<a id="orga9528d1"></a>

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


<a id="org929fb73"></a>

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


<a id="orgac2b889"></a>

### deletion


<a id="org76f0a9f"></a>

### inorder Traversal

Inorder traversal can be used to **sort** the binary tree

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


<a id="org28a36ad"></a>

### preorder Traversal

preorder Traversal can be used to **copy** the binary tree

1.  pseudo code
    
        preTraversal(T)
          if T != NIL
            print T.key
            preTraversal(T.left)
            preTraversal(T.right)

2.  C code
    
        void preorderTraverse( struct Node *T ) {
            if ( T != NULL ) {
                printf("%d, ", T->key);
                preorderTraverse( T->left );
                preorderTraverse( T->right );
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
                void preorderTraverse( Node *T ) {
                    if ( T != NULL ) {
                        printf("%d, ", T->key);
                        preorderTraverse( T->left );
                        preorderTraverse( T->right );
                    }
                }
        
            public:
                Node *root;
                BST() {
                    root = nullptr;
                }
        
                void preorderTraverse() {
                    preorderTraverse( root );
                }
        };


<a id="orgcddb811"></a>

### postorder Traversal

postorder Traversal can be used to **delete** the binary tree

1.  pseudo code
    
        postTraversal(T)
          if T != NIL
            postTraversal(T.left)
            postTraversal(T.right)
            print T.key

2.  C code
    
        void postorderTraverse( struct Node *T ) {
            if ( T != NULL ) {
                postorderTraverse( T->left );
                postorderTraverse( T->right );
                printf("%d, ", T->key);
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
                void postorderTraverse( Node *T ) {
                    if ( T != NULL ) {
                        postorderTraverse( T->left );
                        postorderTraverse( T->right );
                        printf("%d, ", T->key);
                    }
                }
        
            public:
                Node *root;
                BST() {
                    root = nullptr;
                }
        
                void postorderTraverse() {
                    postorderTraverse( root );
                }
        };


<a id="org550c7f8"></a>

## pros


<a id="org21ea9fb"></a>

## cons


<a id="orgfe31d33"></a>

## use cases


<a id="orga81a83a"></a>

# Cartesian Tree


<a id="org7d7055b"></a>

# B-Tree


<a id="orga94cd13"></a>

# Red-Black Tree


<a id="org0a058d3"></a>

# Splay Tree


<a id="orgbebf06a"></a>

# AVL Tree


<a id="org756be28"></a>

# KD Tree

