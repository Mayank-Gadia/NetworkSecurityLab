#include <stdio.h>
#include <stdlib.h>

long int P, alpha;

// Function to calculate modular exponentiation (base^exp % modulus)
long long mod_exp(long long base, long long exponent, long long mod) {
    long long result = 1;
    for (long long i = 0; i < exponent; i++) {
        result = (result * base) % mod;
    }
    return result;
}
// Function to perform Diffie-Hellman Key Exchange
void diffie_hellman(long int private_key,long int *public_key, long int alpha, long int P) 
{
	*public_key = mod_exp(alpha, private_key, P);
}

int main() 
{
	printf("\nEnter a prime number:");
	scanf("%ld", &P);
	
	printf("\nEnter the primitive root of the prime number:");
	scanf("%ld", &alpha);	
	
	long int private_key_client, private_key_server;
	long int public_key_client, public_key_server;
	long int shared_secret_client, shared_secret_server;
	
	// Generate private keys for client and server
	printf("\nEnter the private key of client:");
	scanf("%ld",&private_key_client);
	
	printf("\nEnter the private key of server:");
	scanf("%ld",&private_key_server);
	
	// Perform Diffie-Hellman Key Exchange for client
	diffie_hellman(private_key_client, &public_key_client, alpha, P);
	printf("\nClient public key: %ld\n", public_key_client);
	
	// Perform Diffie-Hellman Key Exchange for server
	diffie_hellman(private_key_server, &public_key_server, alpha, P);
	printf("\nServer public key: %ld\n", public_key_server);
	
	// Calculate shared secrets
	shared_secret_client = mod_exp(public_key_server, private_key_client, P);
	shared_secret_server = mod_exp(public_key_client, private_key_server, P);
	
	// Print shared secrets
	printf("\nClient shared secret: %ld\n", shared_secret_client);
	printf("Server shared secret: %ld\n", shared_secret_server);
	
	return 0;
}
