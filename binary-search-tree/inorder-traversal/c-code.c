void inorderTraverse( struct Node *T ) {
    if ( T != NULL ) {
        inorderTraverse( T->left );
        printf("%d, ", T->key);
        inorderTraverse( T->right );
    }
}
