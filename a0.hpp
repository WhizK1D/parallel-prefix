/*  Abhyudaya
 *  Mourya
 *  amourya
 */
#include <iostream>
#include <omp.h>
#include <math.h>

#ifndef A0_HPP
#define A0_HPP

template <typename T, typename Op>
void omp_scan(int n, const T* in, T* out, Op op)
{
    /*Implement omp_scan to perform parallel prefix */
    int i = 0;
    int *sumLeft = NULL;
    int threadSlice;

    #pragma omp parallel shared(in, out, threadSlice) private(i)
    {
        const int threadCount = omp_get_num_threads();
        threadSlice = ceil(n/float(threadCount));

        #pragma omp single
        {
            sumLeft = new int[threadCount + 1];
            sumLeft[0] = 0;
        }

        int sum = 0;

        // TODO: Check changing to dynamic
        // Bottom-up half of prefix scan method
        #pragma omp for schedule(static, threadSlice)
            for (i = 0; i < n; i++)
            {
                if ((i % threadSlice) == 0)
                {
                    sum = in[i]; // Sum for each slice of data is the first element
                    out[i] = in[i]; // Temporarily set output for slice as the first element
                }
                else
                {
                    out[i] = op(out[i-1], in[i]); // Output for each element is derived from previous
                    sum = op(sum, in[i]); // Sum for each element is the previous (sum op curr)
                }
            }

        const int currThread = omp_get_thread_num();
        sumLeft[currThread + 1] = sum; // calculate overall sum

        // Top-Down half of the prefix scan method
        // Wait for all threads to compute sumLeft
        #pragma omp barrier
        int partial = sumLeft[1];

        for (int i = 2; i < (currThread + 1); i++)
        {
            partial = op(partial, sumLeft[i]); // each partial sum will be added to corresponding sumLeft
        }

        #pragma omp for schedule(static, threadSlice)
            for (int i = 0; i < n; i++)
            {
                if(currThread != 0)
                {
                    out[i] = op(out[i], partial); // each output term is sum of currently computed output and partial sum
                }
            }
    }
}

#endif // A0_HPP
