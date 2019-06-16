

volatile unsigned long SysTime_cur = 0;

								
#define	FSP_TYPE			unsigned char	
#define set_newfs(p, fs)    psw[p].fsp = fs, psw[p].T = SysTime_cur
#define startp(p)			psw[p].fsp = FS_START, psw[p].T = SysTime_cur
#define stopp(p)			psw[p].fsp = FS_STOP
#define check_active(p)	    ((psw[p].fsp != FS_STOP)/* && (psw[p].fsp != FS_ERROR)*/)
#define check_passive(p)    ((psw[p].fsp == FS_STOP)/* || (psw[p].fsp == FS_ERROR)*/)
#define resetT(p)            psw[p].T = SysTime_cur;
#define timeout(p, N)       if((SysTime_cur - psw[p].T) >= N)
#define SET_BIT(r, b)		(r |= (1<<b))
#define CLR_BIT(r, b)		(r &= ~(1<<b))


unsigned long ic_common_bkg_proc_time;

#line 760 "atmega168.ih"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
volatile unsigned long ovf_cnt = 0;


unsigned long ic_ts_millis()
{
unsigned char sreg = SREG;
cli();
unsigned long ovf = ovf_cnt;
unsigned long tcnt = TCNT0;
SREG = sreg;


if ((TIFR0 & _BV(TOV0)) && (tcnt < 255))
ovf++;


unsigned long fract;
const unsigned long mfcpu = F_CPU/1000;

fract = ovf % mfcpu;
fract <<= (8UL + 10UL);
fract /= mfcpu;

ovf /= mfcpu;
ovf <<= (8UL + 10UL);
ovf += fract;
return ovf + (tcnt << 10UL) / mfcpu;
}


ISR(TIMER0_OVF_vect)
{
ovf_cnt++;
}


void ic_ts_init()
{

TCCR0A = 0;
TCCR0B = (1<<CS00) | (1 <<CS02);
TIMSK0 = (1<<TOIE0);
}

#line 29 "test168new.ic"
int program_0_led1_on_time = 100;
int program_0_led1_off_time = 200;
int program_0_led1_pin_num = 0;
int program_0_led2_on_time = 200;
int program_0_led2_off_time = 400;
int program_0_led2_pin_num = 1;
int program_0_led3_on_time = 400;
int program_0_led3_off_time = 800;
int program_0_led3_pin_num = 2;
int program_0_led4_on_time = 800;
int program_0_led4_off_time = 1600;
int program_0_led4_pin_num = 3;
int program_0_led5_on_time = 1600;
int program_0_led5_off_time = 3200;
int program_0_led5_pin_num = 4;

//=============================================================================
//Process type: Blink
//=============================================================================

#line 3
enum PROCESSES
{
	Init,
	Led1Blink,
	Led2Blink,
	Led3Blink,
	Led4Blink,
	Led5Blink,
	PROC_NUM,
};

const FSP_TYPE FS_STOP = 0;
const FSP_TYPE FS_START = 1;

typedef struct
{
	volatile  FSP_TYPE fsp;
	volatile unsigned long T;
}S_PROC_DATA_STRUCT;
S_PROC_DATA_STRUCT psw[PROC_NUM];

int main()
{
	ic_ts_init();
	sei();
	startp(Init);
	while(1)
	{

		ATOMIC_BLOCK(ATOMIC_FORCEON){
			SysTime_cur = ic_ts_millis();
		}
//=============================================================================
//Process: Init
//=============================================================================

#line 51
		switch(psw[Init].fsp)
		{
			case FS_START:
			{
				startp(Led1Blink);
				startp(Led2Blink);
				startp(Led3Blink);
				startp(Led4Blink);
				startp(Led5Blink);
				stopp(Init);

			} //state FS_START
			break;

		}  //process Init

enum Led1Blink_STATES
{
	Led1BlinkOn=3,
	Led1BlinkOff=4,
};

//=============================================================================
//Process: Led1Blink
//=============================================================================

#line 45
		switch(psw[Led1Blink].fsp)
		{

#line 5
			case FS_START:
			{
				DDRB |= (1 << program_0_led1_pin_num);
				PORTB |= (1 << program_0_led1_pin_num);
				set_newfs(Led1Blink, Led1BlinkOn);
			} //state FS_START
			break;


#line 11
			case Led1BlinkOn:
			{
				if((SysTime_cur - psw[Led1Blink].T) >= program_0_led1_on_time)//Timeout
				{
					PORTB &= ~(1 << program_0_led1_pin_num);
					set_newfs(Led1Blink, Led1BlinkOff);
				}
			} //state Led1BlinkOn
			break;


#line 19
			case Led1BlinkOff:
			{
				if((SysTime_cur - psw[Led1Blink].T) >= program_0_led1_off_time)//Timeout
				{
					PORTB |= (1 << program_0_led1_pin_num);
					set_newfs(Led1Blink, Led1BlinkOn);
				}
			} //state Led1BlinkOff
			break;

		}  //process Led1Blink

enum Led2Blink_STATES
{
	Led2BlinkOn=3,
	Led2BlinkOff=4,
};

//=============================================================================
//Process: Led2Blink
//=============================================================================

#line 46
		switch(psw[Led2Blink].fsp)
		{

#line 5
			case FS_START:
			{
				DDRB |= (1 << program_0_led2_pin_num);
				PORTB |= (1 << program_0_led2_pin_num);
				set_newfs(Led2Blink, Led2BlinkOn);
			} //state FS_START
			break;


#line 11
			case Led2BlinkOn:
			{
				if((SysTime_cur - psw[Led2Blink].T) >= program_0_led2_on_time)//Timeout
				{
					PORTB &= ~(1 << program_0_led2_pin_num);
					set_newfs(Led2Blink, Led2BlinkOff);
				}
			} //state Led2BlinkOn
			break;


#line 19
			case Led2BlinkOff:
			{
				if((SysTime_cur - psw[Led2Blink].T) >= program_0_led2_off_time)//Timeout
				{
					PORTB |= (1 << program_0_led2_pin_num);
					set_newfs(Led2Blink, Led2BlinkOn);
				}
			} //state Led2BlinkOff
			break;

		}  //process Led2Blink

enum Led3Blink_STATES
{
	Led3BlinkOn=3,
	Led3BlinkOff=4,
};

//=============================================================================
//Process: Led3Blink
//=============================================================================

#line 47
		switch(psw[Led3Blink].fsp)
		{

#line 5
			case FS_START:
			{
				DDRB |= (1 << program_0_led3_pin_num);
				PORTB |= (1 << program_0_led3_pin_num);
				set_newfs(Led3Blink, Led3BlinkOn);
			} //state FS_START
			break;


#line 11
			case Led3BlinkOn:
			{
				if((SysTime_cur - psw[Led3Blink].T) >= program_0_led3_on_time)//Timeout
				{
					PORTB &= ~(1 << program_0_led3_pin_num);
					set_newfs(Led3Blink, Led3BlinkOff);
				}
			} //state Led3BlinkOn
			break;


#line 19
			case Led3BlinkOff:
			{
				if((SysTime_cur - psw[Led3Blink].T) >= program_0_led3_off_time)//Timeout
				{
					PORTB |= (1 << program_0_led3_pin_num);
					set_newfs(Led3Blink, Led3BlinkOn);
				}
			} //state Led3BlinkOff
			break;

		}  //process Led3Blink

enum Led4Blink_STATES
{
	Led4BlinkOn=3,
	Led4BlinkOff=4,
};

//=============================================================================
//Process: Led4Blink
//=============================================================================

#line 48
		switch(psw[Led4Blink].fsp)
		{

#line 5
			case FS_START:
			{
				DDRB |= (1 << program_0_led4_pin_num);
				PORTB |= (1 << program_0_led4_pin_num);
				set_newfs(Led4Blink, Led4BlinkOn);
			} //state FS_START
			break;


#line 11
			case Led4BlinkOn:
			{
				if((SysTime_cur - psw[Led4Blink].T) >= program_0_led4_on_time)//Timeout
				{
					PORTB &= ~(1 << program_0_led4_pin_num);
					set_newfs(Led4Blink, Led4BlinkOff);
				}
			} //state Led4BlinkOn
			break;


#line 19
			case Led4BlinkOff:
			{
				if((SysTime_cur - psw[Led4Blink].T) >= program_0_led4_off_time)//Timeout
				{
					PORTB |= (1 << program_0_led4_pin_num);
					set_newfs(Led4Blink, Led4BlinkOn);
				}
			} //state Led4BlinkOff
			break;

		}  //process Led4Blink

enum Led5Blink_STATES
{
	Led5BlinkOn=3,
	Led5BlinkOff=4,
};

//=============================================================================
//Process: Led5Blink
//=============================================================================

#line 49
		switch(psw[Led5Blink].fsp)
		{

#line 5
			case FS_START:
			{
				DDRB |= (1 << program_0_led5_pin_num);
				PORTB |= (1 << program_0_led5_pin_num);
				set_newfs(Led5Blink, Led5BlinkOn);
			} //state FS_START
			break;


#line 11
			case Led5BlinkOn:
			{
				if((SysTime_cur - psw[Led5Blink].T) >= program_0_led5_on_time)//Timeout
				{
					PORTB &= ~(1 << program_0_led5_pin_num);
					set_newfs(Led5Blink, Led5BlinkOff);
				}
			} //state Led5BlinkOn
			break;


#line 19
			case Led5BlinkOff:
			{
				if((SysTime_cur - psw[Led5Blink].T) >= program_0_led5_off_time)//Timeout
				{
					PORTB |= (1 << program_0_led5_pin_num);
					set_newfs(Led5Blink, Led5BlinkOn);
				}
			} //state Led5BlinkOff
			break;

		}  //process Led5Blink

	} //while loop
} //main
