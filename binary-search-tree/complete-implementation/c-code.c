#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *right;
    struct Node *left;
};

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

void inorderTraverse( struct Node *T ) {
    if ( T != NULL ) {
        inorderTraverse( T->left );
        printf("%d, ", T->key);
        inorderTraverse( T->right );
    }
}

void postorderTraverse( struct Node *T ) {
    if ( T != NULL ) {
        postorderTraverse( T->left );
        postorderTraverse( T->right );
        printf("%d, ", T->key);
    }
}

void preorderTraverse( struct Node *T ) {
    if ( T != NULL ) {
        printf("%d, ", T->key);
        preorderTraverse( T->left );
        preorderTraverse( T->right );
    }
}

struct Node *getMinRec( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    if ( T->left != NULL ) {
        return getMinRec( T->left );
    }
    return T;
}

struct Node *getMin( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    while ( T->left != NULL ) {
        T = T->left;
    }
    return T;
}

struct Node *getMax( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    while ( T->right != NULL ) {
        T = T->right;
    }
    return T;
}

struct Node *getMaxRec( struct Node *T ) {
    if ( T == NULL ) {
        return NULL;
    }
    if ( T->right != NULL ) {
        return getMaxRec( T->right );
    }
    return T;
}

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

int main(void) {
    struct Node *root = NULL;
    root = insert(root, 83);
    root = insert(root, 74);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 78);
    root = insert(root, 93);
    root = insert(root, 93);
    root = insert(root, -84);
    root = insert(root, 4);
    root = insert(root, 400);

    inorderTraverse(root);
    printf("\n");
    delete(root, 83);
    delete(root, 4);
    delete(root, 93);
    delete(root, 93);
    delete(root, 400);
    inorderTraverse(root);
    printf("\n");

    return 0;
}
