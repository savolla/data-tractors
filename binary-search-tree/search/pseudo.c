treeSearch (x, k)
  if x == NIL or k == x.key
    return x
  if k < x.key
    return treeSearch(x.left, k)
  else
    return treeSearch(x.right, k)
