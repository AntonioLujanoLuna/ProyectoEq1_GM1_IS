//extra.cc
//proyecto IS

#include "extra.h"



//Extrae la hora de una string con formato HH:MM
int strGetHora (const std::string &str) {
    std::string hora = str.substr(0, 2);
    return std::stoi(hora);
}

//Extrae los minutos de una string con formato HH:MM
int strGetMinutos (const std::string &str) {
    std::string minuto = str.substr(3, 2);
    return std::stoi(minuto);
}

bool solapanRutas (const ruta &r1, const ruta &r2) {
    bool solapan = true;

    if (r1.getFecha() == r2.getFecha()) {
        int hr1 = strGetHora(r1.getHora());
        int mr1 = strGetMinutos(r1.getHora());

        int hf1 = hr1;
        int mf1 = mr1 + r1.getDuracionEstimada();
        hf1 += mf1 / 60;
        mf1 %= 60;

        int hr2 = strGetHora(r2.getHora());
        int mr2 = strGetMinutos(r2.getHora());

        int hf2 = hr2;
        int mf2 = mr2 + r2.getDuracionEstimada();
        hf2 += mf2 / 60;
        mf2 %= 60;

        if (hf1 < hr2) {
            solapan = false;
        }
        else if (hf1 == hr2) {
            if (mf1 <= mr2) {
                solapan = false;
            }
        }

        if (hr1 > hf2) {
            solapan = false;
        }
        else if (hr1 == hf2) {
            if (mr1 >= mf2) {
                solapan = false;
            }
        }
    }
    else {
        solapan = false;
    }

    return solapan;
}
