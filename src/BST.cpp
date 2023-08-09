/**
* @file BST.cpp
* @description BST nin Oluştuğu Yer Burada Yükseklik Bulma , Ağaca Veri Ekleme , Postorderı ASCII CHAR ŞEKLİNDE YAZDIRMA VE
  AGACIN ELEMANLARININ TOPLAMINI BULMA İŞLEMLERİ YAPILMIŞTIR
* @course 1-B
* @assignment 2.Ödev
* @date 02.08.2023 ile 09.07.2023 Arası
* @author İlyas Kalfa ve Halil İbrahim Boztaş ve ilyas.kalfa@ogr.sakarya.edu.tr ve halil.boztas@ogr.sakarya.edu.tr

*/

#include "BST.hpp"
#include "Node.hpp"
#include "Stack.hpp"
        
        int BST::indexOf(const int& item,int currentIndex=0){
            while (true)
            {
                if(condition[currentIndex]==0 || currentIndex>= SIZE) return -1;
                else if(item<items[currentIndex]) currentIndex=2*currentIndex+1;
                else if(item>items[currentIndex]) currentIndex=2*currentIndex+2;
                else if(items[currentIndex]=item && condition[currentIndex]==1)
                    return currentIndex;
            }
        }
        BST::BST(){
            items = new int[SIZE];
            clear();
        }
        void BST::clear(){
            for(int i=0;i<SIZE;i++){
                condition[i]=0;
            }
        }
        void BST::add(const int& item){
            int currentIndex=0;
            while(true){
                if(condition[currentIndex]==0){
                    items[currentIndex]=item;
                    condition[currentIndex]=1;
                    break;
                }
                else if(item<items[currentIndex]) currentIndex =2*currentIndex+1;
                else if(item>items[currentIndex]) currentIndex=2*currentIndex+2;
                else return;
            }
        }
        bool BST::search(const int& item){
            return indexOf(item) !=-1;
        }

        void BST::postorder(int currentIndex){     // SOL SAG DGM
            if(currentIndex<SIZE && condition[currentIndex]!=0){

                postorder(2*currentIndex+1);
                postorder(2*currentIndex+2);
                int number=items[currentIndex];                
                char ascii=static_cast<char>(number);
                cout<<ascii<<" ";
                
            }
        }
        int BST::Height(int index){            //YUKSEKLİK BULUR
            if(condition[index]==0) return -1;
            return 1+max(Height(2*index+1),Height(2*index+2));
        }

        int BST::agacTopla() {           // AGACIN ELEMANLARINI TOPLAR
            int toplam=0;
            for(int i=0;i<SIZE;i++){
                if(condition[i]==1){
                    toplam+=items[i];
                }
            }
            return toplam;
        }

        // OPSİYONEL
        /*
        int agacTopla(int currentIndex=0){
            int toplam=0;
            int left=agacTopla(2*currentIndex+1);
            int right=agacTopla(2*currentIndex+2);
            int root=items[currentIndex];
            toplam=left+right+root;
            return toplam;

        }
        */

        BST::~BST(){
            delete [] items;
        }