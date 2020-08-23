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
