struct Node *getMinRec( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    if ( T->left != NULL ) {
        return getMinRec( T->left );
    }
    return T;
}
