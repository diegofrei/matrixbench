/**
 * File: DSPEXTObjects.h
 *
 * @author diego
 * @created Wed Jun 12 14:23:51 CEST 2019
 */
#ifndef DSPEXTObjects_h
#define DSPEXTObjects_h

#include "DSPEObjects.h"

#ifdef __cplusplus

class DSPEOpObject : public DSPEObject {
public:
	DSPEOpObject() {};
	virtual ~DSPEOpObject() {};
};

class DSPECoprocOpObject : public DSPEOpObject {
public:
	DSPECoprocOpObject() {};
	virtual ~DSPECoprocOpObject() {};
};

#endif /* __cplusplus */
#endif
