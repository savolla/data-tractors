getMin(T)
  if T == NIL
    return NIL
  while T.left != NIL
    T = T.left
  return T
