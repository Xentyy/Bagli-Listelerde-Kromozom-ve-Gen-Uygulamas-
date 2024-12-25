/*
* @file DNA.hpp
* @description DNA sınıfının tanımlarını içerir. DNA içindeki kromozomların eklenmesi, çaprazlanması ve yazdırılması gibi temel işlevlerin tanımlarını barındırır.
* @course 2-A
* @assignment 1. ÖDEV
* @date 02.11.2024
* @author Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#ifndef Dna_hpp
#define Dna_hpp

#include "Kromozom.hpp"
#include <string>
#include <iostream>

class DNA {
private:
    Kromozom* ilkKromozom; // DNA içindeki ilk kromozomu işaret eder

public:
    // Dna sınıfının yapıcısı    
    DNA();  
    // DNA sınıfının yıkıcısı, bellekteki tüm kromozomları serbest bırakır            
    ~DNA();
    // cpp dosyalarının başlıklarını imzasını h dosyasına ekliyoruz

    void kromozomEkle(Kromozom* yeniKromozom);
    void dosyadanOku(const std::string& dosyaAdi);
    void caprazlama(int index1, int index2);
    void mutasyon(int kromozomIndex, int genIndex);
    void otomatikIslemler(const std::string& dosyaAdi);
    void ekranaYaz() const;
    void kromozomlariYazdir() const;
private:
    Kromozom* getKromozom(int index) const;
    int genSayisi(Kromozom* kromozom) const;    
};

#endif
