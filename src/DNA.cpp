/*
* @file DNA.cpp
* @description DNA sınıfında tanımlanan işlevlerin gerçekleştirilmesini içerir. DNA’ya kromozom ekleme, çaprazlama işlemi ve tüm kromozomları ekrana veya dosyaya yazdırma işlevlerini burada uygular.
* @course 2-A
* @assignment 1. ÖDEV
* @date 02.11.2024
* @author Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include "DNA.hpp"
#include <fstream>
#include <sstream>

DNA::DNA() : ilkKromozom(NULL) {}   // DNA sınıfı yapıcısı, ilk kromozomu NULL yaparak başlatır

// Yıkıcı fonksiyon
DNA::~DNA() {
    Kromozom* guncel = ilkKromozom;
    while (guncel) {
        Kromozom* silinecek = guncel;
        guncel = guncel->sonraki;
        delete silinecek;
    }
}

// DNA'ya yeni bir kromozom ekler; varsa liste sonuna eklenir
void DNA::kromozomEkle(Kromozom* yeniKromozom) {
    if (!ilkKromozom) {
        ilkKromozom = yeniKromozom;
    } else {
        Kromozom* tmp = ilkKromozom;
        while (tmp->sonraki) {
            tmp = tmp->sonraki;
        }
        tmp->sonraki = yeniKromozom;
    }
}

// Verilen dosyadan DNA’ya kromozomları okur ve ekler
void DNA::dosyadanOku(const std::string& dosyaAdi) {
    std::ifstream dosya(dosyaAdi);
    std::string satir;
    while (std::getline(dosya, satir)) {
        Kromozom* yeniKromozom = new Kromozom();
        std::istringstream ss(satir);
        std::string gen;
        while (ss >> gen) {
            yeniKromozom->genEkle(gen);
        }
        kromozomEkle(yeniKromozom);
    }
    dosya.close();
    kromozomlariYazdir();
}

// İki kromozom arasında çaprazlama işlemi yapar ve yeni kromozomlar oluşturur
void DNA::caprazlama(int index1, int index2) {
    Kromozom* kromozom1 = getKromozom(index1);
    Kromozom* kromozom2 = getKromozom(index2);

    if (!kromozom1 || !kromozom2) return;

    // hen sayısının boyutunu tutma
    int boyut1 = genSayisi(kromozom1);
    int boyut2 = genSayisi(kromozom2);

    // Orta noktaları hesapla
    int orta1 = boyut1 / 2;
    int orta2 = boyut2 / 2;

    // Yeni kromozomları oluştur
    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();

    Gen* gen1 = kromozom1->ilkGen;
    Gen* gen2 = kromozom2->ilkGen;

    // İlk kromozomdan genler ekle
    for (int i = 0; i < boyut1; ++i) {
        if (boyut1 % 2 == 1 && i == orta1) {
            gen1 = gen1->sonraki;
            continue;
        }

        if (i < orta1) {
            yeniKromozom1->genEkle(gen1->veri);
        } else {
            yeniKromozom2->genEkle(gen1->veri);
        }

        gen1 = gen1->sonraki;
    }

    // İkinci kromozomdan genler ekle
    for (int i = 0; i < boyut2; ++i) {
        if (boyut2 % 2 == 1 && i == orta2) {
            gen2 = gen2->sonraki;
            continue;
        }

        if (i >= orta2) {
            yeniKromozom1->genEkle(gen2->veri);
        } else {
            yeniKromozom2->genEkle(gen2->veri);
        }

        gen2 = gen2->sonraki;
    }

    // Yeni kromozomları popülasyona ekle
    kromozomEkle(yeniKromozom1);
    kromozomEkle(yeniKromozom2);
}

// Belirli bir kromozom ve gen indeksine göre mutasyon yapar
void DNA::mutasyon(int kromozomIndex, int genIndex) {
    Kromozom* kromozom = getKromozom(kromozomIndex);
    if (!kromozom) return;

    Gen* gen = kromozom->ilkGen;
    int i = 0;
    while (gen && i < genIndex) {
        gen = gen->sonraki;
        i++;
    }
    if (gen) {
        gen->veri = "X";
    }

    std::cout << "Mutasyon Islemi Sonrasi Kromozomlar:" << std::endl;
}

// Dosyadan otomatik çaprazlama ve mutasyon işlemlerini uygular
void DNA::otomatikIslemler(const std::string& dosyaAdi) {
    std::ifstream dosya(dosyaAdi);
    std::string satir;

    while (std::getline(dosya, satir)) {
        std::istringstream ss(satir);
        std::string islem;
        ss >> islem;

        if (islem == "C") {
            int index1, index2;
            ss >> index1 >> index2;
            caprazlama(index1, index2);
        }
        else if (islem == "M") {
            int kromozomIndex, genIndex;
            ss >> kromozomIndex >> genIndex;
            mutasyon(kromozomIndex, genIndex);
        }
    }
    dosya.close();
}

// DNA yapısındaki her kromozomun ekran çıktısını yapar
void DNA::ekranaYaz() const {
    Kromozom* kromozom = ilkKromozom;

    while (kromozom) {
        Gen* ilkGen = kromozom->ilkGen;
        Gen* secilecekGen = ilkGen;

        Gen* tmp = ilkGen;
        while (tmp) {
            if (tmp->veri < ilkGen->veri) {
                secilecekGen = tmp;
            }
            tmp = tmp->sonraki;
        }
        std::cout << secilecekGen->veri << " ";
        kromozom = kromozom->sonraki;
    }
}

// Belirli bir indeksteki kromozomu döndürür
Kromozom* DNA::getKromozom(int index) const {
    Kromozom* tmp = ilkKromozom;
    int i = 0;
    while (tmp && i < index) {
        tmp = tmp->sonraki;
        i++;
    }
    return tmp;
}

// Verilen kromozomun gen sayısını hesaplar
int DNA::genSayisi(Kromozom* kromozom) const {
    int sayac = 0;
    Gen* tmp = kromozom->ilkGen;
    while (tmp) {
        sayac++;
        tmp = tmp->sonraki;
    }
    return sayac;
}

// DNA’daki tüm kromozomları ekrana yazdırır
void DNA::kromozomlariYazdir() const {
    Kromozom* tmp = ilkKromozom;
    int index = 0;
    while (tmp) {
        std::cout << "Kromozom " << index << ": ";
        tmp->yazdir();
        tmp = tmp->sonraki;
        index++;
    }
}
