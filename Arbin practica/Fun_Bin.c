#include "arb_bin.h"

BinaryTree createNode(element e){
	BinaryTree n=(BinaryTree)malloc(sizeof(nodeT));
	n->e=e;
	n->left=n->right=NULL;
	return n;
}

void newTree(BinaryTree *root,BinaryTree ramaizq,BinaryTree ramader,elemenet e){
	*root=createNode(e);
	(*root)->left=ramaizq;
	(*root)->right=ramader;
}

void preorder(BinaryTree root){
    if (root==NULL) {
        return;
    }
    printf("%c ", root->e);
    preorder(root->left);
    preorder(root->right);
}

void inorder(BinaryTree root){
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%c ", root->e);
    inorder(root->right);
}

void postorder(BinaryTree root){
    if (root==NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->e);
}

BinaryTree buscarElemento(BinaryTree root, element e){
    if (root==NULL || root->e==e) {
        return root;
    }
    BinaryTree result=buscarElemento(root->left,e);
    if(result==NULL) {
        result=buscarElemento(root->right,e);
    }
    return result;
}

int isBalanced(BinaryTree root){
    if (root==NULL) {
        return 1;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return 1;
    }
    return 0;
}

BinaryTree deleteElement(BinaryTree root, element e) {
    if (root==NULL){
        return root;
    }
    if (e<root->e)
        root->left=deleteElement(root->left, e);
    else 
		if (e > root->e)
        	root->right=deleteElement(root->right, e);
    	else{
        	if(root->left==NULL){
            BinaryTree temp=root->right;
            free(root);
            return temp;
        	}else 
			if (root->right==NULL) {
            	BinaryTree temp=root->left;
            	free(root);
            	return temp;
        	}
        	BinaryTree temp=findMin(root->right);
        	root->e=temp->e;
        	root->right=deleteElement(root->right, temp->e);
    	}
    return root;
}
