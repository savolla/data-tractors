postTraversal(T)
  if T != NIL
    postTraversal(T.left)
    postTraversal(T.right)
    print T.key
