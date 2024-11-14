#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    char
      rawMetar[128],
      *start,
      *end;
    string
      item;				// one METAR item
    vector<string>
      itemList;				// list of METAR items
    int
      metarLen;				// length of raw METAR string

    cout << "Enter METAR string: ";
    cin.getline(rawMetar,128);

    //  cout << '[' << rawMetar << ']' << endl;

    // extract all items from the raw string
    metarLen = strlen(rawMetar);

    // loop until start reaches end of string
    for (start=rawMetar;start-rawMetar < metarLen;) {
        // find the start of the item
        for (;start-rawMetar < metarLen && isspace(*start);start++);

        // if we reach end of string, stop loop
        if (start-rawMetar == metarLen)
            break;

        // find the end of the item
        for (end=start+1;end-rawMetar < metarLen && !isspace(*end);end++);

        // copy from raw string into "item"
        for (item="";start<end;start++)
            item += *start;

        // add item to list
        itemList.push_back(item);
    }

    for (int i=0;i<itemList.size();i++)
        cout << '[' << itemList[i] << ']' << endl;

    return 0;
}
