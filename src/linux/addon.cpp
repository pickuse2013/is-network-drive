#include <string>  
#include <iostream>  
#include <sys/mount.h>  
#include <sys/param.h>  
#include <string.h>
/**
 * linux way
 *
 */
void statFileSys(const std::string f)  
{  
    struct statfs fileStat;  
    if(statfs(f.data(),&fileStat) == 0)  
    {  
            std::cout << fileStat.f_type <<std::endl;  
    } else {  
        std::cout << "statfs failed !!!"<<std::endl;  
    }  
}  

int main()  
{  
    statFileSys("/Users/pickuse/Project");  
    statFileSys("/Volumes/Library/SMB-Test");  

    return 0;  
}  