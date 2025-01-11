#include"../include/graphic.h"
#include"../include/server.h"
int main()
{
    int size,width,height;
    std::cout<<"Select window size\n 1. small \n 2.full";
    std::cin>>size;
    if(size == 1 )
    {
        height=800;
        width=600;
    }

    Window win(height,width);
    std::optional<int> window = win.createWindow();

    if(window==-1)
    {
        return -1;
    }
    return 0;
}
/*   Server S(8080);
     S.start();
     */
