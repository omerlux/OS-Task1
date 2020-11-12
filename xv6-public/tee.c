#include "types.h"
#include "stat.h"
#include "user.h"

#include "fcntl.h"

 //passing command line arguments 
    
int main(int argc, char *argv[]) 
{
    if(argc == 2){
        char buf_read[512]; // creates a buffer
        int fd_txt1 = open(argv[1], O_WRONLY | O_CREATE);    // create new fd if not exists, to write only
        while(1){
            int n = read(0, buf_read, sizeof(buf_read));    // return number of bytes
            if(n==0) break; // end of file
            else if(n<0) { // error in read
                printf(2, "read error\n");
                exit();
            }
            else if(n>= 2 && buf_read[n-2]==3) break;// ctrl + c    # TODO: how to implement a signal ctrl+c?
            else {//write to file and console
                if (write(fd_txt1, buf_read, n) != n) { // wrriten bytes not equal to n = error!
                    printf(2, "write error\n");
                }
                if (write(1, buf_read, n) != n) { // wrriten bytes not equal to n = error!
                    printf(2, "write to console error\n");
                }
            }

        }
    }else if(argc == 3){
        char buf_read[512]; // creates a buffer
        int fd_txt1 = open(argv[1], O_RDONLY);
        int fd_txt2 = open(argv[2], O_WRONLY | O_CREATE);    // create new fd if not exists, to write only
        while(1){
            int n = read(fd_txt1, buf_read, sizeof(buf_read));    // return number of bytes
            if(n==0) break; // end of file
            else if(n<0) { // error in read
                printf(2, "read error\n");
                exit();
            }
            else {//write to file and console
                if (write(fd_txt2, buf_read, n) != n) { // wrriten bytes not equal to n = error!
                    printf(2, "write error\n");
                }
            }
        }
    }else
        printf(2, "cannot tee, given %d arguments\n", argc);
    exit();
} 