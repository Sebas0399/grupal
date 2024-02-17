//
// Created by sebas on 16/02/24.
//
#include <vector>
#include <fmt/core.h>
#ifndef GRUPAL_PREFIXSUM_H
#define GRUPAL_PREFIXSUM_H


class prefixSum {
public:

    void static prefixSumSerial(const std::vector<int>& input, std::vector<int>& output) {
        int n = input.size();
        output.resize(n);

        if (n > 0) {
            output[0] = input[0];
            for (int i = 1; i < n; ++i) {
                output[i] = output[i - 1] + input[i];
            }
        }
    }

    void static prefixSumParallel(const std::vector<int>& input, std::vector<int>& output) {
        int n = input.size();
        output.resize(n);

        if (n > 0) {
            output[0] = input[0];
#pragma omp parallel default(none) shared(n,input,output)
#pragma omp for
            for (int i = 1; i < n; ++i) {
                output[i] = output[i - 1] + input[i];
            }
        }
    }

};


#endif //GRUPAL_PREFIXSUM_H
