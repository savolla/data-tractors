struct Node *getMax( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    while ( T->right != NULL ) {
        T = T->right;
    }
    return T;
}
