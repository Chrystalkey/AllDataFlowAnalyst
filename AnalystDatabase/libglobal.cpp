//
// Created by Chrystalkey on 29.07.2018.
//

#include "libglobal.h"
#include "Database.h"

Database *dbPtr = nullptr;
namespace InputCapture{
    InputHooks *hooks = nullptr;
}

QString operator*(const QString& left, quint32 right){
    QString result;
    for(int i = 0; i < right; i++){
        result += left;
    }
    return result;
}
extern "C"{
    void hexdump(const char *data, unsigned int size, FILE *output){
        unsigned char byte;
        unsigned int i, j;
        for (i=0;i < size; i++){
            byte = data[i];
            fprintf(output,"%02x ",byte);
            if((i%16)==15||(i==size-1)){
                for(j=0; j< 15-(i%16); j++)
                    fprintf(output,"   ");
                fprintf(output,"| ");
                for(j=(i-(i%16));j<=i;j++){
                    byte = data[j];
                    if((byte>31) && (byte <127))
                        fprintf(output,"%c",byte);
                    else
                        fprintf(output,".");
                }
                fprintf(output,"\n");
            }
        }
    }
}