/*
* @file Kromozom.cpp
* @description Kromozom sınıfında tanımlanan işlevlerin gerçekleştirilmesini içerir. Gen ekleme ve kromozomu ekrana/dosyaya yazma işlevlerini burada uygular.
* @course 2-A
* @assignment 1. ÖDEV
* @date 02.11.2024
* @author Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include "Kromozom.hpp"

// Kromozom sınıfı yapıcısı; ilkGen ve sonraki işaretçilerini NULL olarak başlatır
Kromozom::Kromozom() : ilkGen(NULL), sonraki(NULL) {}

// Yıkıcı fonksiyon
Kromozom::~Kromozom() {
    Gen* guncel = ilkGen;
    while (guncel) {
        Gen* silinecek = guncel;
        guncel = guncel->sonraki;
        delete silinecek;
    }
}

// Kromozoma yeni bir gen ekler; ilkGen boşsa yeni gen ilkGen olarak ayarlanır
// değilse, mevcut genlerin sonuna yeni bir gen eklenir
void Kromozom::genEkle(const std::string& veri) {
    if (!ilkGen) {
        ilkGen = new Gen(veri);
    } else {
        Gen* tmp = ilkGen;
        while (tmp->sonraki) {
            tmp = tmp->sonraki;
        }
        tmp->sonraki = new Gen(veri);
    }
}

// Kromozomdaki genleri sırayla ekrana yazdırır, her gen arasına boşluk koyar
void Kromozom::yazdir() const {
    Gen* tmp = ilkGen;
    while (tmp) {
        std::cout << tmp->veri << " ";
        tmp = tmp->sonraki;
    }
    std::cout << std::endl;
}

