/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }
/*
FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
*/
/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {

    /*since both aren't true, then 1 must be false */
  return ~(~x & ~y);
    /*DeMorgans Law*/
    
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 
 
 * create mask of 1's in the even place.
 * make it a 32 bit word then return.
 
 */

int evenBits(void) {
     int byte = 0x55;
     int word = byte | byte<<8;
     return (word | word<<16);
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 
 */
/*
boolean algebra says !0  = 1*/

int minusOne(void) {
  return ~0;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

/*
   create 32 bit all even bit number 
   then if x has even bits the outcome of the & will be leave 1's in the even place/
   then this is ^ with every even bit to leave online even bits there
   as long as the is 1 even bit it will return 0 else it will return 1.
*/
int allEvenBits(int x) {
  int twoBytes = 0x55 + (0x55 << 8);
  int allEven = twoBytes + (twoBytes << 16);
  return !((x & allEven) ^ allEven);

}

/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 * create 32 bit odd mask
 * x&odd will only be zero if there is not any odd bits set by the number
 * therefore, the fxn return ! if there is odd bit, els
 */

int anyOddBit(int x) {
  int allBits;
  int allOdd =(0xAA << 8) | 0xAA;
  allOdd = allOdd | (allOdd << 16); /* Gives us 1010 1010 1010 1010 1010 1010 1010 1010 */
  allBits = x & allOdd;
  allBits = !(!allBits); /*! is not, if I have 5000 and not it becomes 0, if you not 0 it becomes 1*/
  return allBits;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    /*
    since x,n,m are passed into the fxn, when we shuftt it by num e.g. n<<3 we are a ctually shifting it by 2^3 (3 is         exponent)
      n = n<<3; // n == n*3 bit position 24
  m = m<<3;
   return x^(x&((255 << n)^)(255<<m))) ^ ((((x&(2555b<< n)) >> n)& 255)<< m)^ ((((x(255<<m))>> m)&255)<<n)
    */
    
  int y = 0;
  n = n<<3; // n == n*8 bit position 24
  m = m<<3; //m == n*8
  y = 0xff & ((x>>n) ^ (x>>m)); // 1111 1111
  x = x ^ (y<<n); 
  x = x ^ (y<<m);
  return x;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 	flags |= DIRTY;			set DIRTY bit
	flags &= ~OPEN;			clear OPEN bit 
	flags ^= VERBOSE;		toggle VERBOSE bit
 */
int addOK(int x, int y) {
  int z=x+y;
  int a=x>>31;
  int b=y>>31;
  int c=z>>31;
  return !!(a^b)|(!(a^c)&!(b^c));

}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 if x is true then 1st expression is evaluated and becomes the result and if false, the 2nsd expressions is evaluated and becomes athe result
 (z&mask) | (y&mask) 
 */
int conditional(int x, int y, int z) {
  /* create mask based on x by adding x to a word of all ones
   * this will either make 0x0 if x is 1 or 0xffffffff if x -s 0
   * use mask to select either y or z
   */
  int mask = ~0 + !x;
  return (y & mask) | (z & ~mask);
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /* Shifts bytes left by 4 and compares it with XOR to 0x3, will return 1 if not 0x3 */
    
    int comparer = (x >> 4) ^ 0x3;

    int is0to9 = ((0x0f & x) + 0x6) & 0xf0;  /*checks if 0 to 9 //15 & x + 6 &240, will return 1 if not 0 to 9*/

  return !(comparer | is0to9);  /*ors it and bans it, if either one is false (1) will return 0.*/
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 very similar to swap bytes
 get the byte using mask and replace the same byte with given constant c
 
 */
int replaceByte(int x, int n, int c) {
  int shift = n << 3; /*same as shifting n*8 (2*8=16 bit shift)*/
  int mask4X = x & ~(0xFF << shift); /*shift the mask of 1111 1111 then mask out 8 bits (~1111 1111 = 0000 0000)*/
return mask4X | (c << shift); /* finally, shift the replacement bytes to correct place and replace in mask4X*/
}
/* reverseBits - reverse the bits in a 32-bit integer,
              i.e. b0 swaps with b31, b1 with b30, etc
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 * 4 kinds of swaps for this question
 * swap conseccutive bit using 0x55(1010101) as a mask
 * Swap nibbles using 0x33 (110011) as a mask
 * Swap bytes using 0x0f(1111) as a mask
 * Swap 2-byte long pairs using 0xFF (11111111) as a mask
 */

int reverseBits(int x) {
  unsigned reverse_x = x;

  int mask_08_switch = 0xFF | (0xFF << 16);
  int mask_04_switch = mask_08_switch ^ (mask_08_switch << 4);
  int mask_02_switch = mask_04_switch ^ (mask_04_switch << 2);
  int mask_01_switch = mask_02_switch ^ (mask_02_switch << 1);

  reverse_x = (reverse_x >> 16) | (reverse_x << 16);
  reverse_x = ((reverse_x & ~mask_08_switch) >>  8) | ((reverse_x & mask_08_switch) <<  8);
  reverse_x = ((reverse_x & ~mask_04_switch) >>  4) | ((reverse_x & mask_04_switch) <<  4);
  reverse_x = ((reverse_x & ~mask_02_switch) >>  2) | ((reverse_x & mask_02_switch) <<  2);
  reverse_x = ((reverse_x & ~mask_01_switch) >>  1) | ((reverse_x & mask_01_switch) <<  1);

  return reverse_x;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 * When u add two positive numbers and get a neg number you get a positive overflow
 * the opposite is a negative overflow
 * use XOR
 * 
 */
int satAdd(int x, int y) {
   int xAddY = x + y;

  int negativeOverflow = 0x1 << 31;
  int positiveOverflow = ~negativeOverflow;

  int overflowMask = ((x ^ xAddY) & (y ^ (xAddY))) >> 31;
  int signMask = x >> 31;

  return ((xAddY) & ~overflowMask) | (overflowMask & ((signMask & negativeOverflow) | (~signMask & positiveOverflow)));

}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  return 2;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}
