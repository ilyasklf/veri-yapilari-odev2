#ifndef BST_HPP
#define BST_HPP


#define SIZE 1000


#include "Node.hpp"
#include "Stack.hpp"
using namespace std;

struct BST {
    int *items;   // DEGERLERİN TUTULACAGI DİZİ
    int condition[SIZE];   //DİZİNİN O İNDEKSİ BOŞ MU DOLU MU DİYE BAKAR. BOŞ İSE 0 DOLU İSE 1 DEGERİNİ ATAR

    int indexOf(const int&,int);
    BST();
    void clear();
    void add(const int&);
    bool search(const int&);
    void postorder(int currentIndex=0);
    int Height(int index=0);
    int agacTopla();
    ~BST();

};
#endif