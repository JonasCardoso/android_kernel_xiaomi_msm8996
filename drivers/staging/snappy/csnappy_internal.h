/*
Copyright 2011 Google Inc. All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

    * Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the
distribution.
    * Neither the name of Google Inc. nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Various stubs for the open-source version of Snappy.

File modified for the Linux Kernel by
Zeev Tarantov <zeev.tarantov <at> gmail.com>
*/

#ifndef CSNAPPY_INTERNAL_H_
#define CSNAPPY_INTERNAL_H_

#ifndef __KERNEL__
#include "csnappy_internal_userspace.h"
#else

#include <linux/types.h>
#include <linux/string.h>
#include <linux/compiler.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>

#ifdef DEBUG
#define DCHECK(cond)	if (!(cond)) \
			printk(KERN_DEBUG "assert failed @ %s:%i\n", \
				__FILE__, __LINE__)
#else
#define DCHECK(cond)
#endif

#define UNALIGNED_LOAD16(_p)		get_unaligned((const uint16_t *)(_p))
#define UNALIGNED_LOAD32(_p)		get_unaligned((const uint32_t *)(_p))
#define UNALIGNED_LOAD64(_p)		get_unaligned((const uint64_t *)(_p))
#define UNALIGNED_STORE16(_p, _val)	put_unaligned((_val), (uint16_t *)(_p))
#define UNALIGNED_STORE32(_p, _val)	put_unaligned((_val), (uint32_t *)(_p))
#define UNALIGNED_STORE64(_p, _val)	put_unaligned((_val), (uint64_t *)(_p))

#define FindLSBSetNonZero(n)		__builtin_ctz(n)
#define FindLSBSetNonZero64(n)		__builtin_ctzll(n)

#endif /* __KERNEL__ */

#define DCHECK_EQ(a, b)	DCHECK(((a) == (b)))
#define DCHECK_NE(a, b)	DCHECK(((a) != (b)))
#define DCHECK_GT(a, b)	DCHECK(((a) >  (b)))
#define DCHECK_GE(a, b)	DCHECK(((a) >= (b)))
#define DCHECK_LT(a, b)	DCHECK(((a) <  (b)))
#define DCHECK_LE(a, b)	DCHECK(((a) <= (b)))

enum {
	LITERAL = 0,
	COPY_1_BYTE_OFFSET = 1,  /* 3 bit length + 3 bits of offset in opcode */
	COPY_2_BYTE_OFFSET = 2,
	COPY_4_BYTE_OFFSET = 3
};

#endif  /* CSNAPPY_INTERNAL_H_ */

