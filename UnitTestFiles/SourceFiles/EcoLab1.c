/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"
#include "IEcoCalculatorY.h"
#include "IdEcoCalculatorD.h"
#include "IEcoCalculatorX.h"
#include "IdEcoCalculatorE.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"
//#include "IdEcoLab2.h"

#include "IEcoConnectionPointContainer.h"
#include "IEcoConnectionPoint.h"
#include "IEcoLab1Events.h"
#include "CEcoLab1Sink.h"

#include <math.h>

int32_t *initVI(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    int32_t *vi = (int32_t *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int32_t));
    for (i = 0; i < size; i++) {
        vi[i] = rand() % 10000 - 5001;
    }
    return vi;
}

int64_t *initVL(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    int64_t *vl = (int64_t *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int64_t));
    for (i = 0; i < size; i++) {
        vl[i] = (int64_t)rand() % 10000 - 5001;
    }
    return vl;
}

float *initVF(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    float *vf = (float *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(float));
    for (i = 0; i < size; i++) {
        vf[i] = ((float) (rand() % 10000 - 5001)) / ((float)(rand() % 1010 + 1));
    }
    return vf;
}

double *initVD(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    double *vd = (double *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(double));
    for (i = 0; i < size; i++) {
        vd[i] = ((double) (rand() % 10000 - 5001)) / ((double)(rand() % 1010 + 1)) ;
    }
    return vd;
}

long double *initVLD(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    long double *vld = (long double *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(long double));
    for (i = 0; i < size; i++) {
        vld[i] = ((long double) (rand() % 10000 - 5001)) / ((long double)(rand() % 1010 + 1)) ;
    }
    return vld;
}

EcoComplex *initVC(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    EcoComplex *vc = (EcoComplex *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(EcoComplex));
    for (i = 0; i < size; i++) {
        vc[i].imag = ((double) (rand() % 10000 - 5001)) / ((double)(rand() % 1010 + 1)) ;
		vc[i].real = ((double) (rand() % 10000 - 5001)) / ((double)(rand() % 1010 + 1)) ;
    }
    return vc;
}

int32_t **initMatI(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i, j;
    int32_t **D = (int32_t **) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int32_t*));
    for (i = 0; i < size; i++) {
        D[i] = (int32_t *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int32_t));
		for (j = 0; j < size; j++) {
			D[i][j] = rand() % 10000 - 5001;
		}
    }
    return D;
}

int64_t **initMatL(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i, j;
    int64_t **D = (int64_t **) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int64_t*));
    for (i = 0; i < size; i++) {
        D[i] = (int64_t *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int64_t));
		for (j = 0; j < size; j++) {
			D[i][j] = (int64_t)rand() % 10000 - 5001;
		}
    }
    return D;
}

float **initMatF(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i, j;
    float **D = (float **) pIMem->pVTbl->Alloc(pIMem, size * sizeof(float*));
    for (i = 0; i < size; i++) {
        D[i] = (float *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(float));
		for (j = 0; j < size; j++) {
			D[i][j] = ((float) (rand() % 10000 - 5001)) / ((float)(rand() % 1010 + 1));
		}
    }
    return D;
}

double **initMatD(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i, j;
    double **D = (double **) pIMem->pVTbl->Alloc(pIMem, size * sizeof(double*));
    for (i = 0; i < size; i++) {
        D[i] = (double *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(double));
		for (j = 0; j < size; j++) {
			D[i][j] = ((double) (rand() % 10000 - 5001)) / ((double)(rand() % 1010 + 1));
		}
    }
    return D;
}

long double **initMatLD(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i, j;
    long double **D = (long double **) pIMem->pVTbl->Alloc(pIMem, size * sizeof(long double*));
    for (i = 0; i < size; i++) {
        D[i] = (long double *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(long double));
		for (j = 0; j < size; j++) {
			D[i][j] = ((long double) (rand() % 10000 - 5001)) / ((long double)(rand() % 1010 + 1)) ;
		}
    }
    return D;
}

EcoComplex **initMatC(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i, j;
    EcoComplex **D = (EcoComplex **) pIMem->pVTbl->Alloc(pIMem, size * sizeof(EcoComplex*));
    for (i = 0; i < size; i++) {
		D[i] = (EcoComplex *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(EcoComplex));
		for (j = 0; j < size; j++) {
			D[i][j].imag = ((double) (rand() % 10000 - 5001)) / ((double)(rand() % 1010 + 1)) ;
			D[i][j].real = ((double) (rand() % 10000 - 5001)) / ((double)(rand() % 1010 + 1)) ;
		}
    }
    return D;
}

int isComplexEqual(EcoComplex* c1, EcoComplex* c2) {
	return c1->imag == c2->imag && c1->real == c2->real;
}

void test_set_diagi_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
    int32_t* vi = initVI(pIMem, n);
	int32_t** D = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->set_diagi_main(pIEcoLab1, vi, n, &D);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in set_diagi_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

    for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			if (i == j) {
				if (D[i][j] != vi[i]) {
					printf("Invalid setting diagi main: main diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i][j] != 0) {
					printf("Invalid setting diagi main: the elem of remaining matrix is not zero (size: %d).\n", n);
					return;
				}
			}
		}
    }

    pIMem->pVTbl->Free(pIMem, vi);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "set_diagi_main", n, total_time);
}

void test_set_diagl_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
    int64_t* vl = initVL(pIMem, n);
	int64_t** D = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->set_diagl_main(pIEcoLab1, vl, n, &D);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in set_diagl_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

    for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			if (i == j) {
				if (D[i][j] != vl[i]) {
					printf("Invalid setting diagl main: main diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i][j] != 0) {
					printf("Invalid setting diagl main: the elem of remaining matrix is not zero (size: %d).\n", n);
					return;
				}
			}
		}
    }

    pIMem->pVTbl->Free(pIMem, vl);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "set_diagl_main", n, total_time);
}

void test_set_diagf_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
    float* vf = initVF(pIMem, n);
	float** D = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->set_diagf_main(pIEcoLab1, vf, n, &D);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in set_diagf_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

    for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			if (i == j) {
				if (D[i][j] != vf[i]) {
					printf("Invalid setting diagf main: main diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i][j] != 0) {
					printf("Invalid setting diagf main: the elem of remaining matrix is not zero (size: %d).\n", n);
					return;
				}
			}
		}
    }

    pIMem->pVTbl->Free(pIMem, vf);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "set_diagf_main", n, total_time);
}

void test_set_diagd_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
    double* vd = initVD(pIMem, n);
	double** D = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->set_diagd_main(pIEcoLab1, vd, n, &D);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in set_diagd_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

    for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			if (i == j) {
				if (D[i][j] != vd[i]) {
					printf("Invalid setting diagd main: main diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i][j] != 0) {
					printf("Invalid setting diagd main: the elem of remaining matrix is not zero (size: %d).\n", n);
					return;
				}
			}
		}
    }

    pIMem->pVTbl->Free(pIMem, vd);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "set_diagd_main", n, total_time);
}

void test_set_diagld_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
    long double* vld = initVLD(pIMem, n);
	long double** D = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->set_diagld_main(pIEcoLab1, vld, n, &D);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in set_diagld_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

    for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			if (i == j) {
				if (D[i][j] != vld[i]) {
					printf("Invalid setting diagld main: main diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i][j] != 0) {
					printf("Invalid setting diagld main: the elem of remaining matrix is not zero (size: %d).\n", n);
					return;
				}
			}
		}
    }

    pIMem->pVTbl->Free(pIMem, vld);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "set_diagld_main", n, total_time);
}

void test_set_diagc_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
    EcoComplex* vc = initVC(pIMem, n);
	EcoComplex** D = 0;
	EcoComplex czero = {0, 0};
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->set_diagc_main(pIEcoLab1, vc, n, &D);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in set_diagc_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

    for (i = 0; i < n; i++){
		for (j = 0; j < n; j++) {
			if (i == j) {
				if (!isComplexEqual(&D[i][j], &vc[i])) {
					printf("Invalid setting diagc main: main diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (!isComplexEqual(&D[i][j], &czero)) {
					printf("Invalid setting diagc main: the elem of remaining matrix is not zero (size: %d).\n", n);
					return;
				}
			}
		}
    }

    pIMem->pVTbl->Free(pIMem, vc);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "set_diagc_main", n, total_time);
}

void test_set_diagi_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, j, m;
    int32_t* vi = initVI(pIMem, n);
	int k[2] = {1, -2};
	int32_t** D = 0;
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->set_diagi_k(pIEcoLab1, vi, n, k[m], &D);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in set_diagi_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n + abs(k[m]); i++){
			for (j = 0; j < n + abs(k[m]); j++) {
				if (k[m] >= 0) {
					if (i + k[m] == j) {
						if (D[i][j] != vi[i]) {
							printf("Invalid setting diagi k >= 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagi k >= 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
				else {
					if (i == j - k[m]) {
						if (D[i][j] != vi[j]) {
							printf("Invalid setting diagi k < 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagi k < 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
			}
		}

		for (i = 0; i < n + abs(k[m]); i++){
			pIMem->pVTbl->Free(pIMem, D[i]);
		}
		pIMem->pVTbl->Free(pIMem, D);
	}
	avg_time /= 2;

	pIMem->pVTbl->Free(pIMem, vi);

    fprintf(file, "%s,%d,%lf\n", "set_diagi_k", n, avg_time);
}

void test_set_diagl_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, j, m;
    int64_t* vl = initVL(pIMem, n);
	int k[2] = {1, -2};
	int64_t** D = 0;
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->set_diagl_k(pIEcoLab1, vl, n, k[m], &D);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in set_diagl_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n + abs(k[m]); i++){
			for (j = 0; j < n + abs(k[m]); j++) {
				if (k[m] >= 0) {
					if (i + k[m] == j) {
						if (D[i][j] != vl[i]) {
							printf("Invalid setting diagl k >= 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagl k >= 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
				else {
					if (i == j - k[m]) {
						if (D[i][j] != vl[j]) {
							printf("Invalid setting diagl k < 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagl k < 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
			}
		}

		for (i = 0; i < n + abs(k[m]); i++){
			pIMem->pVTbl->Free(pIMem, D[i]);
		}
		pIMem->pVTbl->Free(pIMem, D);
	}
	avg_time /= 2;

	pIMem->pVTbl->Free(pIMem, vl);

    fprintf(file, "%s,%d,%lf\n", "set_diagl_k", n, avg_time);
}

void test_set_diagf_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, j, m;
    float* vf = initVF(pIMem, n);
	int k[2] = {1, -2};
	float** D = 0;
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->set_diagf_k(pIEcoLab1, vf, n, k[m], &D);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in set_diagf_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n + abs(k[m]); i++){
			for (j = 0; j < n + abs(k[m]); j++) {
				if (k[m] >= 0) {
					if (i + k[m] == j) {
						if (D[i][j] != vf[i]) {
							printf("Invalid setting diagf k >= 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagf k >= 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
				else {
					if (i == j - k[m]) {
						if (D[i][j] != vf[j]) {
							printf("Invalid setting diagf k < 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagf k < 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
			}
		}

		for (i = 0; i < n + abs(k[m]); i++){
			pIMem->pVTbl->Free(pIMem, D[i]);
		}
		pIMem->pVTbl->Free(pIMem, D);
	}
	avg_time /= 2;

    pIMem->pVTbl->Free(pIMem, vf);
	
    fprintf(file, "%s,%d,%lf\n", "set_diagf_k", n, avg_time);
}

void test_set_diagd_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, j, m;
    double* vd = initVD(pIMem, n);
	int k[2] = {1, -2};
	double** D = 0;
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->set_diagd_k(pIEcoLab1, vd, n, k[m], &D);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in set_diagd_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n + abs(k[m]); i++){
			for (j = 0; j < n + abs(k[m]); j++) {
				if (k[m] >= 0) {
					if (i + k[m] == j) {
						if (D[i][j] != vd[i]) {
							printf("Invalid setting diagd k >= 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagd k >= 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
				else {
					if (i == j - k[m]) {
						if (D[i][j] != vd[j]) {
							printf("Invalid setting diagd k < 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagd k < 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
			}
		}

		for (i = 0; i < n + abs(k[m]); i++){
			pIMem->pVTbl->Free(pIMem, D[i]);
		}
		pIMem->pVTbl->Free(pIMem, D);
	}
	avg_time /= 2;

    pIMem->pVTbl->Free(pIMem, vd);

    fprintf(file, "%s,%d,%lf\n", "set_diagd_k", n, avg_time);
}

void test_set_diagld_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, j, m;
    long double* vld = initVLD(pIMem, n);
	int k[2] = {1, -2};
	long double** D = 0;
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->set_diagld_k(pIEcoLab1, vld, n, k[m], &D);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in set_diagld_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n + abs(k[m]); i++){
			for (j = 0; j < n + abs(k[m]); j++) {
				if (k[m] >= 0) {
					if (i + k[m] == j) {
						if (D[i][j] != vld[i]) {
							printf("Invalid setting diagld k >= 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagld k >= 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
				else {
					if (i == j - k[m]) {
						if (D[i][j] != vld[j]) {
							printf("Invalid setting diagld k < 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (D[i][j] != 0) {
							printf("Invalid setting diagld k < 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
			}
		}

		for (i = 0; i < n + abs(k[m]); i++){
			pIMem->pVTbl->Free(pIMem, D[i]);
		}
		pIMem->pVTbl->Free(pIMem, D);
	}
	avg_time /= 2;

    pIMem->pVTbl->Free(pIMem, vld);

    fprintf(file, "%s,%d,%lf\n", "set_diagld_k", n, avg_time);
}

void test_set_diagc_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, j, m;
    EcoComplex* vc = initVC(pIMem, n);
	int k[2] = {1, -2};
	EcoComplex** D = 0;
	EcoComplex czero = {0, 0};
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->set_diagc_k(pIEcoLab1, vc, n, k[m], &D);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in set_diagc_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n + abs(k[m]); i++){
			for (j = 0; j < n + abs(k[m]); j++) {
				if (k[m] >= 0) {
					if (i + k[m] == j) {
						if (!isComplexEqual(&D[i][j], &vc[i])) {
							printf("Invalid setting diagc k >= 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (!isComplexEqual(&D[i][j], &czero)) {
							printf("Invalid setting diagc k >= 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
				else {
					if (i == j - k[m]) {
						if (!isComplexEqual(&D[i][j], &vc[j])) {
							printf("Invalid setting diagc k < 0: k diag is incorrect (size: %d).\n", n);
							return;
						}
					}
					else {
						if (!isComplexEqual(&D[i][j], &czero)) {
							printf("Invalid setting diagc k < 0: the elem of remaining matrix is not zero (size: %d).\n", n);
							return;
						}
					}   
				}
			}
		}

		for (i = 0; i < n + abs(k[m]); i++){
			pIMem->pVTbl->Free(pIMem, D[i]);
		}
		pIMem->pVTbl->Free(pIMem, D);
	}
	avg_time /= 2;

    pIMem->pVTbl->Free(pIMem, vc);

    fprintf(file, "%s,%d,%lf\n", "set_diagc_k", n, avg_time);
}

void test_get_diagi_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
	int32_t** D = initMatI(pIMem, n);
    int32_t* vi = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->get_diagi_main(pIEcoLab1, D, n, &vi);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in get_diagi_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

	for (i = 0; i < n; i++) {
		if (vi[i] != D[i][i]) {
			printf("Invalid getting diagi main: main diag is incorrect (size: %d).\n", n);
			return;
		}
	}

    pIMem->pVTbl->Free(pIMem, vi);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagi_main", n, total_time);
}

void test_get_diagl_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
	int64_t** D = initMatL(pIMem, n);
    int64_t* vl = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->get_diagl_main(pIEcoLab1, D, n, &vl);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in get_diagl_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

	for (i = 0; i < n; i++) {
		if (vl[i] != D[i][i]) {
			printf("Invalid getting diagl main: main diag is incorrect (size: %d).\n", n);
			return;
		}
	}

    pIMem->pVTbl->Free(pIMem, vl);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagl_main", n, total_time);
}

void test_get_diagf_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
	float** D = initMatF(pIMem, n);
    float* vf = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->get_diagf_main(pIEcoLab1, D, n, &vf);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in get_diagf_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

	for (i = 0; i < n; i++) {
		if (vf[i] != D[i][i]) {
			printf("Invalid getting diagf main: main diag is incorrect (size: %d).\n", n);
			return;
		}
	}

    pIMem->pVTbl->Free(pIMem, vf);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagf_main", n, total_time);
}

void test_get_diagd_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
	double** D = initMatD(pIMem, n);
    double* vd = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->get_diagd_main(pIEcoLab1, D, n, &vd);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in get_diagd_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

	for (i = 0; i < n; i++) {
		if (vd[i] != D[i][i]) {
			printf("Invalid getting diagd main: main diag is incorrect (size: %d).\n", n);
			return;
		}
	}

    pIMem->pVTbl->Free(pIMem, vd);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagd_main", n, total_time);
}

void test_get_diagld_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i, j;
	long double** D = initMatLD(pIMem, n);
    long double* vld = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->get_diagld_main(pIEcoLab1, D, n, &vld);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in get_diagld_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

	for (i = 0; i < n; i++) {
		if (vld[i] != D[i][i]) {
			printf("Invalid getting diagld main: main diag is incorrect (size: %d).\n", n);
			return;
		}
	}

    pIMem->pVTbl->Free(pIMem, vld);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagld_main", n, total_time);
}

void test_get_diagc_main(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double total_time;
    size_t i;
	EcoComplex** D = initMatC(pIMem, n);
    EcoComplex* vc = 0;
	int16_t result;

    begin = clock();
    result = pIEcoLab1 ->pVTbl->get_diagc_main(pIEcoLab1, D, n, &vc);
    end = clock();

	if (result != ERR_ECO_SUCCESES) {
		printf("Error in get_diagc_main (size: %d).\n", n);
        return;
	}

    total_time = (double)(end - begin);

	for (i = 0; i < n; i++) {
		if (!isComplexEqual(&vc[i], &D[i][i])) {
			printf("Invalid getting diagc main: main diag is incorrect (size: %d).\n", n);
			return;
		}
	}

    pIMem->pVTbl->Free(pIMem, vc);
	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
    }
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagc_main", n, total_time);
}

void test_get_diagi_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, m;
	int32_t** D = initMatI(pIMem, n);
    int32_t* vi = 0;
	int k[2] = {1, -2};
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->get_diagi_k(pIEcoLab1, D, n, k[m], &vi);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in get_diagi_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n - abs(k[m]); i++){
			if (k[m] >= 0) {
				if (D[i][i + k[m]] != vi[i]) {
					printf("Invalid getting diagi k >= 0: k diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i - k[m]][i] != vi[i]) {
					printf("Invalid getting diagi k < 0: k diag is incorrect (size: %d).\n", n);
					return;
				} 
			}
		}

		pIMem->pVTbl->Free(pIMem, vi);
	}
	avg_time /= 2;

	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
	}
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagi_k", n, avg_time);
}

void test_get_diagl_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, m;
	int64_t** D = initMatL(pIMem, n);
    int64_t* vl = 0;
	int k[2] = {1, -2};
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->get_diagl_k(pIEcoLab1, D, n, k[m], &vl);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in get_diagl_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n - abs(k[m]); i++){
			if (k[m] >= 0) {
				if (D[i][i + k[m]] != vl[i]) {
					printf("Invalid getting diagl k >= 0: k diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i - k[m]][i] != vl[i]) {
					printf("Invalid getting diagl k < 0: k diag is incorrect (size: %d).\n", n);
					return;
				} 
			}
		}

		pIMem->pVTbl->Free(pIMem, vl);
	}
	avg_time /= 2;

	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
	}
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagl_k", n, avg_time);
}

void test_get_diagf_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, m;
	float** D = initMatF(pIMem, n);
    float* vf = 0;
	int k[2] = {1, -2};
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->get_diagf_k(pIEcoLab1, D, n, k[m], &vf);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in get_diagf_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n - abs(k[m]); i++){
			if (k[m] >= 0) {
				if (D[i][i + k[m]] != vf[i]) {
					printf("Invalid getting diagf k >= 0: k diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i - k[m]][i] != vf[i]) {
					printf("Invalid getting diagf k < 0: k diag is incorrect (size: %d).\n", n);
					return;
				} 
			}
		}

		pIMem->pVTbl->Free(pIMem, vf);
	}
	avg_time /= 2;

	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
	}
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagf_k", n, avg_time);
}

void test_get_diagd_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, m;
	double** D = initMatD(pIMem, n);
    double* vd = 0;
	int k[2] = {1, -2};
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->get_diagd_k(pIEcoLab1, D, n, k[m], &vd);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in get_diagd_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n - abs(k[m]); i++){
			if (k[m] >= 0) {
				if (D[i][i + k[m]] != vd[i]) {
					printf("Invalid getting diagd k >= 0: k diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i - k[m]][i] != vd[i]) {
					printf("Invalid getting diagd k < 0: k diag is incorrect (size: %d).\n", n);
					return;
				} 
			}
		}

		pIMem->pVTbl->Free(pIMem, vd);
	}
	avg_time /= 2;

	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
	}
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagd_k", n, avg_time);
}

void test_get_diagld_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, m;
	long double** D = initMatLD(pIMem, n);
    long double* vld = 0;
	int k[2] = {1, -2};
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->get_diagld_k(pIEcoLab1, D, n, k[m], &vld);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in get_diagld_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n - abs(k[m]); i++){
			if (k[m] >= 0) {
				if (D[i][i + k[m]] != vld[i]) {
					printf("Invalid getting diagld k >= 0: k diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (D[i - k[m]][i] != vld[i]) {
					printf("Invalid getting diagld k < 0: k diag is incorrect (size: %d).\n", n);
					return;
				} 
			}
		}

		pIMem->pVTbl->Free(pIMem, vld);
	}
	avg_time /= 2;

	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
	}
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagld_k", n, avg_time);
}

void test_get_diagc_k(IEcoLab1 *pIEcoLab1, FILE *file, size_t n, IEcoMemoryAllocator1 *pIMem){
    clock_t begin, end;
	double avg_time = 0;
    size_t i, m;
	EcoComplex** D = initMatC(pIMem, n);
    EcoComplex* vc = 0;
	int k[2] = {1, -2};
	int16_t result;

	for (m = 0; m < 2; m++) {
		begin = clock();
		result = pIEcoLab1 ->pVTbl->get_diagc_k(pIEcoLab1, D, n, k[m], &vc);
		end = clock();

		if (result != ERR_ECO_SUCCESES) {
			printf("Error in get_diagc_k (size: %d).\n", n);
			return;
		}

		avg_time += (double)(end - begin);

		for (i = 0; i < n - abs(k[m]); i++){
			if (k[m] >= 0) {
				if (!isComplexEqual(&D[i][i + k[m]], &vc[i])) {
					printf("Invalid getting diagc k >= 0: k diag is incorrect (size: %d).\n", n);
					return;
				}
			}
			else {
				if (!isComplexEqual(&D[i - k[m]][i], &vc[i])) {
					printf("Invalid getting diagc k < 0: k diag is incorrect (size: %d).\n", n);
					return;
				} 
			}
		}

		pIMem->pVTbl->Free(pIMem, vc);
	}
	avg_time /= 2;

	for (i = 0; i < n; i++){
		pIMem->pVTbl->Free(pIMem, D[i]);
	}
	pIMem->pVTbl->Free(pIMem, D);

    fprintf(file, "%s,%d,%lf\n", "get_diagc_k", n, avg_time);
}

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;
	IEcoCalculatorY* pIY = 0;
	IEcoCalculatorX* pIX = 0;
	IEcoUnknown* pIUnknown = 0;
	int k = 3;

	IEcoLab1* pIEcoLab2 = 0;

	FILE * resultFile;
	size_t i, sizes[8] = {100, 1000, 2000, 3000, 5000, 7000, 10000, 100000};

	/* Указатель на интерфейс контейнера точек подключения */
	IEcoConnectionPointContainer* pICPC = 0;
	/* Указатель на интерфейс точки подключения */
	IEcoConnectionPoint* pICP = 0;
	/* Указатель на обратный интерфейс */
	IEcoLab1Events* pIEcoLab1Sink = 0;
	IEcoLab1Events* pIEcoLab1Sink2 = 0;
	IEcoUnknown* pISinkUnk = 0;
	uint32_t cAdvise = 0;

	void* testDiag = 0;
	void** testMat = 0;
	size_t testSize = 4;
	size_t testSize2 = 6;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
	result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
	if (result != 0) {
		/* Освобождение в случае ошибки */
		goto Release;
	}
	result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorB, (IEcoUnknown*)GetIEcoComponentFactoryPtr_AE202E543CE54550899603BD70C62565);
	if (result != 0) {
		/* Освобождение в случае ошибки */
		goto Release;
	}
	result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorA, (IEcoUnknown*)GetIEcoComponentFactoryPtr_4828F6552E4540E78121EBD220DC360E);
	if (result != 0) {
		/* Освобождение в случае ошибки */
		goto Release;
	}
	result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorD, (IEcoUnknown*)GetIEcoComponentFactoryPtr_3A8E44677E82475CB4A3719ED8397E61);
	if (result != 0) {
		/* Освобождение в случае ошибки */
		goto Release;
	}
	result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoCalculatorE, (IEcoUnknown*)GetIEcoComponentFactoryPtr_872FEF1DE3314B87AD44D1E7C232C2F0);
	if (result != 0) {
		/* Освобождение в случае ошибки */
		goto Release;
	}
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
	result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**)&pIEcoLab1);
	if (result != 0 || pIEcoLab1 == 0) {
		/* Освобождение интерфейсов в случае ошибки */
		goto Release;
	}

	/* Проверка поддержки подключений обратного интерфейса */
	result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoConnectionPointContainer, (void**)&pICPC);
	if (result != 0 || pICPC == 0) {
		/* Освобождение интерфейсов в случае ошибки */
		goto Release;
	}
	/* Запрос на получения интерфейса точки подключения */
	result = pICPC->pVTbl->FindConnectionPoint(pICPC, &IID_IEcoLab1Events, &pICP);
	if (result != 0 || pICP == 0) {
		/* Освобождение интерфейсов в случае ошибки */
		goto Release;
	}

	/* Освобождение интерфейса */
	pICPC->pVTbl->Release(pICPC);
	/* Создание экземпляра обратного интерфейса */
	result = createCEcoLab1Sink(pIMem, (IEcoLab1Events**)&pIEcoLab1Sink);

	if (pIEcoLab1Sink != 0) {
		result = pIEcoLab1Sink->pVTbl->QueryInterface(pIEcoLab1Sink, &IID_IEcoUnknown, (void**)&pISinkUnk);
		if (result != 0 || pISinkUnk == 0) {
			/* Освобождение интерфейсов в случае ошибки */
			goto Release;
		}

		/* Подключение */
		result = pICP->pVTbl->Advise(pICP, pISinkUnk, &cAdvise);
		/* Проверка */
		if (result == 0 && cAdvise == 1) {
			/* Сюда можно добавить код */
		}

		/* Освобождение интерфейса */
		pISinkUnk->pVTbl->Release(pISinkUnk);
	}

	testDiag = initVI(pIMem, testSize);

	pIEcoLab1->pVTbl->set_diagi_main(pIEcoLab1, testDiag, testSize, &testMat);

	pIMem->pVTbl->Free(pIMem, testDiag);
	pIMem->pVTbl->Free(pIMem, testMat);

	testDiag = initVI(pIMem, testSize * 2 - abs(k));
	pIEcoLab1->pVTbl->set_diagi_k(pIEcoLab1, testDiag, testSize * 2, k, &testMat);

	pIMem->pVTbl->Free(pIMem, testDiag);
	pIMem->pVTbl->Free(pIMem, testMat);

	if (pIEcoLab1Sink != 0) {
		/* Отключение */
		result = pICP->pVTbl->Unadvise(pICP, cAdvise);
		pIEcoLab1Sink->pVTbl->Release(pIEcoLab1Sink);
	}

	result = createCEcoLab1Sink2(pIMem, (IEcoLab1Events**)&pIEcoLab1Sink2);

	if (pIEcoLab1Sink2 != 0) {
		result = pIEcoLab1Sink2->pVTbl->QueryInterface(pIEcoLab1Sink2, &IID_IEcoUnknown, (void**)&pISinkUnk);
		if (result != 0 || pISinkUnk == 0) {
			/* Освобождение интерфейсов в случае ошибки */
			goto Release;
		}

		/* Подключение */
		result = pICP->pVTbl->Advise(pICP, pISinkUnk, &cAdvise);
		/* Проверка */
		if (result == 0 && cAdvise == 1) {
			/* Сюда можно добавить код */
		}

		/* Освобождение интерфейса */
		pISinkUnk->pVTbl->Release(pISinkUnk);
	}

	testMat = initMatI(pIMem, testSize2);

	pIEcoLab1->pVTbl->get_diagi_main(pIEcoLab1, testMat, testSize2, &testDiag);

	pIMem->pVTbl->Free(pIMem, testDiag);
	pIMem->pVTbl->Free(pIMem, testMat);

	testMat = initMatI(pIMem, testSize2 * 2);
	pIEcoLab1->pVTbl->get_diagi_k(pIEcoLab1, testMat, testSize * 2, k, &testDiag);

	pIMem->pVTbl->Free(pIMem, testDiag);
	pIMem->pVTbl->Free(pIMem, testMat);

	if (pIEcoLab1Sink2 != 0) {
		/* Отключение */
		result = pICP->pVTbl->Unadvise(pICP, cAdvise);
		pIEcoLab1Sink2->pVTbl->Release(pIEcoLab1Sink2);
		pICP->pVTbl->Release(pICP);
	}

	/*result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void**)&pIY);
	if (result != 0 || pIY == 0) {
		goto Release;
	}

	result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void**)&pIX);
	if (result != 0 || pIX == 0) {
		goto Release;
	}

	printf("Tests for EcoLab1 component:\n");
	printf("Addition test 8 + 8 = %d\n", pIX->pVTbl->Addition(pIX, 8, 8));
	printf("Subtraction test 40 - 6 = %d\n", pIX->pVTbl->Subtraction(pIX, 40, 6));
    printf("Multiplication test 8 * 8 = %d\n", pIY->pVTbl->Multiplication(pIY, 8, 8));
    printf("Division test 40 / 6 = %d\n\n\n", pIY->pVTbl->Division(pIY, 40, 6));

	pIX->pVTbl->Release(pIX);
	pIY->pVTbl->Release(pIY);

	printf("\nStart checking interface properties with help QueryInterface:\n");

	result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void**)&pIUnknown);
	if (result == 0) {
		printf("Can get pointer to IUnknown via IEcoLab1\n");
	}

	result = pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoCalculatorY, (void**)&pIY);
	if (result == 0) {
		pIY->pVTbl->Release(pIY);
		printf("Can get pointer to IY via IUnknown\n");
	}

	result = pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoCalculatorX, (void**)&pIX);
	if (result == 0) {
		pIX->pVTbl->Release(pIX);
		printf("Can get pointer to IX via IUnknown\n");
	}

	result = pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoLab1, (void**)&pIEcoLab1);
	if (result == 0) {
		pIEcoLab1->pVTbl->Release(pIEcoLab1);
		printf("Can get pointer to IEcoLab1 via pIUnknown\n");
	}

	result = pIUnknown->pVTbl->QueryInterface(pIUnknown, &IID_IEcoLab1, (void**)&pIUnknown);
	if (result == 0) {
		pIUnknown->pVTbl->Release(pIUnknown);
		printf("Can get pointer to pIUnknown via pIUnknown\n");
	}

	result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void**)&pIX);
	if (result == 0) {
		pIX->pVTbl->Release(pIX);
		printf("Can get pointer to IX via IEcoLab1\n");
	}

	result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void**)&pIY);
	if (result == 0) {
		pIY->pVTbl->Release(pIY);
		printf("Can get pointer to IY via IEcoLab1\n");
	}

	result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoLab1, (void**)&pIEcoLab1);
	if (result == 0) {
		pIEcoLab1->pVTbl->Release(pIEcoLab1);
		printf("Can get pointer to IEcoLab1 via IEcoLab1\n");
	}

	result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorX, (void**)&pIX);
	if (result == 0) {
		pIX->pVTbl->Release(pIX);
		printf("Can get pointer to IX via IY\n");
	}
	result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorY, (void**)&pIY);
	if (result == 0) {
		pIY->pVTbl->Release(pIY);
		printf("Can get pointer to IY via IY\n");
	}
	result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoLab1, (void**)&pIEcoLab1);
	if (result == 0) {
		pIEcoLab1->pVTbl->Release(pIEcoLab1);
		printf("Can get pointer to IEcoLab1 via IY\n");
	}

	result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void**)&pIX);
	if (result == 0) {
		pIX->pVTbl->Release(pIX);
		printf("Can get pointer to IX via IX\n");
	}
	result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorY, (void**)&pIY);
	if (result == 0) {
		pIY->pVTbl->Release(pIY);
		printf("Can get pointer to IY via IX\n");
	}
	result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoLab1, (void**)&pIEcoLab1);
	if (result == 0) {
		pIEcoLab1->pVTbl->Release(pIEcoLab1);
		printf("Can get pointer to IEcoLab1 via IX\n");
	}*/
	
    /*srand(time(0));
    fopen_s(&resultFile, "result.csv", "w");
    fprintf(resultFile, "func_name,type,size,time\n");

    for (i = 0; i < 5; i++) {
        test_set_diagi_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagl_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagf_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagd_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagld_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagc_main(pIEcoLab1, resultFile, sizes[i], pIMem);

		test_set_diagi_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagl_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagf_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagd_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagld_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_set_diagc_k(pIEcoLab1, resultFile, sizes[i], pIMem);

		test_get_diagi_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagl_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagf_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagd_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagld_main(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagc_main(pIEcoLab1, resultFile, sizes[i], pIMem);

		test_get_diagi_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagl_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagf_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagd_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagld_k(pIEcoLab1, resultFile, sizes[i], pIMem);
		test_get_diagc_k(pIEcoLab1, resultFile, sizes[i], pIMem);
    }

    fclose(resultFile);*/

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

