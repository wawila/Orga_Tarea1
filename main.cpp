#include <QCoreApplication>
#include <fstream>
#include <iostream>
//#include <iterator>
//#include <vector>


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fstream img("C:\\Users\\David Chavarria\\Documents\\Orga Archivos\\EncriptarImagen\\imagen1.jpg", ios::binary | ios::in);
    fstream file("texto.txt", ios::binary | ios::out);

    img.seekg(0, ios::end);
    int size = img.tellg();

    cout<<"Size File: "<<size<<endl;

    img.seekg(0, ios::beg);

    char* bytes = new char[size];

    img.read(bytes, size);

    fstream imagen("imagen.jpg", ios::binary | ios::out);


    bytes[1200] = 'D';
    bytes[1300] = 'A';
    bytes[1400] = 'V';
    bytes[1500] = 'I';
    bytes[1600] = 'D';


    file.write(bytes, size);
    imagen.write(bytes, size);

    cout<<bytes[1200];
    cout<<bytes[1300];
    cout<<bytes[1400];
    cout<<bytes[1500];
    cout<<bytes[1600]<<endl;

    imagen.close();
    file.close();

    cout<<"Termino"<<endl;


    return a.exec();
}
