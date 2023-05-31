#include "main.h"

int reverse(char str[], int length){
	int start = 0;
	int end = length - 1;
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return length;
}

int itoa(int num, char *str, int base){
	int i = 0;
	int is_negative = 0;

	if (num == 0){
		str[i++] = '0';
		str[i] = '\0';
		return 1;
	}

	if (num < 0 && base == 10){
		is_negative = 1;
		num = -num;
	}

	while (num != 0){
		int rem = num % base;
		if (rem > 9){
			str[i] = (rem - 10) + 'a';
		}else{
			str[i] = rem + '0';
		}
		i++;
		num = num/base;
	}

	if(is_negative){
		str[i] = '-';
		i++;
	}

	str[i] = '\0';

	reverse(str, i);

	return i;
}


int _printf(const char *format, ...){
	int count;
	va_list args;
	va_start(args, format);

	count = 0;

	while(*format){
		if (*format == '%'){
			format++;/*to progress to the next element*/
			if (*format == '\0') break;
			if(*format =='%'){
				_putchar('%');
				count++;/*increase count*/
			}else if(*format == 'c'){
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}else if(*format =='s'){
				char *s =va_arg(args, char *);
				while (*s){
					_putchar(*s++);
					count++;
				}
			}else if(*format == 'd' || *format == 'i'){
				int d = va_arg(args, int);
				char buffer[20]; /*Assuming maximum 20 digits for integer*/

				int num_digits= itoa(d, buffer, 10);
				int i;
				for (i = 0; i < num_digits; i++){
					_putchar(buffer[i]);
					count++;
				}
			}
		}else{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}





