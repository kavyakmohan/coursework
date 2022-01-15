#include <cstdlib> // atoi, exit, EXIT_FAILURE
#include <iostream> // cout
#include "primes.cpp" // isPrime
#include "fibs.cpp" // isFib

using namespace std;

/* isFibPrime: check if a number is a Fibonacci prime
 * parameters: an integer, n
 * return value: true, if n is both prime and a Fibonacci
 *               false, otherwise
 */
bool isFibPrime(int n) {
    return (isPrime(n) and isFib(n));
}

int main(int argc, char *argv[]) {
    int n, i;

    // check the cmd args
    if (argc != 2) {
        cout << "Must enter one integers as the argument!" << endl;
        exit(EXIT_FAILURE);
    }

    // grab the cmd arg and stuff it in the variable n
    n = atoi(argv[1]);

    // find all the Fibonacci primes between 1 and n
    cout << "Here are the Fibonacci primes between 1 and " << n << endl;

    // iterate over each number 2 thru n
    // and call isFibPrime to check
    for (i = 2; i <= n; i++) {
        if (isFibPrime(i)) {
            // print it out if it checks true
            cout << i << " ";
        }
    }

    cout << endl;
    
    return 0;
}
