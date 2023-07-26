#include <stdio.h>
#include <string.h>

void encryptDecrypt(char *input, char *output) {
	char key[] = {'K','E','Y'}; //Can be any chars, and any size array
	
	int i;
	for(i = 0; i < strlen(input); i++) {
		output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];
	}
}

int main (int argc, char *argv[]) {
	char baseStr[10];
	printf("input phrase:");
	scanf("%s", &baseStr);

	char encrypted[strlen(baseStr)];
	encryptDecrypt(baseStr, encrypted);
	printf("Encrypted:%s\n", encrypted);
	
	char decrypted[strlen(baseStr)];
	encryptDecrypt(encrypted, decrypted);
	printf("Decrypted:%s\n", decrypted);
}
