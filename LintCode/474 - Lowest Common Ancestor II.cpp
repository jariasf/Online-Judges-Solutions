/*******************************************
 ***Problema: Lowest Common Ancestor II
 ***ID: 474
 ***Juez: LintCode
 ***Tipo: LCA with parent pointer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    int getDepth(ParentTreeNode* A){
        int depth = 0;
        while( A -> parent){
            A = A -> parent;
            depth++;
        }
        return depth;
    }

    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        if( root == NULL) return NULL;
        int dA = getDepth(A), dB = getDepth(B);

        while(dA > dB ){
            A = A-> parent;
            dA--;
        }
        while(dB > dA){
            B = B -> parent;
            dB--;
        }

        while( A && B && A != B){
            A = A -> parent;
            B = B -> parent;
        }
        return A;
    }
};
