#include <iostream>
#include <fstream>

using namespace std;
//10px na 10px stroka cveta;
int main(){
    ofstream  os("imag.bmp", ios_base::out|ios_base::binary);
    ::uint16_t bm =0x4D42;


    os.write(reinterpret_cast<char*> (&bm),2);
    ::uint32_t size =0x0000C61A;

    os.write(reinterpret_cast<char*> (&size),4);

    os.seekp(4,ios_base::cur);

    size = 0x0000007A;

    os.write(reinterpret_cast<char*> (&size),4);
    size=0x0000006C;

    os.write(reinterpret_cast<char*> (&size),4);
   size = 0x0000000A;

    os.write(reinterpret_cast<char*> (&size),4);
    size=0x000000AA;
    os.write(reinterpret_cast<char*> (&size),4);
    bm=0x0001;
    os.write(reinterpret_cast<char*> (&bm),2);
    bm=0x0020;
    os.write(reinterpret_cast<char*> (&bm),2);
    size = 0x00000003;
    os.write(reinterpret_cast<char*> (&size),4);
    size=0x00000020;
    os.write(reinterpret_cast<char*> (&size),4);
    size=0x00000B13;
    os.write(reinterpret_cast<char*> (&size),4);
    os.write(reinterpret_cast<char*> (&size),4);
    os.seekp(8,ios_base::cur);
    ::uint8_t  g=0xFF;
    size=0x00FF0000;
    os.write(reinterpret_cast<char*> (&size),4);
    size=0x0000FF00;
    os.write(reinterpret_cast<char*> (&size),4);
    size=0x000000FF;
    os.write(reinterpret_cast<char*> (&size),4);
    size=0xFF000000;
    os.write(reinterpret_cast<char*> (&size),4);
    size=0x57696E20;
    os.write(reinterpret_cast<char*> (&size),4);
    os.seekp(48,ios_base::cur);

    ::uint32_t beg = 0xFF000000;
    for (int i=0;i<17;i++){
        for (int j=0;j<10;j++){
            for(int k =0;k<10;k++){
                os.write(reinterpret_cast<char*> (&beg),4);
            }
        }
     beg +=0x000F0F0F;
    }


//    os.write(reinterpret_cast<char*> (&g),1);
//    os.write(reinterpret_cast<char*> (&g),1);
//    os.write(reinterpret_cast<char*> (&g),1);
//    os.write(reinterpret_cast<char*> (&g),1);
//    os.seekp(2,ios_base::cur);
//    os.write(reinterpret_cast<char*> (&g),1);
//    os.seekp(3,ios_base::cur);
//    os.write(reinterpret_cast<char*> (&g),1);
//    g= 0x00;
//    os.write(reinterpret_cast<char*> (&g),1);
//    os.write(reinterpret_cast<char*> (&g),1);
//    os.write(reinterpret_cast<char*> (&g),1);

    os.close();

}
