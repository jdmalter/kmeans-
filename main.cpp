#include <ctime>
#include <iostream>
#include <sstream>
#include "kmeans.h"
#include "main.h"

static constexpr csize d = 4;

int main(int argc, char** argv) {
    if (argc != 4)
    {
        cout << "main <input> <output> <means>" << endl;
        exit(1);
    }
    
    ifstream input = createInput(argv[1]);
    ofstream output = createOutput(argv[2]);
    csize k = stoi(argv[3]);
    
    const auto vectorSelector = [=] (stringstream &ss) -> double*
    {
        string token;
        double* array = (double*)malloc(d * sizeof(double));
        for (int i = 0; i < d && getline(ss, token, ','); i++)
        {
            array[i] = stod(token);
        }
        return array;
    };
    const auto labelSelector = [=] (stringstream &ss) -> string
    {
        string token;
        getline(ss, token, ',');
        return token;
    };
    
    vector<darray> vectors;
    vector<string> strings;
    for (string line; getline(input, line);)
    {
        stringstream ss(line);
        vectors.push_back(vectorSelector(ss));
        strings.push_back(labelSelector(ss));
    }
    
    srand(time(NULL));    
    write(output, d, vectors, strings, k,  run(d, vectors, k));
    
    input.close();
    output.close();    
    exit(0);
}
