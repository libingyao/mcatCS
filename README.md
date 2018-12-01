# mcatCS
This is the main source code of mcatCS, which provides a novel cross-matching scheme for multi-band astronomical catalogs.

mcatCS contains two parts, grouped spatial index file generation and min-conflict data layout strategy. You need to have original catalogs, then extract celestial coordinate information (right ascension and declination) and the celestial line number in each catalog from the original catalog, run program Build Grouped Spatial Index File to generate index file. then, run program Query to search the objects that matched with the target. If you want to run it on multi-node environment, upload the package and the data on the working nodes of the avaliable computing infrastructure.


## Prerequisites

This program has the following dependencies:
  - Healpix_3.20
  - protobuf_2.6.1
  
All of these dependencies can be found in main directory.


## Installation

Program: Build Grouped Spatial Index File
1) ./configure [options]
2) make
3) ./BuildIndex

Program: Query
1) ./configure [options]
2) make
3) ./Query

CONFIGURE PARAMETERS
   --with-healpix-lib            Path to the HEALPix library (libhealpix_cxx.a) 
   --with-healpix-include        Path to the HEALPix include (healpix_base.h ..)
   --with-protobuf-lib           Path to the Protobuf library (libprotobuf.a)
   --with-protobuf-include       Path to the Protobuf include

Suppose you already have catalogs in various band in your computers. After install all these software, you can run the program in /mcatCS/Grouped Spatial Index File Generation/GSIF_main.cpp. The function of 'Tree to Protobuf' is used to generate index file. Then you will get the index files, run the program in /mcatCS/Min-conflict Data Layout Strategy/min-conflict data layout.cpp to lay out the index files.  

## Query examples

After these steps, you can cross-match and query certain celestial object data from the catalogs using the function 'Protobuf to Tree' in /mcatCS/Grouped Spatial Index File Generation/GSIF_main.cpp. You can run the program on several servers using /mcatCS/Grouped Spatial Index File Generation/send.cpp to send the query command to all the servers.

The input command example: 43.5923, -89.9253

Then, you will get all the celestial coordinate information and the celestial line number in their original catalog that matched with the coordinates of the input.
