/*

zid-128-as-c-libsodium

Generate a Zen identifier (http://www.zidplan.com)
using 128 bits and implementation as a C program
with libsodium cryptography.

Usage:

    zid-128-as-c-libsodium

Example:

    $ zid-128-as-c-libsodium
    0cb49f132271bf0436a8f0689f87ee9c

Tracking:

  * Command: zid-128-as-ruby
  * Version: 4.0.0
  * Created: 2015-01-25
  * Updated: 2018-07-06
  * License: Any of GPL, LGPL, MIT, BSD
  * Contact: Joel Parker Henderson (http://joelparkerhenderson.com)

*/

#include <sodium.h>

int main(void)
{
  /* Initialize */
  if (sodium_init() < 0) { exit(1); }

  /* Allocate */
  unsigned int buf_len = 16;
  unsigned char buf[buf_len];
  unsigned int hex_len = buf_len * 2 + 1;
  char hex[hex_len];

  /* Generate */
  randombytes_buf(buf, buf_len);
  sodium_bin2hex(hex, hex_len, buf, buf_len);
  puts(hex);
  exit(0);
}
