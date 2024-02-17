//
// Created by sebas on 16/02/24.
//

#ifndef GRUPAL_HISTOGRAMA_H
#define GRUPAL_HISTOGRAMA_H
#include <SFML/Graphics.hpp>
#include <fmt/core.h>

#define WIDTH 1280
#define HEIGHT 720
class histograma {
public:
     std::vector<int>calcularHistograma(std::vector<int>valuesRaw){

        std::vector<int>res(256);
        for (int i = 0; i < valuesRaw.size(); ++i) {
            res[valuesRaw[i]]=res[valuesRaw[i]]+1;
        }
         return res;
    }

    std::vector<int>calcularHistogramaParalell(std::vector<int>valuesRaw){

        std::vector<int>res(256);
#pragma omp parallel default(none) shared(res,valuesRaw)
#pragma omp for
        for (int i = 0; i < valuesRaw.size(); ++i) {
            res[valuesRaw[i]]=res[valuesRaw[i]]+1;
        }
        return res;
    }
    int max(std::vector<int>val){
         int max=0;
        for (int i = 0; i < val.size(); ++i) {
            if (max<val[i]){
                max=val[i];
            }
        }
        fmt::println("MAXIMO {}",max);
        return max;
     }
     void renderHisto(std::vector<int>values){
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");


       int maximo=max(values);
        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window wit h black color

            window.clear(sf::Color::Black);
            for (int i = 0; i < 255; ++i) {
                //fmt::println("Size {},Val{}",i,values[i]);

                sf::RectangleShape rectangle(sf::Vector2f((float) WIDTH/255, -(values[i]*HEIGHT)/maximo));
                rectangle.setOutlineThickness(1.f);
                rectangle.setOutlineColor(sf::Color(250, 150, 100));
                rectangle.setPosition(sf::Vector2f(WIDTH-((float )WIDTH/255)*(float )i,HEIGHT));
                //rectangle.setFillColor(sf::Color());
                window.draw(rectangle);


            }


// set the shape color to green
            //shape.setFillColor(sf::Color(100, 250, 50));
            // draw everything here...
            // window.draw(...);

            // end the current frame
            window.display();
        }


    }
};


#endif //GRUPAL_HISTOGRAMA_H
