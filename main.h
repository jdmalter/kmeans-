#ifndef MAIN_H
#define MAIN_H

#include <fstream>


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

void write(ofstream &output, 
        csize d, 
        const vector<darray> &vectors, 
        const vector<string> &strings, 
        csize k, 
        const AssignmentsClusters assignmentsClusters)
{
    const std::vector<int> assignments = assignmentsClusters.assignments;
    const std::vector<double*> clusters = assignmentsClusters.clusters;
    
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
        
        output << "cluster at " << toPrettyString(d, clusters[i]) << " with " << group.size() << " vectors" << endl;
        for (int j = 0; j < group.size(); j++)
        {
            output << toPrettyString(d, vectors[group[j]]) << " " << strings[group[j]] << endl;
        }
        output << endl;
    }
}

#endif /* MAIN_H */
