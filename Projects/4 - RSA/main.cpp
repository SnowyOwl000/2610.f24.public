#include <cstdint>
#include <iostream>
#include <sys/stat.h>

#include "codec64.h"

using namespace std;

//=============================================================================
// bool isPrime(uint64_t n)
//  determine and report if n is prime
//
// Parameter
//  n - number that may or may not be prime
//
// Returns
//  true if n is prime, false if not
//

bool isPrime(uint64_t n) {

    return true;
}

//=============================================================================
// int64_t modInverse(int64_t a,int64_t n)
//  compute and return b such that (a * b) % n == 1
//
// Parameters
//   a - value to find inverse of
//   n - modulus
//
// Returns
//   b such that (a * b) % n == 1, if such a number exists
//   -1 if no such number exists
//

int64_t modInverse(int64_t a,int64_t n) {

    // t = 0, tNew = 1
    // r = n, rNew = a

    // while rNew != 0 {

        // q = r / rNew

        // (t,tNew) = (tNew,t - q*tNew)
        int64_t
            tmp = tNew;
        tNew = t - q * tNew;
        t = tmp;

        // (r,rNew) = (rNew,r - q*rNew)

    // }

    // if r > 1, error

    // if t < 0, then t = t + n

    // return t

    return 0;
}

//=============================================================================
// uint64_t modExp(uint64_t base,uint64_t exp,uint64_t mod)
//  compute (base ** exp) % mod
//
// Parameters
//  base - base to be raised
//  exp  - power to raise base
//  mod  - modulus
//
// Note: This uses a technique called "repeated squaring" to efficiently raise
//       base to a large power quickly, without having to rely on pow()
//

uint64_t modExp(uint64_t base,uint64_t exp,uint64_t m) {

    // ans = 1

    // while exp != 0 {

        // if exp is odd, then ans = (ans * base) % m

        // base = (base * base) % m

        // exp = exp / 2

    // }

    // return ans

    return 0;
}


//=============================================================================
// int64_t getFileSize(char *fn)
//  get the size (in bytes) of the file whose name is given
//
// Parameter
//  fn - name of file about to be encrypted
//
// Returns
//  size of the file, in bytes
//
// Note: stat() is a low-level "system call," a request to interact directly
//       with the OS
//

int64_t getFileSize(char *fn) {
    struct stat
        fs{};

    stat(fn,&fs);

    return fs.st_size;
}

//=============================================================================
// void keyGen()
//  generate a random key pair
//
// Note: writes public key into the file public.key, private key goes in
//       private.key
//

void keyGen() {

    // generate random prime number 4096 <= p < 65536

    // generate another random prime number 4096 <= q < 65536 and p != q

    // calculate n

    // calculate f

    // choose random number 4096 <= e < 65535 such that gcd(e,f) == 1

    // use modInverse to calculate d

    // open public key file

    // make sure open worked

    // write n and e to file

    // close file

    // open private key file

    // make sure open worked

    // write n and d to file

    // close file

}

//=============================================================================
// void encrypt(char *inFileName,char *outFileName,int64_t n,int64_t e)
//  encrypt the given file, place encrypted result in output file
//
// Parameter
//  inFileName  - name of file to be encrypted
//  outFileName - name of file to hold encrypted output
//  n,e         - the public (encryption) key
//

void encrypt(char *inFileName,char *outFileName,int64_t n,int64_t e) {

    // open the input file

    // make sure the open worked

    // prepare codec object for writing

    // get the file size

    // write file size to codec
    codec.put32(fileSize);

    // loop over all bytes in input file, grouped into three-byte chunks

        // read three bytes. don't worry if three bytes aren't available

        // convert bytes into a single number

        // encrypt using modExp

        // send 32-bit encrypted number to codec

    // }

    // close input file

    // tell code we're done

}

//=============================================================================
// void decrypt(char *inFileName,char *outFileName,int64_t n,int64_t d)
//  decrypt the given file, place decrypted result in output file
//
// Parameter
//  inFileName  - name of file to be decrypted
//  outFileName - name of file to hold decrypted output
//  n,d         - the private (decryption) key
//

void decrypt(char *inFileName,char *outFileName,int64_t n,int64_t d) {
    Codec64
        codec;

    // open output file

    // make sure open worked

    // prepare codec for decoding
    codec.beginDecode(inFileName);

    // get file size from codec

    // loop over all bytes in file

        // get 32-bit encrypted value from codec
        cipher = codec.get32();

        // decrypt using modExp
        plain = modExp(cipher,d,n);

        // split decrypted value into three bytes

        // output first byte

        // if necessary, output second byte

        // if necessary, output third byte

    // }

    // close output file

    // tell codec we're done

}

//=============================================================================
// void usage(char *progName)
//  display a proper usage message and stop the program
//
// Parameter
//  progName - name of the program (from main's argv[0])
//

void usage(char *progName) {

    cout << "Usage: " << progName << "-k" << endl
         << "       " << progName << "-e input-file output-file" << endl
         << "       " << progName << "-d input-file output-file" << endl;

    exit(EXIT_FAILURE);
}

//=============================================================================
// int main(int argc,char *argv[])
//  the main function
//
// Parameters
//  argc - number of command-line strings
//  argv - array of command-line strings
//
// Returns
//  0, although usage will call exit(1) if called
//

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
