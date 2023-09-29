struct node {
   int data;   
   struct node *left; //Reference to left child
   struct node *right; //Reference to right child
};

struct node *insert(struct node *root, int val)
{
    if(root == NULL) //if root = NULL or tree traversal reaches NULL
        return getNewNode(val);
    else if(root->key < val) // insert into right subtree
        root->right = insert(root->right,val);
    else if(root->key > val) // insert into left subtree
        root->left = insert(root->left,val);
    return root; // Return the original root after insertion
}