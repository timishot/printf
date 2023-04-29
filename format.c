i#include <stdarg.h>
#include <unistd.h>

int _putchar(char c){
	return write(1, &c, 1);
}


int _printf(const char *format, ...){
	va_list args;
	va_start(args, format);

	int count = 0;

	while(*format){
		if (*format == '%'){
			format++;//to progress to the next element
			if (*format == '\0') break;//if the next element is a is null terminator break
			if(*format =='%'){
				_putchar('%');
				count++;//increase count
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





