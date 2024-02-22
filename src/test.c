#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_memchr_test) {
  char test1[] = "123456";
  char test2 = '4';
  char test3 = '7';
  char test4[] = "hello/\0";
  char test5[] = "h";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 6),
                    (unsigned long)memchr(test1, test3, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 6),
                    (unsigned long)memchr(test4, test6, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 6),
                    (unsigned long)memchr(test4, test8, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 6),
                    (unsigned long)memchr(test4, test9, 6));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[] = "Apple Pay Money Day";
  char test2[] = "Apple with worm";
  char test3[] = "\0";
  char test4[] = "gud\0 job";
  char test5[] = "gud\0 job";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 16) < 0,
                    memcmp(test1, test2, 16) < 0);
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0,
                    memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0,
                    memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0,
                    memcmp(test4, test5, 7) == 0);
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[10] = "12345";
  char test_2[] = "  ";
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  char test_5[30] = "";
  char test_6[] = "4444";
  char test_7[] = "123\0123";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));
}
END_TEST

START_TEST(s21_memset_test) {
  unsigned char test1[10] = "1234357890";
  unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '1', 10),
                    (unsigned long)memset(test1, '1', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '3', 10),
                    (unsigned long)memchr(test1, '3', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '/', 8),
                    (unsigned long)memchr(test1, '/', 8));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '9', 0),
                    (unsigned long)memchr(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '0', 4),
                    (unsigned long)memchr(test1, '0', 4));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '1', 3),
                    (unsigned long)memchr(test2, '1', 3));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_2[4] = "<<<";
  char test_4[2] = "5";
  char test_44[2] = "5";
  char test_5[] = "";

  ck_assert_str_eq(s21_strncat(test_2, test_4, 1), "<<<5");
  ck_assert_str_eq(s21_strncat(test_44, test_5, 0), strncat(test_4, test_5, 0));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Abcdefg";
  int symbol1 = 'd';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "defg");

  char str2[] = "Abcdefg";
  int symbol2 = 'd';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[] = "hella 1";
  char str2[] = "hello 3";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) < 0, strncmp(str1, str2, 5) < 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) == 0,
                   strncmp(str1, str2, 3) == 0);
}
END_TEST

START_TEST(s21_strlen_test) {
  char test_1[] = "12345";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = "   ";
  char test_5[] = "123\0456";
  char test_6[] = "hhh\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));

  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}
END_TEST

START_TEST(s21_strstr_test) {
  char test_1[] = "<<<5>>>";
  char test_2[] = "5";
  char test_3[] = "QwertyQwertyQwerty";
  char test_4[] = "Qwerty";
  char test_5[] = "abcd";
  char test_6[] = "";
  char test_7[] = "aaaaa123aaa1234aaa";
  char test_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char delim1[] = "/()";

  char str_strtok2[] = "one/two/three(four)five";
  char delim2[] = "/()";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(NULL, delim1);
    origin_strtok = strtok(NULL, delim2);
  }
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str1[] = "test of string";
  char dest1[15] = "";

  char str2[] = "test\0";
  char dest2[5] = "";

  char str3[] = "test ";
  char dest3[] = "crushcrush";

  ck_assert_str_eq("test ", s21_strncpy(dest1, str1, 5));
  ck_assert_str_eq("test", s21_strncpy(dest2, str2, 4));
  ck_assert_str_eq("test crush", s21_strncpy(dest3, str3, 10));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "0123456789";
  char test2[] = "9876";
  char test3[] = "LOST: 4-8-15-16-23-42";
  char test4[] = "1234567890";
  char test5[] = "0/";
  char test6[] = "%%\\#";
  char test7[] = " ";
  char test8[] = "1234567890";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
}
END_TEST

START_TEST(s21_strerror_test) {
  char *test1 = s21_strerror(0);
  char *test2 = strerror(0);
  char *test3 = s21_strerror(106);
  char *test4 = strerror(106);
  char *test5 = s21_strerror(2147483647);
  char *test6 = strerror(2147483647);
  char *test7 = s21_strerror(-214748364);
  char *test8 = strerror(-214748364);
  ck_assert_uint_eq((unsigned long)*test1, (unsigned long)*test2);
  ck_assert_uint_eq((unsigned long)*test3, (unsigned long)*test4);
  ck_assert_uint_eq((unsigned long)*test5, (unsigned long)*test6);
  ck_assert_uint_eq((unsigned long)*test7, (unsigned long)*test8);
}
END_TEST

START_TEST(s21_to_upper_test) {
  char destination[] = "Here w0 are123\0";
  char *test01 = s21_to_upper(destination);
  ck_assert_str_eq(test01, "HERE W0 ARE123");
  free(test01);

  char destination2[] = "Here w0 are\n\0";
  char *test02 = s21_to_upper(destination2);
  ck_assert_str_eq(test02, "HERE W0 ARE\n");
  free(test02);

  char destination3[] = "a\n\0";
  char *test03 = s21_to_upper(destination3);
  ck_assert_str_eq(test03, "A\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_upper(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_upper(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_upper(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_upper(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char destination[] = "HERE W0 ARE123\0";
  char *test01 = s21_to_lower(destination);
  ck_assert_str_eq(test01, "here w0 are123");
  free(test01);

  char destination2[] = "HERE W0 ARE\n\0";
  char *test02 = s21_to_lower(destination2);
  ck_assert_str_eq(test02, "here w0 are\n");
  free(test02);

  char destination3[] = "A\n\0";
  char *test03 = s21_to_lower(destination3);
  ck_assert_str_eq(test03, "a\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_lower(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_lower(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_lower(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_lower(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(s21_insert_test) {
  char *s1 = "School-21 test";
  char *s2 = "insert ";
  char *s3 = "amogus";
  char *s4 = "is";
  char *s5 = "shrek";
  char *res1 = s21_insert(s1, " ", 3);
  char *res2 = s21_insert(s5, s3, 5);
  char *res3 = s21_insert(s3, s5, 0);
  char *res4 = s21_insert(s5, s4, 5);
  char *res5 = s21_insert(s2, s1, 4);

  ck_assert_str_eq(res1, "Sch ool-21 test");
  ck_assert_str_eq(res2, "shrekamogus");
  ck_assert_str_eq(res3, "shrekamogus");
  ck_assert_str_eq(res4, "shrekis");
  ck_assert_str_eq(res5, "inseSchool-21 testrt ");

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
}
END_TEST

START_TEST(s21_trim_test) {
  char *str_to_trim = " \n   Hello, world!  !\n";
  char *trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, s21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *empty_format = "";
  trimmed_str = s21_trim(s21_NULL, empty_format);
  ck_assert(trimmed_str == s21_NULL);

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }
}
END_TEST

START_TEST(s21_sprintf_c_test) {
  char str[80];
  char str1[80];
  char x = 'c';
  int res = s21_sprintf(str, "%-10c", x);
  int res1 = sprintf(str1, "%-10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%10c", x);
  res1 = sprintf(str1, "%10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_s_test) {
  char str[80];
  char str1[80];
  char *x = "blablabla";
  int res = s21_sprintf(str, "%10s", x);
  int res1 = sprintf(str1, "%10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-8s", x);
  res1 = sprintf(str1, "%-8s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_d_test) {
  char str[80];
  char str_orig[80];
  int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%05d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_4) {
  char str[80];
  char str_orig[80];
  int a = -23;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_5) {
  char str[80];
  char str_orig[80];
  int a = -23;

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_u_test) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5u", a);
  int res_1_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10.5u", a);
  int res_2_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", a);
  int res_3_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%0u", a);
  int res_4_orig = sprintf(str_orig, "%0u", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-u", a);
  int res_5_orig = sprintf(str_orig, "%-u", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%u", a);
  int res_6_orig = sprintf(str_orig, "%u", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%5u", a);
  int res_7_orig = sprintf(str_orig, "%5u", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%05u", a);
  int res_8_orig = sprintf(str_orig, "%05u", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%-5u", a);
  int res_9_orig = sprintf(str_orig, "%-5u", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%.5u", a);
  int res_10_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%.5u", a);
  int res_11_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%-.5u", a);
  int res_12_orig = sprintf(str_orig, "%-.5u", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "%-10.5u", a);
  int res_13_orig = sprintf(str_orig, "%-10.5u", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%3.5u", a);
  int res_14_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%-3.5u", a);
  int res_15_orig = sprintf(str_orig, "%-3.5u", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "%6.2u", a);
  int res_16_orig = sprintf(str_orig, "%6.2u", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%3.2u", a);
  int res_17_orig = sprintf(str_orig, "%3.2u", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%01u", a);
  int res_18_orig = sprintf(str_orig, "%01u", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_0) {
  char str[80];
  char str_orig[80];
  int a = 0;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_3) {
  char str[80];
  char str_orig[80];
  int a = 234;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+6.2d", a);
  int res_26_orig = sprintf(str_orig, "%+6.2d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%+6.3d", a);
  int res_27_orig = sprintf(str_orig, "%+6.3d", a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);

  int res_28 = s21_sprintf(str, "%+6.4d", a);
  int res_28_orig = sprintf(str_orig, "%+6.4d", a);

  ck_assert_int_eq(res_28, res_28_orig);
  ck_assert_str_eq(str, str_orig);

  int res_29 = s21_sprintf(str, "%-6.2d", -a);
  int res_29_orig = sprintf(str_orig, "%-6.2d", -a);

  ck_assert_int_eq(res_29, res_29_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_f_test) {
  char str[80];
  char str_orig[80];

  double b_7 = 1234523459.123456789;
  int res_7 = s21_sprintf(str, "%f", b_7);
  int res_7_orig = sprintf(str_orig, "%f", b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_8 = 1;
  int res_8 = s21_sprintf(str, "%f", b_8);
  int res_8_orig = sprintf(str_orig, "%f", b_8);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  double b_9 = 0.00345;
  int res_9 = s21_sprintf(str, "%f", b_9);
  int res_9_orig = sprintf(str_orig, "%f", b_9);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  double b_10 = 0.00345;
  int res_10 = s21_sprintf(str, "%f", b_10);
  int res_10_orig = sprintf(str_orig, "%f", b_10);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_string");
  TCase *tc1_1 = tcase_create("s21_string");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, s21_memcmp_test);
  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, s21_strncmp_test);
  tcase_add_test(tc1_1, s21_strlen_test);
  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, s21_strrchr_test);
  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, s21_strtok_test);
  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, s21_strcspn_test);
  tcase_add_test(tc1_1, s21_strerror_test);
  tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_trim_test);
  tcase_add_test(tc1_1, s21_sprintf_c_test);
  tcase_add_test(tc1_1, s21_sprintf_s_test);
  tcase_add_test(tc1_1, s21_sprintf_d_test);
  tcase_add_test(tc1_1, s21_sprintf_d_test_5);
  tcase_add_test(tc1_1, s21_sprintf_d_test_0);
  tcase_add_test(tc1_1, s21_sprintf_d_test_3);
  tcase_add_test(tc1_1, s21_sprintf_u_test);
  tcase_add_test(tc1_1, s21_sprintf_f_test);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}