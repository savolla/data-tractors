<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<title>README.html</title>
<meta http-equiv="Content-Type" content="application/xhtml+xml;charset=utf-8"/>
<link rel="stylesheet" type="text/css" media="all" href="https://cdn.jsdelivr.net/npm/github-markdown-css/github-markdown.min.css"  />
<link rel="stylesheet" type="text/css" media="all" href="https://cdn.jsdelivr.net/gh/highlightjs/cdn-release/build/styles/github.min.css"  /><meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'><style> body { box-sizing: border-box; max-width: 740px; width: 100%; margin: 40px auto; padding: 0 10px; } </style><script src='https://cdn.jsdelivr.net/gh/highlightjs/cdn-release/build/highlight.min.js'></script><script>document.addEventListener('DOMContentLoaded', () => { document.body.classList.add('markdown-body'); document.querySelectorAll('pre[lang] > code').forEach((code) => { code.classList.add(code.parentElement.lang); }); document.querySelectorAll('pre > code').forEach((code) => { hljs.highlightBlock(code); }); });</script>
</head>

<body>

<h1 id="table-of-contents">Table of Contents</h1>
<ol type="1">
<li><a href="#org81521c7">Array</a></li>
<li><a href="#org09c75d8">Stack</a></li>
<li><a href="#org39e28f6">Queue</a></li>
<li><a href="#org9f1de0e">Singly-Linked List</a></li>
<li><a href="#orgc5badd9">Doubly-Linked List</a></li>
<li><a href="#org59cb32a">Skip List</a></li>
<li><a href="#org0348afa">Hash Table</a></li>
<li><a href="#orgb913e93">Binary Search Tree</a>
<ol type="1">
<li><a href="#org6de17b2">what is it</a></li>
<li><a href="#orge0732d2">costs</a></li>
<li><a href="#org8bac6e1">operations</a>
<ol type="1">
<li><a href="#org1ae5aa3">insertion</a></li>
<li><a href="#org40e6527">search</a></li>
<li><a href="#orgba42b0d">deletion</a></li>
</ol></li>
<li><a href="#org29fd726">pros</a></li>
<li><a href="#org41fda94">cons</a></li>
<li><a href="#org938ccba">use cases</a></li>
</ol></li>
<li><a href="#orge31dc8a">Cartesian Tree</a></li>
<li><a href="#org7956541">B-Tree</a></li>
<li><a href="#org4747652">Red-Black Tree</a></li>
<li><a href="#org28004a5">Splay Tree</a></li>
<li><a href="#org8f456cf">AVL Tree</a></li>
<li><a href="#orgddc93c6">KD Tree</a></li>
</ol>
<p><a id="org81521c7"></a></p>
<h1 id="array">Array</h1>
<p><a id="org09c75d8"></a></p>
<h1 id="stack">Stack</h1>
<p><a id="org39e28f6"></a></p>
<h1 id="queue">Queue</h1>
<p><a id="org9f1de0e"></a></p>
<h1 id="singly-linked-list">Singly-Linked List</h1>
<p><a id="orgc5badd9"></a></p>
<h1 id="doubly-linked-list">Doubly-Linked List</h1>
<p><a id="org59cb32a"></a></p>
<h1 id="skip-list">Skip List</h1>
<p><a id="org0348afa"></a></p>
<h1 id="hash-table">Hash Table</h1>
<p><a id="orgb913e93"></a></p>
<h1 id="binary-search-tree">Binary Search Tree</h1>
<figure>
<img src="./.img/bst.png" alt="" /><figcaption>img</figcaption>
</figure>
<p><a id="org6de17b2"></a></p>
<h2 id="what-is-it">what is it</h2>
<p>A binary search tree is a tree data structure where:</p>
<ul>
<li>The nodes to the left are smaller than the current node.</li>
<li>The nodes to the right are larger than the current node.</li>
</ul>
<p><a id="orge0732d2"></a></p>
<h2 id="costs">costs</h2>
<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">
<colgroup>
<col  class="org-left" />
<col  class="org-left" />
<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">
BST
</th>
<th scope="col" class="org-left">
avarage
</th>
<th scope="col" class="org-left">
worst
</th>
</tr>
</thead>
<tbody>
<tr>
<td class="org-left">
Access
</td>
<td class="org-left">
(O((n)))
</td>
<td class="org-left">
(O(n))
</td>
</tr>
<tr>
<td class="org-left">
Search
</td>
<td class="org-left">
(O((n)))
</td>
<td class="org-left">
(O(n))
</td>
</tr>
<tr>
<td class="org-left">
Insertion
</td>
<td class="org-left">
(O((n)))
</td>
<td class="org-left">
(O(n))
</td>
</tr>
<tr>
<td class="org-left">
Deletion
</td>
<td class="org-left">
(O((n)))
</td>
<td class="org-left">
(O(n))
</td>
</tr>
</tbody>
<tbody>
<tr>
<td class="org-left">
Space
</td>
<td class="org-left">
 
</td>
<td class="org-left">
(O(n))
</td>
</tr>
</tbody>
</table>
<p><a id="org8bac6e1"></a></p>
<h2 id="operations">operations</h2>
<p><a id="org1ae5aa3"></a></p>
<h3 id="insertion">insertion</h3>
<ol type="1">
<li><p>pseudo code</p>
<pre><code>insert(T, k)
  if T == NIL
    T = new Node
    T.key = k
  else if k &lt; T.key
    T.left = insert(T.left, k)
  else
    T.right = insert(T.right, k)
  return T</code></pre></li>
<li><p>C code</p>
<pre><code>// T: Tree root
// k: new value
struct Node *insert(struct Node *T, int k) {
    if ( T == NULL ){
        T = (struct Node*)malloc(sizeof(struct Node));
        T-&gt;key = k;
    }
    else if (k &lt; T-&gt;key){
        T-&gt;left = insert(T-&gt;left, k);
    }
    else {
        T-&gt;right = insert(T-&gt;right, k);
    }
    return T;
}</code></pre></li>
<li><p>C++ code with class</p>
<pre><code>class Node {
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
            else if (k &lt; T-&gt;key){
                T-&gt;left = insert(T-&gt;left, k);
            }
            else {
                T-&gt;right = insert(T-&gt;right, k);
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
};</code></pre></li>
</ol>
<p><a id="org40e6527"></a></p>
<h3 id="search">search</h3>
<p><a id="orgba42b0d"></a></p>
<h3 id="deletion">deletion</h3>
<p><a id="org29fd726"></a></p>
<h2 id="pros">pros</h2>
<p><a id="org41fda94"></a></p>
<h2 id="cons">cons</h2>
<p><a id="org938ccba"></a></p>
<h2 id="use-cases">use cases</h2>
<p><a id="orge31dc8a"></a></p>
<h1 id="cartesian-tree">Cartesian Tree</h1>
<p><a id="org7956541"></a></p>
<h1 id="b-tree">B-Tree</h1>
<p><a id="org4747652"></a></p>
<h1 id="red-black-tree">Red-Black Tree</h1>
<p><a id="org28004a5"></a></p>
<h1 id="splay-tree">Splay Tree</h1>
<p><a id="org8f456cf"></a></p>
<h1 id="avl-tree">AVL Tree</h1>
<p><a id="orgddc93c6"></a></p>
<h1 id="kd-tree">KD Tree</h1>

</body>
</html>
