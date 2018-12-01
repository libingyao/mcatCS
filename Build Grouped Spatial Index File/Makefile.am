AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = BuildIndex
BuildIndex_SOURCES = main.cpp 
BuildIndex_LDFLAGS = -L ${HEALPIX_LIB} -L ${PROTOBUF_LIB}
BuildIndex_CPPFLAGS = -I ${HEALPIX_INCLUDE} -I ${PROTOBUF_INCLUDE} 
BuildIndex_LDADD = ./lib/libprotobuf.a ./lib/libprotoc.a ./lib/libhealpix_cxx.a ./lib/libcxxsupport.a
