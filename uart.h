#ifndef __UART_H__
#define __UART_H__
#define uchar unsigned char
#define uint unsigned int
#define SUCCESS 0
#define FAILURE 1

////////////////////////////////////////////////////////////////////////////////////////
void init_USART1(void);
void put_c1(unsigned char c);
unsigned char USART_Receive1( void );
unsigned char receiveStrfromCom(void);
void outStrtoCom(unsigned char *pData,unsigned int length);
/////////////////////////////////////////////////////////////////////////////////////////
/*
void init_USART2(void);
void put_c2(unsigned char c);
unsigned char USART_Receive2( void );
unsigned char receiveStrfromGPRS(void);
void outStrtoGPRS(unsigned char *pData,unsigned int length);*/
///////////////////////////////////////////////////////////////////////////////////////
void MAC_CalCrc16(unsigned char  *pInput, unsigned char * pCrc16, unsigned char ucLen);
unsigned char MAC_CheckCrc16(unsigned char * pInput, unsigned char ucLen);
//////////////////////////////////////////////////////////////////////////////////////
void ComSendResponse(unsigned char CmdData,unsigned char statusdata,unsigned char LenData);
//void GprsSendResponse(unsigned char CmdData,unsigned char statusdata);
unsigned long GetCRC32(unsigned char *szData, unsigned long crc,unsigned long dwSize);


#endif