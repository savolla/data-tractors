void postorderTraverse( struct Node *T ) {
    if ( T != NULL ) {
        postorderTraverse( T->left );
        postorderTraverse( T->right );
        printf("%d, ", T->key);
    }
}
