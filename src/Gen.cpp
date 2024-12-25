/*
* @file Gen.cpp
* @description Gen sınıfında tanımlanan işlevlerin gerçekleştirilmesini içerir. Gen nesnelerinin oluşturulması ve sonraki genle bağlantısının sağlanması gibi işlevleri burada uygular.
* @course 2-A
* @assignment 1. ÖDEV
* @date 02.11.2024
* @author Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include "Gen.hpp"

// Gen sınıfı yapıcısı; genin veri değerini alır ve sonraki işaretçisini NULL yaparak başlatır
Gen::Gen(const std::string& v) : veri(v), sonraki(NULL) {}
