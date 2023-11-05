Zeile 20
********************************************************************************
void enter_progmode (void);
Zeile 23
********************************************************************************
void enter_progmode_hvp (void);
Zeile 25
********************************************************************************
void exit_progmode_hvp (void);
Zeile 33
********************************************************************************
void p16c_enter_progmode (void);
Zeile 44
********************************************************************************
void p18_enter_progmode (void);
Zeile 433
********************************************************************************
void enter_progmode_hvp (void)
{
// Lower MCLR, VDD, DATA, and CLOCK initially.  This will put the
// PIC into the powered-off, reset state just in case.
ISP_HVP_MCLR_HV_OFF
ISP_HVP_VDD_OFF
ISP_DAT_0
ISP_CLK_0

// Wait for the lines to settle.
_delay_us(50);

// Switch DATA and CLOCK into outputs.
ISP_DAT_D_0
ISP_CLK_D_0

// Raise MCLR, then VDD.
ISP_HVP_MCLR_HV_ON
_delay_us(5);
ISP_HVP_VDD_ON
_delay_us(5);
}
Zeile 459
********************************************************************************
void p18_enter_progmode (void)
{
acquire_isp_dat_clk();
ISP_MCLR_0
_delay_us(300);
isp_send(0b10110010,8);
isp_send(0b11000010,8);
isp_send(0b00010010,8);
isp_send(0b00001010,8);
_delay_us(300);
ISP_MCLR_1
}
Zeile 621
********************************************************************************
void exit_progmode (void)
{
release_isp_dat_clk();
ISP_MCLR_1
_delay_ms(30);
ISP_MCLR_0
_delay_ms(30);
ISP_MCLR_1
}
Zeile 633
********************************************************************************
void exit_progmode_hvp (void)
{
// Lower MCLR, VDD, DATA, and CLOCK.
ISP_HVP_MCLR_HV_OFF
ISP_HVP_VDD_OFF
ISP_DAT_0
ISP_CLK_0

// Float the DATA and CLOCK pins.
ISP_DAT_D_I
ISP_CLK_D_I
}
Zeile 649
********************************************************************************
void p16c_enter_progmode (void)
{
acquire_isp_dat_clk();
ISP_MCLR_0
_delay_us(300);
isp_send_8_msb(0x4d);
isp_send_8_msb(0x43);
isp_send_8_msb(0x48);
isp_send_8_msb(0x50);
_delay_us(300);
}
Zeile 802
********************************************************************************
void enter_progmode (void)
{
// just in case PIC VDD is connected to ISP_HVP_VDD also for low voltage programming
ISP_HVP_VDD_ON
_delay_ms(500);

acquire_isp_dat_clk();
ISP_MCLR_0
_delay_us(300);
isp_send(0b01010000,8);
isp_send(0b01001000,8);
isp_send(0b01000011,8);
isp_send(0b01001101,8);

isp_send(0,1);
}
