# mcatCS
This is the main source code of mcatCS, which provides a novel cross-matching scheme for multi-band astronomical catalogs.

mcatCS contains two parts, grouped spatial index file generation and min-conflict data layout strategy. In the program of grouped spatial index file generation, a KD-tree data structure for every file will be built and transfer them into binary format files by Protobuf, then save generated files into disks. Through the program of min-conflict data layout strategy, the index file would be distributed in multiple servers. A command line-based query interface is provided to users. The scheme will take the coordinates entered by users as inputs, and return all data that matched with target in multi-band astronomical catalogs as the result. Our scheme is mainly used for individuals who wish to cross-match local catalogs on their personal computers.


## Prerequisites

This program has the following dependencies:
  - cfitsio 3.3
  - Healpix_3.20
  - protobuf_2.6.1
  
All of these dependencies can be found in main directory.

Suppose you already have catalogs in various band in your computers. After install all these software, you can run the program in /mcatCS/Grouped Spatial Index File Generation/GSIF_main.cpp. The function of 'Tree to Protobuf' is used to generate index file. Then you will get the index files, run the program in /mcatCS/Min-conflict Data Layout Strategy/min-conflict data layout.cpp to lay out the index files.  

## Query examples

After these steps, you can cross-match and query certain celestial object data from the catalogs using the function 'Protobuf to Tree' in /mcatCS/Grouped Spatial Index File Generation/GSIF_main.cpp. You can run the program on several servers using /mcatCS/Grouped Spatial Index File Generation/send.cpp to send the query command to all the servers.

The input command example: 43.5923, -89.9253

Then, you will get all the celestial coordinate information and the celestial line number in their original catalog that matched with the coordinates of the input.
