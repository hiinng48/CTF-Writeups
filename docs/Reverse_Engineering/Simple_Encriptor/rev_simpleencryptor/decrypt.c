#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main() {
    // Read the encrypted file
    FILE *file = fopen("flag.enc", "rb"); 
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    uint8_t *file_content = malloc(file_size);
    fread(file_content, 1, file_size, file);
    fclose(file);

    srand(1655780698); // Seed the random number generator with the known seed

    // Decrypt the file
    for (int i = 4; i < file_size; i++) {
        int random_value = rand(), shift_amount = rand() & 7;
        file_content[i] = (file_content[i] >> shift_amount) | (file_content[i] << (8 - shift_amount)); // Reverse bitwise rotation
        file_content[i] ^= (uint8_t)random_value; // XOR operation with the same random value
    }

    FILE *output_file = fopen("flag.txt", "wb");

    fwrite(file_content + 4, 1, file_size - 4, output_file); // Print the decrypted content into flag.txt
    fclose(output_file);
    free(file_content);

    return 0;
}