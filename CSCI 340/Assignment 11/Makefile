# It is common to assign the compier flags to a variable that is
# then used in multiple compile recipies that are common in realisticly
# large Makefiles.  The name CXXFLAGS for the flags opf the C++ compiler
# is the correct and common way to do this.
CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I.

# By default, make will try to satisfy the first recipie/rule that it finds.
# By convention, 99% of all Makefiles start with a rule named 'all' that
# simply names the target(s) that are to be (re)compiled like this:
all: h8

# The 'all' rule lists the targets of interest... that have their own recipies:
h8: h8.cc
	g++ $(CXXFLAGS) -o hash h8.cc


# A 'phony' target named clean is used to remove all files that the Makefile
# can be used to re-create.
clean:
	rm -f h8

# Some times another 'phony' target is provided to easily force a 'clean' and then
# a rebuild of 'all' the targets.
world: clean all
