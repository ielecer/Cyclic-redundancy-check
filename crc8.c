#include <stdio.h>
#include <stdlib.h>
const unsigned char CRC8_POLY = 0x31; // 1_0011_0001

unsigned char getCRC(unsigned char message[], unsigned char length) {
	unsigned char crc = 0;

	for (unsigned char i = 0; i < length; i++) {
		if (i == 0) {
			crc = message[0];
		}

		for (unsigned char j = 0; j < 8; j++) {
			if (crc & 0x80) {
				crc <<= 1;
				if (i != (length -1)) {
					crc ^= ((message[i + 1] & (0x80 >> j)) >> (7 - j));
				}
				crc ^= CRC8_POLY;
			} else {
				crc <<= 1;
				if (i != (length -1)) {
					crc ^= ((message[i + 1] & (0x80 >> j)) >> (7 - j));
				}
			}
		}
	}
	return crc;
}

int main(int argc, char ** argv) {
	unsigned char message[argc];

	// printf("argc = %d\n", argc);
	// for (char i = 0; i < argc; i++) {
	// 		printf("%s\n", argv[i]);
	// }

	for (unsigned char i = 0; i < argc - 1; i++) {
		message[i] = *argv[i + 1];
	}
	// message[argc - 1] = 0x00;

	message[argc - 1] = getCRC(message, argc - 1);

	for (unsigned char i = 0; i < argc; i ++) {
		printf("0x%02x	", message[i]);
	}
	printf("\n");
}
