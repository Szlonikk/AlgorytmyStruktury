struct Node{
    Node* left;
    Node* right;
    int value;
};
class BinaryTree{
int Size=0;
int Depth=0;
Node* root=nullptr;

public:
    //BinaryTree();
    ~BinaryTree();
    void insert(int x);
    Node* search(int x);
    Node* searchRecursive(int x);
    int size();
    int minimum();
    int maximum();
    int depth();
    void inorder();
    void preorder();
    void postorder();
};
void destruct(Node* node){
    if(node!=nullptr){
        destruct(node->right);
        destruct(node->left);
        delete node;
    }
}
BinaryTree::~BinaryTree(){
    destruct(root);
}
void BinaryTree::insert(int x){
    Node* temp=root;
    if(root==nullptr){
        root= new Node();
        root->value=x;
        Size++;
        Depth++;
    }else{
        int currentDepth=1;
        while(true){
            currentDepth++;
            
            if(x<temp->value){
                if(temp->left==nullptr){
                    temp->left=new Node();
                    temp->left->value=x;
                    Size++;
                    
                    if(currentDepth>Depth){
                        Depth=currentDepth;
                    }
                    break;
                }else{
                    temp=temp->left;
                }
            }else{
                if(temp->right==nullptr){
                    temp->right=new Node();
                    temp->right->value=x;
                    Size++;
                    if(currentDepth>Depth){
                        Depth=currentDepth;
                    }
                    break;
                }else{
                    temp=temp->right;
                }
            }
        }
    }
}
Node* BinaryTree::search(int x){
    Node* temp=root;
    while(temp!=nullptr){
        if(temp->value==x){
            return temp;
        }
        if(x<=temp->value){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return nullptr;
}
Node* searchR(Node* node, int x){
    if(node==nullptr){
        return nullptr;
    }
    if(node->value==x){
        return node;
    }
    if(x<=node->value){
        return searchR(node->left,x);
    }
    return searchR(node->right,x);
}
Node* BinaryTree::searchRecursive(int x){
    return searchR(root,x);
}
int BinaryTree::size(){
    return Size;
}
int BinaryTree::depth(){
    return Depth;
}
int BinaryTree::maximum(){
    if(Size==0){
        throw std::out_of_range("TREE IS EMPTY");
    }
    Node* temp=root;
    while(temp->right!=nullptr){
        temp=temp->right;
    }
    return temp->value;
}
int BinaryTree::minimum(){
    if(Size==0){
        throw std::out_of_range("TREE IS EMPTY");
    }
    Node* temp=root;
    while(temp->left!=nullptr){
        temp=temp->left;
    }
    return temp->value;
}
void Inorder(Node* node){
    if(node!=nullptr){
        Inorder(node->left);
        std::cout<<node->value<<std::endl;
        Inorder(node->right);
    }
}
void BinaryTree::inorder(){
    Inorder(root);
}
void Postorder(Node* node){
    if(node!=nullptr){
        Postorder(node->left);
        Postorder(node->right);
        std::cout<<node->value<<std::endl;
    }
}
void BinaryTree::postorder(){
    Postorder(root);
}
void Preorder(Node* node){
    if(node!=nullptr){
        std::cout<<node->value<<std::endl;
        Preorder(node->left);
        Preorder(node->right);
    }
}
void BinaryTree::preorder(){
    Preorder(root);
}
