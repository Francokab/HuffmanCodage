 struct node {
   int key;   
   struct node *left; //Reference to left child
   struct node *right; //Reference to right child
};

class btree
{
    public:
        btree();
        ~btree();
 
        void insert(int key);
        void printing();
        node *search(int key);
        void destroy_tree();
 
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
         
        node *root;
};