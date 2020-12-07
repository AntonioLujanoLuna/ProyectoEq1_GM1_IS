//extra.h
//proyecto IS

#ifndef EXTRA_H
#define EXTRA_H

#include <string>
#include "rutas.h"

bool fechaValida (const std::string &str);
bool horaValida (const std::string &str);
int strGetHora (const std::string &str);
int strGetMinutos (const std::string &str)
bool solapanRutas (const ruta &r1, const ruta &r2);

#endif