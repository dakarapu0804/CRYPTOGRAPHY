#include <stdio.h>
#include <math.h>

// Function to calculate modular exponentiation
long long int power(long long int a, long long int b, long long int P) {
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

int main() {
    long long int P, G, x, a, y, b;
    // Publicly shared prime number P and base G
    printf("Enter the value of P (a prime number): ");
    scanf("%lld", &P);
    printf("Enter the value of G (a primitive root modulo P): ");
    scanf("%lld", &G);

    // Private keys of both the parties
    printf("Enter the private key of Alice (a less than P): ");
    scanf("%lld", &a);
    printf("Enter the private key of Bob (b less than P): ");
    scanf("%lld", &b);

    // Calculation of public keys
    x = power(G, a, P); // Alice calculates x = (G^a) mod P
    y = power(G, b, P); // Bob calculates y = (G^b) mod P

    // Shared secret key by both the parties
    long long int ka = power(y, a, P); // Secret key for Alice
    long long int kb = power(x, b, P); // Secret key for Bob

    printf("Secret key for Alice: %lld\n", ka);
    printf("Secret key for Bob: %lld\n", kb);

    return 0;
}

