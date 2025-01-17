Zeile 19
********************************************************************************
//void enter_progmode (void);
Zeile 22
********************************************************************************
//void enter_progmode_hvp (void);
Zeile 32
********************************************************************************
//void p16c_enter_progmode (void);
Zeile 43
********************************************************************************
//void p18_enter_progmode (void);
Zeile 431
********************************************************************************
void enter_progmode_hvp (void)
{
// copied from https://github.com/rweather/ardpicprog/blob/2f8b5405440b30b0390f6d9d459da70e70e894cd/ProgramPIC/ProgramPIC.pde#L1084-L1113

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
Zeile 650
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
Zeile 803
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
