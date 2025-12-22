/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoLab1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECOLAB1_H__
#define __I_ECOLAB1_H__

#include "IEcoBase1.h"

typedef struct EcoComplex {
	double real, imag;
} EcoComplex;

/* IEcoLab1 IID = {277FC00C-3562-4096-AFCF-C125B94EEC90} */
#ifndef __IID_IEcoLab1
static const UGUID IID_IEcoLab1 = {0x01, 0x10, {0x27, 0x7F, 0xC0, 0x0C, 0x35, 0x62, 0x40, 0x96, 0xAF, 0xCF, 0xC1, 0x25, 0xB9, 0x4E, 0xEC, 0x90}};
#endif /* __IID_IEcoLab1 */

typedef struct IEcoLab1* IEcoLab1Ptr_t;

typedef struct IEcoLab1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ IEcoLab1Ptr_t me, /* in */ const UGUID* riid, /* out */ voidptr_t* ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ IEcoLab1Ptr_t me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ IEcoLab1Ptr_t me);

    /* IEcoLab1 */
    int16_t (ECOCALLMETHOD *set_diagi_main)(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t* v, /* in */ size_t n, /* out */ int32_t*** D);
	int16_t (ECOCALLMETHOD *set_diagl_main)(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t* v, /* in */ size_t n, /* out */ int64_t*** D);
	int16_t (ECOCALLMETHOD *set_diagf_main)(/* in */ IEcoLab1Ptr_t me, /* in */ float* v, /* in */ size_t n, /* out */ float*** D);
	int16_t (ECOCALLMETHOD *set_diagd_main)(/* in */ IEcoLab1Ptr_t me, /* in */ double* v, /* in */ size_t n, /* out */ double*** D);
	int16_t (ECOCALLMETHOD *set_diagld_main)(/* in */ IEcoLab1Ptr_t me, /* in */ long double* v, /* in */ size_t n, /* out */ long double*** D);
	int16_t (ECOCALLMETHOD *set_diagc_main)(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex* v, /* in */ size_t n, /* out */ EcoComplex*** D);

	int16_t (ECOCALLMETHOD *set_diagi_k)(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t* v, /* in */ size_t n, /* in */ int k, /* out */ int32_t*** D);
	int16_t (ECOCALLMETHOD *set_diagl_k)(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t* v, /* in */ size_t n, /* in */ int k, /* out */ int64_t*** D);
	int16_t (ECOCALLMETHOD *set_diagf_k)(/* in */ IEcoLab1Ptr_t me, /* in */ float* v, /* in */ size_t n, /* in */ int k, /* out */ float*** D);
	int16_t (ECOCALLMETHOD *set_diagd_k)(/* in */ IEcoLab1Ptr_t me, /* in */ double* v, /* in */ size_t n, /* in */ int k, /* out */ double*** D);
	int16_t (ECOCALLMETHOD *set_diagld_k)(/* in */ IEcoLab1Ptr_t me, /* in */ long double* v, /* in */ size_t n, /* in */ int k, /* out */ long double*** D);
	int16_t (ECOCALLMETHOD *set_diagc_k)(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex* v, /* in */ size_t n, /* in */ int k, /* out */ EcoComplex*** D);

	int16_t (ECOCALLMETHOD *get_diagi_main)(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t** D, /* in */ size_t n, /* out */ int32_t** v);
	int16_t (ECOCALLMETHOD *get_diagl_main)(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t** D, /* in */ size_t n, /* out */ int64_t** v);
	int16_t (ECOCALLMETHOD *get_diagf_main)(/* in */ IEcoLab1Ptr_t me, /* in */ float** D, /* in */ size_t n, /* out */ float** v);
	int16_t (ECOCALLMETHOD *get_diagd_main)(/* in */ IEcoLab1Ptr_t me, /* in */ double** D, /* in */ size_t n, /* out */ double** v);
	int16_t (ECOCALLMETHOD *get_diagld_main)(/* in */ IEcoLab1Ptr_t me, /* in */ long double** D, /* in */ size_t n, /* out */ long double** v);
	int16_t (ECOCALLMETHOD *get_diagc_main)(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex** D, /* in */ size_t n, /* out */ EcoComplex** v);

	int16_t (ECOCALLMETHOD *get_diagi_k)(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t** D, /* in */ size_t n, /* in */ int k, /* out */ int32_t** v);
	int16_t (ECOCALLMETHOD *get_diagl_k)(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t** D, /* in */ size_t n, /* in */ int k, /* out */ int64_t** v);
	int16_t (ECOCALLMETHOD *get_diagf_k)(/* in */ IEcoLab1Ptr_t me, /* in */ float** D, /* in */ size_t n, /* in */ int k, /* out */ float** v);
	int16_t (ECOCALLMETHOD *get_diagd_k)(/* in */ IEcoLab1Ptr_t me, /* in */ double** D, /* in */ size_t n, /* in */ int k, /* out */ double** v);
	int16_t (ECOCALLMETHOD *get_diagld_k)(/* in */ IEcoLab1Ptr_t me, /* in */ long double** D, /* in */ size_t n, /* in */ int k, /* out */ long double** v);
	int16_t (ECOCALLMETHOD *get_diagc_k)(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex** D, /* in */ size_t n, /* in */ int k, /* out */ EcoComplex** v);

} IEcoLab1VTbl, *IEcoLab1VTblPtr;

interface IEcoLab1 {
    struct IEcoLab1VTbl *pVTbl;
} IEcoLab1;


#endif /* __I_ECOLAB1_H__ */
