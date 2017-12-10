#include <array>
#include <ctime>
#include <iostream>
#include <sstream>
#include "main.h"

static constexpr csize d = 4;
static constexpr cu32 iterations = 50;

int main(int argc, char** argv) {
    if (argc != 4)
    {
        cout << "main <input> <output> <means>" << endl;
        exit(1);
    }
    
    ifstream input = createInput(argv[1]);
    ofstream output = createOutput(argv[2]);
    csize k = stoi(argv[3]);
    
    const auto vectorSelector = [=] (stringstream &ss) -> darray<d>
    {
        string token;
        array<double, d>* components = new array<double, d>;
        for (int i = 0; i < d && getline(ss, token, ','); i++)
        {
            (*components)[i] = stod(token);
        }
        darray<d>* pointer = new darray<d>(*components);
        return *pointer;
    };
    const auto labelSelector = [=] (stringstream &ss) -> string
    {
        string token;
        getline(ss, token, ',');
        return token;
    };
    
    vector<darray<d>> vectors;
    vector<string> strings;
    for (string line; getline(input, line);)
    {
        stringstream ss(line);
        vectors.push_back(vectorSelector(ss));
        strings.push_back(labelSelector(ss));
    }
    
    srand(time(NULL));
    vector<darray<d>> clusters = run<d>(vectors, k, iterations);
    write<d>(output, vectors, strings, k, clusters);
    
    input.close();
    output.close();    
    exit(0);
}
