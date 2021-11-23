#include <stdio.h>

void guess(void);

int main(void)
{	
	printf("Please choose an intager from 0 to 100");
	printf(". And I will guess which one you choose, ");
	printf("do not cheat me!\n");
	printf("Let's begin: ");
	guess();
	printf("Look! I'm really a smart guy!");
	
	return 0;
}

void guess(void)
{
	int nb = 100;
	int ns = 0;
	int n = 50;
	char ch;
	
	while(1){
		printf("Does %d is the number you choose? Please enter Y / N: \n", n);
		while((ch = getchar()) != 'Y'&&ch != 'N'){
			printf("I can only recognize Y / N!! Please try again: \n");
			while(getchar() != '\n'){
				continue;
			}
		}
		while(getchar() != '\n'){
			continue;
		}
		if(ch == 'Y'){
			break;
		}
		else{
			printf("Does %d bigger than your number or smaller than your number? Please enter B / S: \n", n);
			while((ch = getchar()) != 'B'&&ch != 'S'){
				printf("I can only recognize B / S!! Pleasef try again: \n");
				while(getchar() != '\n'){
					continue;
				}
			}
			while(getchar() != '\n'){
				continue;
			}
			if(ch == 'B'){
				nb = n;
				n = (ns + n) / 2;
			}
			else if(ch == 'S'){
				ns = n;
				n = (nb + n) / 2;
			}
		}
		if(nb == n){
			ns = 0;
		}
		if(ns == n){
			nb = 100;
		}
	}
}