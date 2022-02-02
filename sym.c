#include "defs.h"
#include "data.h"
#include "decl.h"

static int Globs = 0;

int findglob(char *s) {
    int i;
    for (i=0;i<Globs;i++) {
        if (*s == *Gsym[i].name && !strcmp(s, Gsym[i].name))
            return (i);
    }
    return -1;
}

static int newglob(void) {
  int p;

  if ((p = Globs++) >= NSYMBOLS)
    fatal("Too many global symbols");
  return (p);
}

// Add a global symbol to the symbol table.
// Return the slot number in the symbol table
int addglob(char *name) {
  int y;

  // If this is already in the symbol table, return the existing slot
  if ((y = findglob(name)) != -1)
    return (y);

  // Otherwise get a new slot, fill it in and
  // return the slot number
  y = newglob();
  Gsym[y].name = strdup(name);
  return (y);
}
