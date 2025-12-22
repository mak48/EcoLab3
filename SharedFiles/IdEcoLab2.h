
/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoLab2
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoLab2
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

#ifndef __ID_ECOLAB2_H__
#define __ID_ECOLAB2_H__

#include "IEcoBase1.h"
//#include "IEcoLab2.h"

/* EcoLab2 CID = {B4140439-2CF2-4C3E-A036-54C799165BDD} */
#ifndef __CID_EcoLab2
static const UGUID CID_EcoLab2 = {0x01, 0x10, {0xB4, 0x14, 0x04, 0x39, 0x2C, 0xF2, 0x4C, 0x3E, 0xA0, 0x36, 0x54, 0xC7, 0x99, 0x16, 0x5B, 0xDD}};
#endif /* __CID_EcoLab2 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_B41404392CF24C3EA03654C799165BDD;
#endif

#endif /* __ID_ECOLAB2_H__ */

