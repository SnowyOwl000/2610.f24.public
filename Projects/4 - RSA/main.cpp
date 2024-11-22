#include <cstdint>
#include <iostream>

using namespace std;

bool isPrime(uint64_t n) {

    return true;
}

int64_t modInverse(int64_t a,int64_t n) {


    return 0;
}

uint64_t modExp(uint64_t base,uint64_t exp,uint64_t mod) {


    return 0;
}

void keyGen() {

}

void encrypt(char *inFileName,char *outFileName,int64_t n,int64_t e) {

}

void decrypt(char *inFileName,char *outFileName,int64_t n,int64_t d) {

}

void usage(char *progName) {

    cout << "Usage: " << progName << "-k" << endl
         << "       " << progName << "-e input-file output-file" << endl
         << "       " << progName << "-d input-file output-file" << endl;

    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]) {
    // some variables

    // make sure argc is at least 2
    if (argc == 1)
        usage(argv[0]);

    // make sure argv[1][0] is a -

    // if argv[1][1] == k, do... {
        // make sure argv[1][2] == 0

        // make sure argc == 2

        // call keygen()
    // }

    // else if argv[1][1] == e, do... {
        // make sure argv[1][2] == 0

        // make sure argc == 4

        // read n and e from public.key

        // call encrypt(argv[2],argv[3],n,e)
    // }

    // else if argv[1][1] == d, do... {
        // make sure argv[1][2] == 0

        // make sure argc == 4

        // read n and d from private.key

        // call decrypt(argv[2],argv[3],n,d)
    // }

    // else display an error message

    return 0;
}
