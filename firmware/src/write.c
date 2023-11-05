Zeile 39
********************************************************************************
void p16c_isp_write_cfg (unsigned int data, unsigned int addr);
Zeile 41
********************************************************************************
void p18q_isp_write_cfg (unsigned int data, unsigned long addr);
Zeile 355
********************************************************************************
//void isp_write_pgm (unsigned int * data, unsigned char n);
Zeile 357
********************************************************************************
void isp_write_pgm (unsigned int * data, unsigned char n, unsigned char slow)
{
unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
for (i=0;i<n;i++)  
  {
  isp_send(0x02,6);
  isp_send(data[i]<<1,16);  
  if (i!=(n-1))
    isp_send(0x06,6);
  }
isp_send(0x08,6);
if (slow==1)
  _delay_ms(5);
else
  _delay_ms(3);
isp_send(0x06,6);
}
Zeile 472
********************************************************************************
void p18fk_isp_write_pgm (unsigned int * data, unsigned long addr, unsigned char n)
{
unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
p18_send_cmd_payload(0,0x8E7F);
p18_send_cmd_payload(0,0x9C7F);
p18_send_cmd_payload(0,0x847F);
p18_set_tblptr(addr);
for (i=0;i<n-1;i++)  
  p18_send_cmd_payload(0x0D,data[i]);  
p18_send_cmd_payload(0x0F,data[n-1]);  
p_18_modfied_nop(0);
}
Zeile 486
********************************************************************************
void p18_isp_write_pgm (unsigned int * data, unsigned long addr, unsigned char n)
{
unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
p18_send_cmd_payload(0,0x8EA6);
p18_send_cmd_payload(0,0x9CA6);
p18_send_cmd_payload(0,0x84A6);
p18_set_tblptr(addr);
for (i=0;i<n-1;i++)  
  p18_send_cmd_payload(0x0D,data[i]);  
p18_send_cmd_payload(0x0F,data[n-1]);  
p_18_modfied_nop(1);
}
Zeile 500
********************************************************************************
void p18_isp_write_cfg (unsigned char data1, unsigned char data2, unsigned long addr)
{
unsigned int i;
//_delay_us(3*ISP_CLK_DELAY);
p18_send_cmd_payload(0,0x8EA6);
p18_send_cmd_payload(0,0x8CA6);
p18_send_cmd_payload(0,0x84A6);
p18_set_tblptr(addr);
p18_send_cmd_payload(0x0F,data1);  
p_18_modfied_nop(1);
_delay_ms(5);
p18_set_tblptr(addr+1);
i = data2;
i = i << 8;
p18_send_cmd_payload(0x0F,i);  
p_18_modfied_nop(1);
_delay_ms(5);
}
Zeile 538
********************************************************************************
void p18fk_isp_write_cfg (unsigned char data1, unsigned char data2, unsigned long addr)
{
unsigned int i;
//_delay_us(3*ISP_CLK_DELAY);
p18_send_cmd_payload(0,0x8E7F);
p18_send_cmd_payload(0,0x8C7F);
p18_set_tblptr(addr);
p18_send_cmd_payload(0x0F,data1);  
p_18_modfied_nop(1);
_delay_ms(5);
p18_set_tblptr(addr+1);
i = data2;
i = i << 8;
p18_send_cmd_payload(0x0F,i);  
p_18_modfied_nop(1);
_delay_ms(5);
}
Zeile 711
********************************************************************************
void p16c_isp_write_pgm (unsigned int * data, unsigned long addr, unsigned char n)
{
unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
p16c_set_pc(addr);
for (i=0;i<n;i++)  
  p16c_load_nvm(data[i],1);  
p16c_set_pc(addr);
p16c_begin_prog(0);
}
Zeile 732
********************************************************************************
void p16c_isp_write_cfg (unsigned int data, unsigned long addr)
{
//unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
p16c_set_pc(addr);
p16c_load_nvm(data,0);  
p16c_begin_prog(1);
}
Zeile 749
********************************************************************************
void p18q_isp_write_pgm (unsigned int * data, unsigned long addr, unsigned char n)
{
unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
p16c_set_pc(addr);
for (i=0;i<n;i++)
  {  
  isp_send_8_msb(0xE0);  
  _delay_us(2);
  isp_send_24_msb(data[i]);  
  _delay_us(65);
  }
}
Zeile 763
********************************************************************************
void p18q_isp_write_cfg (unsigned int data, unsigned long addr)
{
//unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
p16c_set_pc(addr);
isp_send_8_msb(0xE0);  
_delay_us(2);
isp_send_24_msb(data);  
_delay_us(65); 
}
