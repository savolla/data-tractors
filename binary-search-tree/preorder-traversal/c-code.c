void preorderTraverse( struct Node *T ) {
    if ( T != NULL ) {
        printf("%d, ", T->key);
        preorderTraverse( T->left );
        preorderTraverse( T->right );
    }
}
