// x: node
getMinimumRec(T)
  if T == NIL // if Tree is Empty
    return NIL
  if T.left != NIL // if not bottom
    return getMinimumRec(T.left) // continue to bottom
  return T
