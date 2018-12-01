# mcatCS
This is the main source code of mcatCS, which provides a novel cross-matching scheme for multi-band astronomical catalogs.

mcatCS contains two parts, grouped spatial index file generation and min-conflict data layout strategy. You need to have original catalogs, then extract celestial coordinate information (right ascension and declination) and the celestial line number in each catalog from the original catalog, run program Build Grouped Spatial Index File to generate index file. Then, run program Query to search the objects that matched with the target. If you want to run it on multi-node environment, use min-conflict data layout strategy to distribute the data to each node, and upload the code packages.

## Prerequisites

This program has the following dependencies:
  - Healpix_3.20
  - protobuf_2.6.1  

All of these dependencies can be found in main directory.


## Installation

Program: Build Grouped Spatial Index File <br>
  - /configure [options] <br>
  - make 
  
It will generate an executable file：BuildIndex

Program: Query <br>
  - ./configure [options] <br>
  - make 
  
It will generate an executable file：Query

CONFIGURE PARAMETERS

   --with-healpix-lib = Path to the HEALPix library (libhealpix_cxx.a) <br> 
   --with-healpix-include = Path to the HEALPix include (healpix_base.h ..) <br> 
   --with-protobuf-lib = Path to the Protobuf library (libprotobuf.a) <br> 
   --with-protobuf-include = Path to the Protobuf include <br>


## Operating guide
  - ./BUildIndex                 <br> 
  To generate index file 
  
  - ./Query                      <br> 
  To run query server(s)
  
  - ./Request                    <br> 
  To input the target object coordinates

## Query examples



The input command example: 43.5923, -89.9253

Then, you will get all the celestial coordinate information and the celestial line number in their original catalog that matched with the coordinates of the input.
