#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    int count = 0;
    char filename[8];
    FILE *img = NULL;
    // while there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close the last file if it is open
    if (img != NULL)
    {
        fclose(img);
    }

    // Close the memory card file
    fclose(card);
}
