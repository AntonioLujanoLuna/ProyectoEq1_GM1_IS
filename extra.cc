//extra.cc
//proyecto IS

#include "extra.h"

bool fechaValida (const std::string &str) {
    if (str.size() == 10) {
        //Comprueba el formato
        for (int i = 0; i < 10; i++) {
            if (i == 2 || i == 5) {
                if (str[i] != '/') {
                    return false;
                }
            }
            else {
                if (!std::isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba el mes
        int m = std::stoi(str.substr(3, 2));
        if (m < 1 || m > 12) {
            return false;
        }

        //Comprueba el dia en funcion del mes
        int d = std::stoi(str.substr(0, 2));
        if (d < 1) { return false; }

        switch (m) {
            case  1: return d <= 31;
            case  2: return d <= 28;
            case  3: return d <= 31;
            case  4: return d <= 30;
            case  5: return d <= 31;
            case  6: return d <= 30;
            case  7: return d <= 31;
            case  8: return d <= 31;
            case  9: return d <= 30;
            case 10: return d <= 31;
            case 11: return d <= 30;
            case 12: return d <= 31;
        }
    }
    else {
        return false;
    }

    return true;
}

bool horaValida (const std::string &str) {
    if (str.size() == 5) {
        //Comprueba el formato
        for (int i = 0; i < 5; i++) {
            if (i == 2) {
                if (str[i] != ':') {
                    return false;
                }
            }
            else {
                if (!std::isdigit(str[i])) {
                    return false;
                }
            }
        }

        //Comprueba que la hora sea valida
        int h = strGetHora(str);
        if (h < 0 || h > 23) {
            return false;
        }

        //Comprueba que los minutos sean validos
        int m = strGetMinutos(str);
        if (m < 0 || m > 59) {
            return false;
        }
    }
    else {
        return false;        
    }

    return true;
}

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