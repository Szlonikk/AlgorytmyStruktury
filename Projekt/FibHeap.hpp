#include <iostream>
#include <vector>
#include "ArrayList.hpp"
#include <climits>
struct Node{
    int key;      // wartosc wezla
    int degree;   // liczba dzieci wezla
    Node *parent; // wskaznik do rodzica
    Node *child;  // wskaznik do jednego z dzieci
    Node *left;   // sasiad lewy
    Node *right;  // sasiad prawy
    bool mark;    // flaga potrzebna do innych funkcji
};

class FibonacciHeap{
private:
    int n;                      /// liczba wezlow
    Node *min;                  // najmniejszy element
    void consolidate();         // przebudowuje strukture kopca
    void cut(Node *x, Node *y); // odetnij x od rodzica, którym jest y, x staje sie korzeniem
    void cascadingCut(Node *y);
    void link(Node *x, Node *y); // x staje sie synem y
public:
    Node *minRoot(); // dostep do minimalnego elementu
    FibonacciHeap();
    ~FibonacciHeap();
    void push(int x);                 // dodaje do listy korzeni
    int top();                        // najmniejszy element
    int size();                       // rozmiar
    void decreaseKey(Node *x, int k); // obniza klucz wezla i przebudowuje strukture drzewa
    void remove(Node *x);             // usuwa wezel
    int pop();                        // usuwa najmniejszy elemeny
};
FibonacciHeap::FibonacciHeap(){
    min=nullptr;
    n=0;
}
FibonacciHeap::~FibonacciHeap(){
    while(min != nullptr){
        pop();
    }
}
void FibonacciHeap::decreaseKey(Node *x,int k){
    if(k > x->key){
        throw std::out_of_range("DECRASE ERROR! (WRONG PARAMETER)");
    }
    x->key=k;
    Node *y=x->parent;
    if(y != nullptr && x->key < y->key){
        cut(x, y);
        cascadingCut(y);
    }
    if(x->key < min->key){
        min=x;
    }
}
void FibonacciHeap::remove(Node *x)
{
    decreaseKey(x,INT_MIN);
    pop();
}
void FibonacciHeap::push(int x)
{
    Node *newNode=new Node;
    newNode->key=x;
    newNode->degree=0;
    newNode->mark=false;
    newNode->child=nullptr;
    newNode->parent=nullptr;
    if(min != nullptr){
        newNode->left=min->left;
        newNode->right=min;
        min->left->right=newNode;
        min->left=newNode;

        if(x < min->key){
            min=newNode;
        }
    }else{
        newNode->left=newNode;
        newNode->right=newNode;
        min=newNode;
    }
    n++;
}
int FibonacciHeap::top(){
    if(min != nullptr){
        return min->key;
    }
    return -1;
}
int FibonacciHeap::size(){
    return n;
}
void FibonacciHeap::link(Node *x, Node *y){
    x->right->left=x->left;
    x->left->right=x->right;
    x->parent=y;
    if(y->child==nullptr){
        y->child=x;
        x->right=x;
        x->left=x;
    }else{
        y->child->left->right=x;
        x->left=y->child->left;
        y->child->left=x;
        x->right=y->child;
    }
    y->degree++;
    x->mark=false;
}
void FibonacciHeap::consolidate(){
    std::vector<Node *> A(n);
    Node *w=min;
    if(w==nullptr){

        return;
    }
    do{
        Node *x=w;
        int d=x->degree;
        w=w->right;
        while(A[d] != nullptr){
            Node *y=A[d];
            if(x->key > y->key){
                std::swap(x,y);
            }
            link(y,x);
            A[d]=nullptr;
            d++;
        }
        A[d]=x;
    }while(w != min);
    min=nullptr;
    for (int i=0;i<(int)A.size();i++){
        if(A[i]!=nullptr){
            if(min==nullptr){
                min=A[i];
                min->left=min;
                min->right=min;
            }else{
                min->left->right=A[i];
                A[i]->left=min->left;
                min->left=A[i];
                A[i]->right=min;
                if(A[i]->key < min->key){
                    min=A[i];
                }
            }
        }
    }
}
int FibonacciHeap::pop()
{
    Node *z=min;
    int minValue;
    if(z != nullptr){
        minValue=z->key;
        if(z->child != nullptr){
            Node *x=z->child;
            Node *next=nullptr;
            do{
                next=x->right;
                min->right->left=x;
                x->right=min->right;
                min->right=x;
                x->left=min;
                x->parent=nullptr;
                x=next;
            } while(x != z->child);
        }
        z->left->right=z->right;
        z->right->left=z->left;

        if(z==z->right){
            min=nullptr;
        }else{
            min=z->right;
            consolidate();
        }
        delete z;
        n--;
        return minValue;
    }
    throw std::out_of_range("HEAP IS EMPTY");
}
void FibonacciHeap::cut(Node *x, Node *y)
{
    y->degree--;

    if(y->child==x){
        y->child=x->right;
    }

    x->left->right=x->right;
    x->right->left=x->left;

    min->left->right=x;
    x->left=min->left;
    x->right=min;
    min->left=x;

    x->parent=nullptr;
    x->mark=false;
}
void FibonacciHeap::cascadingCut(Node *y){
    Node *z=y->parent;
    if(z != nullptr){
        if(!y->mark){
            y->mark=true;
        }else{
            cut(y, z);
            cascadingCut(z);
        }
    }
}
Node *FibonacciHeap::minRoot(){
    return min;
}