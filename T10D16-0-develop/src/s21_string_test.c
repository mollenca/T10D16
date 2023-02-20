#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
#ifdef strlen
  s21_strlen_test();
#endif
#ifdef strcmp
  s21_strcmp_test();
#endif
#ifdef strcpy
  s21_strcpy_test();
#endif
#ifdef strcat
  s21_strcat_test();
#endif
#ifdef strchr
  s21_strchr_test();
#endif
#ifdef strstr
  s21_strstr_test();
#endif
}

void s21_strlen_test() {
  char str2[12] = "s c h o o l\0";
  char str3[25] = "s c h o o l\n s c h o o l\0";
  char str4[2] = "\0";
  int ans;

  printf("test_1:\n");
  printf("\tinput:"
         "\n\tNULL");
  ans = s21_strlen(NULL);
  printf("\n\toutput:"
         "\n\t%d",
         ans);
  if (ans == -1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_2:");
  printf("\n\tinput:"
         "\n\t\"q w e r t y\"");
  ans = s21_strlen(str2);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == 11)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_3:");
  printf("\n\tinput:"
         "\n\t\"s c h o o l\n s c h o o l\"");
  ans = s21_strlen(str3);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == 24)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_4:");
  printf("\n\tinput:"
         "\n\t\"\"");
  ans = s21_strlen(str4);
  printf("\n\toutput:"
         "\n\t0");

  if (ans == 0)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");
}

void s21_strcmp_test() {
  char str[6] = "12345\0";
  char str1[6] = "12346\0";
  char str2[6] = "12344\0";
  char str3[6] = "1a345\0";
  int ans;

  printf("test_1:\n");
  printf("\tinput:"
         "\n\tNULL, NULL");
  ans = s21_strcmp(NULL, NULL);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == 0)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_2:");
  printf("\n\tinput:"
         "\n\t\"12345\", \"12345\"");
  ans = s21_strcmp(str, str);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == 0)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_3:");
  printf("\n\tinput:"
         "\n\t\"12345\", \"12346\"");
  ans = s21_strcmp(str, str1);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == -1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_4:");
  printf("\n\tinput:"
         "\n\t\"12346\", \"12344\"");
  ans = s21_strcmp(str1, str2);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == 1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_5:");
  printf("\n\tinput:"
         "\n\t\"12345\", \"1a345\"");
  ans = s21_strcmp(str, str3);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == -1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");
}

void s21_strcpy_test() {
  char str[10];
  char str1[7] = "1r,r46\0";
  char str2[6] = "\0";
  int ans;

  printf("test_1:\n");
  printf("\tinput:"
         "\n\tNULL, NULL");
  ans = s21_strcpy(NULL, NULL);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == 1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_2:");
  printf("\n\tinput:"
         "\n\tstr, \"1r,r46\"");
  s21_strcpy(str, str1);
  printf("\n\toutput:"
         "\n\t\"%s\"",
         str);

  if (s21_strcmp(str, str1) == 0)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_3:");
  printf("\n\tinput:"
         "\n\tstr, \"\"");
  s21_strcpy(str, str2);
  printf("\n\toutput:"
         "\n\t\"%s\"",
         str);

  if (s21_strcmp(str, str2) == 0)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");
}

void s21_strcat_test() {
  char str[10];
  char str1[7] = "1r,r46\0";
  char str2[1] = "\0";
  int ans;

  printf("test_1:\n");
  printf("\tinput:"
         "\n\tstr, NULL");
  ans = s21_strcat(str, NULL);
  printf("\n\toutput:"
         "\n\t%d",
         ans);

  if (ans == 1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_2:");
  printf("\n\tinput:"
         "\n\tstr, \"1r,r46\"");
  s21_strcat(str, str1);
  printf("\n\toutput:"
         "\n\t\"%s\"",
         str);

  if (s21_strcmp(str, "1r,r46\0") == 0)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_3:");
  printf("\n\tinput:"
         "\n\tstr, \"\"");
  s21_strcat(str, str2);
  printf("\n\toutput:"
         "\n\t\"%s\"",
         str);

  if (s21_strcmp(str, "1r,r46\0") == 0)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");
}

void s21_strchr_test() {
  char str[7] = "1r,r46\0";
  char *ans;

  printf("test_1:\n");
  printf("\tinput:"
         "\n\t\"1r,r46\", \'t\'");
  ans = s21_strchr(str, 't');
  printf("\n\toutput:"
         "\n\t%s",
         ans);

  if (ans == NULL)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_2:");
  printf("\n\tinput:"
         "\n\t\"1r,r46\", \'6\'");
  ans = s21_strchr(str, '6');
  printf("\n\toutput:"
         "\n\t%d",
         (int)(ans - str));

  if (ans == str + 5)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_3:");
  printf("\n\tinput:"
         "\n\t\"1r,r46\", \'\\0\'");
  ans = s21_strchr(str, '\0');
  printf("\n\toutput:"
         "\n\t%s",
         ans);

  if (ans == NULL)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");
}

void s21_strstr_test() {
  char str[7] = "1r,r46\0";
  char *ans;

  printf("test_1:\n");
  printf("\tinput:"
         "\n\t\"1r,r46\", \"r,r\"");
  ans = s21_strstr(str, "r,r\0");
  printf("\n\toutput:"
         "\n\t%d",
         (int)(ans - str));

  if (ans == str + 1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_2:");
  printf("\n\tinput:"
         "\n\t\"1r,r46\", \"632\"");
  ans = s21_strstr(str, "632\0");
  printf("\n\toutput:"
         "\n\t%s",
         ans);

  if (ans == NULL)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");

  printf("test_3:");
  printf("\n\tinput:"
         "\n\t\"1r,r46\", \"r\"");
  ans = s21_strstr(str, "r\0");
  printf("\n\toutput:"
         "\n\t%d",
         (int)(ans - str));

  if (ans == str + 1)
    printf("\n\tSUCCESS\n");
  else
    printf("\n\tFAIL\n");
}