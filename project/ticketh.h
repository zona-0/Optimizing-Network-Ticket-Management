#ifndef TICKETH_H_INCLUDED
#define TICKETH_H_INCLUDED

#include <iostream>
#include <string>

typedef struct Publikasi* adrPublikasi;

struct Publikasi{
    string judul;
    int tahun; 
    string kategori;
    adrPublikasi next;

};

adrPublikasi createPublikasi(string judul, int tahun, string kategori){
    Publikasi *p = new publikasi;
    p->judul = judul;
    


}


#endif // TICKETH_H_INCLUDED
