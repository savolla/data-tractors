struct Node *getMaxRec( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    if ( T->right != NULL ) {
        return getMaxRec( T->right );
    }
    return T;
}
