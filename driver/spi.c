#include <spi.h>

/* SPI registers Masks */
#define CR1_CLEAR_MASK            ((uint16_t)0x3040)
#define I2SCFGR_CLEAR_MASK        ((uint16_t)0xF040)

void OpenSPI (SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct)
{
    uint16_t tmpreg = 0;
    /* Get the SPIx CR1 value */
    tmpreg = SPIx->CR1;
    /* Clear BIDIMode, BIDIOE, RxONLY, SSM, SSI, LSBFirst, BR, MSTR, CPOL and CPHA bits */
    tmpreg &= CR1_CLEAR_MASK;
    /* Configure SPIx: direction, NSS management, first transmitted bit, BaudRate prescaler
     master/salve mode, CPOL and CPHA */
    tmpreg |= (uint16_t)((uint32_t)SPI_InitStruct->SPI_Direction | SPI_InitStruct->SPI_Mode |
                  SPI_InitStruct->SPI_DataSize | SPI_InitStruct->SPI_CPOL |
                  SPI_InitStruct->SPI_CPHA | SPI_InitStruct->SPI_NSS |
                  SPI_InitStruct->SPI_BaudRatePrescaler | SPI_InitStruct->SPI_FirstBit);
    /* Write to SPIx CR1 */
    SPIx->CR1 = tmpreg;
    /* Activate the SPI mode (Reset I2SMOD bit in I2SCFGR register) */
    SPIx->I2SCFGR &= (uint16_t)~((uint16_t)SPI_I2SCFGR_I2SMOD);
    /* Enable the selected SPI peripheral */
    SPIx->CR1 |= SPI_CR1_SPE;
}

void CloseSPI (SPI_TypeDef* SPIx)
{
    SPIx->CR1 &= (uint16_t)~((uint16_t)SPI_CR1_SPE);
}

void PutTx1SPI (SPI_TypeDef* SPIx, uint16_t data)
{
    SPIx->DR = data;
}

uint16_t GetRx1SPI (void)
{
    return SPIx->DR;
}

void PutTxSPI (int )
