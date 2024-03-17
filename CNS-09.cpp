#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate power
long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

int main()
{
    long long int P, G, a, b, A, B, secretKeyA, secretKeyB;

    // Publicly known prime number and primitive root
    printf("Enter the value of prime number (P): ");
    scanf("%lld", &P);
    printf("Enter the value of primitive root of %lld (G): ", P);
    scanf("%lld", &G);

    // Private keys for both parties
    printf("Enter the private key for Alice (a): ");
    scanf("%lld", &a);
    printf("Enter the private key for Bob (b): ");
    scanf("%lld", &b);

    // Calculation of public keys
    A = power(G, a, P);
    B = power(G, b, P);

    // Secret key calculation
    secretKeyA = power(B, a, P);
    secretKeyB = power(A, b, P);

    printf("Secret key for Alice: %lld\n", secretKeyA);
    printf("Secret key for Bob: %lld\n", secretKeyB);

    return 0;
}

