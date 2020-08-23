struct Node *delete( struct Node *T, int k) {
    if ( T == NULL ) {
        return T;
    }
    if (k < T->key) {
        T->left = delete(T->left, k);
    }
    else if (k > T->key) {
        T->right = delete(T->right, k);
    }
    else {
        if (T->left == NULL) {
            struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
            tmp = T->right;
            free(T);
            return tmp;
        }
        else if (T->right == NULL) {
            struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
            tmp = T->left;
            free(T);
            return tmp;
        }
        struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp = getMin(T->right);
        T->key = tmp->key;
        T->right = delete(T->right, tmp->key);
    }
    return T;
}
