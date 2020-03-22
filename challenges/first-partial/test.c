#include <stdio.h>
#include <regex.h>
 
int match(const char *string, const char *pattern)
{
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, string, 0, NULL, 0);
    regfree(&re);
    if (status != 0) return 0;
    return 1;
}
 
int main(void)
{
    const char* s1 = "[2019-03-22 21:24] [ALPM] installed linux-api-headers (4.17.11-1)";
    const char* re = "[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}";
    const char* re2 = "\\[ALPM] installed";
    printf("%s matches %s? %s\n", s1, re, match(s1, re) ? "true" : "false");
    printf("%s matches %s? %s\n", s1, re2, match(s1, re2) ? "true" : "false");
}