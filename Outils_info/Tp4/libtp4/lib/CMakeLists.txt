
add_library(tp4 SHARED tp4.c)

set_target_properties( tp4  PROPERTIES
	  VERSION 1.3.4
	  SOVERSION 1
	  CFLAGS -Wall
	)


