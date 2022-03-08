#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
using namespace std;

repCmd::repCmd(){}

void repCmd::assignParameters(parameter* directives[100], int size){
    if(size != 0){
        for(int i = 0; i<size; i++){
            if(strcmp(directives[i]->name,(char*)"-name") == 0){
                this->name = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-path") == 0){
                this->path = directives[i]->stringValue;
            }else if(strcmp(directives[i]->name,(char*)"-id") == 0){
                this->id = toMayus(directives[i]->stringValue);
            }else if(strcmp(directives[i]->name,(char*)"-ruta") == 0){
                this->ruta = directives[i]->stringValue;
            }
        }
    }
}

string createTd(string content){
    return "<td>" + content + "</td>";
}

string createTh(string content){
    return "<th>" + content + "</th>";
}

void repCmd::execute(){
    if(this->name == "" || this->id == "" || this->path == ""){
        cout << "Error: faltan parametros obligatorios en el comando rep" << endl;
        return;
    }

    // CREACION DE CARPETAS DESPUES DE LA PADRE
    string parent_path = "mkdir -p ";
    parent_path += this->path.substr(0,this->path.find_last_of("/\\"));
    system(parent_path.c_str());

    // OBTENGO EL NOMBRE DEL REPORTE A GENERAR
    string report_name = this->path.substr(this->path.find_last_of("/\\")+1,this->path.length());

    // BUSCO EN LA LISTA LA PARTICION INIDICADA
    pnodo element;
    element = global_list.getElement(this->id);
    FILE *file = fopen(element->path_disk.c_str(),"r");

    if(this->name == "MBR"){
        MBR mbr;
        fseek(file,0,SEEK_SET);
        fread(&mbr,sizeof(MBR),1,file);

        string htmlContent = "<html>\n<body>\n<table>\n";

        // REPORTE DE MBR
        htmlContent += "<tr>\n";
        htmlContent += createTh("REPORTE DE MBR");
        htmlContent += "\n</tr>";
        htmlContent += "<tr>\n";
        htmlContent += createTd("mbr_tamano");
        htmlContent += createTd(std::to_string(mbr.size));
        htmlContent += "\n</tr>";
        htmlContent += "<tr>\n";
        htmlContent += createTd("mbr_fecha_creacion");
        htmlContent += createTd(mbr.date);
        htmlContent += "\n</tr>";
        htmlContent += "<tr>\n";
        htmlContent += createTd("mbr_disk_signature");
        htmlContent += createTd(std::to_string(mbr.signature));
        htmlContent += "\n</tr>";

        for(int i=0; i<4; i++){
            //cout << mbr.partitions[i].name << endl;
            if(mbr.partitions[i].type != 'P'){
                cout << "trabajar como extendida" << endl;
            }else{
                if(mbr.partitions[i].size != -1){
                    string aux;
                    htmlContent += "<tr>\n";
                    htmlContent += createTh("Particion");
                    htmlContent += "\n</tr>";

                    htmlContent += "<tr>\n";
                    htmlContent += createTd("part_status");
                    aux.push_back(mbr.partitions[i].status);
                    htmlContent += createTd(aux);
                    htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";
                    htmlContent += createTd("part_type");
                    aux.push_back(mbr.partitions[i].type);
                    htmlContent += createTd(aux);
                    htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";
                    htmlContent += createTd("part_fit");
                    htmlContent += createTd(mbr.partitions[i].fit);
                    htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";
                    htmlContent += createTd("part_start");
                    htmlContent += createTd(std::to_string(mbr.partitions[i].start));
                    htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";
                    htmlContent += createTd("part_size");
                    htmlContent += createTd(std::to_string(mbr.partitions[i].size));
                    htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";
                    htmlContent += createTd("part_name");
                    htmlContent += createTd(mbr.partitions[i].name);
                    htmlContent += "\n</tr>";
                }
            }
        }

        htmlContent += "</table>\n</body>\n</html>\n";
        cout << htmlContent << endl;
        //cout << "entra en rep" << endl;
        //system("dot -Tpng /media/gerson/PR1/commands/ver.dot -o /media/gerson/PR1/commands/jiji.png");
    }
}