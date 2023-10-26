/*
 * commands.h v1.0.0
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
 * known firmware commands for PIC programmer
 * used in firmware.c and pp3.c
 * 
 * initial version 2023/10/25
 * 
 */

#ifndef CMD_H
#define CMD_H

#define ENTER_PROGMODE          0x01
#define EXIT_PROGMODE           0x02

#define ISP_RESET_PTR           0x03
#define ISP_SEND_CFG            0x04
#define ISP_INC_PTR             0x05
#define ISP_READ_PGM            0x06
#define ISP_MASS_ERASE          0x07
#define ISP_WRITE_PGM           0x08
#define ISP_RESET_PTR           0x09

#define P18_ENTER_PROGMODE      0x10
#define P18_ENTER_PROGMODE      0x11
#define P18_ISP_WRITE_PGM       0x12
#define P18_ISP_MASS_ERASE      0x13
#define P18_ISP_WRITE_CFG       0x14

#define P18FJ_ISP_MASS_ERASE    0x23
#define P18FK_ISP_MASS_ERASE    0x30
#define P18FK_ISP_WRITE_PGM     0x31
#define P18FK_ISP_WRITE_CFG     0x32

#define P16C_ENTER_PROGMODE     0x40
#define P16C_ISP_READ_PGM       0x41
#define P16C_ISP_WRITE_PGM      0x42
#define P16C_BULK_ERASE         0x43
#define P16C_ISP_WRITE_CFG      0x44
#define P18Q_ISP_WRITE_CFG      0x45		// check with v
#define P18Q_ISP_WRITE_PGM      0x46
#define P18Q_ISP_READ_CFG       0x47
#define P18Q_ISP_WRITE_CFG_ADDR 0x48		// check with ^
#define P18QXX_BULK_ERASE       0x49

#define ENTER_PROGMODE_HVP      0x91
#define EXIT_PROGMODE_HVP       0x92

#endif
