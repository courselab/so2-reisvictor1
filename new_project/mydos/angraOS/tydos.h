/*
 *    SPDX-FileCopyrightText: 2024 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2024 reisvictor1 <reisvictor448@gmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative work from SYSeg (https://gitlab.com/monaco/syseg)
 *  and contains modifications carried out by the following author(s):
 *  reisvictor1 <reisvictor448@gmail.com>
 */

/* Library libtydos.a should be statically linked against user programs meant 
   for running on TyDOS. It provides some custom C functions that invoke system 
   calls for trivial tasks. 

   This is the header file that should be included in the user programs. */



#ifndef TYDOS_H
#define TYDOS_H

/* Syscall numbers. */

#define SYS_INVALID 0
#define SYS_EXIT    1
#define SYS_WRITE   2

void puts(const char* str);	/* Outputs 'str' on the screen. */

#endif  /* TYDOS_H  */
