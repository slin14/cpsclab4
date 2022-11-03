#include "recursion.h"

/*
 Calculates the power.
 PARAM:     base is an integer
 PARAM:     power is an integer
 PRE:       power >= 0
 PRE:       base != 0
 RETURN:    base^power
 */
int calculate_power(int base, int power)
{
	if (power == 0) {
		return 1;
	}
	else {
		return base * calculate_power(base, power - 1);
	}
	return -1;
}

/*
 Returns the number of digits in an integer
 PARAM:     number is an integer
 PRE:       0 < number <= INT_MAX
 RETURN:    the number of digits in the number
 */
int count_digits(int number)
{
	if ((number / 10) == 0) {
		return 1;
	}
	else {
		return 1 + count_digits(number / 10);
	}
}

/*
 Returns the length of the specified string.
 PARAM:  string, a pointer to an array of char
 PRE:    the string pointer is not a dangling pointer
 RETURN: the length of the string passed as a parameter
 */
int string_length(char* string)
{
	if (string[0] == '\0') {
		return 0;
	}
	else {
		return 1 + string_length(string + 1);
	}
}

/*
 Determines if a string is a palindrome.  DOES NOT skip spaces!
 For example,
 ""     -> returns 1 (an empty string is a palindrome)
 "the"  -> returns 0
 "abba" -> returns 1
 "Abba" -> returns 0
 "never odd or even" -> returns 0
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  string, a pointer to an array of char
 PARAM:  string_length, the length of the string
 PRE:    the string pointer is not a dangling pointer
 PRE:    string_length is the correct length of the string
 RETURN: IF string is a palindrome
				 THEN 1
		 END 0
 */
int is_palindrome(char* string, int string_length)
{
	if (string_length <= 1) {
		return 1;
	}
	if (string_length == 2) {
		if (string[0] == string[string_length-1]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (string[0] == string[string_length-1]) {
		return is_palindrome(string + 1, string_length - 2);
	}
	else {
		return 0;
	}
}

/*
 Draws a ramp.  The length of the longest rows is specified by the parameter.
 For the recursive call, be aware that both parameters can be modified.
 PARAM:     number, an integer
 PARAM:     buffer, a character array of sufficient length
 PRE:       number >= 1
						buffer has sufficient length and contains null characters from the buffer
						address to the end of its length
 POST:      draws a ramp whose height is the specified number into buffer
 RETURN:    the number of characters written into buffer. Don't forget to count your
						newline characters!
 */
int draw_ramp(int number, char* buffer)
{
	int ret_val = 0;
	if (number == 0) {
		return 0;
	}
	if (number == 1) {
		ret_val = draw_row(number, buffer);
	}
	else {
		ret_val = draw_row(number, buffer) + 1;
		strcat(buffer, "\n");
		ret_val = ret_val + draw_ramp(number - 1, buffer);
		strcat(buffer, "\n"); 
		ret_val = ret_val + draw_row(number, buffer) + 1;
		if (ret_val > strlen(buffer)) {
			buffer[ret_val] = '\0';
		}
	}
	return ret_val;
}

/*
 Draws a row of asterisks of the specified length
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  size, an integer
 PARAM:  buffer, a character array of sufficient length
 PRE:    size >= 1
				 buffer has sufficient length and contains null characters from the buffer
				 address to the end of its length
 POST:   draws a row of asterisks of specified length to buffer
 RETURN: the number of characters drawn
 */
int draw_row(int size, char* buffer)
{
	if (size == 0) {
		return 0;
	}
	else if (size == 1) {
		strcat(buffer, "*");
		return 1;
	}
	else {
		strcat(buffer, "*");
		return 1 + draw_row(size - 1, buffer);
	}
}