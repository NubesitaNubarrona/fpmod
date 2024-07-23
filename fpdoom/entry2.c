#include "common.h"
#include "cmd_def.h"
#include "usbio.h"
#include "syscode.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if LIBC_SDIO
#include "sdio.h"
#include "microfat.h"
#include "fatfile.h"
#endif

void _debug_msg(const char *msg);
void _malloc_init(void *addr, size_t size);
void _stdio_init(void);
int _argv_init(char ***argvp, int skip);
int _argv_copy(char ***argvp, int argc, char *src);

int main(int argc, char **argv);

#ifdef CXX_SUPPORT
#include "cxx_init.h"
#endif

void entry_main2(char *image_addr, uint32_t image_size, uint32_t bss_size, int arg_skip) {
	int argc; char **argv = NULL;
	uint32_t fw_addr = (uint32_t)image_addr & 0xf0000000;
	uint32_t ram_addr = fw_addr + 0x04000000;
	uint32_t ram_size = MEM4(ram_addr);

	memset(image_addr + image_size, 0, bss_size);

#if !CHIP
	if (fw_addr == 0x30000000) {
		uint32_t t0 = MEM4(0x205003fc);
		_chip = (int32_t)(t0 << 15) < 0 ? 2 : 3;
		chip_fn[0] = chip_fn[1];
	} else _chip = 1;
#if LIBC_SDIO < 3
	usb_init_base();
#endif
#endif

#if LIBC_SDIO < 3
	// usb_init();
	_debug_msg("entry2");
#endif
	{
		char *addr = image_addr + image_size + bss_size;
		size_t size = ram_addr + ram_size - (uint32_t)addr;
		char *p;
#if INIT_MMU
		size -= 0x4000; // MMU table
#endif
#if LIBC_SDIO
		size -= 1024;
#endif
		p = addr + size;
#if LIBC_SDIO
		p -= sizeof(fatdata_t);
		memcpy(&fatdata_glob, p, sizeof(fatdata_t));
		p -= sizeof(unsigned);
		sdio_shl = *(unsigned*)p;
#endif
		// load sys_data
		p -= sizeof(sys_data);
		memcpy(&sys_data, p, sizeof(sys_data));
		_malloc_init(addr, size);
	}
	_stdio_init();
#if CHIPRAM_ARGS || LIBC_SDIO >= 3
	(void)arg_skip;
	{
		char *p = (char*)CHIPRAM_ADDR;
		argc = _argv_copy(&argv, *(short*)p, p + sizeof(short));
	}
#else
	argc = _argv_init(&argv, arg_skip);
#endif
#ifdef CXX_SUPPORT
	cxx_init(argc, argv);
#endif
	exit(main(argc, argv));
}

