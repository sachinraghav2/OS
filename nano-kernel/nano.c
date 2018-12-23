// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#include <stdlib.h>
#include <util/delay.h>


// Define here the global static variables
//unsigned char *SP1;
//SP1 = (unsigned char *)SP;
 struct tasks{
	     int tid;
	     int priority;
	     char status;
	     }T[2]={{1,1,'r'},{2,2,'r'}};
	struct pointers{
		uint16_t  *bptr;
		unsigned char *uptr;
		void (*b_funptr)(void);
		void (*u_funptr)(void);
		}p;
//
int flag;


// Interrupt handler example for INT0
//
ISR (TIMER2_COMP_vect){
	asm("in r21, 0x3d");
	asm("in r22, 0x3e");
	if(flag==0)
	{
       	asm("ldi r16, 0x70");
	 	  asm("out 0x3d, r16");
	 	  asm("ldi r16, 0x00");
		  asm("out 0x3e , r16");
		    asm("push r21");
		      asm("push r22");
		  asm("push r16");
		  asm("push r17");
		  asm("push r18");
		  p.bptr =(uint16_t *) SP;
	}
	else
	{
			asm("ldi r16, 0x90");
	 	  asm("out 0x3d, r16");
	 	  asm("ldi r16, 0x00");
		  asm("out 0x3e , r16");
		   asm("push r21");
		    asm("push r22");
		  asm("push r16");
		  asm("push r17");
		  asm("push r18");
		  	  p.uptr=(unsigned char *)SP;
		}
	flag = (flag^1);
	if(flag==0)
	{
		SP= (uint16_t *)p.bptr;
		asm("pop r18");		
		asm("pop r17");
		asm("pop r16");
//		SP = p.b_funptr;
		}
	else
	{
		SP=
		asm("pop r18");		
		asm("pop r17");
		asm("pop r16");
//*SP = p.u_funptr;
		}
}		

void delay	(	double d	 ) 	
{
		_delay_us(d);
}
	
void blink_init(void)
{
		
//	char *bsp=malloc(sizeof(char)*32);
		asm("in r21, 0x3d");
	asm("in r22, 0x3e");
       	asm("ldi r16, 0x70");
	 	  asm("out 0x3d, r16");
	 	  asm("ldi r16, 0x00");
		  asm("out 0x3e , r16");
//	  asm("ldi r16, LOW(_blink<<1)");
//	  asm("ldi r16, HIGH(_blink<<1)");
//		  asm("push r16");
//		  asm(" push LOW(blink_init) ");
	asm("ldi r16, 0");
	asm("ldi r17, 0");
	asm("ldi r18, 0");
		  asm("push r16");
		  asm("push r17");
		  asm("push r18");
		     p.bptr=(unsigned char *)SP;
		  asm("out 0x3d, r21");
		  asm("out 0x3e, r22");
	

	       }	
	
	
void uart_init(void)
{
	asm("in r21, 0x3d");
	asm("in r22, 0x3e");
       	asm("ldi r16, 0x90");
	 	  asm("out 0x3d, r16");
	 	  asm("ldi r16, 0x00");
		  asm("out 0x3e , r16");
	asm("ldi r16, 0");
	asm("ldi r17, 0");
	asm("ldi r18, 0");
		  asm("push r16");
		  asm("push r17");
		  asm("push r18");
		  	  p.uptr=(unsigned char *)SP;
		  UBRRL = 0x33;
		  UCSRB = (1<<TXEN) | (1<<RXEN);
		  UCSRC = (1<<UCSZ1) | (1<<UCSZ0) | (1<<URSEL);
		  asm("out 0x3d, r21");
		  asm("out 0x3e, r22");
	//	  asm("out pcl, r22");
	
		//  asm("ret")       ;
	//	  asm("mov r16, 0x00");
}

/*void load_SP(unsigned char sph, unsigned char spl)
{
    SP = (sph << 8) | spl;
} */


void blink(void)
{
	while(1)
	{
		PORTB = 0x55;
		delay(1000);
		PORTB = 0xaa;
		delay(1000);
	}
}
void uart_send(void)
{
	while(1)
		{
			while( ! ( UCSRA & (1<<RXC) ) );
			while( ! ( UCSRA & (1<<UDRE) ) );
			UDR = 'A';
		}
}

int main(void) {
			uart_init();
	     blink_init();
	     p.b_funptr = &blink;
	     p.u_funptr = &uart_send;
	     DDRB = 0xff;
	    TCNT2 = 0;
	    OCR2 = 98;
	    TCCR2 |= (1<<CS20) | (1<<CS21) | (1<<CS22) | (1<<WGM21);
	    TIMSK |= (1<<OCIE2) ;
	    sei();
	    blink();
	
	
				

   while(1) {             // Infinite loop; define here the
     // my_function();      // system behaviour
   }

}






