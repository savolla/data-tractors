// T: Tree root
// k: new value
struct Node *insert(struct Node *T, int k) {
    if ( T == NULL ){
        T = (struct Node*)malloc(sizeof(struct Node));
        T->key = k;
    }
    else if (k < T->key){
        T->left = insert(T->left, k);
    }
    else {
        T->right = insert(T->right, k);
    }
    return T;
}
