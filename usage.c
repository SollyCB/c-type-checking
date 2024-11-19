#include <string.h>
#include <stdio.h>

// does not work with lvalues
#define typecheck(a, b, c) (b = (typeof(a))b, c)

// necessary for lvalue references
#define ptypecheck(a, b, c) (*b = *(typeof(a))b, c)

int fn_(void *a, void *b, long sz)
{
  memcpy(a, b, sz);
  return 0;
}

#define fn(a, b) fn_(ptypecheck(a, b, a), b, sizeof(*a))

struct one { int x; };
struct two { int x; };

#define TYPECHECK_PASSES 0

#if TYPECHECK_PASSES
int main(void) {
  struct one a = {5};
  struct one b = {10};

  printf("Before Copy: a = %i, b = %i\n", a.x, b.x);

  if (fn(&a, &b))
    return -1;

  printf("After Copy: a = %i, b = %i\n", a.x, b.x);

  return 0;
}
#else
int main(void) {
  struct one a = {5};
  struct two b = {10};

  printf("Before Copy: a = %i, b = %i", a.x, b.x);

  if (fn(&a, &b))
    return -1;

  printf("After Copy: a = %i, b = %i", a.x, b.x);

  return 0;
}
#endif
