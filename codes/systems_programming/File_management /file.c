/*
            Notes on file management 



    File operations: Create, Delete, Append Write read
    

    a.Single level Directory System 
    One directory in the whole file system. All files are stored in the same directory

    b. Two level directory system 
    Two directories in the file system. One directory is for the user and the other directory is for the system.

    c. Hierarchical
    Multiple directories in the file system. The directories are arranged in a tree-like structure. 
    The root directory is at the top of the tree. The root directory contains all the other directories. 
    The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the other directories. Each directory contains files and other directories. Each directory can have multiple subdirectories. Each subdirectory can have multiple files and other subdirectories. The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the other directories. Each directory contains files and other directories. Each directory can have multiple subdirectories. Each subdirectory can have multiple files and other subdirectories. The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the other directories. Each directory contains files and other directories. Each directory can have multiple subdirectories. Each subdirectory can have multiple files and other subdirectories. The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the other directories. Each directory contains files and other directories. Each directory can have multiple subdirectories. Each subdirectory can have multiple files and other subdirectories. The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the other directories. Each directory contains files and other directories. Each directory can have multiple subdirectories. Each subdirectory can have multiple files and other subdirectories. The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the other directories. Each directory contains files and other directories. Each directory can have multiple subdirectories. Each subdirectory can have multiple files and other subdirectories. The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the other directories. Each directory contains files and other directories. Each directory can have multiple subdirectories. Each subdirectory can have multiple files and other subdirectories. The directories are arranged in a tree-like structure. The root directory is at the top of the tree. The root directory contains all the

    
    Unix vs Windows when it come to file management
    Unix:
    You can't have two files with the same name in the same directory but in Unix you can so long as they have different cases.

    
    Relative path vs 

    Wildcard eg * ? # ~ / $

    Gunzip and gzip
    

    df and du how much space is left in our devuce 

    uname -a


    kannel
    cygwin -Cygwin allows source code for Unix-like operating systems to be compiled and run on Windows. 
    load balancing in Linux


    File management in C is done using a pointer of type FILE. 
    This pointer is used to hold the base address of the file. 
    The file pointer is a structure that holds the information about the file. 
    The file pointer is declared as FILE *fp. 
    The file pointer is used to access the file, read and write, close, open, create, delete rename, copy, move the file. 
    The file pointer is used to get the file information, file size 

    Syntax File *fpointer

    File operations: Create, Delete, Append Write read
    Some operations fopen, fclose, fprintf, fscanf., getc, putc, fseek, ftell, rewind  
    
    Reading a binary File file size 
    fwrite and fread

    fwrite takes four arguments :
        address of data written 
        number of such type of data 
    
    fseek 
    ftell rewind functions 
    */
