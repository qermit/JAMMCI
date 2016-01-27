/*
 * fru.c
 *
 *   AFCIPMI  --
 *
 *   Copyright (C) 2015  Piotr Miedzik  <P.Miedzik@gsi.de>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "fru.h"
#include "ipmi.h"

/*
 * fru generated with external tool
 * mainly it says x4 pci-express Gen1
 * without this MCH will not enable FCLK
 */
const char default_fru[136] __attribute__ ((section (".FRU"))) = {
0x01, 0x00, 0x00, 0x01, 0x07, 0x0D, 0x00, 0xEA, 0x01, 0x06, 0x19, 0x00, 0x00, 0x00, 0xC8, 0x43,
0x72, 0x65, 0x6F, 0x74, 0x65, 0x63, 0x68, 0xC3, 0x41, 0x46, 0x43, 0xC9, 0x30, 0x30, 0x30, 0x30,
0x30, 0x30, 0x30, 0x30, 0x31, 0xC5, 0x41, 0x46, 0x43, 0x76, 0x32, 0xC7, 0x43, 0x6F, 0x72, 0x65,
0x46, 0x52, 0x55, 0xC1, 0x00, 0x00, 0x00, 0xAF, 0x01, 0x06, 0x19, 0xC3, 0x47, 0x53, 0x49, 0xC3,
0x41, 0x46, 0x43, 0xC5, 0x30, 0x30, 0x30, 0x30, 0x31, 0xC2, 0x76, 0x33, 0xC5, 0x30, 0x30, 0x30,
0x30, 0x31, 0xC6, 0x4E, 0x6F, 0x20, 0x74, 0x61, 0x67, 0xC7, 0x43, 0x6F, 0x72, 0x65, 0x46, 0x52,
0x55, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF9, 0xC0, 0x02, 0x06, 0x1E, 0x1A, 0x5A, 0x31, 0x00,
0x16, 0x00, 0x41, 0xC0, 0x82, 0x10, 0xBB, 0xF3, 0x5A, 0x31, 0x00, 0x19, 0x00, 0x00, 0x80, 0x01,
0x04, 0x00, 0xF0, 0x00, 0x2F, 0x00, 0x00, 0xFD,
};


// @todo: add support for writing/readint to external memory

void fru_read_to_buffer(char *buff, int offset, int length) {
		int i;
		int j = offset;
		//char *write_buffer = buff;
		//char *read_buffer = default_fru+offset;
		for (i = 0; i<length; i++, j++ ) {
			if (j < sizeof(default_fru)) {
				buff[i] = default_fru[j];
			} else {
				buff[i] = 0xFF;
			}

		}
}

void fru_read_common_header(fru_common_header_t * header) {
	fru_read_to_buffer(header, 0, sizeof(fru_common_header_t));
}