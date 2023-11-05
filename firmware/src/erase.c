Zeile 27
********************************************************************************
void isp_mass_erase (void);
Zeile 35
********************************************************************************
void p16c_bulk_erase (void);
Zeile 52
********************************************************************************
void p18_isp_mass_erase (void);
Zeile 382
********************************************************************************
void isp_mass_erase (void)
{
//_delay_ms(10);
//_delay_us(3*ISP_CLK_DELAY);
//isp_send(0x11,6);
isp_send_config(0);
isp_send(0x09,6);
_delay_ms(10);
//isp_send(0x0B,6);
//_delay_ms(10);
}
Zeile 669
********************************************************************************
void p16c_bulk_erase (void)
{
  isp_send_8_msb(0x18);
  _delay_ms(100);
}
Zeile 741
********************************************************************************
void p18qxx_bulk_erase (void)
{
  isp_send_8_msb(0x18);
  _delay_us(2);
  isp_send_24_msb(0x00001e);    // Bit 3: Configuration memory Bit 1: Flash memory
  _delay_ms(11);
}
Zeile 820
********************************************************************************
void p18_isp_mass_erase (void)
{
p18_set_tblptr(0x3C0005);
p18_send_cmd_payload(0x0C,0x0F0F);
p18_set_tblptr(0x3C0004);
p18_send_cmd_payload(0x0C,0x8F8F);
p18_send_cmd_payload(0,0x0000);
isp_send(0x00,4);
_delay_ms(20);
isp_send(0x00,16);
}
Zeile 832
********************************************************************************
void p18fj_isp_mass_erase (void)
{
p18_set_tblptr(0x3C0005);
p18_send_cmd_payload(0x0C,0x0101);
p18_set_tblptr(0x3C0004);
p18_send_cmd_payload(0x0C,0x8080);
p18_send_cmd_payload(0,0x0000);
isp_send(0x00,4);
_delay_ms(600);
isp_send(0x00,16);
}
Zeile 844
********************************************************************************
void p18fk_isp_mass_erase (unsigned char data1, unsigned char data2, unsigned char data3)
{
unsigned int tmp1, tmp2, tmp3;
tmp1 = data1;
tmp1 = (tmp1<<8)|data1;
tmp2 = data2;
tmp2 = (tmp2<<8)|data2;
tmp3 = data3;
tmp3 = (tmp3<<8)|data3;
p18_set_tblptr(0x3C0004);
p18_send_cmd_payload(0x0C,tmp3);
p18_set_tblptr(0x3C0005);
p18_send_cmd_payload(0x0C,tmp2);
p18_set_tblptr(0x3C0006);
p18_send_cmd_payload(0x0C,tmp1);
p18_send_cmd_payload(0x00,0);
isp_send(0x00,4);
_delay_ms(5);
isp_send(0x00,16);
}
