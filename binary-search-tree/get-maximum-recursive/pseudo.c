// x: node
getMaximumRec(T)
  if T == NIL // if Tree is Empty
    return NIL
  if T.right != NIL // if not bottom
    return getMaximumRec(T.right) // continue to bottom
  return T
