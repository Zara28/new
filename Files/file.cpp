#pragma once

#include "TXLib.h"
#include <iostream>

#include <fstream>
#include <string>
#include "cartinca.cpp"

using namespace std;

int massive(CartincaNaKarte* KART1)
{
    ifstream fout;
    const char* imya_faila = txInputBox ("������ �����?", "System", "");
    //fout.open("Files\\Openfile.txt");
    //string imya_faila;
    //getline (fout, imya_faila);
    //fout.close();

    fout.open(imya_faila);

    int nomer = 0;
    string get = "1";
    while (fout.good() && strlen(get.c_str()) > 0) {
        getline (fout, get);

        if (strlen(get.c_str()) > 0)
        {
            int pos1 = get.find(',');
            string adress = get.substr(0, pos1 );
            get = get.substr(pos1 + 1);

            int pos2 = get.find(',');
            string x = get.substr(0, pos2);
            get = get.substr(pos2 + 1);

            int pos3 = get.find(',');
            string y = get.substr(0, pos3);

            KART1[nomer] = {txLoadImage(adress.c_str()), atoi(x.c_str()), atoi(y.c_str()), true, adress.c_str()};
            nomer++;
        }
    }

    fout.close();

    return nomer;
}

void saveMassive(CartincaNaKarte* KART1, int nomer_kartinki)
{
    ifstream fout;
    const char* imya_faila_save = txInputBox ("���� ���������?", "System", "");
    //fout.open("Files\\savefile.txt");
    //string imya_faila_save;
    //getline (fout, imya_faila_save);
    //fout.close();


    ofstream fout_save;
    fout_save.open(imya_faila_save);

    //CartincaNaKarte KART[1];
    //KART[0] = {txLoadImage("Icons\\Monuments\\Lenin.bmp"), 200, 200, true, "Icons\\Monuments\\Lenin.bmp"};
    for(int i = 0; i< nomer_kartinki; i++)
    {
        if (KART1[i].RISOVAT_KARTINKU)
        {
            fout_save << KART1[i].adress << "," << KART1[i].X << "," << KART1[i].Y << endl;
        }
    }

    fout.close();
}