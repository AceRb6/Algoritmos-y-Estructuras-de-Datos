#include "arb_bin.h"

BinaryTree createNode(element e) {
    BinaryTree n = (BinaryTree)malloc(sizeof(struct nodeT));
    n->e = e;
    n->left = n->right = NULL;
    return n;
}

void newTree(BinaryTree* root, BinaryTree ramaizq, BinaryTree ramader, element e){
    *root = createNode(e);
    (*root)->left = ramaizq;
    (*root)->right = ramader;
}

void preorder(BinaryTree root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->e);
    preorder(root->left);
    preorder(root->right);
}

void inorder(BinaryTree root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->e);
    inorder(root->right);
}

void postorder(BinaryTree root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->e);
}

BinaryTree buscarElemento(BinaryTree root, element buscado) {
    if (root == NULL || root->e == buscado) {
        return root;
    }
    BinaryTree resultadoIzq = buscarElemento(root->left, buscado);
    if (resultadoIzq != NULL) {
        return resultadoIzq;
    }
    BinaryTree resultadoDer = buscarElemento(root->right, buscado);
    return resultadoDer;
}


BinaryTree deleteElement(BinaryTree root, element e) {
    if (root == NULL) {
        return root;
    }
    if (e < root->e) {
        root->left = deleteElement(root->left, e);
    } else if (e > root->e) {
        root->right = deleteElement(root->right, e);
    } else {
        if (root->left == NULL) {
            BinaryTree temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BinaryTree temp = root->left;
            free(root);
            return temp;
        }
        BinaryTree temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->e = temp->e;
        root->right = deleteElement(root->right, temp->e);
    }
    return root;
}

/// funciones del ejercicio:
void liberarArbol(BinaryTree root) {
    if (root == NULL) {
        return;
    }
    liberarArbol(root->left);
    liberarArbol(root->right);
    free(root);
}


