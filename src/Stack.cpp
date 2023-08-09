/**
* @file Stack.cpp
* @description STACK İN OLUŞTUĞU YER . STACK E ELEMAN EKLEME , ÇIKARMA , ELEMANINI GETİRME İŞLEMLERİ YAPILAN YERDİR
* @course 1-B
* @assignment 2.Ödev
* @date 02.08.2023 ile 09.07.2023 Arası
* @author İlyas Kalfa ve Halil İbrahim Boztaş ve ilyas.kalfa@ogr.sakarya.edu.tr ve halil.boztas@ogr.sakarya.edu.tr

*/

#include "Node.hpp"
#include "Stack.hpp"


    Stack::Stack(){
        topOfStack=NULL;
    }
    bool Stack::isEmpty(){
        return topOfStack == NULL;
    }
    void Stack::clear(){
        while(!isEmpty()) pop();
    }
    void Stack::push(const int& item){             // EKLEME FONKSİYONU
        topOfStack=new Node(item,topOfStack);
    }
    const int& Stack::top(){               // ELEMANI DÖNDÜRME FONKSİYONU
        if(isEmpty()) throw "Stack is Empty";
        return topOfStack->data;
    }
    void Stack::pop(){             // SİLME FONKSİYONU
        if(isEmpty()) throw "Stack is Empty";
        Node *del=topOfStack;
        topOfStack=topOfStack->next;
        delete del;
    }
    Stack::~Stack(){           // YIKICI FONKSİYON
        clear();
    }