#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    // una mappa è una sequenza chiave-valore
    map<string, int> mappa;
    mappa["Gabry"] = 100;
    mappa["Giovanni"] = 89;
    mappa["Melo"] = 59;

    map<string, int>::iterator itr;
    for (itr = mappa.begin(); itr != mappa.end(); itr++)
    {
        // (*itr) prendo il primo valore
        cout << "Chiave [" << (*itr).first << "] "
             << " Valore [" << (*itr).second << "] " << endl;
    }
}
