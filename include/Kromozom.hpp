/*
* @file Kromozom.hpp
* @description Kromozom sınıfının tanımlarını içerir. Her bir kromozomu oluşturan genleri tutar ve ekleme, yazdırma gibi temel işlevlerin tanımlarını barındırır.
* @course 2-A
* @assignment 1. ÖDEV
* @date 02.11.2024
* @author Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#ifndef Kromozom_hpp
#define Kromozom_hpp

// Gen.hpp dosyasını ve gereken kütüphaneleri ekliyoruz
#include "Gen.hpp"
#include <iostream>
#include <fstream>
#include <string>


// Kromozom sınıfı, genleri ve kromozomlar arası bağlantıyı tutar
class Kromozom {
public:
    Gen* ilkGen;        // Kromozomun ilk genine işaretçi
    Kromozom* sonraki;  // Sonraki kromozoma işaretçi

    Kromozom(); // Yapıcı fonksiyon, ilkGen ve sonraki işaretçilerini başlatır
                    
    ~Kromozom(); // Yıkıcı fonksiyon, kromozomun tüm genlerini bellekten siler

    //Gövdede bulunan fonksiyonların imzaları
    void genEkle(const std::string& veri);
    void yazdir() const;
};

#endif
