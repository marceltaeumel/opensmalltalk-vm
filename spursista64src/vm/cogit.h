/* Automatically generated by
	CCodeGenerator VMMaker.oscog-eem.2925 uuid: bc30e1c2-363b-4238-ac06-0fc4bc0cfa96
 */


/*** Function Prototypes ***/


#if !PRODUCTION && defined(PlatformNoDbgRegParms)
# define NoDbgRegParms PlatformNoDbgRegParms
#endif

#if !defined(NoDbgRegParms)
# define NoDbgRegParms /*empty*/
#endif



#if !defined(NeverInline)
# define NeverInline /*empty*/
#endif

extern sqInt abortOffset(void);
extern void addCogMethodsToHeapMap(void);
extern sqInt bytecodePCForstartBcpcin(sqInt mcpc, sqInt startbcpc, CogBlockMethod *cogMethod);
extern void callCogCodePopReceiver(void);
extern void callCogCodePopReceiverAndClassRegs(void);
extern sqInt ceCPICMissreceiver(CogMethod *cPIC, sqInt receiver);
extern void ceFree(void *pointer);
extern void* ceMalloc(size_t size);
extern sqInt ceSICMiss(sqInt receiver);
extern void checkAssertsEnabledInCogit(void);
extern sqInt checkIntegrityOfObjectReferencesInCode(sqInt gcModes);
extern char * codeEntryFor(char *address);
extern char * codeEntryNameFor(char *address);
extern sqInt cogCodeBase(void);
extern sqInt cogCodeConstituents(sqInt withDetails);
extern CogMethod * cogFullBlockMethodnumCopied(sqInt aMethodObj, sqInt numCopied);
extern void cogitPostGCAction(sqInt gcMode);
extern sqInt cogMethodDoesntLookKosher(CogMethod *cogMethod);
extern CogMethod * cogMNUPICSelectorreceivermethodOperandnumArgs(sqInt selector, sqInt rcvr, sqInt methodOperand, sqInt numArgs);
extern CogMethod * cogselector(sqInt aMethodObj, sqInt aSelectorOop);
extern void compactCogCompiledCode(void);
extern void enterCogCodePopReceiver(void);
extern CogBlockMethod * findMethodForStartBcpcinHomeMethod(sqInt startbcpc, CogMethod *cogMethod);
extern void followForwardedLiteralsIn(CogMethod *cogMethod);
extern void followForwardedMethods(void);
extern void followMovableLiteralsAndUpdateYoungReferrers(void);
extern void freeUnmarkedMachineCode(void);
extern sqInt isPCWithinMethodZone(void *address);
extern sqInt isSendReturnPC(sqInt retpc);
extern void linkSendAtintooffsetreceiver(sqInt callSiteReturnAddress, CogMethod *sendingMethod, CogMethod *targetMethod, sqInt theEntryOffset, sqInt receiver);
extern void mapObjectReferencesInMachineCode(sqInt gcMode);
extern void markAndTraceMachineCodeOfMarkedMethods(void);
extern void markMethodAndReferents(CogBlockMethod *aCogMethod);
extern usqInt maxCogMethodAddress(void);
extern usqInt mcPCForBackwardBranchstartBcpcin(sqInt bcpc, sqInt startbcpc, CogBlockMethod *cogMethod);
extern usqInt minCogMethodAddress(void);
extern sqInt mnuOffset(void);
extern sqInt patchToOpenPICFornumArgsreceiver(sqInt selector, sqInt numArgs, sqInt receiver);
extern void printCogMethodFor(void *address);
extern void printTrampolineTable(void);
extern sqInt recordPrimTraceFunc(void);
extern void setBreakMethod(sqInt anObj);
extern void setPostCompileHook(void (*aFunction)(CogMethod *));
extern void setSelectorOfto(CogMethod *cogMethod, sqInt aSelectorOop);
extern sqInt traceLinkedSendOffset(void);
extern void unlinkAllSends(void);
extern void unlinkSendsLinkedForInvalidClasses(void);
extern void unlinkSendsOfisMNUSelector(sqInt selector, sqInt isMNUSelector);
extern void unlinkSendsToFree(void);
extern void unlinkSendsToMachineCodePrimitiveMethodsAndFreeIf(sqInt freeIfTrue);
extern void unlinkSendsToandFreeIf(sqInt targetMethodObject, sqInt freeIfTrue);
extern void addAllToYoungReferrers(void);
extern CogMethod * cogMethodContaining(usqInt mcpc);
extern void freeMethod(CogMethod *cogMethod);
extern sqInt kosherYoungReferrers(void);
extern CogMethod * methodFor(void *address);
extern sqInt methodsCompiledToMachineCodeInto(sqInt arrayObj);
extern sqInt numMethods(void);
extern sqInt numMethodsOfType(sqInt cogMethodType);
extern void printCogMethods(void);
extern void printCogMethodsOfType(sqInt cmType);
extern void printCogMethodsWithMethod(sqInt methodOop);
extern void printCogMethodsWithPrimitive(sqInt primIdx);
extern void printCogMethodsWithSelector(sqInt selectorOop);
extern void printCogYoungReferrers(void);
extern sqInt printOpenPICList(void);
extern sqInt pruneYoungReferrers(void);
extern char * whereIsMaybeCodeThing(sqInt anOop);
extern sqInt numRegArgs(void);
extern void resetCountersIn(CogMethod *cogMethod);
extern sqInt cogMethodHasMachineCodePrim(CogMethod *aCogMethod);
extern sqInt genQuickReturnConst(void);
extern sqInt genQuickReturnInstVar(void);
extern sqInt genQuickReturnSelf(void);
extern sqInt mapPCDataForinto(CogMethod *cogMethod, sqInt arrayObj);
extern void recordCallOffsetIn(CogMethod *cogMethod);
extern void rewritePrimInvocationInto(CogMethod *cogMethod, void (*primFunctionPointer)(void));
extern void voidCogCompiledCode(void);
extern sqInt defaultCogCodeSize(void);
extern usqInt getJumpTargetPCAt(sqInt pc);
extern void initializeCodeZoneFromupTo(sqInt startAddress, sqInt endAddress);
extern sqInt picDataForinto(CogMethod *cogMethod, sqInt arrayObj);
extern double getCogCodeZoneThreshold(void);
extern sqInt setCogCodeZoneThreshold(double ratio);
extern void callCogCodePopReceiverArg0Regs(void);
extern void callCogCodePopReceiverArg1Arg0Regs(void);


/*** Global Variables ***/
extern sqInt blockNoContextSwitchOffset;
extern sqInt breakPC;
extern sqInt cbEntryOffset;
extern sqInt cbNoSwitchEntryOffset;
extern sqInt ceBaseFrameReturnTrampoline;
extern void (*ceCall0ArgsPIC)(void);
extern void (*ceCall1ArgsPIC)(void);
extern void (*ceCall2ArgsPIC)(void);
extern void (*ceCallCogCodePopReceiverAndClassRegs)(void);
extern void (*ceCallCogCodePopReceiverArg0Regs)(void);
extern void (*ceCallCogCodePopReceiverArg1Arg0Regs)(void);
extern void (*ceCallCogCodePopReceiverReg)(void);
extern sqInt ceCannotResumeTrampoline;
extern void (*ceCaptureCStackPointers)(void);
extern sqInt ceCheckForInterruptTrampoline;
extern void (*ceEnterCogCodePopReceiverReg)(void);
extern usqIntptr_t (*ceGetFP)(void);
extern usqIntptr_t (*ceGetSP)(void);
extern void (*ceInvokeInterpret)(void);
extern sqInt ceReturnToInterpreterTrampoline;
#if COGMTVM
extern usqIntptr_t (*ceTryLockVMOwner)(usqIntptr_t);
#endif
extern sqInt cFramePointerInUse;
extern sqInt cmEntryOffset;
extern sqInt cmNoCheckEntryOffset;
extern sqInt missOffset;
extern void (*realCECallCogCodePopReceiverAndClassRegs)(void);
extern void (*realCECallCogCodePopReceiverArg0Regs)(void);
extern void (*realCECallCogCodePopReceiverArg1Arg0Regs)(void);
extern void (*realCECallCogCodePopReceiverReg)(void);
extern void (*realCEEnterCogCodePopReceiverReg)(void);
extern int traceFlags ;
extern sqInt traceStores;


/*** Macros ***/
#define blockAlignment() 8
#define breakOnImplicitReceiver() (traceFlags & 64)
#define ceBaseFrameReturnPC() ceBaseFrameReturnTrampoline
#define ceCannotResumePC() ((usqInt)ceCannotResumeTrampoline)
#define ceReturnToInterpreterPC() ((usqInt)ceReturnToInterpreterTrampoline)
#define entryOffset() cmEntryOffset
#define interpretOffset() missOffset
#define maxCogCodeSize() (16*1024*1024)
#define noCheckEntryOffset() cmNoCheckEntryOffset
#define noContextSwitchBlockEntryOffset() blockNoContextSwitchOffset
#define printOnTrace() (traceFlags & 1)
#define recordBlockTrace() (traceFlags & 4)
#define recordEventTrace() (traceFlags & 16)
#define recordOverflowTrace() (traceFlags & 32)
#define recordPrimTrace() (traceFlags & 8)
#define recordSendTrace() (traceFlags & 2)
#define tryLockVMOwnerTo(value) ceTryLockVMOwner(value)
#define fullBlockEntryOffset() cbEntryOffset
#define fullBlockNoContextSwitchEntryOffset() cbNoSwitchEntryOffset

