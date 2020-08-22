insert(T, k)
  if T == NIL
    T = new Node
    T.key = k
  else if k < T.key
    T.left = insert(T.left, k)
  else
    T.right = insert(T.right, k)
  return T
