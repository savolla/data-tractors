struct Node *search( struct Node *T, int k ) {
    if ( T == NULL || k == T->key ) {
        return T;
    }
    if ( k < T->key ) {
        return search( T->left, k );
    }
    else
        return search( T->right, k );
}
