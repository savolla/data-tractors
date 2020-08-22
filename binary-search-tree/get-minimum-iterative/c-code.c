struct Node *getMin( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    while ( T->left != NULL ) {
        T = T->left;
    }
    return T;
}
