/*
* @file Gen.hpp
* @description Gen sınıfının tanımlarını içerir. Bir kromozomun temel yapı taşı olan genlerin verilerini ve diğer genlere bağlantı bilgilerini tutar.
* @course 2-A
* @assignment 1. ÖDEV
* @date 02.11.2024
* @author Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#ifndef Gen_hpp
#define Gen_hpp

#include <string>

// Gen sınıfı, bir kromozomdaki tek bir genin verisini ve bağlantısını tutar
class Gen {
public:
    std::string veri;   // Genin verisini tutar
    Gen* sonraki;       // Bir sonraki gene işaretçi


    // Yapıcı fonksiyon, genin verisini alır ve sonraki bağlantısını başlatır
    Gen(const std::string& v);
};

#endif
