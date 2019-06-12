/**
 * File: DSPEXTObjects.h
 *
 * @author diego
 * @created Tue Jun 11 15:38:27 CEST 2019
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
