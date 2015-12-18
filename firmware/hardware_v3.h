/*    Copyright (C) 2014 GP Orcullo
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef __HARDWARE_V3__
#define __HARDWARE_V3__

#define SYS_FREQ                (80000000ul)
#define GetSystemClock()        (SYS_FREQ)
#define	GetPeripheralClock()	(GetSystemClock())
#define	GetInstructionClock()	(GetSystemClock())

/*    PORT USAGE
 *
 *	Pin	Port	Dir	Signal
 *
 *  1   RE5     IN  E_STOP
 *  2   RE6     IN  Y_MIN
 *  3   RE7     IN  TOUCH_OFF
 *  4   RG6     IN  SPI_CLK
 *  5   RG7     IN  SPI_MOSI
 *  6   RG8     OUT SPI_MISO
 *  7   MCLR
 *  8   RG9     IN  nSPI_CE0
 *  11  RB5     OUT LED1
 *  12  RB4     OUT LED2
 *  13  RB3     OUT LED3
 *  14  RB2     OUT LED4
 *  15  RB1     PGC
 *  16  RB0     PGD
 *  17  RB6     OUT N.C.
 *  18  RB7     OUT N.C.
 *  21  RB8     OUT N.C.
 *  22  RB9     OUT N.C.
 *  23 TMS
 *  24 TDO
 *  27 TCK
 *  28 TDI
 *  29 RB14    OUT N.C.
 *  30 RB15    OUT N.C.
 *  31 RF4     IN  SCL
 *  32 RF5     IN  SDA
 *  33 RF3     OUT N.C.
 *  34 VBUS
 *  36 USB D-
 *  37 USB D+
 *  42 RD8     OUT X DIR
 *  43 RD9     OUT Y DIR
 *  44 RD10    OUT Z DIR
 *  45 RD11    OUT E0 DIR (A DIR)
 *  46 RD0     OUT X STEP
 *  47 RC13    OUT E1 DIR (Coolant ON/OFF)
 *  48 RC14    OUT Output Driver Enable
 *  49 RD1     OUT Y STEP
 *  50 RD2     OUT Z STEP
 *  51 RD3     OUT E0 STEP   (A STEP)
 *  52 RD4     OUT E1 STEP   (SPINDLE ENABLE)
 *  53 RD5     OUT X Enable  (ENABLE)
 *  54 RD6     OUT Y Enable  (MIST ENABLE)
 *  55 RD7     OUT Z Enable  (FLOOD ENABLE)
 *  58 RF0     OUT E0 Enable (A ENABLE)
 *  59 RF1     OUT E1 Enable
 *  60 RE0     IN  X MAX
 *  61 RE1     IN  Z MAX
 *  62 RE2     IN  X MIN
 *  63 RE3     IN  Z MIN
 *  64 RE4     IN  Y MAX
 *
 */

#define SET_STOP_INPUT      do{TRISESET = BIT_5;}while(0)
#define SET_TOUCHOFF_INPUT  do{TRISESET = BIT_7;}while(0)
#define SET_X_MAX_INPUT     do{TRISESET = BIT_0;}while(0)
#define SET_X_MIN_INPUT     do{TRISESET = BIT_2;}while(0)
#define SET_Y_MAX_INPUT     do{TRISESET = BIT_4;}while(0)
#define SET_Y_MIN_INPUT     do{TRISESET = BIT_6;}while(0)
#define SET_Z_MAX_INPUT     do{TRISESET = BIT_1;}while(0)
#define SET_Z_MIN_INPUT     do{TRISESET = BIT_3;}while(0)

#define STOP_IN         (PORTEbits.RE5)
#define TOUCHOFF_IN     (PORTEbits.RE7)
#define X_MAX_IN        (PORTEbits.RE0)
#define X_MIN_IN        (PORTEbits.RE2)
#define Z_MAX_IN        (PORTEbits.RE1)
#define Z_MIN_IN        (PORTEbits.RE3)
#define Y_MAX_IN        (PORTEbits.RE4)
#define Y_MIN_IN        (PORTEbits.RE6)

#define HOME_A_IN		(X_MAX_IN)
#define HOME_X_IN		(X_MIN_IN)
#define HOME_Y_IN		(Y_MIN_IN)
#define HOME_Z_IN		(Z_MIN_IN)

#define SET_DRV_OUTPUT          do{TRISCCLR = BIT_14;}while(0)
#define SET_ENABLE_OUTPUT		do{TRISDCLR = BIT_5;}while(0)
#define SET_COOLANT_OUTPUT      do{TRISCCLR = BIT_13;}while(0)
#define SET_SPINDLE_EN_OUTPUT	do{TRISDCLR = BIT_4;}while(0)
#define SET_MIST_EN_OUTPUT		do{TRISDCLR = BIT_6;}while(0)
#define SET_FLOOD_EN_OUTPUT		do{TRISDCLR = BIT_7;}while(0)
#define SET_E1_ENABLE_OUTPUT    do{TRISFCLR = BIT_1;}while(0)

// AXIS drives
#define SET_STEP_X_OUTPUT		do{TRISDCLR = BIT_0;}while(0)
#define SET_DIR_X_OUTPUT		do{TRISDCLR = BIT_8;}while(0)
#define SET_STEP_Y_OUTPUT		do{TRISDCLR = BIT_1;}while(0)
#define SET_DIR_Y_OUTPUT		do{TRISDCLR = BIT_9;}while(0)
#define SET_STEP_Z_OUTPUT		do{TRISDCLR = BIT_2;}while(0)
#define SET_DIR_Z_OUTPUT		do{TRISDCLR = BIT_10;}while(0)
#define SET_STEP_A_OUTPUT		do{TRISDCLR = BIT_3;}while(0)
#define SET_DIR_A_OUTPUT		do{TRISDCLR = BIT_11;}while(0)

// LED Outputs
#define SET_LED4_OUTPUT         do{TRISBCLR = BIT_2;}while(0)
#define SET_LED3_OUTPUT         do{TRISBCLR = BIT_3;}while(0)
#define SET_LED2_OUTPUT         do{TRISBCLR = BIT_4;}while(0)
#define SET_LED1_OUTPUT         do{TRISBCLR = BIT_5;}while(0)

#define DRIVER_LO        (LATCCLR = BIT_14)
#define DRIVER_HI        (LATCSET = BIT_14)
#define ENABLE_LO		 (LATDCLR = BIT_5)
#define ENABLE_HI		 (LATDSET = BIT_5)
#define SPINDLE_EN_LO	 (LATDCLR = BIT_4)
#define SPINDLE_EN_HI    (LATDSET = BIT_4)
#define MIST_EN_LO		 (LATDCLR = BIT_6)
#define MIST_EN_HI		 (LATDSET = BIT_6)
#define COOLANT_EN_LO    (LATCCLR = BIT_13)
#define COOLANT_EN_HI    (LATCSET = BIT_13)
#define COOLANT_TOGGLE   (LATCINV = BIT_13)
#define FLOOD_EN_LO		 (LATDCLR = BIT_7)
#define FLOOD_EN_HI		 (LATDSET = BIT_7)
#define E1_ENABLE_LO     (LATFCLR = BIT_1)
#define E1_ENABLE_HI     (LATFSET = BIT_1)
#define E1_ENABLE_TOGGLE (LATFINV = BIT_1)
#define STEP_X_LO		 (LATDCLR = BIT_0)
#define STEP_X_HI		 (LATDSET = BIT_0)
#define DIR_X_LO		 (LATDCLR = BIT_8)
#define DIR_X_HI		 (LATDSET = BIT_8)
#define STEP_Y_LO		 (LATDCLR = BIT_1)
#define STEP_Y_HI		 (LATDSET = BIT_1)
#define DIR_Y_LO		 (LATDCLR = BIT_9)
#define DIR_Y_HI		 (LATDSET = BIT_9)
#define STEP_Z_LO		 (LATDCLR = BIT_2)
#define STEP_Z_HI		 (LATDSET = BIT_2)
#define DIR_Z_LO		 (LATDCLR = BIT_10)
#define DIR_Z_HI		 (LATDSET = BIT_10)
#define STEP_A_LO		 (LATDCLR = BIT_3)
#define STEP_A_HI		 (LATDSET = BIT_3)
#define DIR_A_LO		 (LATDCLR = BIT_11)
#define DIR_A_HI		 (LATDSET = BIT_11)
#define LED4_LO          (LATBCLR = BIT_2)
#define LED4_HI          (LATBSET = BIT_2)
#define LED4_TOGGLE      (LATBINV = BIT_2)
#define LED3_LO          (LATBCLR = BIT_3)
#define LED3_HI          (LATBSET = BIT_3)
#define LED3_TOGGLE      (LATBINV = BIT_3)
#define LED2_LO          (LATBCLR = BIT_4)
#define LED2_HI          (LATBSET = BIT_4)
#define LED2_TOGGLE      (LATBINV = BIT_4)
#define LED1_LO          (LATBCLR = BIT_5)
#define LED1_HI          (LATBSET = BIT_5)
#define LED1_TOGGLE      (LATBINV = BIT_5)


#endif /* __HARDWARE_V3__ */
