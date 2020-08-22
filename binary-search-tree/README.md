
# Binary Search Tree

![img](../.img/bst.png)

## what is it

A binary search tree is a tree data structure where:

-   The nodes to the left are smaller than the current node.
-   The nodes to the right are larger than the current node.
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




## operations

<details>
<summary>insertion</summary>

- [pseudo code](insertion/pseudo.c)
- [C code](insertion/c-code.c)
- [C++ class](insertion/cpp-class.cpp)

</details>

<details>
<summary>search</summary>

- [pseudo code](search/pseudo.c)
- [C code](search/c-code.c)
- [C++ class](search/cpp-class.cpp)

</details>

<details>
<summary>deletion</summary>

- [pseudo code](deletion/pseudo.c)
- [C code](deletion/c-code.c)
- [C++ class](deletion/cpp-class.cpp)

</details>

<details>
<summary>inorder traversal</summary>

- [pseudo code](inorder-traversal/pseudo.c)
- [C code](inorder-traversal/c-code.c)
- [C++ class](inorder-traversal/cpp-class.cpp)

Inorder traversal can be used to **sort** the binary tree
</details>

<summary>preorder traversal</summary>

- [pseudo code](preorder-traversal/pseudo.c)
- [C code](preorder-traversal/c-code.c)
- [C++ class](preorder-traversal/cpp-class.cpp)

preorder Traversal can be used to **copy** the binary tree
</details>

<summary>postorder traversal</summary>

- [pseudo code](postorder-traversal/pseudo.c)
- [C code](postorder-traversal/c-code.c)
- [C++ class](postorder-traversal/cpp-class.cpp)

postorder Traversal can be used to **delete** the binary tree
</details>

## complete implementation
## pros
## cons
## use cases
