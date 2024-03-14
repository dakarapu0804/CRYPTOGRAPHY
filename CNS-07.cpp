#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to find the greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to generate keys
void generateKeys(int p, int q, int *publicKey, int *privateKey, int *n) {
    int phi = (p - 1) * (q - 1);
    *n = p * q;

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }

    *publicKey = e;

    // Calculate d, the modular multiplicative inverse of e modulo phi
    int d, k = 1;
    while (1) {
        if ((k * phi + 1) % e == 0) {
            d = (k * phi + 1) / e;
            break;
        }
        k++;
    }
    *privateKey = d;
}

// Function to encrypt
long long encrypt(int plaintext, int publicKey, int n) {
    long long ciphertext = modExp(plaintext, publicKey, n);
    return ciphertext;
}

// Function to decrypt
long long decrypt(long long ciphertext, int privateKey, int n) {
    long long plaintext = modExp(ciphertext, privateKey, n);
    return plaintext;
}

int main() {
    int p, q, publicKey, privateKey, n;
    int plaintext;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    printf("Enter plaintext to encrypt: ");
    scanf("%d", &plaintext);

    generateKeys(p, q, &publicKey, &privateKey, &n);

    long long encryptText = encrypt(plaintext, publicKey, n);
    printf("Encrypted Message: %lld\n", encryptText);

    long long decryptText = decrypt(encryptText, privateKey, n);
    printf("Decrypted Message: %lld\n", decryptText);

    return 0;
}

