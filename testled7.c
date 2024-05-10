unsigned char code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
// Define pin for 74HC595
#define SHCP_PIN PIN_C0
#define DS_PIN PIN_C1
#define STCP_PIN PIN_C2
void IC_74HC595(uint8_t data)
{
    uint8_t i;
    output_low(SHCP_PIN);
    for (i = 0; i <= 7; i++)
    {
        if ((data & 0x80) == 0)
            output_low(DS_PIN);
        else
            output_high(DS_PIN);
        data = data << 1;
        output_high(SHCP_PIN);
        output_low(SHCP_PIN);
    }
}
void IC_74HC595_Output()
{
    output_low(STCP_PIN);
    delay_us(5);
    output_high(STCP_PIN);
    output_low(STCP_PIN);
}
void main(void)
{
    uint8_t i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            IC_74HC595(code7seg[i]);
            IC_74HC595(code7seg[j]);
            IC_74HC595_Output();
            delay_ms(100);
        }
    }
}
