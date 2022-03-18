#include "../abstract/command.h"
#include "../allStructs/structs.h"
#include "../allStructs/globals.h"

#include<iostream>
#include <cstring> 
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cmath>
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

// QUITA DECIMALES A UN INT Y LO CONVIERTE A STRING
string truncateNumber(float v){
    return  to_string(v).substr(0,to_string(v).find_last_of(".")+3);
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

    // LEO TODO LO RELACIONADO AL SISTEMA DE ARCHIVOS
    SuperBloque superbloque;
    fseek(file,element->start + sizeof(Partition),SEEK_SET);
    fread(&superbloque,sizeof(SuperBloque),1,file);

    // CREACION DE ARRAYS PARA GUARDAR BITMAPS
    char bitinodes[superbloque.inodes_count];
    char bitblocks[superbloque.blocks_count];
    fseek(file,superbloque.bm_inode_start,SEEK_SET);
    fread(&bitinodes,sizeof(bitinodes),1,file);
    fseek(file,superbloque.bm_block_start,SEEK_SET);
    fread(&bitblocks,sizeof(bitblocks),1,file);

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
                htmlContent += "<tr>\n";htmlContent += createTd("part_start");htmlContent += createTd(std::to_string(temp.start + sizeof(Partition)));htmlContent += "\n</tr>";
                htmlContent += "<tr>\n";htmlContent += createTd("part_size");htmlContent += createTd(std::to_string(temp.size - sizeof(Partition)));htmlContent += "\n</tr>";
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
                    htmlContent += "<tr>\n";htmlContent += createTd("part_start");htmlContent += createTd(std::to_string(temp.start + sizeof(Partition)));htmlContent += "\n</tr>";
                    htmlContent += "<tr>\n";htmlContent += createTd("part_size");htmlContent += createTd(std::to_string(temp.size - sizeof(Partition)));htmlContent += "\n</tr>";
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

        float porcentage = 0;
        string dotContent = "digraph html { abc [shape=none, margin=0, label=< \n \
        <TABLE BORDER=\"1\" COLOR=\"#10a20e\" CELLBORDER=\"1\" CELLSPACING=\"3\" CELLPADDING=\"4\">";
        string logicas = "\n<TR>";
        string all_partitions="\n<TR>\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\">MBR</TD>\n";
        int availaible_space = 0;

        for(int i=0; i<4; i++){
            if(mbr.partitions[i].type != 'P'){
                int colspan = 2;
                Partition temp; // GUARDA EL TEMPORAL PARA RECORRER LA LISTA

                // LEO LA PRIMERA PARTICION LOGICA A DONDE APUNTA LA EXTENDIDA Y ASIGNO A TEMP
                fseek(file,mbr.partitions[i].next,SEEK_SET);
                fread(&temp,sizeof(Partition),1,file);
                // GRAFICA DE LOGICA
                porcentage = ((static_cast<float>(temp.size) * 100) / mbr.size);
                logicas += "\n<TD COLOR=\"#87b8a4\"> Lógica <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                logicas += "\n<TD COLOR=\"#87b8a4\">EBR</TD>\n" ;

                // MIENTRAS NO SE LLEGUE AL FINAL DE LA LISTA
                while(temp.next != -1){
                    colspan += 2;
                    fseek(file,temp.next,SEEK_SET);
                    fread(&temp,sizeof(Partition),1,file);
                    // GRAFICA DE LOGICA
                    porcentage = ((static_cast<float>(temp.size) * 100) / mbr.size);
                    logicas += "\n<TD COLOR=\"#87b8a4\"> Lógica <BR/>"+truncateNumber(porcentage)+"%</TD>\n";
                    logicas += "\n<TD COLOR=\"#87b8a4\">EBR</TD>\n" ;
                }

                // MIENTRAS NO LLEGUE A LA ULTIMA PARTICION
                if(i!=3){
                    // GRAFICA DE EXTENDIDA
                    porcentage = ((static_cast<float>(mbr.partitions[i].size) * 100) / mbr.size);
                    all_partitions += "\n<TD COLOR=\"#75e400\" COLSPAN=\""+std::to_string(colspan)+"\"> Extendida <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;

                    if(mbr.partitions[i+1].size != -1){
                        // CALCULO ESPACIO VACIO
                        availaible_space = (mbr.partitions[i+1].start) - (mbr.partitions[i].start + mbr.partitions[i].size);
                        // CALCULO PORCENTAJE
                        porcentage = ((static_cast<float>(availaible_space) * 100) / mbr.size);
                        if(porcentage > 0.8){
                            all_partitions += "\n<TD COLOR=\"#75e400\" COLSPAN=\""+std::to_string(colspan)+"\"> Libre <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                        }
                    }
                }else{
                    // GRAFICA DE EXTENDIDA
                    porcentage = ((static_cast<float>(mbr.partitions[i].size) * 100) / mbr.size);
                    all_partitions += "\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\"> Extendida <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                    // CALCULO ESPACIO VACIO
                    availaible_space = mbr.size - (mbr.partitions[i].start + mbr.partitions[i].size);
                    // CALCULO PORCENTAJE
                    porcentage = ((static_cast<float>(availaible_space) * 100) / mbr.size);
                    if(porcentage > 0.8){
                        all_partitions += "\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\"> Libre <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                    }
                }

            }else{
                // GRAFICO SOLO LAS PARTICIONES EXISTENTES
                if(mbr.partitions[i].size != -1){
                    // MIENTRAS NO LLEGUE A LA ULTIMA PARTICION
                    if(i!=3){
                        // GRAFICA DE PRIMARIA
                        porcentage = ((static_cast<float>(mbr.partitions[i].size) * 100) / mbr.size);
                        all_partitions += "\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\"> Primaria <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;

                        if(mbr.partitions[i+1].size != -1){
                            // CALCULO ESPACIO VACIO
                            availaible_space = (mbr.partitions[i+1].start) - (mbr.partitions[i].start + mbr.partitions[i].size);
                            // CALCULO PORCENTAJE
                            porcentage = ((static_cast<float>(availaible_space) * 100) / mbr.size);
                            if(porcentage > 0.8){
                                all_partitions += "\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\"> Libre <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                            }
                        }else{
                            // CALCULO ESPACIO VACIO
                            availaible_space = mbr.size - (mbr.partitions[i].start + mbr.partitions[i].size);
                            // CALCULO PORCENTAJE
                            porcentage = round((static_cast<float>(availaible_space) * 100) / mbr.size);
                            
                            if(porcentage > 0.8){
                                all_partitions += "\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\"> Libre <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                            }
                        }
                    }else{
                        // GRAFICA DE PRIMARIA
                        porcentage = round((static_cast<float>(mbr.partitions[i].size) * 100) / mbr.size);
                        all_partitions += "\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\"> Primaria <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                        // CALCULO ESPACIO VACIO
                        availaible_space = mbr.size - (mbr.partitions[i].start + mbr.partitions[i].size);
                        // CALCULO PORCENTAJE
                        porcentage = round((static_cast<float>(availaible_space) * 100) / mbr.size);
                        if(porcentage > 0.8){
                            all_partitions += "\n<TD COLOR=\"#75e400\" ROWSPAN=\"3\"> Libre <BR/>"+truncateNumber(porcentage)+"%</TD>\n" ;
                        }
                    }
                }
            }
        }


        all_partitions += "</TR>\n";
        logicas += "</TR>\n";
        dotContent += all_partitions + logicas +"</TABLE>>];\n}";
        //cout << dotContent << endl;

        ofstream output_file;
        output_file.open(this->path + ".dot");
        output_file << dotContent << endl;
        output_file.close();
        
        string command = "dot -Tpng " + this->path + ".dot" + " -o "+ this->path + ".png";
        system(command.c_str());

    } else if(this->name == "INODE"){
        InodeTable temp_inode;
        // CABECERA DEL GRAFO
        string dotContent = "digraph reporte {\n fontname=\"Helvetica,Arial,sans-serif\" \n rankdir=LR; \n node [shape=box]; \n node [fontname=\"Helvetica,Arial,sans-serif\" \n]";

        string nodes = "";
        string edges = "";

        // RECORRO INODOS
        for (int i=0; i<sizeof(bitinodes);i++){
            if(bitinodes[i] != '0'){
                //cout << superbloque.inode_start + i*sizeof(InodeTable) << endl;
                fseek(file,superbloque.inode_start + i*sizeof(InodeTable), SEEK_SET);
                fread(&temp_inode,sizeof(InodeTable),1,file);
                nodes += to_string(i) + "[label = \"\\n";  
                nodes += "Inodo: " + to_string(i) + "\\n";
                nodes += "i_uid: " + to_string(temp_inode.uid) + "\\n";
                nodes += "i_gid: " + to_string(temp_inode.gid) + "\\n";
                nodes += "i_size: " + to_string(temp_inode.size) + "\\n";
                //cout << temp_inode.atime << endl;
                nodes += "i_atime: " + (string)temp_inode.atime + "\\n";
                nodes += "i_ctime: " + (string)temp_inode.ctime + "\\n";
                nodes += "i_mtime: " + (string)temp_inode.mtime + "\\n";
                for(int i=0; i<15; i++){
                    nodes += "i_block_" + to_string(i+1) + ": " + to_string(temp_inode.block[i]) + "\\n";
                }
                //cout << temp_inode.atime << endl;
                aux = ""; aux.push_back(temp_inode.type);
                nodes += "i_type: " + aux + "\\n";
                nodes += "i_perm: " + to_string(temp_inode.perm) + "\\n";

                nodes += "\"]"; 
            }
        }

        // CREO LOS NODOS CON SUS ARISTAS
        int previous_inode=0;
        for(int i_inode=0; i_inode<sizeof(bitinodes); i_inode++){
            if(bitinodes[i_inode] != '0'){
                if((i_inode != sizeof(bitinodes)) && i_inode != 0){
                    edges += to_string(previous_inode) + "->" + to_string(i_inode) + "\n";
                    previous_inode = i_inode;
                }
            }
        }

        dotContent += nodes;
        dotContent += edges;
        dotContent += "}";
        //cout << dotContent << endl;

        ofstream output_file;
        output_file.open(this->path + ".dot");
        output_file << dotContent << endl;
        output_file.close();
        
        string command = "dot -Tpng " + this->path + ".dot" + " -o "+ this->path + ".png";
        system(command.c_str());
    } else if(this->name == "BLOCK"){
        // VARIABLE PARA RECORRER INODOS
        InodeTable temp_inode;

        // VARIABLES PARA MOSTRAR TODOS LOS TIPOS DE BLOQUES
        FileBlock file_block;
        ArchiveBlock archive_block;

        // CABECERA DEL GRAFO
        string dotContent = "digraph reporte {\n fontname=\"Helvetica,Arial,sans-serif\" \n rankdir=LR; \n node [shape=box]; \n node [fontname=\"Helvetica,Arial,sans-serif\" \n]";

        string nodes = "";
        string edges = "";
        

        // RECORRO INODOS
        for (int i=0; i<sizeof(bitinodes);i++){
            // SI NO ES UN INODO LIBRE 
            if(bitinodes[i] != '0'){
                // LEO EL INODO
                fseek(file,superbloque.inode_start + i*sizeof(InodeTable), SEEK_SET);
                fread(&temp_inode,sizeof(InodeTable),1,file);
                for(int block_index=0; block_index<14; block_index++){
                    if(temp_inode.block[block_index] != -1){
                        // SI ES UN NODO DE ARCHIVO
                        if(temp_inode.type == '1'){
                            //cout << temp_inode.block[block_index] << endl;
                            fseek(file,superbloque.block_start + temp_inode.block[block_index]*sizeof(ArchiveBlock), SEEK_SET);
                            fread(&archive_block,sizeof(ArchiveBlock),1,file);
                            nodes += to_string(temp_inode.block[block_index]) + "[label = \"\\n"; 
                            nodes += "Bloque: " + to_string(temp_inode.block[block_index]) + "\n";
                            int new_line = 0; 
                            for(int content=0; content<64; content++){
                                nodes += archive_block.content[content];
                                if(new_line == 16){
                                    nodes += "\\n";
                                    new_line = 0;
                                }
                                new_line++;
                            }
                            nodes += "\"]"; 
                        }else if(temp_inode.type == '0'){ // SI ES UN BLOQUE DE CARPETA
                            fseek(file,superbloque.block_start + temp_inode.block[block_index]*sizeof(FileBlock), SEEK_SET);
                            fread(&file_block,sizeof(FileBlock),1,file);
                            nodes += to_string(temp_inode.block[block_index]) + "[align=left,label = \"\\n";
                            nodes += "Bloque: " + to_string(temp_inode.block[block_index]) + "\n";
                            nodes += "b_name        b_inodo \\n";
                            for(int content=0; content<4; content++){
                                //cout << temp_inode.block[block_index] << " " << file_block.content[content].name << endl;
                                nodes += (string)file_block.content[content].name + "   ->   " + to_string(file_block.content[content].inodo) + "\\n\n";
                            }
                            nodes += "\"]"; 
                        }
                    }
                }
            }
        }

        // CREO LOS NODOS CON SUS ARISTAS
        int previous_block=0;
        for(int i_block=0; i_block<sizeof(bitblocks); i_block++){
            if(bitblocks[i_block] != '0'){
                if((i_block != sizeof(bitblocks)) && i_block != 0){
                    edges += to_string(previous_block) + "->" + to_string(i_block) + "\n";
                    previous_block = i_block;
                }
            }
        }

        dotContent += nodes;
        dotContent += edges;
        dotContent += "}";
        //cout << dotContent << endl;
        ofstream output_file;
        output_file.open(this->path + ".dot");
        output_file << dotContent << endl;
        output_file.close();
        
        string command = "dot -Tpng " + this->path + ".dot" + " -o "+ this->path + ".png";
        system(command.c_str());
    } else if(this->name == "BM_INODE"){
        string bm_inodes = "";

        for(int inode=0; inode<sizeof(bitinodes); inode++){
            bm_inodes += bitinodes[inode];
            bm_inodes += " ";
            if(inode == 19){
                bm_inodes += "\n";
            }
        }
        //cout << bm_inodes << endl;
        // CREO EL .TXT 
        ofstream output_file;
        output_file.open(this->path + ".txt");
        output_file << bm_inodes << endl;
        output_file.close();

    }else if(this->name == "BM_BLOCK"){
        string bm_block = "";

        for(int block=0; block<sizeof(bitblocks); block++){
            bm_block += bitblocks[block];
            bm_block += " ";
            if(block == 19){
                bm_block += "\n";
            }
        }

        // CREO EL .TXT 
        ofstream output_file;
        output_file.open(this->path + ".txt");
        output_file << bm_block << endl;
        output_file.close();
    }else if(this->name == "SB"){
        // BUSCO EL PRIMER INODO LIBRE
        for(int i=0; i<sizeof(bitinodes); i++){
            if(bitinodes[i] == '0'){
                superbloque.first_inode = i;
                break;
            }
        }

        // BUSCO EL PRIMER BLOQUE LIBRE
        for(int i=0; i<sizeof(bitblocks); i++){
            if(bitblocks[i] == '0'){
                superbloque.first_block = i;
                break;
            }
        }

        string html_content = "<html>\n<head><title>"+report_name+"</title> <link rel=\"stylesheet\" type=\"text/css\" href=\"/media/gerson/PR1/styles/style.css\" /> </head>\n<body>\n<table>\n";

        html_content += "<tr>\n";
        html_content += createTh("REPORTE DE SUPERBLOQUE","mbr-th");
        html_content += createTh("","mbr-th");
        html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_filesystem_type");html_content += createTd(to_string(superbloque.filesystem_type));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_inodes_count");html_content += createTd(to_string(superbloque.inodes_count));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_blocks_count");html_content += createTd(to_string(superbloque.blocks_count));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_free_blocks_count");html_content += createTd(to_string(superbloque.free_blocks_count));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_free_inodes_count");html_content += createTd(to_string(superbloque.free_inodes_count));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_mtime");html_content += createTd(string(superbloque.mtime));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_umtime");html_content += createTd(string(superbloque.umtime));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_mnt_count");html_content += createTd(to_string(superbloque.mnt_count));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_magic");html_content += createTd(to_string(superbloque.magic));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_inode_size");html_content += createTd(to_string(superbloque.inode_size));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_block_size");html_content += createTd(to_string(superbloque.block_size));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_first_inode");html_content += createTd(to_string(superbloque.first_inode));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_first_block");html_content += createTd(to_string(superbloque.first_block));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_bm_inode_start");html_content += createTd(to_string(superbloque.bm_inode_start));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_bm_block_start");html_content += createTd(to_string(superbloque.bm_block_start));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_inode_start");html_content += createTd(to_string(superbloque.inode_start));html_content += "\n</tr>";
        html_content += "<tr>\n";html_content += createTd("sb_block_start");html_content += createTd(to_string(superbloque.block_start));html_content += "\n</tr>";

        html_content += "</table>\n</body>\n</html>\n";
        //cout << html_content << endl;

        ofstream output_file;
        output_file.open(this->path + ".html");
        output_file << html_content << endl;
        output_file.close();
    }

    fclose(file);
}