#include "sortingalgorithm.hpp"
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace SortLibrary;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Uso: " << argv[0] << " <dimensione_vettore>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    vector<int> v(n);

    srand(time(nullptr)); //riempio il vettore con valori casuali
    for (int& elem : v)
    {
        elem = rand() % 10000;
    }

    vector<int> v2 = v; //copio il vettore affinchè i 2 algoritmi lavorino sullo stesso vettore

    auto start_bubble = high_resolution_clock::now(); //cronometro BubbleSort
    BubbleSort(v);
    auto stop_bubble = high_resolution_clock::now();
    auto duration_bubble = duration_cast<microseconds>(stop_bubble - start_bubble);

    auto start_merge = high_resolution_clock::now(); //cronometro MergeSort
    MergeSort(v2);
    auto stop_merge = high_resolution_clock::now();
    auto duration_merge = duration_cast<microseconds>(stop_merge - start_merge);

    cout << "Tempo di esecuzione BubbleSort: " << duration_bubble.count() << " microsecondi" << endl;
    cout << "Tempo di esecuzione MergeSort: " << duration_merge.count() << " microsecondi" << endl;

    return 0;
}


