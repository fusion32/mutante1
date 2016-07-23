#include <stdlib.h>

int isdigit(const char d)
{
	switch(d){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return 0;
	}

	return -1;
}

int isintchar(const char c)
{
	switch(c){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '+':
		case '-':
			return 0;
	}

	return -1;
}

int isfloatchar(const char c)
{
	switch(c){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '+':
		case '-':
		case '.':
		case 'e':
			return 0;
	}

	return -1;
}

int next_float(const char *str, float *res)
{
	const char *ptr, *end;
	int find, sign, sign2, pos, exponent, i;
	float val, mult;

	find = 0;
	ptr = str;
	end = NULL;
	while(*ptr != 0x00 && find == 0){
		if(isfloatchar(*ptr) == 0){
			end = ptr + 1;
			while(isfloatchar(*end) == 0){
				if(isdigit(*end))
					find = 1;
				end++;
			}

			if(find == 0)
				ptr = end;
		}
		else{
			ptr++;
		}
	}

	if(find == 0)
		return -1;


	// NOTE: end will be the first not valid character
	// after the actual float so we just need to check
	// while ptr is less than end (ptr < end)

	if(*ptr == '-'){
		sign = -1;
		ptr++;
	}
	else{
		sign = 1;
		if(*ptr == '+')
			ptr++;
	}


	//
	// pos == 0 -> integer part
	// pos == 1 -> decimal part
	// pos == 2 -> exponent part
	// pos == 3 -> end
	//

	pos = 0;
	val = 0;
	exponent = 0;
	mult = 0.1f;
	while(ptr < end && pos < 3){
		if(*ptr == '.'){
			if(pos >= 1)
				pos = 3;

			else
				pos = 1;
		}
		else if(*ptr == 'e'){
			if(pos >= 2)
				pos = 3;

			else{
				if(ptr[1] == '-'){
					sign2 = -1;
					ptr++;
				}
				else{
					if(ptr[1] == '+')
						ptr++;
					sign2 = 1;
				}
				pos = 2;
			}
		}
		else if(isdigit(*ptr) == 0){
			if(pos == 0){
				val = val * 10 + *ptr - 48;
			}
			else if(pos == 1){
				val = val + (*ptr - 48) * mult;
				mult = mult * 0.1f;
			}
			else if(pos == 2){
				exponent = exponent * 10 + *ptr - 48;
			}
		}
		else{
			pos = 3;
		}

		ptr++;
	}

	mult = 1;
	for(i = 0; i < exponent; i++){
		if(sign2 == 1)
			mult = mult * 10;
		else
			mult = mult * 0.1f;
	}

	*res = sign * val * mult;
	return 0;
}

int next_integer(const char *str, int *res)
{
	const char *ptr, *end;
	int val, sign, find;


	find = 0;
	ptr = str;
	end = NULL;
	while(*ptr != 0x00 && find == 0){
		if(isintchar(*ptr) == 0){
			end = ptr;
			while(isintchar(*end) == 0){
				if(isdigit(*end) == 0)
					find = 1;
				end++;
			}

			if(find == 0)
				ptr = end;
		}
		else{
			ptr++;
		}
	}

	if(find == 0)
		return -1;

	if(*ptr == '-'){
		sign = -1;
		ptr++;
	}
	else{
		if(*ptr == '+')
			ptr++;
		sign = 1;
	}

	val = 0;
	while(ptr < end && isdigit(*ptr) == 0){
		val = val * 10 + (*ptr) - 48;
		ptr++;
	}

	*res = sign * val;
	return 0;
}

float *float_array(const int count, const char *content)
{
	float *data;
	float val;
	const char *ptr;
	int i;

	if(count <= 0)
		return NULL;

	data = malloc(sizeof(float) * count);

	i = 0;
	ptr = content;
	while(*ptr != 0x00){
		if(*ptr == 0x20 || ptr == content){
			if(next_float(ptr, &val) == 0){
				data[i] = (float)val;
				i++;
			}
		}
		ptr++;
	}
	return data;
}

int *int_array(const int count, const char *content)
{
	int *data;
	int val;
	const char *ptr;
	int i;

	if(count <= 0)
		return NULL;

	data = malloc(sizeof(int) * count);

	i = 0;
	ptr = content;
	while(*ptr != 0x00){
		if(*ptr == 0x20 || ptr == content){
			if(next_integer(ptr, &val) == 0){
				data[i] = val;
				i++;
			}
		}
		ptr++;
	}
	return data;
}