/*
C99 and compiler-specific annotations for functions and variables -- Philip Conrad 1/3/2012 -- New BSD License
License Text:
Copyright 2010 Philip Conrad. All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of Philip Conrad nor the names of any
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

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
*/

/* ----- MSVC Loadout ----------------------------------------------------------- */
#if defined(_MSC_VER) && (_MSC_VER >= 1600) /* should work on MSVC 2010 or better */

/* ----- FUNCTION ANNOTATIONS ----- */

/* 'fconst' (specifically, the GCC const attribute) has no meaning to MSVC. */
#define fconst

/* 'pure' has no meaning to MSVC. */
#define pure

/* 'frestrict' is 'restrict', but for functions. */
#define frestrict __declspec( restrict )

/* 'noalias' means that a function call does not modify or reference visible global state and only modifies the 
memory pointed to directly by pointer parameters (first-level indirections). */
#define noalias __declspec( noalias )

/* 'inline' works similarly to the C++ equivalent. */
#define inline __inline

/* 'forcedinline' forces inlining in almost all circumstances, regardless of whether the compiler likes it or not.
   use with great care. */
#define forceinline __forceinline

/* 'noinline' in MSVC++ tells the compiler to never inline a particular member function (function in a class). 
   otherwise, it should do no harm. */
#define noinline __declspec(noinline)

/*'naked' prevents codegen from outputting prolog/epilog code. this lets you handle the prolog/epilog with inline ASM. 
   Note: this can only be used at the function definition site; it can't be used in prototypes. */
#define naked __declspec( naked )

/* 'hot' has no meaning to MSVC. */
#define hot

/* 'cold' has no meaning to MSVC. */
#define cold

/* ----- VARIABLE ANNOTATIONS ----- */

/* 'restrict' for variables. */
#define restrict __restrict



/* ----- GCC Loadout ----------------------------------------------------------- */
#elif defined(__GUNC__) &&  (__GNUC__ >= 3) /* we need greater than GCC ver. 

/* ----- FUNCTION ANNOTATIONS ----- */

/* 'fconst' is similar to 'pure', except that the function is restricted from reading global memory. */
#define fconst __attribute__((const))

/* 'pure' assures the compiler that the function has no side-effects. */
#define pure __attribute__((pure))

/* 'frestrict' works as expected for functions in GCC. */
#define frestrict __restrict__

/* 'noalias' in MSVC is very close in meaning to the "malloc" attribute in GCC. */
#define noalias __attribute__((malloc))

/* 'inline' for functions. */
#define inline __inline__

/* 'forceinline' uses the "always_inline" attribute in GCC. if 'flatten' is on, it will force inlining 
   further than usual. turn on 'flatten' only if you know what you are doing. */
#define forceinline __attribute__((always_inline)) /* __attribute__((flatten)) */

/* 'noinline' prevents inlining. */
#define noinline __attribute__((noinline))

/* 'naked' forces GCC to not generate prolog/epilog code on ARM, AVR, MCORE, RX and SPU. use with caution. */
#define naked __attribute__((naked))

/* 'hot' tells GCC to heavily optimize the function, as it is a hotspot. it may also cause the 
function's generated code to be relocated to a quick-access zone of the executable. */
#define hot __attribute__((hot))

/* 'cold' tells GCC that the function is unlikely to be executed. it may also cause the function's 
   generated code to be relocated to the "cold-code" portion of the executable. */
#define cold __attribute__((cold))

/* ----- VARIABLE ANNOTATIONS ----- */

/* 'restrict' works for both variables and functions in GCC. */
#define restrict __restrict__



/* ----- NULL Loadout (for everybody else) ------------------------------------- */
#else

/* ----- FUNCTION ANNOTATIONS ----- */

#define fconst

#define pure

#define frestrict

#define noalias

#define inline

#define forceinline

#define noinline

#define naked

#define hot

#define cold

/* ----- VARIABLE ANNOTATIONS ----- */

#define restrict



#endif