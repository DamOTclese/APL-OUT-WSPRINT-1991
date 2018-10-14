
    static unsigned char characters[] = {
          0,  0,164,  0, 80, 26, 22,  0,  0,  0,
	160, 58,  0,157, 59, 68,  0,  0,  0,161,
          0, 64,  0, 47, 56, 57, 23, 22, 81, 82,
         72, 73,153, 49,202,200,  5,207,208,154,
         17, 18, 31, 27, 48, 28,151, 20,141,142,
        143,144,145,146,147,148,149,150,155, 19,
         37, 39, 41, 54,201,114,115,116,117,118,
        119,120,121,122,123,124,125,126,127,128,
        129,130,131,132,133,134,135,136,137,138,
        139, 15, 21, 16, 35,  0,220, 87, 88, 89,
         90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
        100,101,102,103,104,105,106,107,108,109,
        110,111,112, 84,198, 83, 55,113,  0,  0,
          0,  0,  0,  0, 42,  0,  0,  0,  0,  0,
          0, 32,  0, 33,  0,113, 29,  0,  0, 66,
          0, 67, 77,  0,  0,  0,  0,  0,220,  0,
          0,  0,  0,  0,  0,  0, 71, 76,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0, 43,  0, 45,166,  0, 70,
         51, 52, 50, 74, 69, 75,156, 63, 44, 60,
        164,140, 40, 38, 78, 79, 30,202, 65, 53,
         36, 46, 61,152, 34,  0
    } ;

#include <stdio.h>
#include <string.h>

void main(void)
{
    FILE *inf;
    int loop2;
    unsigned char byte;
    char found;
    char record[201], ccount;

    inf=fopen("WSPRINT.OUT","rb");
    ccount = 0;

    while (! feof(inf)) {
	byte = fgetc(inf);
	found = 0;

        for (loop2 = 0; found == 0 && loop2 < sizeof(characters); loop2++) {
	    if ((characters[loop2] - 1) == byte) {
		record[ccount++] = loop2;
		record[ccount] = (char)NULL;
		found = 1;

		if (loop2 == 0x0a) {
		    ccount--;
		    record[ccount--] = (char)NULL;
		    record[ccount--] = (char)NULL;

		    while (record[ccount] == ' ') {
			record[ccount--] = (char)NULL;
		    }

		    (void)printf("%s\n", record);
		    ccount = 0;
		}
            }
	}
	if (found == 0) {
	    record[ccount++] = '?';
	    record[ccount] = (char)NULL;
	}
    }

    fcloseall();
}
