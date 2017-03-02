#ifndef LIB_SPI_H
#define LIB_SPI_H

#include <stm32f4xx.h>

typedef struct
{
  uint16_t SPI_Direction;           /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref SPI_data_direction */

  uint16_t SPI_Mode;                /*!< Specifies the SPI operating mode.
                                         This parameter can be a value of @ref SPI_mode */

  uint16_t SPI_DataSize;            /*!< Specifies the SPI data size.
                                         This parameter can be a value of @ref SPI_data_size */

  uint16_t SPI_CPOL;                /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref SPI_Clock_Polarity */

  uint16_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref SPI_Clock_Phase */

  uint16_t SPI_NSS;                 /*!< Specifies whether the NSS signal is managed by
                                         hardware (NSS pin) or by software using the SSI bit.
                                         This parameter can be a value of @ref SPI_Slave_Select_management */

  uint16_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                         used to configure the transmit and receive SCK clock.
                                         This parameter can be a value of @ref SPI_BaudRate_Prescaler
                                         @note The communication clock is derived from the master
                                               clock. The slave clock does not need to be set. */

  uint16_t SPI_FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
                                         This parameter can be a value of @ref SPI_MSB_LSB_transmission */

  uint16_t SPI_CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation. */
}SPI_InitTypeDef;

void OpenSPI (SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);                       /* opne the SPIx, for x = 1, 2, 3 */
void CloseSPI (SPI_TypeDef* SPIx);                      /* close the SPI */
void PutTx1SPI (SPI_TypeDef* SPIx, uint16_t b);                    /* put 1 byte */
uint16_t  GetRx1SPI (void);                     /* get 1 byte */
void PutTxSPI (int n, ...);                /* put n bytes */
int  GetRxSPI (int n, ...);                /* get n bytes */
int  IOCTLSPI (int nFunc, ...);            /* I/O control function */

enum IOCTL_FUNC_TYPE
{
    IOC_SET_REG,            IOC_GET_REG,   /* set/get registers */

    /* Communication status flags*/
    IOC_SET_TXE,            IOC_GET_TXE,
    IOC_SET_RXNE,           IOC_GET_RXNE,
    IOC_SET_BSY,            IOC_GET_BSY,

}

#endif
