//
// Created by sebas on 16/02/24.
//

#ifndef GRUPAL_HISTOGRAMA_H
#define GRUPAL_HISTOGRAMA_H
#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include <cmath>
#define WIDTH 1280
#define HEIGHT 720
class histograma {
public:
     std::vector<int>calcularHistograma(std::vector<int>valuesRaw, int grupos){


        std::vector<int>res_grup(grupos);
        int paso=std::ceil(256/grupos);
        for (int i = 0; i < valuesRaw.size(); ++i) {
            int tmp=valuesRaw[i];
            int it=0;
            while (tmp-paso>0){
                tmp=tmp-paso;
                it++;
            }
            //fmt::println("Valor {},conjunto {}",valuesRaw[i],it);
            res_grup[it]=res_grup[it]+1;
        }
         return res_grup;
    }

    std::vector<int>calcularHistogramaParalell(std::vector<int>valuesRaw,int grupos){

        std::vector<int>res_grup(grupos);
        int paso=std::ceil(256/grupos);
#pragma omp parallel default(none) shared(res_grup,valuesRaw,paso)
#pragma omp for
        for (int i = 0; i < valuesRaw.size(); ++i) {
            int tmp=valuesRaw[i];
            int it=0;
            while (tmp-paso>0){
                tmp=tmp-paso;
                it++;
            }

            res_grup[it]=res_grup[it]+1;
        }
        return res_grup;
    }

};


#endif //GRUPAL_HISTOGRAMA_H
