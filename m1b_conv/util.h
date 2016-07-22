//

int isdigit(const char d);
int isintchar(const char c);
int isfloatchar(const char c);

int next_float(const char *str, float *res);
int next_integer(const char *str, int *res);

float *float_array(const int count, const char *content);
int *int_array(const int count, const char *content);