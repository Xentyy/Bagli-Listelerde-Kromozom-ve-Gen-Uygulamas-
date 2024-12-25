/*
* @file main.cpp
* @description Programın giriş noktasıdır. DNA ve Kromozom nesnelerinin oluşturulması, genlerin eklenmesi, çaprazlama işlemlerinin yapılması ve sonuçların ekrana veya dosyaya yazdırılması gibi ana işlemleri başlatır ve yönetir.
* @course 2-A
* @assignment 1. ÖDEV
* @date 02.11.2024
* @author Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include "DNA.hpp"
#include <iostream>

int main() {
    // DNA nesnesini dinamik olarak oluşturuyoruz ve Dna.txt dosyasından verileri okuyoruz
    std::cout << "\n\n";
    DNA* dna = new DNA();
    dna->dosyadanOku("Dna.txt");

    int secim;
    do {
        // Menü seçeneklerini ekrana yazdırıyoruz
        std::cout << "\n1- Caprazlama\n2- Mutasyon\n3- Otomatik Islemler\n4- Ekrana Yaz\n5- Cikis\nSecim: ";
        std::cin >> secim;

        if (secim == 1) {
            // Çaprazlama işlemi için kullanıcıdan iki kromozom indeksi alıyoruz
            int index1, index2;
            std::cout << "\nCaprazlanacak Kromozomlarin Satir Numaralari: ";
            std::cout << "\nIlk Kromozomun Satir Numarasi: ";
            std::cin >> index1;
            std::cout << "\nIkinci Kromozomun Satir Numarasi: ";
            std::cin >> index2;
            dna->caprazlama(index1, index2);
            dna->kromozomlariYazdir();
        }
        else if (secim == 2) {
            // Mutasyon işlemi için kullanıcıdan kromozom ve gen indeksi alıyoruz
            int kromozomIndex, genIndex;
            std::cout << "Mutasyon Yapilacak Kromozom ve Gen: ";
            std::cout << "\nKromozomun Satir Numarasi: ";
            std::cin >> kromozomIndex;
            std::cout << "\nGenin Sira Numarasi Numarasi: ";
            std::cin >> genIndex;
            dna->mutasyon(kromozomIndex, genIndex);
            dna->kromozomlariYazdir();
        }
        else if (secim == 3) {
            // "Islemler.txt" dosyasından otomatik işlemleri gerçekleştiriyoruz
            dna->otomatikIslemler("Islemler.txt");
            dna->kromozomlariYazdir();
            std::cout << "\nIslem tamamlandi!\n ";
        }
        else if (secim == 4) {
            // DNA nesnesindeki kromozomları ekrana yazdırıyoruz
            dna->ekranaYaz();
        }
    } while (secim != 5);

    // DNA nesnesini bellekten siliyoruz
    // Bu satır DNA sınıfındaki destructor'ı çağırır
    delete dna; 

    return 0;
}

