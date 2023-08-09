/**
* @file Test.cpp
* @description Her ŞEYİN KULLANILDIĞI YERDİR. İLK ÖNCE STACK DİZİSİ OLUŞTURUP DOSYAYI OKUYUP GELEN SAYININ DURUMUNA GÖRE STACK OLUŞTURUP EKLEME İŞLEMİ YAPILIR.
  AGAC DİZİSİ OLUSTURULUR VE DAHA SONRA STACKTEN ELEMANLAR ÇIKARILARAK AGACA EKLENİR. VERİLER AGACA EKLENDİKTEN SONRA AGACLARIN YÜKSEKLİKLERİ BULUNUR.
  AMACIMIZ O SATIRDAKI YÜKSEKLİĞİ EN BÜYÜK OLAN AĞACI BULUP ONU POSTORDER YAZDIRMAKTIR.EĞER YÜKSEKLİKLER EŞİTSE AĞAÇLARIN ELEMAANLARIN TOPLAMINA GÖRE 
  YÜKSEKLİK SEÇEERİZ.SLEEP KOMUTU İLE 10 MS BEKLENİR. EN SONDA DİZİLER İADE EDİLİR.
* @course 1-B
* @assignment 2.Ödev
* @date 02.08.2023 ile 09.07.2023 Arası
* @author İlyas Kalfa ve Halil İbrahim Boztaş ve ilyas.kalfa@ogr.sakarya.edu.tr ve halil.boztas@ogr.sakarya.edu.tr

*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "Node.hpp"
#include "Stack.hpp"
#include "BST.hpp"

using namespace std;


int main()
{
    system("cls");
	ifstream dosya("Sayilar.txt");              //Sayilar.txt Yİ AÇAR

    string satir;
    int sayi;

    Stack **diziStack = new Stack*[500];        //STACK DİZİSİ OLUŞTURDUK
    int size=0;
    
    while(getline(dosya, satir)){           // ILK SATIRI OUR
        istringstream iss(satir);
        while (iss >> sayi) {               // SATIRLARDAKİ ELEMANLARI OKUR
            // STACK E ELEMAN EKLEME
            if(size==0){        // EĞER İLK İNDİSSE STACK ÜRET
                diziStack[size] = new Stack();
                size++;
                diziStack[size-1]->push(sayi);
            }
            else if(sayi%2==0 && sayi>diziStack[size-1]->topOfStack->data){         // EĞER ÇİFT VE GELEN BÜYÜKSE YENİ STACK ÜRET
                diziStack[size] = new Stack();
                size++;
                diziStack[size-1]->push(sayi);
                
            }
            else 
                diziStack[size-1]->push(sayi);
        }

        // STACKTEN ÇIKARIP AGACA EKLEME

        BST **bst=new BST*[size];           //AGAC DİZİSİ OLUŞTUR
        for(int i=0;i<size;i++){
            bst[i] = new BST();             //AGAC DİZİSİNİN ELEMANLARINA AGAC BAGLA
            while (!diziStack[i]->isEmpty())        // BOŞ DOLU KONTROLÜ
            {
                bst[i]->add(diziStack[i]->top());
                diziStack[i]->pop();
            }
        }

        // AGACLARI BİRBİRLERİ İLE KARŞILAŞTIRMA

        BST* hBST = bst[0];                     // BASLANGICTA İLK AGACI EN YÜKSEK OLARAK KABUL ET
        for (int i = 1; i < size; i++) {
            if (bst[i]->Height() > hBST->Height()) {
                hBST = bst[i];                  // DAHA SONRA YENİ GELEN YÜKSEKSE İLK KABUL ETTİĞİMİZ İLE DEĞİŞTİR
            }
            else if(bst[i]->Height()==hBST->Height()){          //AGAC YUKSEKLİKLERİ EŞİT Mİ KONTROL ET
                if(bst[i]->agacTopla() > hBST->agacTopla()){            
                    hBST=bst[i];            // AGAC YUKSEKLİKLERİ ESİTSE HANGİSİNİN ELEMAN TOPLAMI YUKSEKSE ONUNLA ESİTLE
                }
            }
        }

        hBST->postorder();              // YUKSEKLİGİ UZUN OLANI POSTORDER YAZDIR
        cout<<endl;
        Sleep(10);              // EKRANDA 10 MİLİSANİYE BEKLE
        
        for (int i = 0; i < size; i++)          //DİZİLERİ BOŞALT
        {
            delete diziStack[i];
            delete bst[i];
        }
        delete [] bst;
        size = 0;
    }
	return 0;
}