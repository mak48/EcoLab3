/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"
#include "CEcoLab1EnumConnectionPoints.h"
#include "IEcoConnectionPointContainer.h"
#include "IEcoLab1Events.h"

#include <math.h>

int16_t ECOCALLMETHOD CEcoLab1_Fire_OnSettingDiagCall(/* in */ struct IEcoLab1* me, int k) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->OnSettingDiagCall(pIEvents, k);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Fire_OnSettingDiagElemCall(/* in */ struct IEcoLab1* me, int step, const void** mat, size_t size) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->OnSettingDiagElemCall(pIEvents, step, mat, size);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Fire_BeforeSettingDiag(/* in */ struct IEcoLab1* me, const void* v, const void** mat, size_t size, int k) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->BeforeSettingDiag(pIEvents, v, mat, size, k);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Fire_AfterSettingDiag(/* in */ struct IEcoLab1* me, const void** mat, size_t elem_count) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->AfterSettingDiag(pIEvents, mat, elem_count);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}


int16_t ECOCALLMETHOD CEcoLab1_Fire_OnGettingDiagCall(/* in */ struct IEcoLab1* me, int k) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->OnGettingDiagCall(pIEvents, k);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Fire_OnGettingDiagElemCall(/* in */ struct IEcoLab1* me, int step, const void* v, size_t size) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->OnGettingDiagElemCall(pIEvents, step, v, size);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Fire_BeforeGettingDiag(/* in */ struct IEcoLab1* me, const void* v, const void** mat, size_t size, int k) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->BeforeGettingDiag(pIEvents, v, mat, size, k);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Fire_AfterGettingDiag(/* in */ struct IEcoLab1* me, const void* v, size_t elem_count) {
	CEcoLab1* pCMe = (CEcoLab1*)me;
	int16_t result = 0;
	IEcoEnumConnections* pEnum = 0;
	IEcoLab1Events* pIEvents = 0;
	EcoConnectionData cd;

	if (me == 0) {
		return -1;
	}

	if (pCMe->m_pISinkCP != 0) {
		result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
		if ((result == 0) && (pEnum != 0)) {
			while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
				result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
				if ((result == 0) && (pIEvents != 0)) {
					result = pIEvents->pVTbl->AfterGettingDiag(pIEvents, v, elem_count);
					pIEvents->pVTbl->Release(pIEvents);
				}
				cd.pUnk->pVTbl->Release(cd.pUnk);
			}
			pEnum->pVTbl->Release(pEnum);
		}
	}
	return result;
}

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
static int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ IEcoLab1Ptr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
	CEcoLab1* pCMe = (CEcoLab1*)me;

	int16_t result;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

	return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ IEcoLab1Ptr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

	return pCMe->m_pIUnkOuter->pVTbl->AddRef(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ IEcoLab1Ptr_t me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1; /* ERR_ECO_POINTER */
    }

	return pCMe->m_pIUnkOuter->pVTbl->Release(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция set_diag_main
 * </сводка>
 *
 * <описание>
 *   На вход подается массив чисел. Необходимо вернуть квадратную матрицу, где данные числа будут стоять на главной диагонали, а остальные числа равны нулю
 * </описание>
 *
 */

static EcoComplex complex_zero() {
    EcoComplex zero = {0, 0};
    return zero;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagi_main(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t* v, /* in */ size_t n, /* out */ int32_t*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int32_t** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }
	CEcoLab1_Fire_OnSettingDiagCall(me, 0);

	resultMatrix = (int32_t**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(int32_t*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n; i++) {
		resultMatrix[i] = (int32_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(int32_t));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
                pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
            }
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n; j++) {
			resultMatrix[i][j] = 0;
		}
	}

	CEcoLab1_Fire_BeforeSettingDiag(me, v, resultMatrix, n, 0);

	for (i = 0; i < n; i++) {
		resultMatrix[i][i] = v[i];
		CEcoLab1_Fire_OnSettingDiagElemCall(me, i, resultMatrix, n);
	}
    *D = resultMatrix;
	CEcoLab1_Fire_AfterSettingDiag(me, *D, n);

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagl_main(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t* v, /* in */ size_t n, /* out */ int64_t*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int64_t** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (int64_t**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(int64_t*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n; i++) {
		resultMatrix[i] = (int64_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(int64_t));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
                pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
            }
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n; j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		resultMatrix[i][i] = v[i];
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagf_main(/* in */ IEcoLab1Ptr_t me, /* in */ float* v, /* in */ size_t n, /* out */ float*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	float** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (float**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(float*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n; i++) {
		resultMatrix[i] = (float*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(float));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
                pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
            }
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n; j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		resultMatrix[i][i] = v[i];
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagd_main(/* in */ IEcoLab1Ptr_t me, /* in */ double* v, /* in */ size_t n, /* out */ double*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	double** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (double**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(double*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n; i++) {
		resultMatrix[i] = (double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(double));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n; j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		resultMatrix[i][i] = v[i];
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagld_main(/* in */ IEcoLab1Ptr_t me, /* in */ long double* v, /* in */ size_t n, /* out */ long double*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	long double** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (long double**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(long double*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n; i++) {
		resultMatrix[i] = (long double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(long double));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n; j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		resultMatrix[i][i] = v[i];
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagc_main(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex* v, /* in */ size_t n, /* out */ EcoComplex*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int i, j;
    EcoComplex** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

    resultMatrix = (EcoComplex**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(EcoComplex*));
    if (resultMatrix == 0) {
        return ERR_ECO_POINTER;
    }
        
    for (i = 0; i < n; i++) {
        resultMatrix[i] = (EcoComplex*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(EcoComplex));
        if (resultMatrix[i] == 0) {
            for (j = 0; j < i; j++) {
                pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
            }
            pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);
            return ERR_ECO_POINTER;
        }

        // Инициализация нулями
        for (j = 0; j < n; j++) {
            resultMatrix[i][j] = complex_zero();
        }
    }

    // Заполнение главной диагонали
    for (i = 0; i < n; i++) {
        resultMatrix[i][i] = v[i];
    }
    
    *D = resultMatrix;
    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagi_k(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t* v, /* in */ size_t n, /* in */ int k, /* out */ int32_t*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int32_t** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }
	CEcoLab1_Fire_OnSettingDiagCall(me, k);

	resultMatrix = (int32_t**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(int32_t*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n + abs(k); i++) {
		resultMatrix[i] = (int32_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(int32_t));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n + abs(k); j++) {
			resultMatrix[i][j] = 0;
		}
	}

	CEcoLab1_Fire_BeforeSettingDiag(me, v, resultMatrix, n, k);

	for (i = 0; i < n - k; i++) {
		if (k >= 0) {
			resultMatrix[i][i + k] = v[i];
		}
		else {
			resultMatrix[i - k][i] = v[i];
		}

		CEcoLab1_Fire_OnSettingDiagElemCall(me, i, resultMatrix, n);
	}
    *D = resultMatrix;
	CEcoLab1_Fire_AfterSettingDiag(me, *D, n);

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagl_k(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t* v, /* in */ size_t n, /* in */ int k, /* out */ int64_t*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int64_t** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (int64_t**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(int64_t*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n + abs(k); i++) {
		resultMatrix[i] = (int64_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(int64_t));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n + abs(k); j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		if (k >= 0) {
			resultMatrix[i][i + k] = v[i];
		}
		else {
			resultMatrix[i - k][i] = v[i];
		}
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagf_k(/* in */ IEcoLab1Ptr_t me, /* in */ float* v, /* in */ size_t n, /* in */ int k, /* out */ float*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	float** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (float**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(float*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n + abs(k); i++) {
		resultMatrix[i] = (float*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(float));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n + abs(k); j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		if (k >= 0) {
			resultMatrix[i][i + k] = v[i];
		}
		else {
			resultMatrix[i - k][i] = v[i];
		}
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagd_k(/* in */ IEcoLab1Ptr_t me, /* in */ double* v, /* in */ size_t n, /* in */ int k, /* out */ double*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	double** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (double**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(double*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n + abs(k); i++) {
		resultMatrix[i] = (double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(double));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n + abs(k); j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		if (k >= 0) {
			resultMatrix[i][i + k] = v[i];
		}
		else {
			resultMatrix[i - k][i] = v[i];
		}
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagld_k(/* in */ IEcoLab1Ptr_t me, /* in */ long double* v, /* in */ size_t n, /* in */ int k, /* out */ long double*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	long double** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (long double**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(long double*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n + abs(k); i++) {
		resultMatrix[i] = (long double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(long double));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n + abs(k); j++) {
			resultMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		if (k >= 0) {
			resultMatrix[i][i + k] = v[i];
		}
		else {
			resultMatrix[i - k][i] = v[i];
		}
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_set_diagc_k(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex* v, /* in */ size_t n, /* in */ int k, /* out */ EcoComplex*** D) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	EcoComplex** resultMatrix = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultMatrix = (EcoComplex**)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(EcoComplex*));
	if (resultMatrix == 0) {
		return ERR_ECO_POINTER;
	}
		
	for (i = 0; i < n + abs(k); i++) {
		resultMatrix[i] = (EcoComplex*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n + abs(k)) * sizeof(EcoComplex));
		if (resultMatrix[i] == 0) {
			for (j = 0; j < i; j++) {
				pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix[j]);
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, resultMatrix);

			return ERR_ECO_POINTER;
		}

		for (j = 0; j < n + abs(k); j++) {
			resultMatrix[i][j] = complex_zero();
		}
	}

	for (i = 0; i < n; i++) {
		if (k >= 0) {
			resultMatrix[i][i + k] = v[i];
		}
		else {
			resultMatrix[i - k][i] = v[i];
		}
	}
    *D = resultMatrix;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagi_main(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t** D, /* in */ size_t n, /* out */ int32_t** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int32_t* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	CEcoLab1_Fire_OnGettingDiagCall(me, 0);

	resultVec = (int32_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(int32_t));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	CEcoLab1_Fire_BeforeGettingDiag(me, resultVec, D, n, 0);

	for (i = 0; i < n; i++) {
		resultVec[i] = D[i][i];
		CEcoLab1_Fire_OnGettingDiagElemCall(me, i, resultVec, n);
	}
    *v = resultVec;
	CEcoLab1_Fire_AfterGettingDiag(me, *v, n);

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagl_main(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t** D, /* in */ size_t n, /* out */ int64_t** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int64_t* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultVec = (int64_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(int64_t));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n; i++) {
		resultVec[i] = D[i][i];
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagf_main(/* in */ IEcoLab1Ptr_t me, /* in */ float** D, /* in */ size_t n, /* out */ float** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	float* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultVec = (float*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(float));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n; i++) {
		resultVec[i] = D[i][i];
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagd_main(/* in */ IEcoLab1Ptr_t me, /* in */ double** D, /* in */ size_t n, /* out */ double** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	double* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultVec = (double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(double));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n; i++) {
		resultVec[i] = D[i][i];
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagld_main(/* in */ IEcoLab1Ptr_t me, /* in */ long double** D, /* in */ size_t n, /* out */ long double** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	long double* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultVec = (long double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(long double));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n; i++) {
		resultVec[i] = D[i][i];
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagc_main(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex** D, /* in */ size_t n, /* out */ EcoComplex** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	EcoComplex* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	resultVec = (EcoComplex*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(EcoComplex));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n; i++) {
		resultVec[i] = D[i][i];
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagi_k(/* in */ IEcoLab1Ptr_t me, /* in */ int32_t** D, /* in */ size_t n, /* in */ int k, /* out */ int32_t** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int32_t* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	CEcoLab1_Fire_OnGettingDiagCall(me, k);

	if (abs(k) >= n) {
		return -1;
	}

	resultVec = (int32_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n - abs(k)) * sizeof(int32_t));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	CEcoLab1_Fire_BeforeGettingDiag(me, resultVec, D, n, k);

	for (i = 0; i < n - abs(k); i++) {
		if (k >= 0) {
			resultVec[i] = D[i][i + k];
		}
		else {
			resultVec[i] = D[i - k][i];
		}
		CEcoLab1_Fire_OnGettingDiagElemCall(me, i, resultVec, n - abs(k));
	}
    *v = resultVec;
	CEcoLab1_Fire_AfterGettingDiag(me, *v, n - abs(k));

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagl_k(/* in */ IEcoLab1Ptr_t me, /* in */ int64_t** D, /* in */ size_t n, /* in */ int k, /* out */ int64_t** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	int64_t* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	if (abs(k) >= n) {
		return -1;
	}

	resultVec = (int64_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n - abs(k)) * sizeof(int64_t));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n - abs(k); i++) {
		if (k >= 0) {
			resultVec[i] = D[i][i + k];
		}
		else {
			resultVec[i] = D[i - k][i];
		}
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagf_k(/* in */ IEcoLab1Ptr_t me, /* in */ float** D, /* in */ size_t n, /* in */ int k, /* out */ float** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	float* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	if (abs(k) >= n) {
		return -1;
	}

	resultVec = (float*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n - abs(k)) * sizeof(float));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n - abs(k); i++) {
		if (k >= 0) {
			resultVec[i] = D[i][i + k];
		}
		else {
			resultVec[i] = D[i - k][i];
		}
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagd_k(/* in */ IEcoLab1Ptr_t me, /* in */ double** D, /* in */ size_t n, /* in */ int k, /* out */ double** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	double* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	if (abs(k) >= n) {
		return -1;
	}

	resultVec = (double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n - abs(k)) * sizeof(double));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n - abs(k); i++) {
		if (k >= 0) {
			resultVec[i] = D[i][i + k];
		}
		else {
			resultVec[i] = D[i - k][i];
		}
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagld_k(/* in */ IEcoLab1Ptr_t me, /* in */ long double** D, /* in */ size_t n, /* in */ int k, /* out */ long double** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	long double* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	if (abs(k) >= n) {
		return -1;
	}

	resultVec = (long double*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n - abs(k)) * sizeof(long double));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n - abs(k); i++) {
		if (k >= 0) {
			resultVec[i] = D[i][i + k];
		}
		else {
			resultVec[i] = D[i - k][i];
		}
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_get_diagc_k(/* in */ IEcoLab1Ptr_t me, /* in */ EcoComplex** D, /* in */ size_t n, /* in */ int k, /* out */ EcoComplex** v) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	int i, j;
	EcoComplex* resultVec = 0;

    /* Проверка указателей */
    if (me == 0 || v == 0 || D == 0) {
        return ERR_ECO_POINTER;
    }

	if (abs(k) >= n) {
		return -1;
	}

	resultVec = (EcoComplex*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, (n - abs(k)) * sizeof(EcoComplex));
	if (resultVec == 0) {
		return ERR_ECO_POINTER;
	}

	for (i = 0; i < n - abs(k); i++) {
		if (k >= 0) {
			resultVec[i] = D[i][i + k];
		}
		else {
			resultVec[i] = D[i - k][i];
		}
	}
    *v = resultVec;

    return ERR_ECO_SUCCESES;
}

static int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_QueryInterface(/* in */ IEcoCalculatorYPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
	int16_t result;

	/* Проверка указателей */
	if (me == 0 || ppv == 0) {
		return ERR_ECO_POINTER;
	}

	return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_AddRef(/* in */ IEcoCalculatorYPtr_t me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));

	/* Проверка указателя */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	return pCMe->m_pIUnkOuter->pVTbl->AddRef(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
static uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_Release(/* in */ IEcoCalculatorYPtr_t me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));

	/* Проверка указателя */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	return pCMe->m_pIUnkOuter->pVTbl->Release(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Multiplication
 * </сводка>
 *
 * <описание>
 *   Функция Multiplication для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_Multiplication(/* in */ IEcoCalculatorYPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
	int32_t result = 0;

	/* Проверка указателей */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	if (pCMe->m_pIY != 0) {
		result = pCMe->m_pIY->pVTbl->Multiplication(pCMe->m_pIY, a, b);
	}

	return result;
}

/*
 *
 * <сводка>
 *   Функция Division
 * </сводка>
 *
 * <описание>
 *   Функция Division для интерфейса IEcoCalculatorY
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_Division(/* in */ IEcoCalculatorYPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(IEcoUnknownPtr_t));
	int16_t result = 0;

	/* Проверка указателей */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	if (pCMe->m_pIY != 0) {
		result = pCMe->m_pIY->pVTbl->Division(pCMe->m_pIY, a, b);
	}

	return result;
}


/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_QueryInterface(/* in */ IEcoCalculatorXPtr_t me, /* in */ const UGUID* riid, /* out */ void** ppv) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));

	/* Проверка указателей */
	if (me == 0 || ppv == 0) {
		return ERR_ECO_POINTER;
	}

	return pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_AddRef(/* in */ IEcoCalculatorXPtr_t me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));

	/* Проверка указателя */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	return pCMe->m_pIUnkOuter->pVTbl->AddRef(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_Release(/* in */ IEcoCalculatorXPtr_t me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));

	/* Проверка указателя */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	return pCMe->m_pIUnkOuter->pVTbl->Release(pCMe->m_pIUnkOuter);
}

/*
 *
 * <сводка>
 *   Функция Addition
 * </сводка>
 *
 * <описание>
 *   Функция Addition для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
int32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_Addition(/* in */ IEcoCalculatorXPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
	int32_t result = 0;

	/* Проверка указателей */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	if (pCMe->m_pIX != 0) {
		result = pCMe->m_pIX->pVTbl->Addition(pCMe->m_pIX, a, b);
	}

	return result;
}

/*
 *
 * <сводка>
 *   Функция Subtraction
 * </сводка>
 *
 * <описание>
 *   Функция Subtraction для интерфейса IEcoCalculatorX
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_Subtraction(/* in */ IEcoCalculatorXPtr_t me, /* in */ int16_t a, /* in */ int16_t b) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 2 * sizeof(IEcoUnknownPtr_t));
	int16_t result = 0;

	/* Проверка указателей */
	if (me == 0) {
		return -1; /* ERR_ECO_POINTER */
	}

	if (pCMe->m_pIX != 0) {
		result = pCMe->m_pIX->pVTbl->Subtraction(pCMe->m_pIX, a, b);
	}

	return result;
}

static int16_t ECOCALLMETHOD CEcoLab1_NondelegatingQueryInterface(/* in */ struct IEcoUnknown* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 3 * sizeof(IEcoUnknownPtr_t));
	int16_t result;

	if (me == 0 || ppv == 0) {
		return -1;
	}

	if (IsEqualUGUID(riid, &IID_IEcoLab1)) {
		*ppv = &pCMe->m_pVTblIEcoLab1;
		pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
	}
	else if (IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer)) {
		*ppv = &pCMe->m_pVTblICPC;
		pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
	}
	else if (IsEqualUGUID(riid, &IID_IEcoCalculatorY)) {
		*ppv = &pCMe->m_pVTblIY;
		pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
	}
	else if (IsEqualUGUID(riid, &IID_IEcoCalculatorX)) {
		if (pCMe->m_pInnerUnknown != 0) {
			return pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
		}
		else {
			*ppv = &pCMe->m_pVTblIX;
			pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
		}
	}
	else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
		*ppv = &pCMe->m_pVTblINondelegatingUnk;
		++pCMe->m_cRef;
	}
	else {
		*ppv = 0;
		return ERR_ECO_NOINTERFACE;
	}
	return ERR_ECO_SUCCESES;
}

static uint32_t ECOCALLMETHOD CEcoLab1_NondelegatingAddRef(/* in */ struct IEcoUnknown* me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 3 * sizeof(IEcoUnknownPtr_t));

	/* Проверка указателя */
	if (me == 0) {
		return -1;
	}

	return ++pCMe->m_cRef;
}

static uint32_t ECOCALLMETHOD CEcoLab1_NondelegatingRelease(/* in */ struct IEcoUnknown* me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 3 * sizeof(IEcoUnknownPtr_t));

	/* Проверка указателя */
	if (me == 0) {
		return -1;
	}

	/* Уменьшение счетчика ссылок на компонент */
	--pCMe->m_cRef;

	/* В случае обнуления счетчика, освобождение данных экземпляра */
	if (pCMe->m_cRef == 0) {
		if (pCMe->m_pInnerUnknown != 0) {
			if (pCMe->m_pInnerUnknown->pVTbl->Release(pCMe->m_pInnerUnknown) == 0) {
				pCMe->m_pInnerUnknown = 0;
			}
			else {
				pCMe->m_cRef = 1;
			}
		}
		if (pCMe->m_cRef == 0) {
			deleteCEcoLab1((IEcoLab1*)pCMe);
		}
		return 0;
	}
	return pCMe->m_cRef;
}

int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_QueryInterface(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 4 * sizeof(IEcoUnknownPtr_t));
	IEcoUnknown* nonDelegating = (IEcoUnknown*)&pCMe->m_pVTblINondelegatingUnk;
	int16_t result;
	if (me == 0 || ppv == 0) {
		return -1;
	}
	result = nonDelegating->pVTbl->QueryInterface(nonDelegating, riid, ppv);
	if (result != 0 && pCMe->m_pIUnkOuter != 0) {
		result = pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
	}
	return result;
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_AddRef(/* in */ struct IEcoConnectionPointContainer* me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 4 * sizeof(IEcoUnknownPtr_t));
	/* Проверка указателя */
	if (me == 0) {
		return -1;
	}

	return pCMe->m_pVTblINondelegatingUnk->AddRef((IEcoUnknown*)&pCMe->m_pVTblINondelegatingUnk);
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_Release(/* in */ struct IEcoConnectionPointContainer* me) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*) -
		sizeof(struct IEcoCalculatorX*) - sizeof(struct IEcoUnknown*));
	/* Проверка указателя */
	if (me == 0) {
		return -1;
	}

	/* Уменьшение счетчика ссылок на компонент */
	return pCMe->m_pVTblINondelegatingUnk->Release((IEcoUnknown*)&pCMe->m_pVTblINondelegatingUnk);
}

int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints(/* in */ struct IEcoConnectionPointContainer* me, /* out */ struct IEcoEnumConnectionPoints** ppEnum) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 4 * sizeof(IEcoUnknownPtr_t));
	int16_t result = 0;

	if (me == 0 || ppEnum == 0) {
		return -1;
	}

	result = createCEcoLab1EnumConnectionPoints((IEcoUnknown*)pCMe->m_pISys,
		(struct IEcoConnectionPoint*)&pCMe->m_pISinkCP->m_pVTblICP, ppEnum);

	return result;
}

int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ struct IEcoConnectionPoint** ppCP) {
	CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - 4 * sizeof(IEcoUnknownPtr_t));
	int16_t result = 0;

	if (me == 0 || ppCP == 0) {
		return -1;
	}

	if (!IsEqualUGUID(riid, &IID_IEcoLab1Events)) {
		*ppCP = 0;
		/* CONNECT_E_NOCONNECTION */
		return -1;
	}

	if (pCMe->m_pISinkCP == 0) {
		/* E_FAIL */
		return -1;
	}

	pCMe->m_pISinkCP->m_pVTblICP->AddRef((struct IEcoConnectionPoint*)&pCMe->m_pISinkCP->m_pVTblICP);
	*ppCP = (struct IEcoConnectionPoint*)&pCMe->m_pISinkCP->m_pVTblICP;

	return 0;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ IEcoLab1Ptr_t me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoInterfaceBus1* pIBus = 0;
	IEcoUnknown* pOuterUnknown = (IEcoUnknown*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

	result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);

	result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY, (void**)&pCMe->m_pIY);
	if (result != 0 || pCMe->m_pIY == 0) {
		// Получение интерфейса IEcoCalculatorY по работе с умножением и делением у компонента "D"
		result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0, &IID_IEcoCalculatorY, (void**)&pCMe->m_pIY);
	}

	result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorB, pOuterUnknown, &IID_IEcoUnknown, (void**)&pCMe->m_pInnerUnknown);
	if (result != 0 || pCMe->m_pInnerUnknown == 0) {
		result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoCalculatorX, (void**)&pCMe->m_pIX);
	}

	result = createCEcoLab1ConnectionPoint((IEcoUnknown*)pCMe->m_pISys,
		(IEcoConnectionPointContainer*)&pCMe->m_pVTblICPC, &IID_IEcoLab1Events, (IEcoConnectionPoint**)&(pCMe->m_pISinkCP));
	if (result == 0 && pCMe->m_pISinkCP != 0) {
		result = 0;
	}

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
	CEcoLab1_QueryInterface,
	CEcoLab1_AddRef,
	CEcoLab1_Release,
	CEcoLab1_set_diagi_main,
	CEcoLab1_set_diagl_main,
	CEcoLab1_set_diagf_main,
	CEcoLab1_set_diagd_main,
	CEcoLab1_set_diagld_main,
	CEcoLab1_set_diagc_main,
	CEcoLab1_set_diagi_k,
	CEcoLab1_set_diagl_k,
	CEcoLab1_set_diagf_k,
	CEcoLab1_set_diagd_k,
	CEcoLab1_set_diagld_k,
	CEcoLab1_set_diagc_k,
	CEcoLab1_get_diagi_main,
	CEcoLab1_get_diagl_main,
	CEcoLab1_get_diagf_main,
	CEcoLab1_get_diagd_main,
	CEcoLab1_get_diagld_main,
	CEcoLab1_get_diagc_main,
	CEcoLab1_get_diagi_k,
	CEcoLab1_get_diagl_k,
	CEcoLab1_get_diagf_k,
	CEcoLab1_get_diagd_k,
	CEcoLab1_get_diagld_k,
	CEcoLab1_get_diagc_k,
};

IEcoConnectionPointContainerVTbl g_x0000000500000000C000000000000046VTblCPC = {
		CEcoLab1_IEcoConnectionPointContainer_QueryInterface,
		CEcoLab1_IEcoConnectionPointContainer_AddRef,
		CEcoLab1_IEcoConnectionPointContainer_Release,
		CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints,
		CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint
};

IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTbl = {
	CEcoLab1_IEcoCalculatorX_QueryInterface,
	CEcoLab1_IEcoCalculatorX_AddRef,
	CEcoLab1_IEcoCalculatorX_Release,
	CEcoLab1_IEcoCalculatorX_Addition,
	CEcoLab1_IEcoCalculatorX_Subtraction
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTbl = {
	CEcoLab1_IEcoCalculatorY_QueryInterface,
	CEcoLab1_IEcoCalculatorY_AddRef,
	CEcoLab1_IEcoCalculatorY_Release,
	CEcoLab1_IEcoCalculatorY_Multiplication,
	CEcoLab1_IEcoCalculatorY_Division
};

IEcoUnknownVTbl g_x000000000000000000000000000000AAVTblUnk = {
		CEcoLab1_NondelegatingQueryInterface,
		CEcoLab1_NondelegatingAddRef,
		CEcoLab1_NondelegatingRelease
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
	int16_t result = -1;
	IEcoSystem1* pISys = 0;
	IEcoInterfaceBus1* pIBus = 0;
	IEcoInterfaceBus1MemExt* pIMemExt = 0;
	IEcoMemoryAllocator1* pIMem = 0;
	CEcoLab1* pCMe = 0;
	UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

	/* Проверка указателей */
	if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
		return result;
	}

	/* Получение системного интерфейса приложения */
	result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void**)&pISys);

	/* Проверка */
	if (result != 0 && pISys == 0) {
		return result;
	}

	/* Получение интерфейса для работы с интерфейсной шиной */
	result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
	result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
	if (result == 0 && pIMemExt != 0) {
		rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
		pIMemExt->pVTbl->Release(pIMemExt);
	}

	/* Получение интерфейса распределителя памяти */
	pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);

	/* Проверка */
	if (result != 0 && pIMem == 0) {
		/* Освобождение системного интерфейса в случае ошибки */
		pISys->pVTbl->Release(pISys);
		return result;
	}

	/* Выделение памяти для данных экземпляра */
	pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

	/* Сохранение указателя на системный интерфейс */
	pCMe->m_pISys = pISys;

	/* Сохранение указателя на интерфейс для работы с памятью */
	pCMe->m_pIMem = pIMem;

	pCMe->m_cRef = 1;

	pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

	pCMe->m_pVTblIY = &g_xBD6414C29096423EA90C04D77AFD1CADVTbl;

	pCMe->m_pVTblIX = &g_x9322111622484742AE0682819447843DVTbl;

	pCMe->m_pVTblINondelegatingUnk = &g_x000000000000000000000000000000AAVTblUnk;

	pCMe->m_pVTblICPC = &g_x0000000500000000C000000000000046VTblCPC;

	pCMe->m_pIUnkOuter = 0;
	if (pIUnkOuter != 0) {
		pCMe->m_pIUnkOuter = pIUnkOuter;
		*ppIEcoLab1 = (IEcoLab1*)&pCMe->m_pVTblINondelegatingUnk;
	}
	else {
		pCMe->m_pIUnkOuter = (IEcoUnknown*)&pCMe->m_pVTblINondelegatingUnk;
		*ppIEcoLab1 = (IEcoLab1*)pCMe;
	}

	/* Инициализация данных */

	pCMe->m_pIY = 0;

	pCMe->m_pIX = 0;

	pCMe->m_pInnerUnknown = 0;

	/* Возврат указателя на интерфейс */
	*ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1) {
	CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
	IEcoMemoryAllocator1* pIMem = 0;

	if (pIEcoLab1 != 0) {
		pIMem = pCMe->m_pIMem;
		/* Освобождение */
		if (pCMe->m_pIY != 0) {
			pCMe->m_pIY->pVTbl->Release(pCMe->m_pIY);
		}
		if (pCMe->m_pIX != 0) {
			pCMe->m_pIX->pVTbl->Release(pCMe->m_pIX);
		}
		if (pCMe->m_pISys != 0) {
			pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
		}
		pIMem->pVTbl->Free(pIMem, pCMe);
		pIMem->pVTbl->Release(pIMem);
	}
}
