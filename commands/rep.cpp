#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
#include <fstream>
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

string createTh(string content, string className){
    return "<th class=\"" + className + "\">" + content + "</th>";
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
    string aux; // STRING PARA CONVERTIR CARACTERES

    // LEO EL MBR
    MBR mbr;
    fseek(file,0,SEEK_SET);
    fread(&mbr,sizeof(MBR),1,file);

    if(this->name == "MBR"){

        string htmlContent = "<html>\n<head><title>"+report_name+"</title> <link rel=\"stylesheet\" type=\"text/css\" href=\"/media/gerson/PR1/styles/style.css\" /> </head>\n<body>\n<table>\n";

        // REPORTE DE MBR
        htmlContent += "<tr>\n";
        htmlContent += createTh("REPORTE DE MBR","mbr-th");
        htmlContent += createTh("","mbr-th");
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
                htmlContent += "<tr>\n";
                htmlContent += createTh("Particion","primary-th");
                htmlContent += createTh("","primary-th");
                htmlContent += "\n</tr>";

                htmlContent += "<tr>\n";htmlContent += createTd("part_status");aux = "";aux.push_back(mbr.partitions[i].status);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_type");aux = "";aux.push_back(mbr.partitions[i].type);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_fit");htmlContent += createTd(mbr.partitions[i].fit);htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_start");htmlContent += createTd(std::to_string(mbr.partitions[i].start));htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_size");htmlContent += createTd(std::to_string(mbr.partitions[i].size));htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_name");htmlContent += createTd(mbr.partitions[i].name);htmlContent += "\n</tr>";

                Partition temp; // GUARDA EL TEMPORAL PARA RECORRER LA LISTA

                // LEO LA PRIMERA PARTICION LOGICA A DONDE APUNTA LA EXTENDIDA Y ASIGNO A TEMP
                fseek(file,mbr.partitions[i].next,SEEK_SET);
                fread(&temp,sizeof(Partition),1,file);

                htmlContent += "<tr>\n";
                htmlContent += createTh("Particion Lógica","logic-th");
                htmlContent += createTh("","logic-th");
                htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_status");aux = "";aux.push_back(temp.status);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_type");aux = "";aux.push_back(temp.type);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_fit");htmlContent += createTd(temp.fit);htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_start");htmlContent += createTd(std::to_string(temp.start));htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_size");htmlContent += createTd(std::to_string(temp.size));htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_name");htmlContent += createTd(temp.name);htmlContent += "\n</tr>";

                // MIENTRAS NO SE LLEGUE AL FINAL DE LA LISTA
                while(temp.next != -1){
                    fseek(file,temp.next,SEEK_SET);
                    fread(&temp,sizeof(Partition),1,file);

                    htmlContent += "<tr>\n";
                    htmlContent += createTh("Particion Lógica","logic-th");
                    htmlContent += createTh("","logic-th");
                    htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_status");aux = "";aux.push_back(temp.status);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_type");aux = "";aux.push_back(temp.type);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_fit");htmlContent += createTd(temp.fit);htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_start");htmlContent += createTd(std::to_string(temp.start));htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_size");htmlContent += createTd(std::to_string(temp.size));htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_name");htmlContent += createTd(temp.name);htmlContent += "\n</tr>";
                }

            }else{
                if(mbr.partitions[i].size != -1){
                    htmlContent += "<tr>\n";
                    htmlContent += createTh("Particion","primary-th");
                    htmlContent += createTh("","primary-th");
                    htmlContent += "\n</tr>";

                    htmlContent += "<tr>\n";htmlContent += createTd("part_status");aux = "";aux.push_back(mbr.partitions[i].status);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_type");aux = "";aux.push_back(mbr.partitions[i].type);htmlContent += createTd(aux);htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_fit");htmlContent += createTd(mbr.partitions[i].fit);htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_start");htmlContent += createTd(std::to_string(mbr.partitions[i].start));htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_size");htmlContent += createTd(std::to_string(mbr.partitions[i].size));htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_name");htmlContent += createTd(mbr.partitions[i].name);htmlContent += "\n</tr>";
                }
            }
        }

        htmlContent += "</table>\n</body>\n</html>\n";
        //cout << htmlContent << endl;

        ofstream output_file;
        output_file.open(this->path + ".html");
        output_file << htmlContent << endl;
        output_file.close();

        //system("dot -Tpng /media/gerson/PR1/commands/ver.dot -o /media/gerson/PR1/commands/jiji.png");
    }else if(this->name == "DISK"){

        string dotContent = "digraph{\ntbl[shape=plaintext\nlabel=<<table border='0' cellborder='1' color='blue' cellspacing='0'>\n";

        for(int i=0; i<4; i++){
            //cout << mbr.partitions[i].name << endl;
            if(mbr.partitions[i].type != 'P'){

                Partition temp; // GUARDA EL TEMPORAL PARA RECORRER LA LISTA

                // LEO LA PRIMERA PARTICION LOGICA A DONDE APUNTA LA EXTENDIDA Y ASIGNO A TEMP
                fseek(file,mbr.partitions[i].next,SEEK_SET);
                fread(&temp,sizeof(Partition),1,file);

                // MIENTRAS NO SE LLEGUE AL FINAL DE LA LISTA
                while(temp.next != -1){
                    fseek(file,temp.next,SEEK_SET);
                    fread(&temp,sizeof(Partition),1,file);
                }

            }else{
                // GRAFICO SOLO LAS PARTICIONES EXISTENTES
                if(mbr.partitions[i].size != -1){
                    dotContent += "<td rowspan='2'>" + (string)mbr.partitions[i].name + "<br/>" + (string)mbr.partitions[i].name + "</td>";
                }
            }
        }

        dotContent += "</table>\n>];\n}";
        //cout << htmlContent << endl;

        //ofstream output_file;
        //output_file.open(this->path + ".html");
        //output_file << htmlContent << endl;
        //output_file.close();

    }
}