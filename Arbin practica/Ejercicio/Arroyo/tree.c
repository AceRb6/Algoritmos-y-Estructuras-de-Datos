#include "tree.h"

Tree createNode(data d) {
    Tree newNode = (Tree)malloc(sizeof(struct node));
    newNode->d = d;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void createTree(Tree* root, Tree leftChild, Tree rightChild, data d) {
    *root = createNode(d);
    (*root)->left = leftChild;
    (*root)->right = rightChild;
}

void preorderTraversal(Tree root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->d);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Tree root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->d);
    inorderTraversal(root->right);
}

void postorderTraversal(Tree root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->d);
}

Tree searchElement(Tree root, data target) {
    if (root == NULL || root->d == target) {
        return root;
    }
    Tree resultLeft = searchElement(root->left, target);
    if (resultLeft != NULL) {
        return resultLeft;
    }
    Tree resultRight = searchElement(root->right, target);
    return resultRight;
}

Tree deleteElement(Tree root, data d) {
    if (root == NULL) {
        return root;
    }
    if (d < root->d) {
        root->left = deleteElement(root->left, d);
    } else if (d > root->d) {
        root->right = deleteElement(root->right, d);
    } else {
        if (root->left == NULL) {
            Tree temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Tree temp = root->left;
            free(root);
            return temp;
        }
        Tree temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->d = temp->d;
        root->right = deleteElement(root->right, temp->d);
    }
    return root;
}

void freeTree(Tree root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
