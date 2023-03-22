#include <iostream>
#include <stdlib.h>
#include "BinaryTree.hpp"
using namespace std;
int main(){
    BinaryTree tree;
    int value;
    int operations;
    cin>>operations;
    for(int i=0;i<operations;i++){
        cin>>value;
        tree.insert(value);
    }
    cout<<tree.size()<<" "<<tree.depth()<<" "<<tree.minimum()<<" "<<tree.maximum()<<endl;
    tree.preorder();
    //tree.inorder();
    for(int i=1;i<10;i++){
        if(tree.search(i)==nullptr){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
}