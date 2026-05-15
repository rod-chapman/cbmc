#include <assert.h>

// This harness deliberately produces a forall over an array index in the
// SMT2 encoding so that a regression test can check `--add-triggers`.
int main()
{
  int a[16];
  unsigned i;
  __CPROVER_assume(i < 16);
  __CPROVER_assume(__CPROVER_forall { unsigned j; (j < 16) ==> (a[j] >= 0) });
  assert(a[i] >= 0);
  return 0;
}
