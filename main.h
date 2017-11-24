#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include <vector>

#include "darray.h"

using namespace std;

ifstream createInput(const char* s)
{
    ifstream input;
    input.open(s);
    if (!input)
    {
        cout << "Must be able to read from " << s << endl;
        exit(1);
    }
    return input;
}

ofstream createOutput(const char* s)
{
    ofstream output;
    output.open(s);
    if (!output)
    {
        cout << "Must be able to write to " << s << endl;
        exit(1);
    }
    return output;
}

template<csize d>
void write(ofstream &output, 
        const vector<darray<d>> &vectors, 
        const vector<string> &strings, 
        csize k, 
        const AssignmentsClusters<d> assignmentsClusters)
{
    const vector<int> assignments = assignmentsClusters.assignments;
    const vector<darray<d>> clusters = assignmentsClusters.clusters;
    
    for (int i = 0; i < k; i++)
    {
        vector<int> group;
        for (int j = 0; j < assignments.size(); j++)
        {
            if (i == assignments[j])
            {
                group.push_back(j);
            }
        }
        
        string clusterString(begin(clusters[i]), end(clusters[i]));
        output << "cluster at " << clusterString << " with " << group.size() << " vectors" << endl;
        for (int j = 0; j < group.size(); j++)
        {
            string vectorString(begin(vectors[group[j]]), end(vectors[group[j]]));
            output << vectorString << " " << strings[group[j]] << endl;
        }
        output << endl;
    }
}

#endif /* MAIN_H */
