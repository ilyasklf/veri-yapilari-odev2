/**
* @file Node.cpp
* @description Stackin Düğüm Yapısının Oluştuğu Yer
* @course 1-B
* @assignment 2.Ödev
* @date 02.08.2023 ile 09.07.2023 Arası
* @author İlyas Kalfa ve Halil İbrahim Boztaş ve ilyas.kalfa@ogr.sakarya.edu.tr ve halil.boztas@ogr.sakarya.edu.tr

*/

#include "Node.hpp"

Node::Node(int data, Node *next=NULL){
    this->data=data;
    this->next=next;
}
