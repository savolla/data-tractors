### Pseudo Code for BST

Extracted from CLRS and other resources annd optimized

#### insert

```c
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

#### search

```c
search(T, k)
  if T == NIL or T == x.key
    return T
  if T < T.key
    return search(T.left, k)
  else
    return search(T.right, k)
```

#### delete

```c
delete(T, k)
  if T == NIL
    return T
  if k < T.key
    T.left = delete(T.left, k)
  else if k > T.key
    T.right = delete(T.right, k)
  else if k == T.key
    if T.left == NIL
      tmp = T.right
      delete T
      return tmp
    else if T.right == NIL
      tmp = T.left
      delet T
      return tmp
    tmp = getMin(T.right)
    T.key = tmp.key
    T.right = delete(T.right, tmp.key)
  return T
```

#### Max and Min

```c
getMax(T)
  if T == NIL
    return NIL
  while T.right != NIL
    T = T.right
  return T
```

```c
getMin(T)
  if T == NIL
    return NIL
  while T.left != NIL
    T = T.left
  return T
```

#### Traversals

```c
iTraversal(T)
  if T != NIL
    iTraversal(T.left)
    print T.key
    iTraversal(T.right)
```

```c
preTraversal(T)
  if T != NIL
    print T.key
    preTraversal(T.left)
    preTraversal(T.right)
```

```c
postTraversal(T)
  if T != NIL
    postTraversal(T.left)
    postTraversal(T.right)
    print T.key
```
