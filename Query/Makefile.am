AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = Query
Query_SOURCES = main.cpp 
Query_LDFLAGS = -L ${HEALPIX_LIB} -L ${PROTOBUF_LIB}
Query_CPPFLAGS = -I ${HEALPIX_INCLUDE} -I ${PROTOBUF_INCLUDE} 
Query_LDADD = ./lib/libprotobuf.a ./lib/libprotoc.a ./lib/libhealpix_cxx.a ./lib/libcxxsupport.a
