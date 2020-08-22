getMax(T)
  if T == NIL
    return NIL
  while T.right != NIL
    T = T.right
  return T
