#include <stdio.h>


/* --- 1.1 Getting Started --- */


/* Exercise 1-1. Run the ``hello, world'' program on your system.
 * Experiment with leaving out parts of the program, to see what error messages you get.
*/


/* Exercise 1-2. Experiment to find out what happens when prints's argument string contains \c,
 * where c is some character not listed above.
 */


/* --- 1.2 Variables and Arithmetic Expressions --- */


/* Exercise 1-3. Modify the temperature conversion program to print a heading above the table. */
/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; */
void temperature_table() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--original version--\n");
  printf("Fht\tCelsius\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%4d\t%4d\n", fahr, celsius);
    fahr += step;
  }
}


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * floating-point version
 */
void temperature_table_float() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--floating-point version--\n");
  printf("Fht\tCelsius\n");

  fahr = (float) lower;
  while (fahr <= (float) upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%5.1f\t%7.3f\n", fahr, celsius);
    fahr += (float) step;
  }
}


/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */
void temperature_table_reverse_convert() {
  float fahr, celsius;
  int lower, upper, step;

  lower = -20;      // lower limit of temperature table
  upper = 150;    // upper limit
  step = 17;      // step size

  printf("--reverse convert version--\n");
  printf("Celsius\tFht\n");

  celsius = (float) lower;
  while (celsius <= (float) upper) {
    fahr = celsius * 9 / 5 + 32;
    printf("%5.1f\t%7.3f\n", celsius, fahr);
    celsius += (float) step;
  }
}


/* --- 1.3 The for statement --- */


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * for statement version, in reverse order
 */
void temperature_table_for() {
  int fahr;
  float celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--for statement version--\n");
  printf("Fht\tCelsius\n");

  for (fahr = lower; fahr <= upper; fahr += step) {
    celsius = 5 * ((float) fahr - 32) / 9;
    printf("%5d\t%7.3f\n", fahr, celsius);
  }
}


/* Exercise 1-5. Modify the temperature conversion program to
 * print the table in reverse order, that is, from 300 degrees to 0.
 */
void temperature_table_reverse_order() {
  int fahr;
  float celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--for statement reverse version--\n");
  printf("Fht\tCelsius\n");

  for (fahr = upper; fahr >= lower; fahr -= step) {
    celsius = 5 * ((float) fahr - 32) / 9;
    printf("%5d\t%7.3f\n", fahr, celsius);
  }
}


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * for statement symbolic constants version
 */
void temperature_table_symbolic_constants() {
  int fahr;
  float celsius;

#define LOWER 0
#define UPPER 300
#define STEP 20

  printf("--for statement symbolic constants version--\n");
  printf("Fht\tCelsius\n");

  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    celsius = 5 * ((float) fahr - 32) / 9;
    printf("%5d\t%7.3f\n", fahr, celsius);
  }
#undef LOWER
#undef UPPER
#undef STEP
}


/* --- 1.4 Symbolic Constants --- */


/* --- 1.5 Character Input and Output --- */


void copy_input_to_output() {
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  printf("[EOF detected]\n");
}


void copy_input_to_output_1() {
  int c;

  // parenthesis is necessary
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
  printf("[EOF detected]\n");
}


/* Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1. */
// Answer: getchar() will return either a char or EOF


/* Exercise 1-7. Write a program to print the value of EOF. */
void print_EOF() {
  printf("Value of EOF: %d\n", EOF);
  /* -1 on a Windows 10 with MSVC */
}


/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */
void count_white_space() {
  int c;
  int black_cnt = 0, tab_cnt = 0, newline_cnt = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++black_cnt;
    } else if (c == '\t') {
      ++tab_cnt;
    } else if (c == '\n') {
      ++newline_cnt;
    }
  }
  printf("black_cnt=%d, tab_cnt=%d, newline_cnt=%d\ntotal=%d",
         black_cnt, tab_cnt, newline_cnt, black_cnt + tab_cnt + newline_cnt);
}


/* Exercise 1-9. Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */
void reduce_target_char() {
  int c;
  const char TARGET = ' ';
  int prev_hit = 0;
  while ((c = getchar()) != EOF) {
    if (c == TARGET) {
      if (prev_hit) {
        continue;
      }

      prev_hit = 1;
    } else {
      prev_hit = 0;
    }
    putchar(c);
  }
}


/* Exercise 1-10. Write a program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 */
void replace_white_space() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }
}


/* count lines, words, and characters in input. */
void word_count() {
#define IN  1     /* inside  a word */
#define OUT 0     /* outside a word */
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("nl=%d, nw=%d, nc=%d\n", nl, nw, nc);
#undef IN
#undef OUT
}

/* Exercise 1-11. How would you test the word count program?
 * What kinds of input are most likely to uncover bugs if there are any?
 */
// Answer: Other white space characters may be erroneously count as word.

// From https://stackoverflow.com/questions/5717411/how-to-test-word-count-program-if-there-is-any-uncovered-bugs :
// Texts with multiple spaces between words.
// Texts bigger than 2GB
// Words which contain a dash but no whitespace.
// Non-ascii words.
// Files in some different encoding (if your program supports that)
// Characters which are surrounded by whitespace but do not contain any word characters (e.g. "hello - world")
// Texts without any words
// Texts with all words on a single line


/* Exercise 1-12. Write a program that prints its input one word per line. */
void print_one_word_per_line() {
  const int IN  = 1;
  const int OUT = 0;

  int c;
  int state = IN;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      putchar('\n');
    }
    putchar(c);
  }
}

/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input. */


/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks
 * to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
 */
void detab(int tab_width) {
  int c;
  int num_char_this_line = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int num_space = tab_width - (num_char_this_line % tab_width);
      num_char_this_line += num_space;
//      printf(" [%d]", num_space);
      while (num_space--) {
        putchar(' ');
      }
    } else if (c == '\n') {
      putchar(c);
      num_char_this_line = 0;
    } else {
      putchar(c);
      ++num_char_this_line;
    }
  }
}


void emtab(int tab_width) {
  int c;
  int num_char_this_line = 0, num_consecutive_space = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++num_consecutive_space;
    } else {
      if (num_consecutive_space > 0) {
        int num_head = num_char_this_line % tab_width;
        int num_tab = (num_head + num_consecutive_space) / tab_width;
        int num_space = (num_head + num_consecutive_space) - num_tab * tab_width;
        if (num_tab == 0) {
          num_space = num_consecutive_space;
        }
//        printf("[num_tab=%d, num_space=%d]", num_tab, num_space);
        while (num_tab--) {
          putchar('\t');
        }
        while (num_space--) {
          putchar(' ');
        }
        num_char_this_line += num_consecutive_space;
        num_consecutive_space = 0;
      }
      putchar(c);

      if (c == '\n') {
        num_char_this_line = 0;
      } else if (c == '\t') {
        num_char_this_line += tab_width - num_char_this_line % tab_width;
      } else {
        ++num_char_this_line;
      }
    }
  }
}


void fold_long_lines(int width) {
  // TODO
}


void file_io_test() {
  // For Windows: use Ctrl+Z to send EOF with keyboard

//  copy_input_to_output();
//  detab(8);   // 8 for powershell
  emtab(8);   // 8 for powershell

}


int main() {
  // temperature tables

//  temperature_table();
//  temperature_table_float();
//  temperature_table_reverse_convert();
//  temperature_table_for();
//  temperature_table_reverse_order();
//  temperature_table_symbolic_constants();

  // chars
//  copy_input_to_output();
//  copy_input_to_output_1();
//  print_EOF();
//  count_white_space();
//  reduce_target_char();
//  replace_white_space();

//  word_count();
  print_one_word_per_line();
//  file_io_test();
//  print_EOF();


  return 0;
}
