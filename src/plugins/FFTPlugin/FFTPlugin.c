/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.1702 uuid: ca289ff1-8bc0-40d7-a4bb-42b583f02dd1
   from
	FFTPlugin VMMaker.oscog-eem.1702 uuid: ca289ff1-8bc0-40d7-a4bb-42b583f02dd1
 */
static char __buildInfo[] = "FFTPlugin VMMaker.oscog-eem.1702 uuid: ca289ff1-8bc0-40d7-a4bb-42b583f02dd1 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
static float * checkedFloatPtrOf(sqInt oop);
static unsigned int * checkedWordPtrOf(sqInt oop);
EXPORT(const char*) getModuleName(void);
static sqInt loadFFTFrom(sqInt fftOop);
static sqInt permuteData(void);
EXPORT(sqInt) primitiveFFTPermuteData(void);
EXPORT(sqInt) primitiveFFTScaleData(void);
EXPORT(sqInt) primitiveFFTTransformData(void);
static sqInt scaleData(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
static sqInt transformData(sqInt forward);
static sqInt transformForward(sqInt forward);


/*** Variables ***/
static sqInt fftSize;
static float * imagData;
static sqInt imagDataSize;

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*booleanValueOf)(sqInt obj);
static sqInt (*failed)(void);
static sqInt (*fetchIntegerofObject)(sqInt fieldIndex, sqInt objectPointer);
static sqInt (*fetchPointerofObject)(sqInt index, sqInt oop);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stSizeOf)(sqInt oop);
static sqInt (*stackObjectValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt booleanValueOf(sqInt obj);
extern sqInt failed(void);
extern sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer);
extern sqInt fetchPointerofObject(sqInt index, sqInt oop);
extern void * firstIndexableField(sqInt oop);
extern sqInt isWords(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stSizeOf(sqInt oop);
extern sqInt stackObjectValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FFTPlugin VMMaker.oscog-eem.1702 (i)"
#else
	"FFTPlugin VMMaker.oscog-eem.1702 (e)"
#endif
;
static sqInt nu;
static unsigned int * permTable;
static sqInt permTableSize;
static float * realData;
static sqInt realDataSize;
static float * sinTable;
static sqInt sinTableSize;



/*	Return the first indexable word of oop which is assumed to be
	variableWordSubclass 
 */

	/* FFTPlugin>>#checkedFloatPtrOf: */
static float *
checkedFloatPtrOf(sqInt oop)
{
	success(isWords(oop));
	if (failed()) {
		return 0;
	}
	return ((float *) (firstIndexableField(oop)));
}


/*	Return the first indexable word of oop which is assumed to be
	variableWordSubclass 
 */

	/* FFTPlugin>>#checkedWordPtrOf: */
static unsigned int *
checkedWordPtrOf(sqInt oop)
{
	success(isWords(oop));
	return ((unsigned int *) (firstIndexableField(oop)));
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* FFTPlugin>>#loadFFTFrom: */
static sqInt
loadFFTFrom(sqInt fftOop)
{
    sqInt oop;

	success((slotSizeOf(fftOop)) >= 6);
	if (failed()) {
		return 0;
	}
	nu = fetchIntegerofObject(0, fftOop);
	fftSize = fetchIntegerofObject(1, fftOop);
	oop = fetchPointerofObject(2, fftOop);
	sinTableSize = stSizeOf(oop);
	/* begin checkedFloatPtrOf: */
	success(isWords(oop));
	if (failed()) {
		sinTable = 0;
		goto l1;
	}
	sinTable = ((float *) (firstIndexableField(oop)));
l1:	/* end checkedFloatPtrOf: */;
	oop = fetchPointerofObject(3, fftOop);
	permTableSize = stSizeOf(oop);
	/* begin checkedWordPtrOf: */
	success(isWords(oop));
	permTable = ((unsigned int *) (firstIndexableField(oop)));
	oop = fetchPointerofObject(4, fftOop);
	realDataSize = stSizeOf(oop);
	/* begin checkedFloatPtrOf: */
	success(isWords(oop));
	if (failed()) {
		realData = 0;
		goto l2;
	}
	realData = ((float *) (firstIndexableField(oop)));
l2:	/* end checkedFloatPtrOf: */;
	oop = fetchPointerofObject(5, fftOop);
	imagDataSize = stSizeOf(oop);
	/* begin checkedFloatPtrOf: */
	success(isWords(oop));
	if (failed()) {
		imagData = 0;
		goto l3;
	}
	imagData = ((float *) (firstIndexableField(oop)));
l3:	/* end checkedFloatPtrOf: */;
	success((((((1L << nu) == fftSize) && (((fftSize / 4) + 1) == sinTableSize)) && (fftSize == realDataSize)) && (fftSize == imagDataSize)) && (realDataSize == imagDataSize));
	return (failed()) == 0;
}

	/* FFTPlugin>>#permuteData */
static sqInt
permuteData(void)
{
    unsigned int a;
    unsigned int b;
    sqInt end;
    sqInt i;
    float  tmp;

	i = 0;
	end = permTableSize;
	while (i < end) {
		a = (permTable[i]) - 1;
		b = (permTable[i + 1]) - 1;
		if (!((a < realDataSize)
			 && (b < realDataSize))) {
			return success(0);
		}
		tmp = realData[a];
		realData[a] = (realData[b]);
		realData[b] = tmp;
		tmp = imagData[a];
		imagData[a] = (imagData[b]);
		imagData[b] = tmp;
		i += 2;
	}
	return 0;
}

	/* FFTPlugin>>#primitiveFFTPermuteData */
EXPORT(sqInt)
primitiveFFTPermuteData(void)
{
    sqInt rcvr;

	rcvr = stackObjectValue(0);
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	permuteData();
	if (failed()) {

		/* permuteData went wrong. Do the permutation again -- this will restore the original order */
		permuteData();
	}
	return 0;
}

	/* FFTPlugin>>#primitiveFFTScaleData */
EXPORT(sqInt)
primitiveFFTScaleData(void)
{
    sqInt rcvr;

	rcvr = stackObjectValue(0);
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	scaleData();
	return 0;
}

	/* FFTPlugin>>#primitiveFFTTransformData */
EXPORT(sqInt)
primitiveFFTTransformData(void)
{
    sqInt fftScale;
    sqInt fftSize2;
    sqInt fftSize4;
    sqInt forward;
    sqInt i;
    sqInt ii;
    float  imagT;
    float  imagU;
    sqInt ip;
    sqInt j;
    sqInt lev;
    sqInt lev1;
    sqInt level;
    sqInt rcvr;
    float  realT;
    float  realU;
    sqInt theta;

	forward = booleanValueOf(stackValue(0));
	rcvr = stackObjectValue(1);
	if (!(loadFFTFrom(rcvr))) {
		return null;
	}
	/* begin transformData: */
	permuteData();
	if (failed()) {

		/* permuteData went wrong. Do the permutation again -- this will restore the original order */
		permuteData();
		goto l1;
	}
	/* begin transformForward: */
	fftSize2 = fftSize / 2;
	fftSize4 = fftSize / 4;
	for (level = 1; level <= nu; level += 1) {
		lev = 1L << level;
		lev1 = lev / 2;
		fftScale = fftSize / lev;
		for (j = 1; j <= lev1; j += 1) {

			/* pi * (j-1) / lev1 mapped onto 0..n/2 */
			theta = (j - 1) * fftScale;
			if (theta < fftSize4) {

				/* Compute U, the complex multiplier for each level */
				realU = sinTable[(sinTableSize - theta) - 1];
				imagU = sinTable[theta];
			}
			else {
				realU = 0.0 - (sinTable[theta - fftSize4]);
				imagU = sinTable[fftSize2 - theta];
			}
			if (!forward) {
				imagU = 0.0 - imagU;
			}
			i = j;
			while (i <= fftSize) {
				ip = (i + lev1) - 1;
				ii = i - 1;
				realT = ((realData[ip]) * realU) - ((imagData[ip]) * imagU);
				imagT = ((realData[ip]) * imagU) + ((imagData[ip]) * realU);
				realData[ip] = ((realData[ii]) - realT);
				imagData[ip] = ((imagData[ii]) - imagT);
				realData[ii] = ((realData[ii]) + realT);
				imagData[ii] = ((imagData[ii]) + imagT);
				i += lev;
			}
		}
	}
	if (!forward) {
		scaleData();
	}
l1:	/* end transformData: */;
	if (!(failed())) {
		pop(1);
	}
	return 0;
}


/*	Scale all elements by 1/n when doing inverse */

	/* FFTPlugin>>#scaleData */
static sqInt
scaleData(void)
{
    sqInt i;
    float  realN;

	if (fftSize <= 1) {
		return null;
	}
	realN = ((float) (1.0 / (((double) fftSize))));
	for (i = 0; i < fftSize; i += 1) {
		realData[i] = ((realData[i]) * realN);
		imagData[i] = ((imagData[i]) * realN);
	}
	return 0;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		booleanValueOf = interpreterProxy->booleanValueOf;
		failed = interpreterProxy->failed;
		fetchIntegerofObject = interpreterProxy->fetchIntegerofObject;
		fetchPointerofObject = interpreterProxy->fetchPointerofObject;
		firstIndexableField = interpreterProxy->firstIndexableField;
		isWords = interpreterProxy->isWords;
		pop = interpreterProxy->pop;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stSizeOf = interpreterProxy->stSizeOf;
		stackObjectValue = interpreterProxy->stackObjectValue;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* FFTPlugin>>#transformData: */
static sqInt
transformData(sqInt forward)
{
    sqInt fftScale;
    sqInt fftSize2;
    sqInt fftSize4;
    sqInt i;
    sqInt ii;
    float  imagT;
    float  imagU;
    sqInt ip;
    sqInt j;
    sqInt lev;
    sqInt lev1;
    sqInt level;
    float  realT;
    float  realU;
    sqInt theta;

	permuteData();
	if (failed()) {

		/* permuteData went wrong. Do the permutation again -- this will restore the original order */
		permuteData();
		return null;
	}
	/* begin transformForward: */
	fftSize2 = fftSize / 2;
	fftSize4 = fftSize / 4;
	for (level = 1; level <= nu; level += 1) {
		lev = 1L << level;
		lev1 = lev / 2;
		fftScale = fftSize / lev;
		for (j = 1; j <= lev1; j += 1) {

			/* pi * (j-1) / lev1 mapped onto 0..n/2 */
			theta = (j - 1) * fftScale;
			if (theta < fftSize4) {

				/* Compute U, the complex multiplier for each level */
				realU = sinTable[(sinTableSize - theta) - 1];
				imagU = sinTable[theta];
			}
			else {
				realU = 0.0 - (sinTable[theta - fftSize4]);
				imagU = sinTable[fftSize2 - theta];
			}
			if (!forward) {
				imagU = 0.0 - imagU;
			}
			i = j;
			while (i <= fftSize) {
				ip = (i + lev1) - 1;
				ii = i - 1;
				realT = ((realData[ip]) * realU) - ((imagData[ip]) * imagU);
				imagT = ((realData[ip]) * imagU) + ((imagData[ip]) * realU);
				realData[ip] = ((realData[ii]) - realT);
				imagData[ip] = ((imagData[ii]) - imagT);
				realData[ii] = ((realData[ii]) + realT);
				imagData[ii] = ((imagData[ii]) + imagT);
				i += lev;
			}
		}
	}
	if (!forward) {
		scaleData();
	}
	return 0;
}

	/* FFTPlugin>>#transformForward: */
static sqInt
transformForward(sqInt forward)
{
    sqInt fftScale;
    sqInt fftSize2;
    sqInt fftSize4;
    sqInt i;
    sqInt ii;
    float  imagT;
    float  imagU;
    sqInt ip;
    sqInt j;
    sqInt lev;
    sqInt lev1;
    sqInt level;
    float  realT;
    float  realU;
    sqInt theta;

	fftSize2 = fftSize / 2;
	fftSize4 = fftSize / 4;
	for (level = 1; level <= nu; level += 1) {
		lev = 1L << level;
		lev1 = lev / 2;
		fftScale = fftSize / lev;
		for (j = 1; j <= lev1; j += 1) {

			/* pi * (j-1) / lev1 mapped onto 0..n/2 */
			theta = (j - 1) * fftScale;
			if (theta < fftSize4) {

				/* Compute U, the complex multiplier for each level */
				realU = sinTable[(sinTableSize - theta) - 1];
				imagU = sinTable[theta];
			}
			else {
				realU = 0.0 - (sinTable[theta - fftSize4]);
				imagU = sinTable[fftSize2 - theta];
			}
			if (!forward) {
				imagU = 0.0 - imagU;
			}
			i = j;
			while (i <= fftSize) {
				ip = (i + lev1) - 1;
				ii = i - 1;
				realT = ((realData[ip]) * realU) - ((imagData[ip]) * imagU);
				imagT = ((realData[ip]) * imagU) + ((imagData[ip]) * realU);
				realData[ip] = ((realData[ii]) - realT);
				imagData[ip] = ((imagData[ii]) - imagT);
				realData[ii] = ((realData[ii]) + realT);
				imagData[ii] = ((imagData[ii]) + imagT);
				i += lev;
			}
		}
	}
	return 0;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "FFTPlugin";
void* FFTPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveFFTPermuteData\000\001", (void*)primitiveFFTPermuteData},
	{(void*)_m, "primitiveFFTScaleData\000\001", (void*)primitiveFFTScaleData},
	{(void*)_m, "primitiveFFTTransformData\000\001", (void*)primitiveFFTTransformData},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveFFTPermuteDataAccessorDepth = 1;
signed char primitiveFFTScaleDataAccessorDepth = 1;
signed char primitiveFFTTransformDataAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
