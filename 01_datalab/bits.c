/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 김남윤 2020030819
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~(x & ~ y) & (~(~x&y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 * tmin : 100...000
 */
int tmin(void) {
  int min = 0x01;
  min <<= 31;
  return min;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 *  tmax : 01111111111
 *  shift 못 씀
 */
int isTmax(int x) {
  // Tmax는 0111111111.11111 
  int test = 0x7fffffff; // tmax 값
  return !(test^x); // 011111111.. 비교 >> Tmax
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 * test : 1010 .... 1010
 * x와 test의 xor 이후 0000, 0001, 0101, 0100 등의 형태만 남고, 이를 다시 test와 &연산을 진행했을 때
 * >> 0이 나오면 모든 Oddbit가 1임
 */
int allOddBits(int x) {
  int test = 0xAAAAAAAA;
  
  return !((test^x) & test);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x + 1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 *  0x30 == 0001 1110
 *  0x39 == 0010 0111
 *  0x30과 0x3a 의 minus 값을 정해 놓고 x 더해서 음수 나오나 안나오나로 검사
 *  
 */
int isAsciiDigit(int x) {
  
  int lowertest = (~0x30 + 1) + x;
  int uppertest = (~0x3a + 1) + x;

  // lower가 양수, upper 가 음수 일 때 return 1
  return (!(lowertest >> 31)) & (uppertest >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 * x가 0이 아닌 숫자 일 때 전부 111111..11111
 * test = 0 인 경우 ~test + 1 : >>> 00000 (overflow)
 * test = 1인 경우 : ~test + 1: >>> 1111...
 */
int conditional(int x, int y, int z) {
  int test = !!x ; // x 를 0이나 1으로 바꿈
  
  return ((~test + 1) & y) | (~(~test + 1) & z); 
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 * y - x 값 작업 실행후 그 결과 보고 진행
 * // test가 양수 일 경우,  return 1 else, return 0 >> tmax, tmin의 문제
 * x가 음수, y가 양수가 되면 무조건 통과하게 설정 >> test2
 * x가 양수. y가 음수가 되면 무조건 불통과
 * 
 */
int isLessOrEqual(int x, int y) {
  
  int test = y + (~x + 1);
  int test2 = ((x>>31) & !(y>>31)); // x는 음수 y는 양수
  int test3 = ((y>>31) & !(x>>31)); // x는 양수, y는 음수
  
  return ((test2 | (!(test>>31))) & !test3);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 *  0은 1 나머지는 전부 0
 *   
 */
int logicalNeg(int x) {
  int test = x>>31; // 음수 거르기, 음수면 0xff.ffff, 양수인 경우, 0일 경우에는 0
  int test2 = ((~x + 1) >> 31);  // - x가 음수인지 확인해서 거름 양수면 0xffff...ffff, 음수거나  0이면 0
  int test3 = test | test2; // 
  // 0이 아닌 경우 test | test2 >> 0xffffffff >> 1을 더해주면 0
  // 0인 경우 test | test2 >> 0 >> 1 더해주면 1
  // XOR 0x01로 처리
  // right shift 할 때 부호 유지됨
  return (test3 + 1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  
  return 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 *   // 
 *   1 - 8 - 23
 *   주어진 uf에다가 곱하기 2를 진행함
 *  exponent 값을 1 올리자
 */
unsigned floatScale2(unsigned uf) {
  // NaN인지 검사 exp = 11111.1111 일 때 , frac != 000.00000
  int i = 0;
  unsigned test = uf << 1;
  while(i < 8) {
    if(!!(test & 0x80000000U)) { // 1인 경우
      i++;
      test <<= 1;
      continue;
    }
    break;
  }
  // while에서 안 걸렸으면 exp =1111.11....111
  
  
  if(i == 8) return uf; // exp 1111 >> return uf

  // 뽑기
  unsigned sign = uf & 0x80000000U; // 1000.000........0
  unsigned signif = (uf << 9); // significand가 0인지 체크 필요
  unsigned exp = (uf >> 23) & 0x000000ffU; // exp만 살리고 다 죽임 (밑으로 내림)
  
  if(!signif && !exp) // significand와 exp가 둘다 0인 경우
    return uf;
  else if(!exp)  {// exp가 0인 경우, 매우 작은 수 일 때 
    return (sign | (uf << 1)); // uf에 2를 곱한 값(left shift) + sign 유지
  }
  // 그냥 보통의 경우
  else {
    exp += 1;
    return (uf & 0x807fffffU) | (exp << 23);
  }


  /*
  if(signif | exp) exp += 1; // 곱해주는 것이므로 exp에 1을 더해줌 (0인 경우에는 더하지 않음)
  exp <<= 23; // 다시 제자리로 돌림
  unsigned test2 = uf & 0x80001fffU; // sign , significand만 살림
  */


}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
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
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
