#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// number of bytes in the WAV header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // check for correct number of arguments
    if (argc != 4)
    {
        printf("usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // open input file
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("could not open file.\n");
        return 1;
    }

    // open output file
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        fclose(input);
        printf("could not open file.\n");
        return 1;
    }

    // read scaling factor
    float factor = atof(argv[3]);

    // create a buffer for the header
    uint8_t header[HEADER_SIZE];

    // read the header from the input file
    fread(header, HEADER_SIZE, 1, input);

    // write the header to the output file
    fwrite(header, HEADER_SIZE, 1, output);

    // buffer to hold each sample
    int16_t sample;

    // read samples from input file, scale, and write to output file
    while (fread(&sample, sizeof(int16_t), 1, input) == 1)
    {
        sample = (int16_t) (sample * factor);
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

    // close input and output files
    fclose(input);
    fclose(output);

    return 0;
}
