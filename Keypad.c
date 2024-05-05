#include "Keypad.h"

char keypad(){
	while(1){
	c1=c2=c3=c4=1;
	r1=0;r2=1;r3=1;r4=1;
	if(c1==0){
		while(c1==0);
		return '1';
	}
	else if(c2==0){
		while(c2==0);
		return '2';

	}
	else if(c3==0){
		while(c3==0);
		return '3';

	}
	else if(c4==0){
		while(c4==0);
		return 'A';
	}
	r1=1;r2=0;r3=1;r4=1;
	if(c1==0)
		{
		while(c1==0);
		return '4';

		}
	else if(c2==0){
		while(c2==0);
		return '5';

	}
	else if(c3==0){
		while(c3==0);
		return '6';

	}
	else if(c4==0){
		while(c4==0);
		return 'B';

	}
	r1=1;r2=1;r3=0;r4=1;
	if(c1==0)
		{
		while(c1==0);
		return '7';

		}
	else if(c2==0){
		while(c2==0);
		return '8';

	}
	else if(c3==0){
		while(c3==0);
		return '9';

	}
	else if(c4==0){
		while(c4==0);
		return 'C';

	}
		r1=1;r2=1;r3=0;r4=0;
if(c1==0)
		{
	while(c1==0);
		return '*';

		}
	else if(c2==0){
		while(c2==0);
		return '0';

	}
	else if(c3==0){
		while(c3==0);
				return '#';

	}
	else if(c4==0){
		while(c4==0);
		return 'D';
	}
	}
}