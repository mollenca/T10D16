#include "s21_string.h"

#include <stdlib.h>

int s21_strlen(char *str) {
  int ans = 0;

  if (!str) {
    ans = -1;
  } else {
    while (*(str + ans) != '\0')
      ans++;
  }

  return ans;
}

int s21_strcmp(char *str1, char *str2) {
  int len1 = s21_strlen(str1), len2 = s21_strlen(str2), ans = 0;
  if (!str1 && str2) {
    ans = -1;
  } else if (str1 && !str2) {
    ans = 1;
  } else if (!str1 && !str2) {
    ans = 0;
  } else if (len1 > len2) {
    ans = 1;
  } else if (len1 < len2) {
    ans = -1;
  } else {
    for (int i = 0; i < len1; i++) {
      if ((int)str1[i] > (int)str2[i]) {
        ans = 1;
        break;
      } else if ((int)str1[i] < (int)str2[i]) {
        ans = -1;
        break;
      }
    }
  }

  return ans;
}

int s21_strcpy(char *dst, char *src) {
  int flag = 0, len_src;

  if (!dst || !src) {
    flag = 1;
  } else {
    len_src = s21_strlen(src);

    for (int i = 0; i < len_src; i++)
      dst[i] = src[i];

    *(dst + len_src) = '\0';
  }

  return flag;
}

int s21_strcat(char *src, char *add) {
  int len_src = s21_strlen(src), len_add = s21_strlen(add), flag = 0;

  if (!src || !add) {
    flag = 1;
  } else {
    for (int i = 0; i < len_add; i++)
      src[i + len_src] = add[i];
    src[len_src + len_add] = '\0';
  }
  return flag;
}

char *s21_strchr(char *src, int search) {
  int len = s21_strlen(src);
  char *ans;

  for (ans = src; ans - src <= len; ans++)
    if ((int)*ans == search)
      break;

  return ans >= src + len ? NULL : ans;
}

char *s21_strstr(char *src, char *search) {
  char *ans;
  int len_src = s21_strlen(src), len_search = s21_strlen(search), flag = 0;

  for (ans = src; ans - src < len_src - len_search; ans++) {
    flag = 1;

    for (int i = 0; i < len_search; i++)
      if (*(ans + i) != search[i]) {
        flag = 0;
        break;
      }

    if (flag == 1)
      break;
  }

  return flag ? ans : NULL;
}