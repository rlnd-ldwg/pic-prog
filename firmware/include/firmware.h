/*
 * firmware.h v1.0.0
 * 
 * Copyright October 2023 R.Ludwig
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * constant and macro definition for main program
 * 
 * initial version 2023/10/26
 * 
 */
 
#ifndef FW_H
#define FW_H

#define ISP_PORT  PORTC
#define ISP_DDR   DDRC
#define ISP_PIN   PINC
#define ISP_CLK   0     // A0/PC0 PIC: programm clock (PGC)
#define ISP_DAT   1     // A1/PC1 PIC: programm data (PGD)
#define ISP_MCLR  3     // A3/PC3 PIC: reset (MCLR)
#define ISP_HVP_MCLR 4  // A4/PC4 PIC: VPP (same as MCLR Pin but for HVP - conversion necessary to use LVP and HPV together
#define ISP_HVP_VDD  2  // A2/PC2 PIC: VDD 

#define ISP_CLK_DELAY  1
#define _BAUD   57600   				// Baud rate (9600 is default)
#define _UBRR   (F_CPU/16)/_BAUD - 1	// Used for UBRRL and UBRRH 

#define ISP_MCLR_1 ISP_PORT |= (1<<ISP_MCLR);
#define ISP_MCLR_0 ISP_PORT &= ~(1<<ISP_MCLR);
#define ISP_MCLR_D_I ISP_DDR &= ~(1<<ISP_MCLR);
#define ISP_MCLR_D_0 ISP_DDR |= (1<<ISP_MCLR);

#define ISP_DAT_1 ISP_PORT |= (1<<ISP_DAT);
#define ISP_DAT_0 ISP_PORT &= ~(1<<ISP_DAT);
#define ISP_DAT_V (ISP_PIN&(1<<ISP_DAT))
#define ISP_DAT_D_I ISP_DDR &= ~(1<<ISP_DAT);
#define ISP_DAT_D_0 ISP_DDR |= (1<<ISP_DAT);

#define ISP_CLK_1 ISP_PORT |= (1<<ISP_CLK);
#define ISP_CLK_0 ISP_PORT &= ~(1<<ISP_CLK);
#define ISP_CLK_D_I ISP_DDR &= ~(1<<ISP_CLK);
#define ISP_CLK_D_0 ISP_DDR |= (1<<ISP_CLK);

#define ISP_HVP_MCLR_HV_OFF ISP_PORT |= (1<<ISP_HVP_MCLR); // inverted by transistor
#define ISP_HVP_MCLR_HV_ON ISP_PORT &= ~(1<<ISP_HVP_MCLR); // inverted by transistor
#define ISP_HVP_MCLR_D_I ISP_DDR &= ~(1<<ISP_HVP_MCLR);
#define ISP_HVP_MCLR_D_0 ISP_DDR |= (1<<ISP_HVP_MCLR);

#define ISP_HVP_VDD_ON ISP_PORT |= (1<<ISP_HVP_VDD);
#define ISP_HVP_VDD_OFF ISP_PORT &= ~(1<<ISP_HVP_VDD);
#define ISP_HVP_VDD_D_I ISP_DDR &= ~(1<<ISP_HVP_VDD);
#define ISP_HVP_VDD_D_0 ISP_DDR |= (1<<ISP_HVP_VDD);

#endif
