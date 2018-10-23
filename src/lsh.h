/*******************************/
/* lsh.h */

/* Name:    Andreas Charalampous
 * A.M :    1115201500195
 * e-mail:  sdi1500195@di.uoa.gr
 */
/********************************/
#pragma once
#include <string>
#include <vector>

#include "metrics.h"

/*  Implementation of the class that uses the LSH algorithm */

/* Class of LSH that holds all the metrics */
template <class T>
class LSH{
    private:
        int L; // number of hash tables for each metric
        std::vector<euclidean<T>*> eu_tables; // euclidian tables
        std::vector<csimilarity<T>*> cs_tables; // cosine similarity tables 
    public:
        /* Given number of tables, metrics and number of input, create LSH structure */
        LSH(int, int, int, int);

        /* Add a new vector in all the hash tables */
        void add_vector(vector_item<T>*);

        /* Finds ANN of given vector, searching in all hash tables */
        void findANN(vector_item<T>&, float, float&, std::string&);
};