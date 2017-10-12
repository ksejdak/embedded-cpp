////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Kuba Sejdak <kuba.sejdak@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
////////////////////////////////////////////////////////////////////////////////////

#include "stm32f4xx_usart.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Defined in linker script.
extern char heap_min;
extern char heap_max;

static char *heap_end = NULL;

caddr_t _sbrk(intptr_t increment)
{
    if (heap_end == NULL)
        heap_end = &heap_min;

    char *prev_heap_end = heap_end;

    if (heap_end + increment > &heap_max)
        return (caddr_t) NULL;

    heap_end += increment;
    return (caddr_t) prev_heap_end;
}

int _write(int fd, const void *buf, size_t count)
{
    for (int i = 0; i < count; ++i) {
        while (USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET);
        USART_SendData(UART4, ((char *) buf)[i]);
    }

    return count;
}

int _close(int fd)
{
    return -1;
}

int _read(int fd, void *buf, size_t count)
{
    return -1;
}

off_t _lseek(int fd, off_t offset, int whence)
{
    return -1;
}

void _exit(int status)
{
    while (1);
}

int _fstat(int fd, struct stat *buf)
{
    return 0;
}

int _isatty(int fd)
{
    return 1;
}
