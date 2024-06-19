#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 int main (){
    int n;
    FILE  *afile;
    afile = fopen("file.inp","w+");
    cout <<"nhap n:";
    cin >>n;
    fprintf(afile, "%d \n",n);
    srand(time(0));
    for(int i=0;i < n;i++){
        int a = rand() %(9000 - -1000 +1 );
        fprintf(afile,"%d ",a);
    }
    fclose(afile);
    return 0;
 };
