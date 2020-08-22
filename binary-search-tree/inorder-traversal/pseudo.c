iTraversal(T)
  if T != NIL
    iTraversal(T.left)
    print T.key
    iTraversal(T.right)
