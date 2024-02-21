#include <iostream>
#include <vector>
#include "prefixSum.h"
#include "utils.h"
#include <chrono>
#include "histograma.h"

int main() {


    std::vector<int> input = utils::initVector(100000000);
    std::vector<int> output;
    //Prefix sum serial
    auto start = std::chrono::high_resolution_clock::now();
    prefixSum::prefixSumSerial(input, output);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempo = end - start;

    fmt::println("Prefix sum serial time: {} ms",tiempo.count());

    auto start1 = std::chrono::high_resolution_clock::now();
    prefixSum::prefixSumParallel(input, output);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempo1 = end1 - start1;

    fmt::println("Prefix sum parallel time: {} ms",tiempo1.count());
    //utils::printVector(output);
    histograma histograma;
    auto valuesRaw=utils::initVectorHist(100000);
    int grupos=4;

    auto startHistSerial = std::chrono::high_resolution_clock::now();
    auto valHist=histograma.calcularHistograma(valuesRaw,grupos);
    auto endHistSerial = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempoHistoSerial = endHistSerial - startHistSerial;

    fmt::println("Histograma serial time: {} ms",tiempoHistoSerial.count());

    auto startHistParallel = std::chrono::high_resolution_clock::now();
    auto valHistParallel=histograma.calcularHistogramaParalell(valuesRaw,grupos);
    auto endHistParallel = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempoHistoParallel = endHistParallel - startHistParallel;

    fmt::println("Histograma paralell time: {} ms",tiempoHistoParallel.count());

    return 0;
}
