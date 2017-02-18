#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
    const char* libraries;
    const char* modules;

    cvGetModuleInfo( 0, &libraries, &modules );

    printf("\nOpenCV Module information:\nLibraries: %s\nModules: %s\n\n", libraries, modules );
}
